################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testFiles/test_runner.cpp 

OBJS += \
./XSpeed/testFiles/test_runner.o 

CPP_DEPS += \
./XSpeed/testFiles/test_runner.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/testFiles/%.o: ../testFiles/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"/home/rajarshi/eclipse-workspace/XSpeed-plan/XSpeed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


