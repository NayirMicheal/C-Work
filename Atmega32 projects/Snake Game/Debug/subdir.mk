################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DELAY.c \
../DIO_prog.c \
../LCD_prog.c \
../LED_MATRIX_prog.c \
../SEVENSEG_prog.c \
../main.c 

OBJS += \
./DELAY.o \
./DIO_prog.o \
./LCD_prog.o \
./LED_MATRIX_prog.o \
./SEVENSEG_prog.o \
./main.o 

C_DEPS += \
./DELAY.d \
./DIO_prog.d \
./LCD_prog.d \
./LED_MATRIX_prog.d \
./SEVENSEG_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


