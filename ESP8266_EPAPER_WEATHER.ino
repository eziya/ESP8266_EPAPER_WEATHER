#include "Arduino.h"
#include <ArduinoJson.h>
#include <Ticker.h>

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#include <GxEPD.h>
#include <GxGDEP015OC1/GxGDEP015OC1.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

#include <Fonts/DSDIGIT9pt7b.h>
#include <Fonts/DSDIGIT30pt7b.h>

#include "ImageData.h"

#define WIFI_SSID			"SSID"
#define WIFI_PWD			"PWD"
#define REGION				"tenan"
#define COUNTRY				"kr"
#define APPID				"APPID"
#define REQ_INTERVAL_SEC	60

#define WEATHER_ICON_WIDTH	72
#define WEATHER_ICON_HEIGHT	72

bool requestFlag = false;
Ticker ticker;
String JsonStr;
DynamicJsonBuffer jsonBuffer;

/* BUSY -> GPIO4, RST -> GPIO2, DC -> GPIO0, CS -> GPIO5, CLK -> GPIO14, DIN -> GPIO13, GND -> GND, 3.3V -> 3.3V */
/* I've changed CS pin from GPIO15 to GPIO5 as Waveshare EPD makes GPIO15 high when NodeMCU restarts. */
GxIO_Class io(SPI, SS, 0, 2);
GxEPD_Class display(io);

void setup() {
	Serial.begin(115200);
	//Serial.setDebugOutput(true);

	if(!configWiFi())
	{
		Serial.println("ERROR: configESP");
		while(1);
	}

	/* Initialize GxEPD library */
	display.init();

	/* Set ticker as 10 minutes */
	ticker.attach(REQ_INTERVAL_SEC, tickerHandler);

	/* Get weather information */
	requestWeatherInfo();
	delay(3000);
	requestForecastInfo();
}

void loop()
{
	/* Every 10 minutes */
	if(requestFlag)
	{
		requestWeatherInfo();
		delay(3000);
		requestForecastInfo();
		requestFlag = false;
	}
}

void tickerHandler()
{
	/* If you call requestWeatherInfo directly inside ticker callback function, HttpClient doesn't work properly */
	requestFlag = true;
}

bool configWiFi()
{
	Serial.println();

	if(!WiFi.begin(WIFI_SSID, WIFI_PWD))
	{
		Serial.println("ERROR: WiFi.begin");
		return false;
	}

	Serial.println("OK: WiFi.begin");

	while(WiFi.status() != WL_CONNECTED)
	{
		delay(100);
		Serial.print(".");
	}

	Serial.println();
	Serial.println("OK: WiFi connected");

	return true;
}

void requestWeatherInfo()
{
	HTTPClient httpClient;
	httpClient.setTimeout(2000);

	/* Connect & Request */
	String url = String("/data/2.5/weather?q=") + String(REGION) + String(",") + String(COUNTRY) + String("&units=metric&appid=") + String(APPID);
	if(!httpClient.begin("api.openweathermap.org", 80, url.c_str()))
	{
		Serial.println("ERROR: HTTPClient.begin");
		return;
	}

	Serial.println("OK: HTTPClient.begin");

	int httpCode = httpClient.GET();

	/* Check response */
	if(httpCode > 0)
	{
		Serial.printf("[HTTP] request from the client was handled: %d\n", httpCode);
		String payload = httpClient.getString();
		parseWeatherJson(payload);
	}
	else
	{
		Serial.printf("[HTTP] connection failed: %s\n", httpClient.errorToString(httpCode).c_str());
	}

	httpClient.end();
}

void parseWeatherJson(String buffer)
{
	int JsonStartIndex = buffer.indexOf('{');
	int JsonLastIndex = buffer.lastIndexOf('}');

	/* Substring JSON string */
	JsonStr = buffer.substring(JsonStartIndex, JsonLastIndex+1);
	Serial.println("PARSE JSON WEATHER INFORMATION: " + JsonStr);

	/* Clear buffer */
	jsonBuffer.clear();

	/* Parse JSON string */
	JsonObject& root = jsonBuffer.parseObject(JsonStr);

	if(root.success())
	{
		/* Get information */
		double temp = root["main"]["temp"];
		int humidity = root["main"]["humidity"];
		int temp_min = root["main"]["temp_min"];
		int temp_max = root["main"]["temp_max"];
		int speed = root["wind"]["speed"];
		int direction = root["wind"]["direction"];
		int conditionId = root["weather"][0]["id"];
		const char* name = root["name"];
		const char* weather = parseWeatherCondition(conditionId);

		/* Serial Output */
		Serial.printf("Temp: %3.1f\r\n", temp);
		Serial.printf("Humidity: %d\r\n", humidity);
		Serial.printf("Min. Temp: %d\r\n", temp_min);
		Serial.printf("Max. Temp: %d\r\n", temp_max);
		Serial.printf("Wind Speed: %d\r\n", speed);
		Serial.printf("Wind Direction: %d\r\n", direction);
		Serial.printf("ConditionId: %d\r\n", conditionId);
		Serial.printf("Name: %s\r\n", name);
		Serial.printf("Weather: %s\r\n", weather);

		/* Draw EPD */
		drawBackgroundImage();
		drawWeatherIcon(conditionId);
		drawText(110, 80, String(temp, 1).c_str(), &DSDIGIT30pt7b);
		drawText(5, 115, String(name).c_str(), &DSDIGIT9pt7b);
		drawText("\r\n  Humidity: ");
		drawText(String(humidity).c_str());
		drawText("%");
		drawText("\r\n  Min Temp: ");
		drawText(String(temp_min).c_str());
		drawText(" ,Max Temp: ");
		drawText(String(temp_max).c_str());
		drawText("\r\n  Wind Speed: ");
		drawText(String(speed).c_str());
		drawText("\r\n  Wind Direction: ");
		drawText(String(direction).c_str());
		showDisplay();
	}
	else
	{
		Serial.println("jsonBuffer.parseObject failed");
	}
}

