################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src-gen/Ampel.c 

OBJS += \
./src-gen/Ampel.o 

C_DEPS += \
./src-gen/Ampel.d 


# Each subdirectory must supply rules for building sources it contributes
src-gen/%.o: ../src-gen/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed="__attribute__((__packed__))"' -DUSE_HAL_DRIVER -DSTM32F411xE -I"/home/simon/stash/Ampel/Inc" -I"/home/simon/stash/Ampel/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/simon/stash/Ampel/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/simon/stash/Ampel/Drivers/CMSIS/Include" -I"/home/simon/stash/Ampel/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/simon/stash/Ampel/Inc"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


