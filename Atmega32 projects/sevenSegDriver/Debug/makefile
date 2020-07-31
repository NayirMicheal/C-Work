################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
sevenSegDriver.lss \

FLASH_IMAGE += \
sevenSegDriver.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: sevenSegDriver.elf secondary-outputs

# Tool invocations
sevenSegDriver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,sevenSegDriver.map -mmcu=atmega32 -o "sevenSegDriver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

sevenSegDriver.lss: sevenSegDriver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S sevenSegDriver.elf  >"sevenSegDriver.lss"
	@echo 'Finished building: $@'
	@echo ' '

sevenSegDriver.hex: sevenSegDriver.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex sevenSegDriver.elf  "sevenSegDriver.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: sevenSegDriver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 sevenSegDriver.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: sevenSegDriver.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:sevenSegDriver.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) sevenSegDriver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