void requestForecastInfo()
{
	HTTPClient httpClient;
	httpClient.setTimeout(2000);

	/* Connect & Request */
	String url = String("/data/2.5/forecast?q=") + String(REGION) + String(",") + String(COUNTRY) + String("&cnt=8&units=metric&appid=") + String(APPID);
	if(!httpClient.begin("api.openweathermap.org", 80, url.c_str()))
	{
		Serial.println("ERROR: HTTPClient.begin");
		return;
	}

	Serial.println("OK: HTTPClient.begin");

	int httpCode = httpClient.GET();

	/* Check response */
	if(httpCode > 0)
	{
		Serial.printf("[HTTP] request from the client was handled: %d\n", httpCode);
		String payload = httpClient.getString();
		parseForecastJson(payload);
	}
	else
	{
		Serial.printf("[HTTP] connection failed: %s\n", httpClient.errorToString(httpCode).c_str());
	}

	httpClient.end();
}


void parseForecastJson(String buffer)
{
	int JsonStartIndex = buffer.indexOf('{');
	int JsonLastIndex = buffer.lastIndexOf('}');

	JsonStr = buffer.substring(JsonStartIndex, JsonLastIndex+1);
	Serial.println("PARSE JSON FORECAST INFORMATION: " + JsonStr);

	jsonBuffer.clear();
	JsonObject& root = jsonBuffer.parseObject(JsonStr);

	if(root.success())
	{
		JsonArray& list = root["list"];

		for(auto& item : list)
		{
			const char* time = item["dt_txt"];
			double temp = item["main"]["temp"];
			int humidity = item["main"]["humidity"];
			int conditionId = item["weather"][0]["id"];
			const char* weather = parseWeatherCondition(conditionId);

			Serial.printf("Time: %s\r\n", time);
			Serial.printf("Temp: %3.1f C\r\n", temp);
			Serial.printf("Humidity: %d %%\r\n", humidity);
			Serial.printf("Condition: %d\r\n", conditionId);
			Serial.printf("Weather: %s\r\n", weather);
		}
	}
	else
	{
		Serial.println("jsonBuffer.parseObject failed");
	}
}

const char* parseWeatherCondition(int conditionId)
{
	/* Return string for conditionId */
	if(conditionId >= 200 && conditionId < 300) return "Thunderstorm";
	else if(conditionId >= 300 && conditionId < 400) return "Drizzle";
	else if(conditionId >= 500 && conditionId < 600) return "Rain";
	else if(conditionId >= 600 && conditionId < 700) return "Snow";
	else if(conditionId >= 700 && conditionId < 800) return "Fog";
	else if(conditionId == 800) return "Clear";
	else if(conditionId > 800 && conditionId < 900) return "Clouds";
	else return "Unknown condition";
}

void drawBackgroundImage()
{
	/* Clear screen */
	display.fillScreen(GxEPD_WHITE);

	/* Draw bitmap */
	display.drawBitmap(FRAME, 0, 0, GxEPD_WIDTH, GxEPD_HEIGHT, GxEPD_BLACK, GxEPD::bm_normal);
}

void drawWeatherIcon(int conditionId)
{
	/* Draw bitmap image for conditionId */
	const uint8_t* bitmap;
	if(conditionId >= 200 && conditionId < 300)
	{
		bitmap = STORM;
	}
	else if(conditionId >= 300 && conditionId < 400)
	{
		bitmap = RAIN;
	}
	else if(conditionId >= 500 && conditionId < 600)
	{
		bitmap = RAIN;
	}
	else if(conditionId >= 600 && conditionId < 700)
	{
		bitmap = SNOW;
	}
	else if(conditionId >= 700 && conditionId < 800)
	{
		bitmap = FOG;
	}
	else if(conditionId == 800)
	{
		bitmap = SUNNY;
	}
	else if(conditionId > 800 && conditionId < 900)
	{
		bitmap = SUNNY_CLOUDY;
	}
	else
	{
		bitmap = SUNNY;
	}

	display.drawBitmap(bitmap, 14, 14, WEATHER_ICON_WIDTH, WEATHER_ICON_HEIGHT, GxEPD_BLACK, GxEPD::bm_normal);
}

void drawText(int x, int y, const char* text, const GFXfont* font)
{
	/* set text color */
	display.setTextColor(GxEPD_BLACK);

	/* set font */
	display.setFont(font);

	/* set position */
	display.setCursor(x, y);

	/* print text */
	display.print(text);
}

void drawText(const char* text)
{
	/* print text */
	display.print(text);
}

void showDisplay()
{
	/* show frame buffer */
	display.update();
}

