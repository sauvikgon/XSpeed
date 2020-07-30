################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../benchmarks/bouncingBall.cpp \
../benchmarks/fiveDimSys.cpp \
../benchmarks/platoon.cpp \
../benchmarks/spacecraft.cpp \
../benchmarks/timedBouncingBall.cpp 

OBJS += \
./XSpeed/benchmarks/bouncingBall.o \
./XSpeed/benchmarks/fiveDimSys.o \
./XSpeed/benchmarks/platoon.o \
./XSpeed/benchmarks/spacecraft.o \
./XSpeed/benchmarks/timedBouncingBall.o 

CPP_DEPS += \
./XSpeed/benchmarks/bouncingBall.d \
./XSpeed/benchmarks/fiveDimSys.d \
./XSpeed/benchmarks/platoon.d \
./XSpeed/benchmarks/spacecraft.d \
./XSpeed/benchmarks/timedBouncingBall.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/benchmarks/%.o: ../benchmarks/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"../" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


