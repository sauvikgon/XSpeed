################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testing/Unit_Testing_HybridAutomata/test_hybridAutomata.cpp \
../testing/Unit_Testing_HybridAutomata/test_location.cpp \
../testing/Unit_Testing_HybridAutomata/test_transition.cpp 

OBJS += \
./XSpeed/testing/Unit_Testing_HybridAutomata/test_hybridAutomata.o \
./XSpeed/testing/Unit_Testing_HybridAutomata/test_location.o \
./XSpeed/testing/Unit_Testing_HybridAutomata/test_transition.o 

CPP_DEPS += \
./XSpeed/testing/Unit_Testing_HybridAutomata/test_hybridAutomata.d \
./XSpeed/testing/Unit_Testing_HybridAutomata/test_location.d \
./XSpeed/testing/Unit_Testing_HybridAutomata/test_transition.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/testing/Unit_Testing_HybridAutomata/%.o: ../testing/Unit_Testing_HybridAutomata/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"/home/rajarshi/eclipse-workspace/XSpeed-plan/XSpeed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


