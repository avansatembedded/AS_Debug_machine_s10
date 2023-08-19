################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Screens/Src/screen_home.c \
../App/Screens/Src/screen_setup.c 

OBJS += \
./App/Screens/Src/screen_home.o \
./App/Screens/Src/screen_setup.o 

C_DEPS += \
./App/Screens/Src/screen_home.d \
./App/Screens/Src/screen_setup.d 


# Each subdirectory must supply rules for building sources it contributes
App/Screens/Src/%.o App/Screens/Src/%.su App/Screens/Src/%.cyclo: ../App/Screens/Src/%.c App/Screens/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Graphics/Inc -I../App/Screens/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-App-2f-Screens-2f-Src

clean-App-2f-Screens-2f-Src:
	-$(RM) ./App/Screens/Src/screen_home.cyclo ./App/Screens/Src/screen_home.d ./App/Screens/Src/screen_home.o ./App/Screens/Src/screen_home.su ./App/Screens/Src/screen_setup.cyclo ./App/Screens/Src/screen_setup.d ./App/Screens/Src/screen_setup.o ./App/Screens/Src/screen_setup.su

.PHONY: clean-App-2f-Screens-2f-Src

