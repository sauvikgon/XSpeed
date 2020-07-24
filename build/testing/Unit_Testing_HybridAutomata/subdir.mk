################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testing/Unit_Testing_HybridAutomata/test_hybridAutomata.cpp \
../testing/Unit_Testing_HybridAutomata/test_location.cpp \
../testing/Unit_Testing_HybridAutomata/test_transition.cpp 

OBJS += \
./testing/Unit_Testing_HybridAutomata/test_hybridAutomata.o \
./testing/Unit_Testing_HybridAutomata/test_location.o \
./testing/Unit_Testing_HybridAutomata/test_transition.o 

CPP_DEPS += \
./testing/Unit_Testing_HybridAutomata/test_hybridAutomata.d \
./testing/Unit_Testing_HybridAutomata/test_location.d \
./testing/Unit_Testing_HybridAutomata/test_transition.d 


# Each subdirectory must supply rules for building sources it contributes
testing/Unit_Testing_HybridAutomata/%.o: ../testing/Unit_Testing_HybridAutomata/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -D DEBUG -I/usr/local/include/ -I/usr/local/include/UnitTest++/ -I"/home/rajarshi/eclipse-workspac../XSpeed" -O3 -g -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


