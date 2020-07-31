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
audio_three_btns.lss \

FLASH_IMAGE += \
audio_three_btns.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: audio_three_btns.elf secondary-outputs

# Tool invocations
audio_three_btns.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,audio_three_btns.map -mmcu=atmega32 -o "audio_three_btns.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

audio_three_btns.lss: audio_three_btns.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S audio_three_btns.elf  >"audio_three_btns.lss"
	@echo 'Finished building: $@'
	@echo ' '

audio_three_btns.hex: audio_three_btns.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex audio_three_btns.elf  "audio_three_btns.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: audio_three_btns.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 audio_three_btns.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: audio_three_btns.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -Uflash:w:audio_three_btns.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) audio_three_btns.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
