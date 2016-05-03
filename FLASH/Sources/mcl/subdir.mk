################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/mcl/ARM_SysTick.c" \
"../Sources/mcl/CrystalClock.c" \
"../Sources/mcl/RGB_LEDs.c" \
"../Sources/mcl/interrupts.c" \
"../Sources/mcl/variables_funciones.c" \

C_SRCS += \
../Sources/mcl/ARM_SysTick.c \
../Sources/mcl/CrystalClock.c \
../Sources/mcl/RGB_LEDs.c \
../Sources/mcl/interrupts.c \
../Sources/mcl/variables_funciones.c \

OBJS += \
./Sources/mcl/ARM_SysTick.o \
./Sources/mcl/CrystalClock.o \
./Sources/mcl/RGB_LEDs.o \
./Sources/mcl/interrupts.o \
./Sources/mcl/variables_funciones.o \

C_DEPS += \
./Sources/mcl/ARM_SysTick.d \
./Sources/mcl/CrystalClock.d \
./Sources/mcl/RGB_LEDs.d \
./Sources/mcl/interrupts.d \
./Sources/mcl/variables_funciones.d \

OBJS_QUOTED += \
"./Sources/mcl/ARM_SysTick.o" \
"./Sources/mcl/CrystalClock.o" \
"./Sources/mcl/RGB_LEDs.o" \
"./Sources/mcl/interrupts.o" \
"./Sources/mcl/variables_funciones.o" \

C_DEPS_QUOTED += \
"./Sources/mcl/ARM_SysTick.d" \
"./Sources/mcl/CrystalClock.d" \
"./Sources/mcl/RGB_LEDs.d" \
"./Sources/mcl/interrupts.d" \
"./Sources/mcl/variables_funciones.d" \

OBJS_OS_FORMAT += \
./Sources/mcl/ARM_SysTick.o \
./Sources/mcl/CrystalClock.o \
./Sources/mcl/RGB_LEDs.o \
./Sources/mcl/interrupts.o \
./Sources/mcl/variables_funciones.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/mcl/ARM_SysTick.o: ../Sources/mcl/ARM_SysTick.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcl/ARM_SysTick.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mcl/ARM_SysTick.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mcl/CrystalClock.o: ../Sources/mcl/CrystalClock.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcl/CrystalClock.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mcl/CrystalClock.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mcl/RGB_LEDs.o: ../Sources/mcl/RGB_LEDs.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcl/RGB_LEDs.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mcl/RGB_LEDs.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mcl/interrupts.o: ../Sources/mcl/interrupts.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcl/interrupts.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mcl/interrupts.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mcl/variables_funciones.o: ../Sources/mcl/variables_funciones.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcl/variables_funciones.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mcl/variables_funciones.o"
	@echo 'Finished building: $<'
	@echo ' '


