################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DELAY.c \
../DIO_prog.c \
../EXTI_prog.c \
../GIE_prog.c \
../LED_MATRIX_prog.c \
../main.c 

OBJS += \
./DELAY.o \
./DIO_prog.o \
./EXTI_prog.o \
./GIE_prog.o \
./LED_MATRIX_prog.o \
./main.o 

C_DEPS += \
./DELAY.d \
./DIO_prog.d \
./EXTI_prog.d \
./GIE_prog.d \
./LED_MATRIX_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


