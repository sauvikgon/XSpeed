################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../utilities/memUtilities/memUsage.cpp 

OBJS += \
./XSpeed/utilities/memUtilities/memUsage.o 

CPP_DEPS += \
./XSpeed/utilities/memUtilities/memUsage.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/utilities/memUtilities/%.o: ../utilities/memUtilities/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"../" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


