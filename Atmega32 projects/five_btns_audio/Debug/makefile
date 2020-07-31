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
five_btns_audio.lss \

FLASH_IMAGE += \
five_btns_audio.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: five_btns_audio.elf secondary-outputs

# Tool invocations
five_btns_audio.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,five_btns_audio.map -mmcu=atmega32 -o "five_btns_audio.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

five_btns_audio.lss: five_btns_audio.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S five_btns_audio.elf  >"five_btns_audio.lss"
	@echo 'Finished building: $@'
	@echo ' '

five_btns_audio.hex: five_btns_audio.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex five_btns_audio.elf  "five_btns_audio.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: five_btns_audio.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 five_btns_audio.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: five_btns_audio.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:five_btns_audio.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) five_btns_audio.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
