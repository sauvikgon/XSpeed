################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../benchmarks/vehiclePlatoon/vehicle10_platoon.cpp \
../benchmarks/vehiclePlatoon/vehicle5_platoon.cpp 

OBJS += \
./XSpeed/benchmarks/vehiclePlatoon/vehicle10_platoon.o \
./XSpeed/benchmarks/vehiclePlatoon/vehicle5_platoon.o 

CPP_DEPS += \
./XSpeed/benchmarks/vehiclePlatoon/vehicle10_platoon.d \
./XSpeed/benchmarks/vehiclePlatoon/vehicle5_platoon.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/benchmarks/vehiclePlatoon/%.o: ../benchmarks/vehiclePlatoon/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I/usr/local/include/UnitTest++/ -I"../" -O3 -g -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


