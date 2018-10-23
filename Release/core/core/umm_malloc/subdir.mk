################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266\umm_malloc\umm_malloc.c 

C_DEPS += \
.\core\core\umm_malloc\umm_malloc.c.d 

AR_OBJ += \
.\core\core\umm_malloc\umm_malloc.c.o 


# Each subdirectory must supply rules for building sources it contributes
core\core\umm_malloc\umm_malloc.c.o: D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266\umm_malloc\umm_malloc.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"D:\sloeber\arduinoPlugin\packages\esp8266\tools\xtensa-lx106-elf-gcc\1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/include" "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/lwip2/include" "-ID:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/tools/sdk/libc/xtensa-lx106-elf/include" "-ID:/Workspace/Arduino/ESP8266_EPAPER_WEATHER/Release/core" -c -Wall -Wextra  -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=80000000L -DLWIP_OPEN_SRC -DTCP_MSS=536   -DARDUINO=10802 -DARDUINO_ESP8266_NODEMCU -DARDUINO_ARCH_ESP8266 -DARDUINO_BOARD="\"ESP8266_NODEMCU\""   -DESP8266   -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\cores\esp8266" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\variants\nodemcu" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\libraries\SPI" -I"C:\Users\kiki\Documents\Arduino\libraries\EPD1IN54" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\libraries\ESP8266HTTPClient\src" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\libraries\ESP8266WiFi\src" -I"D:\sloeber\arduinoPlugin\libraries\ArduinoJson\5.13.2\src" -I"C:\Users\kiki\Documents\Arduino\libraries\GxEPD-master\src" -I"D:\sloeber\arduinoPlugin\libraries\Adafruit_GFX_Library\1.2.9" -I"D:\sloeber\arduinoPlugin\packages\esp8266\hardware\esp8266\2.4.2\libraries\Ticker" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


