################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testing/Unit_Testing_Utilities/Unit_Testing_Directions/test_bestDirections.cpp 

OBJS += \
./testing/Unit_Testing_Utilities/Unit_Testing_Directions/test_bestDirections.o 

CPP_DEPS += \
./testing/Unit_Testing_Utilities/Unit_Testing_Directions/test_bestDirections.d 


# Each subdirectory must supply rules for building sources it contributes
testing/Unit_Testing_Utilities/Unit_Testing_Directions/%.o: ../testing/Unit_Testing_Utilities/Unit_Testing_Directions/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -D DEBUG -I/usr/local/include/ -I/usr/local/include/UnitTest++/ -I"/home/rajarshi/eclipse-workspac../XSpeed" -O3 -g -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


