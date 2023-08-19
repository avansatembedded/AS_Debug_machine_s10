################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Midhun\ Kumar/Midhun\ Kumar/Embedde_System_Engineering/Projects/My_Projects/STM32\ Cube\ IDE/stm32F429Zi\ RGB\ LCD/Fonts/Src/BritannicBold18pts.c \
C:/Users/Midhun\ Kumar/Midhun\ Kumar/Embedde_System_Engineering/Projects/My_Projects/STM32\ Cube\ IDE/stm32F429Zi\ RGB\ LCD/Fonts/Src/CenturyGothic18pts.c \
../Graphics/Src/LTDC.c \
C:/Users/Midhun\ Kumar/Midhun\ Kumar/Embedde_System_Engineering/Projects/My_Projects/STM32\ Cube\ IDE/stm32F429Zi\ RGB\ LCD/Fonts/Src/TimesNewRoman18pts_Bold.c \
C:/Users/Midhun\ Kumar/Midhun\ Kumar/Embedde_System_Engineering/Projects/My_Projects/STM32\ Cube\ IDE/stm32F429Zi\ RGB\ LCD/Fonts/Src/TimesNewRoman48pts.c \
C:/Users/Midhun\ Kumar/Midhun\ Kumar/Embedde_System_Engineering/Projects/My_Projects/STM32\ Cube\ IDE/stm32F429Zi\ RGB\ LCD/Fonts/Src/TimesNewRoman8pts_Bold.c 

OBJS += \
./Graphics/Src/BritannicBold18pts.o \
./Graphics/Src/CenturyGothic18pts.o \
./Graphics/Src/LTDC.o \
./Graphics/Src/TimesNewRoman18pts_Bold.o \
./Graphics/Src/TimesNewRoman48pts.o \
./Graphics/Src/TimesNewRoman8pts_Bold.o 

C_DEPS += \
./Graphics/Src/BritannicBold18pts.d \
./Graphics/Src/CenturyGothic18pts.d \
./Graphics/Src/LTDC.d \
./Graphics/Src/TimesNewRoman18pts_Bold.d \
./Graphics/Src/TimesNewRoman48pts.d \
./Graphics/Src/TimesNewRoman8pts_Bold.d 


# Each subdirectory must supply rules for building sources it contributes
Graphics/Src/BritannicBold18pts.o: C:/Users/Midhun\ Kumar/Midhun\ Kumar/Embedde_System_Engineering/Projects/My_Projects/STM32\ Cube\ IDE/stm32F429Zi\ RGB\ LCD/Fonts/Src/BritannicBold18pts.c Graphics/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Graphics/Inc -I../App/Screens/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Graphics/Src/BritannicBold18pts.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Graphics/Src/CenturyGothic18pts.o: C:/Users/Midhun\ Kumar/Midhun\ Kumar/Embedde_System_Engineering/Projects/My_Projects/STM32\ Cube\ IDE/stm32F429Zi\ RGB\ LCD/Fonts/Src/CenturyGothic18pts.c Graphics/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Graphics/Inc -I../App/Screens/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Graphics/Src/CenturyGothic18pts.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Graphics/Src/%.o Graphics/Src/%.su Graphics/Src/%.cyclo: ../Graphics/Src/%.c Graphics/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Graphics/Inc -I../App/Screens/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Graphics/Src/TimesNewRoman18pts_Bold.o: C:/Users/Midhun\ Kumar/Midhun\ Kumar/Embedde_System_Engineering/Projects/My_Projects/STM32\ Cube\ IDE/stm32F429Zi\ RGB\ LCD/Fonts/Src/TimesNewRoman18pts_Bold.c Graphics/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Graphics/Inc -I../App/Screens/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Graphics/Src/TimesNewRoman18pts_Bold.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Graphics/Src/TimesNewRoman48pts.o: C:/Users/Midhun\ Kumar/Midhun\ Kumar/Embedde_System_Engineering/Projects/My_Projects/STM32\ Cube\ IDE/stm32F429Zi\ RGB\ LCD/Fonts/Src/TimesNewRoman48pts.c Graphics/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Graphics/Inc -I../App/Screens/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Graphics/Src/TimesNewRoman48pts.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Graphics/Src/TimesNewRoman8pts_Bold.o: C:/Users/Midhun\ Kumar/Midhun\ Kumar/Embedde_System_Engineering/Projects/My_Projects/STM32\ Cube\ IDE/stm32F429Zi\ RGB\ LCD/Fonts/Src/TimesNewRoman8pts_Bold.c Graphics/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -DUSE_FULL_LL_DRIVER -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Graphics/Inc -I../App/Screens/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Graphics/Src/TimesNewRoman8pts_Bold.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Graphics-2f-Src

clean-Graphics-2f-Src:
	-$(RM) ./Graphics/Src/BritannicBold18pts.cyclo ./Graphics/Src/BritannicBold18pts.d ./Graphics/Src/BritannicBold18pts.o ./Graphics/Src/BritannicBold18pts.su ./Graphics/Src/CenturyGothic18pts.cyclo ./Graphics/Src/CenturyGothic18pts.d ./Graphics/Src/CenturyGothic18pts.o ./Graphics/Src/CenturyGothic18pts.su ./Graphics/Src/LTDC.cyclo ./Graphics/Src/LTDC.d ./Graphics/Src/LTDC.o ./Graphics/Src/LTDC.su ./Graphics/Src/TimesNewRoman18pts_Bold.cyclo ./Graphics/Src/TimesNewRoman18pts_Bold.d ./Graphics/Src/TimesNewRoman18pts_Bold.o ./Graphics/Src/TimesNewRoman18pts_Bold.su ./Graphics/Src/TimesNewRoman48pts.cyclo ./Graphics/Src/TimesNewRoman48pts.d ./Graphics/Src/TimesNewRoman48pts.o ./Graphics/Src/TimesNewRoman48pts.su ./Graphics/Src/TimesNewRoman8pts_Bold.cyclo ./Graphics/Src/TimesNewRoman8pts_Bold.d ./Graphics/Src/TimesNewRoman8pts_Bold.o ./Graphics/Src/TimesNewRoman8pts_Bold.su

.PHONY: clean-Graphics-2f-Src

