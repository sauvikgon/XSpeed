################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/hybridAutomata/hybridAutomata.cpp \
../core/hybridAutomata/location.cpp \
../core/hybridAutomata/transition.cpp \
../core/hybridAutomata/varToIndexMap.cpp 

OBJS += \
./XSpeed/core/hybridAutomata/hybridAutomata.o \
./XSpeed/core/hybridAutomata/location.o \
./XSpeed/core/hybridAutomata/transition.o \
./XSpeed/core/hybridAutomata/varToIndexMap.o 

CPP_DEPS += \
./XSpeed/core/hybridAutomata/hybridAutomata.d \
./XSpeed/core/hybridAutomata/location.d \
./XSpeed/core/hybridAutomata/transition.d \
./XSpeed/core/hybridAutomata/varToIndexMap.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/core/hybridAutomata/%.o: ../core/hybridAutomata/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"../" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


