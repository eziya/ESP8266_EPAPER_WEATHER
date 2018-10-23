################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ..\makefile.init

RM := del 

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include libraries\Ticker\subdir.mk
-include libraries\SPI\subdir.mk
-include libraries\GxEPD-master\src\GxIO\GxIO_SPI\subdir.mk
-include libraries\GxEPD-master\src\GxIO\subdir.mk
-include libraries\GxEPD-master\src\GxGDEW075Z09\subdir.mk
-include libraries\GxEPD-master\src\GxGDEW075T8\subdir.mk
-include libraries\GxEPD-master\src\GxGDEW0583T7\subdir.mk
-include libraries\GxEPD-master\src\GxGDEW042Z15\subdir.mk
-include libraries\GxEPD-master\src\GxGDEW042T2\subdir.mk
-include libraries\GxEPD-master\src\GxGDEW029Z10\subdir.mk
-include libraries\GxEPD-master\src\GxGDEW027W3\subdir.mk
-include libraries\GxEPD-master\src\GxGDEW027C44\subdir.mk
-include libraries\GxEPD-master\src\GxGDEW0213Z16\subdir.mk
-include libraries\GxEPD-master\src\GxGDEW0154Z17\subdir.mk
-include libraries\GxEPD-master\src\GxGDEW0154Z04\subdir.mk
-include libraries\GxEPD-master\src\GxGDEP015OC1\subdir.mk
-include libraries\GxEPD-master\src\GxGDEH029A1\subdir.mk
-include libraries\GxEPD-master\src\GxGDE0213B1\subdir.mk
-include libraries\GxEPD-master\src\subdir.mk
-include libraries\ESP8266WiFi\src\subdir.mk
-include libraries\ESP8266HTTPClient\src\subdir.mk
-include libraries\EPD1IN54\subdir.mk
-include libraries\Adafruit_GFX_Library\subdir.mk
-include core\core\umm_malloc\subdir.mk
-include core\core\spiffs\subdir.mk
-include core\core\libb64\subdir.mk
-include core\core\subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ..\makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
D:\Workspace\Arduino\ESP8266_EPAPER_WEATHER\Release\arduino.ar \

ELF += \
ESP8266_EPAPER_WEATHER.elf \

HEX += \
ESP8266_EPAPER_WEATHER.hex \


# All Target
all: ESP8266_EPAPER_WEATHER

# Tool invocations
ESP8266_EPAPER_WEATHER: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"D:\sloeber\arduinoPlugin\packages\esp8266\tools\xtensa-lx106-elf-gcc\1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-size" -A "D:/Workspace/Arduino/ESP8266_EPAPER_WEATHER/Release/ESP8266_EPAPER_WEATHER.elf"
	@echo 'Finished building target: $@'
	@echo ' '

D:\Workspace\Arduino\ESP8266_EPAPER_WEATHER\Release\arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"D:\sloeber\arduinoPlugin\packages\esp8266\tools\xtensa-lx106-elf-gcc\1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar" cru  "D:/Workspace/Arduino/ESP8266_EPAPER_WEATHER/Release/arduino.ar"    D:/Workspace/Arduino/ESP8266_EPAPER_WEATHER/Release/arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

ESP8266_EPAPER_WEATHER.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	${A.RECIPE.HOOKS.LINKING.PRELINK.1.PATTERN}
	${A.RECIPE.C.COMBINE.PATTERN.1}  $(LINK_OBJ) ${A.RECIPE.C.COMBINE.PATTERN.2} ${A.ARCHIVE_FILE_PATH} ${A.RECIPE.C.COMBINE.PATTERN.3} ${JANTJE.EXTRA.ALL} ${JANTJE.EXTRA.LINK}${A.JANTJE.POST.LINK}
	@echo 'Finished building: $@'
	@echo ' '

ESP8266_EPAPER_WEATHER.hex: $(ELF)
	@echo 'Do all objcopy commands'
	"D:\sloeber\arduinoPlugin\packages\esp8266\tools\esptool\0.4.13/esptool.exe" -eo "D:\sloeber\/arduinoPlugin/packages/esp8266/hardware/esp8266/2.4.2/bootloaders/eboot/eboot.elf" -bo "D:/Workspace/Arduino/ESP8266_EPAPER_WEATHER/Release/ESP8266_EPAPER_WEATHER.bin" -bm dio -bf 40 -bz 4M -bs .text -bp 4096 -ec -eo "D:/Workspace/Arduino/ESP8266_EPAPER_WEATHER/Release/ESP8266_EPAPER_WEATHER.elf" -bs .irom0.text -bs .text -bs .data -bs .rodata -bc -ec
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents

-include ..\makefile.targets
