################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testing/Unit_Testing_Simulation/test_simulationConstantMotion.cpp \
../testing/Unit_Testing_Simulation/test_simulationHelicopter.cpp \
../testing/Unit_Testing_Simulation/test_simulationNavigation.cpp \
../testing/Unit_Testing_Simulation/test_simulationNavigation3by3.cpp \
../testing/Unit_Testing_Simulation/test_simulationNavigation5by5.cpp \
../testing/Unit_Testing_Simulation/test_simulationNavigation9by9.cpp \
../testing/Unit_Testing_Simulation/test_simulationOscillatorModel.cpp \
../testing/Unit_Testing_Simulation/test_simulationRotationCircle.cpp \
../testing/Unit_Testing_Simulation/test_simulationTimedBBall.cpp 

OBJS += \
./testing/Unit_Testing_Simulation/test_simulationConstantMotion.o \
./testing/Unit_Testing_Simulation/test_simulationHelicopter.o \
./testing/Unit_Testing_Simulation/test_simulationNavigation.o \
./testing/Unit_Testing_Simulation/test_simulationNavigation3by3.o \
./testing/Unit_Testing_Simulation/test_simulationNavigation5by5.o \
./testing/Unit_Testing_Simulation/test_simulationNavigation9by9.o \
./testing/Unit_Testing_Simulation/test_simulationOscillatorModel.o \
./testing/Unit_Testing_Simulation/test_simulationRotationCircle.o \
./testing/Unit_Testing_Simulation/test_simulationTimedBBall.o 

CPP_DEPS += \
./testing/Unit_Testing_Simulation/test_simulationConstantMotion.d \
./testing/Unit_Testing_Simulation/test_simulationHelicopter.d \
./testing/Unit_Testing_Simulation/test_simulationNavigation.d \
./testing/Unit_Testing_Simulation/test_simulationNavigation3by3.d \
./testing/Unit_Testing_Simulation/test_simulationNavigation5by5.d \
./testing/Unit_Testing_Simulation/test_simulationNavigation9by9.d \
./testing/Unit_Testing_Simulation/test_simulationOscillatorModel.d \
./testing/Unit_Testing_Simulation/test_simulationRotationCircle.d \
./testing/Unit_Testing_Simulation/test_simulationTimedBBall.d 


# Each subdirectory must supply rules for building sources it contributes
testing/Unit_Testing_Simulation/%.o: ../testing/Unit_Testing_Simulation/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -D DEBUG -I/usr/local/include/ -I/usr/local/include/UnitTest++/ -I"/home/rajarshi/eclipse-workspac../XSpeed" -O3 -g -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


