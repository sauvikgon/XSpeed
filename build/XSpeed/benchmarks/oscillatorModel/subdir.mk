################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../benchmarks/oscillatorModel/Oscillator.cpp \
../benchmarks/oscillatorModel/Oscillator_timed.cpp \
../benchmarks/oscillatorModel/f_osc_32.cpp \
../benchmarks/oscillatorModel/f_osc_32_timed.cpp \
../benchmarks/oscillatorModel/f_osc_8.cpp \
../benchmarks/oscillatorModel/f_osc_8_timed.cpp 

OBJS += \
./XSpeed/benchmarks/oscillatorModel/Oscillator.o \
./XSpeed/benchmarks/oscillatorModel/Oscillator_timed.o \
./XSpeed/benchmarks/oscillatorModel/f_osc_32.o \
./XSpeed/benchmarks/oscillatorModel/f_osc_32_timed.o \
./XSpeed/benchmarks/oscillatorModel/f_osc_8.o \
./XSpeed/benchmarks/oscillatorModel/f_osc_8_timed.o 

CPP_DEPS += \
./XSpeed/benchmarks/oscillatorModel/Oscillator.d \
./XSpeed/benchmarks/oscillatorModel/Oscillator_timed.d \
./XSpeed/benchmarks/oscillatorModel/f_osc_32.d \
./XSpeed/benchmarks/oscillatorModel/f_osc_32_timed.d \
./XSpeed/benchmarks/oscillatorModel/f_osc_8.d \
./XSpeed/benchmarks/oscillatorModel/f_osc_8_timed.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/benchmarks/oscillatorModel/%.o: ../benchmarks/oscillatorModel/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I/usr/local/include/UnitTest++/ -I"../" -O3 -g -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


