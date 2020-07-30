################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testers/Unit_Testing_HybridAutomata/test_hybridAutomata.cpp \
../testers/Unit_Testing_HybridAutomata/test_location.cpp \
../testers/Unit_Testing_HybridAutomata/test_transition.cpp 

OBJS += \
./XSpeed/testers/Unit_Testing_HybridAutomata/test_hybridAutomata.o \
./XSpeed/testers/Unit_Testing_HybridAutomata/test_location.o \
./XSpeed/testers/Unit_Testing_HybridAutomata/test_transition.o 

CPP_DEPS += \
./XSpeed/testers/Unit_Testing_HybridAutomata/test_hybridAutomata.d \
./XSpeed/testers/Unit_Testing_HybridAutomata/test_location.d \
./XSpeed/testers/Unit_Testing_HybridAutomata/test_transition.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/testers/Unit_Testing_HybridAutomata/%.o: ../testers/Unit_Testing_HybridAutomata/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"../" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


