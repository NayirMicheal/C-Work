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
Hex_binary.lss \

FLASH_IMAGE += \
Hex_binary.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Hex_binary.elf secondary-outputs

# Tool invocations
Hex_binary.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Hex_binary.map -mmcu=atmega32 -o "Hex_binary.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Hex_binary.lss: Hex_binary.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Hex_binary.elf  >"Hex_binary.lss"
	@echo 'Finished building: $@'
	@echo ' '

Hex_binary.hex: Hex_binary.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Hex_binary.elf  "Hex_binary.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Hex_binary.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Hex_binary.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Hex_binary.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
