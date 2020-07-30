################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testFiles/Unit_Testing_Utilities/test_directions.cpp \
../testFiles/Unit_Testing_Utilities/test_postAssignment.cpp \
../testFiles/Unit_Testing_Utilities/test_templatePolyhedra.cpp 

OBJS += \
./XSpeed/testFiles/Unit_Testing_Utilities/test_directions.o \
./XSpeed/testFiles/Unit_Testing_Utilities/test_postAssignment.o \
./XSpeed/testFiles/Unit_Testing_Utilities/test_templatePolyhedra.o 

CPP_DEPS += \
./XSpeed/testFiles/Unit_Testing_Utilities/test_directions.d \
./XSpeed/testFiles/Unit_Testing_Utilities/test_postAssignment.d \
./XSpeed/testFiles/Unit_Testing_Utilities/test_templatePolyhedra.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/testFiles/Unit_Testing_Utilities/%.o: ../testFiles/Unit_Testing_Utilities/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"/home/rajarshi/eclipse-workspace/XSpeed-plan/XSpeed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


