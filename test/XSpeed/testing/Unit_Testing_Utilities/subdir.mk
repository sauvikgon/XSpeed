################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testing/Unit_Testing_Utilities/test_directions.cpp \
../testing/Unit_Testing_Utilities/test_postAssignment.cpp \
../testing/Unit_Testing_Utilities/test_templatePolyhedra.cpp 

OBJS += \
./XSpeed/testing/Unit_Testing_Utilities/test_directions.o \
./XSpeed/testing/Unit_Testing_Utilities/test_postAssignment.o \
./XSpeed/testing/Unit_Testing_Utilities/test_templatePolyhedra.o 

CPP_DEPS += \
./XSpeed/testing/Unit_Testing_Utilities/test_directions.d \
./XSpeed/testing/Unit_Testing_Utilities/test_postAssignment.d \
./XSpeed/testing/Unit_Testing_Utilities/test_templatePolyhedra.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/testing/Unit_Testing_Utilities/%.o: ../testing/Unit_Testing_Utilities/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"/home/rajarshi/eclipse-workspace/XSpeed-plan/XSpeed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


