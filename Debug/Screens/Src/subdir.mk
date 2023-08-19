################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
OBJS += \
./Screens/Src/screen_home.o \
./Screens/Src/screen_setup.o 

C_DEPS += \
./Screens/Src/screen_home.d \
./Screens/Src/screen_setup.d 


# Each subdirectory must supply rules for building sources it contributes
Screens/Src/screen_home.o: C:/Users/Midhun\ Kumar/Midhun\ Kumar/Embedde_System_Engineering/Projects/My_Projects/STM32\ Cube\ IDE/AS_debug_machine_s10/App/Screens/Src/screen_home.c Screens/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Graphics/Inc -I../App/Screens/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Screens/Src/screen_setup.o: C:/Users/Midhun\ Kumar/Midhun\ Kumar/Embedde_System_Engineering/Projects/My_Projects/STM32\ Cube\ IDE/AS_debug_machine_s10/App/Screens/Src/screen_setup.c Screens/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Graphics/Inc -I../App/Screens/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Screens-2f-Src

clean-Screens-2f-Src:
	-$(RM) ./Screens/Src/screen_home.cyclo ./Screens/Src/screen_home.d ./Screens/Src/screen_home.o ./Screens/Src/screen_home.su ./Screens/Src/screen_setup.cyclo ./Screens/Src/screen_setup.d ./Screens/Src/screen_setup.o ./Screens/Src/screen_setup.su

.PHONY: clean-Screens-2f-Src

