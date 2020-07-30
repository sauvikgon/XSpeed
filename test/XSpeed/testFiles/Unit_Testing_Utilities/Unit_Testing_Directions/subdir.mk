################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testFiles/Unit_Testing_Utilities/Unit_Testing_Directions/test_bestDirections.cpp 

OBJS += \
./XSpeed/testFiles/Unit_Testing_Utilities/Unit_Testing_Directions/test_bestDirections.o 

CPP_DEPS += \
./XSpeed/testFiles/Unit_Testing_Utilities/Unit_Testing_Directions/test_bestDirections.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/testFiles/Unit_Testing_Utilities/Unit_Testing_Directions/%.o: ../testFiles/Unit_Testing_Utilities/Unit_Testing_Directions/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"/home/rajarshi/eclipse-workspace/XSpeed-plan/XSpeed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


