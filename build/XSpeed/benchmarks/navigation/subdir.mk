################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../benchmarks/navigation/nav04Timed.cpp \
../benchmarks/navigation/navigation5by5.cpp 

OBJS += \
./XSpeed/benchmarks/navigation/nav04Timed.o \
./XSpeed/benchmarks/navigation/navigation5by5.o 

CPP_DEPS += \
./XSpeed/benchmarks/navigation/nav04Timed.d \
./XSpeed/benchmarks/navigation/navigation5by5.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/benchmarks/navigation/%.o: ../benchmarks/navigation/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I/usr/local/include/UnitTest++/ -I"../" -O3 -g -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


