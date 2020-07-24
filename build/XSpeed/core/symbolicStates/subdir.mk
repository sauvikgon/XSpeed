################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/symbolicStates/initialState.cpp \
../core/symbolicStates/symbolicStates.cpp \
../core/symbolicStates/symbolicStatesUtility.cpp 

OBJS += \
./XSpeed/core/symbolicStates/initialState.o \
./XSpeed/core/symbolicStates/symbolicStates.o \
./XSpeed/core/symbolicStates/symbolicStatesUtility.o 

CPP_DEPS += \
./XSpeed/core/symbolicStates/initialState.d \
./XSpeed/core/symbolicStates/symbolicStates.d \
./XSpeed/core/symbolicStates/symbolicStatesUtility.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/core/symbolicStates/%.o: ../core/symbolicStates/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I/usr/local/include/UnitTest++/ -I"../" -O3 -g -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


