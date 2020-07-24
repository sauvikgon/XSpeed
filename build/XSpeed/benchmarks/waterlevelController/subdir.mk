################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../benchmarks/waterlevelController/watertank_controller.cpp 

OBJS += \
./XSpeed/benchmarks/waterlevelController/watertank_controller.o 

CPP_DEPS += \
./XSpeed/benchmarks/waterlevelController/watertank_controller.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/benchmarks/waterlevelController/%.o: ../benchmarks/waterlevelController/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I/usr/local/include/UnitTest++/ -I"../" -O3 -g -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


