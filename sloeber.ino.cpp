#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2018-10-23 22:17:59

#include "Arduino.h"
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

void setup() ;
void loop() ;
void tickerHandler() ;
bool configWiFi() ;
void requestWeatherInfo() ;
void parseWeatherJson(String buffer) ;
void requestForecastInfo() ;
void parseForecastJson(String buffer) ;
const char* parseWeatherCondition(int conditionId) ;
void drawBackgroundImage() ;
void drawWeatherIcon(int conditionId) ;
void drawText(int x, int y, const char* text, const GFXfont* font) ;
void drawText(const char* text) ;
void showDisplay() ;

#include "ESP8266_EPAPER_WEATHER.ino"


#endif
