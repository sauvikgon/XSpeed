################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testFiles/Unit_Testing_HybridAutomata/test_hybridAutomata.cpp \
../testFiles/Unit_Testing_HybridAutomata/test_location.cpp \
../testFiles/Unit_Testing_HybridAutomata/test_transition.cpp 

OBJS += \
./XSpeed/testFiles/Unit_Testing_HybridAutomata/test_hybridAutomata.o \
./XSpeed/testFiles/Unit_Testing_HybridAutomata/test_location.o \
./XSpeed/testFiles/Unit_Testing_HybridAutomata/test_transition.o 

CPP_DEPS += \
./XSpeed/testFiles/Unit_Testing_HybridAutomata/test_hybridAutomata.d \
./XSpeed/testFiles/Unit_Testing_HybridAutomata/test_location.d \
./XSpeed/testFiles/Unit_Testing_HybridAutomata/test_transition.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/testFiles/Unit_Testing_HybridAutomata/%.o: ../testFiles/Unit_Testing_HybridAutomata/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"/home/rajarshi/eclipse-workspace/XSpeed-plan/XSpeed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


