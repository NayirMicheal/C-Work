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
GRAPHICAL_LCD.lss \

FLASH_IMAGE += \
GRAPHICAL_LCD.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: GRAPHICAL_LCD.elf secondary-outputs

# Tool invocations
GRAPHICAL_LCD.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,GRAPHICAL_LCD.map -mmcu=atmega32 -o "GRAPHICAL_LCD.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

GRAPHICAL_LCD.lss: GRAPHICAL_LCD.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S GRAPHICAL_LCD.elf  >"GRAPHICAL_LCD.lss"
	@echo 'Finished building: $@'
	@echo ' '

GRAPHICAL_LCD.hex: GRAPHICAL_LCD.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex GRAPHICAL_LCD.elf  "GRAPHICAL_LCD.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: GRAPHICAL_LCD.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 GRAPHICAL_LCD.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: GRAPHICAL_LCD.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:GRAPHICAL_LCD.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) GRAPHICAL_LCD.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
