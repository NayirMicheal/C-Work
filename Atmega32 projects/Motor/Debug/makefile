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
khalifa_motor.lss \

FLASH_IMAGE += \
khalifa_motor.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: khalifa_motor.elf secondary-outputs

# Tool invocations
khalifa_motor.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,khalifa_motor.map -mmcu=atmega32 -o "khalifa_motor.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

khalifa_motor.lss: khalifa_motor.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S khalifa_motor.elf  >"khalifa_motor.lss"
	@echo 'Finished building: $@'
	@echo ' '

khalifa_motor.hex: khalifa_motor.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex khalifa_motor.elf  "khalifa_motor.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: khalifa_motor.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 khalifa_motor.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: khalifa_motor.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:khalifa_motor.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) khalifa_motor.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
