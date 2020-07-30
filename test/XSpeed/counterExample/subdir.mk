################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../counterExample/abstractCE.cpp \
../counterExample/abstractSymbolicState.cpp \
../counterExample/concreteCE.cpp \
../counterExample/nlpFunctions.cpp \
../counterExample/simulation.cpp \
../counterExample/wofcCounterExample.cpp 

OBJS += \
./XSpeed/counterExample/abstractCE.o \
./XSpeed/counterExample/abstractSymbolicState.o \
./XSpeed/counterExample/concreteCE.o \
./XSpeed/counterExample/nlpFunctions.o \
./XSpeed/counterExample/simulation.o \
./XSpeed/counterExample/wofcCounterExample.o 

CPP_DEPS += \
./XSpeed/counterExample/abstractCE.d \
./XSpeed/counterExample/abstractSymbolicState.d \
./XSpeed/counterExample/concreteCE.d \
./XSpeed/counterExample/nlpFunctions.d \
./XSpeed/counterExample/simulation.d \
./XSpeed/counterExample/wofcCounterExample.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/counterExample/%.o: ../counterExample/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"/home/rajarshi/eclipse-workspace/XSpeed-plan/XSpeed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


