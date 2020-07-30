################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../application/plotterUtility.cpp \
../application/reachabilityCaller.cpp \
../application/readCommandLine.cpp \
../application/sfDirections.cpp \
../application/sfUtility.cpp \
../application/simulationCaller.cpp \
../application/userOptions.cpp 

OBJS += \
./XSpeed/application/plotterUtility.o \
./XSpeed/application/reachabilityCaller.o \
./XSpeed/application/readCommandLine.o \
./XSpeed/application/sfDirections.o \
./XSpeed/application/sfUtility.o \
./XSpeed/application/simulationCaller.o \
./XSpeed/application/userOptions.o 

CPP_DEPS += \
./XSpeed/application/plotterUtility.d \
./XSpeed/application/reachabilityCaller.d \
./XSpeed/application/readCommandLine.d \
./XSpeed/application/sfDirections.d \
./XSpeed/application/sfUtility.d \
./XSpeed/application/simulationCaller.d \
./XSpeed/application/userOptions.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/application/%.o: ../application/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"/home/rajarshi/eclipse-workspace/XSpeed-plan/XSpeed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


