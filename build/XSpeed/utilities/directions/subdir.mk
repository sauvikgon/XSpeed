################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../utilities/directions/Convert_To_BestDirection.cpp 

OBJS += \
./XSpeed/utilities/directions/Convert_To_BestDirection.o 

CPP_DEPS += \
./XSpeed/utilities/directions/Convert_To_BestDirection.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/utilities/directions/%.o: ../utilities/directions/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I/usr/local/include/UnitTest++/ -I"../" -O3 -g -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


