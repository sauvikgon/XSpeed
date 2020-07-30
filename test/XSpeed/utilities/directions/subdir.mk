################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../utilities/directions/convertToBestDirection.cpp 

OBJS += \
./XSpeed/utilities/directions/convertToBestDirection.o 

CPP_DEPS += \
./XSpeed/utilities/directions/convertToBestDirection.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/utilities/directions/%.o: ../utilities/directions/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"../" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


