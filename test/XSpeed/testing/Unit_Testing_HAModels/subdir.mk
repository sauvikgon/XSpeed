################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testing/Unit_Testing_HAModels/test_helicopterModel.cpp 

OBJS += \
./XSpeed/testing/Unit_Testing_HAModels/test_helicopterModel.o 

CPP_DEPS += \
./XSpeed/testing/Unit_Testing_HAModels/test_helicopterModel.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/testing/Unit_Testing_HAModels/%.o: ../testing/Unit_Testing_HAModels/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"/home/rajarshi/eclipse-workspace/XSpeed-plan/XSpeed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


