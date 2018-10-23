################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Users\kiki\Documents\Arduino\libraries\GxEPD-master\src\GxGDE0213B1\GxGDE0213B1.cpp 

LINK_OBJ += \
.\libraries\GxEPD-master\src\GxGDE0213B1\GxGDE0213B1.cpp.o 

CPP_DEPS += \
.\libraries\GxEPD-master\src\GxGDE0213B1\GxGDE0213B1.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\GxEPD-master\src\GxGDE0213B1\GxGDE0213B1.cpp.o: C:\Users\kiki\Documents\Arduino\libraries\GxEPD-master\src\GxGDE0213B1\GxGDE0213B1.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"D:\sloeber\arduinoPlugin\packages\esp8266\tools\xtensa-lx106-elf-gcc\1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-ID:/Workspace/Arduino/ESP8266_EPAPER_WEATHER/Release/core" -c -Wall -Wextra  -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_NODEMCU -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="\"ESP8266_NODEMCU\""   -DESP8266   -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\variants\nodemcu" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\libraries\SPI" -I"C:\Users\kiki\Documents\Arduino\libraries\EPD1IN54" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\libraries\ESP8266HTTPClient\src" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\libraries\ESP8266WiFi\src" -I"D:\sloeber\arduinoPlugin\libraries\ArduinoJson\5.13.2\src" -I"C:\Users\kiki\Documents\Arduino\libraries\GxEPD-master\src" -I"D:\sloeber\arduinoPlugin\libraries\Adafruit_GFX_Library\1.2.9" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\libraries\Ticker" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


