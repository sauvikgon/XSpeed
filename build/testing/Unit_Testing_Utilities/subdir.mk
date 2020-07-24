################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testing/Unit_Testing_Utilities/test_directions.cpp \
../testing/Unit_Testing_Utilities/test_postAssignment.cpp \
../testing/Unit_Testing_Utilities/test_standardVector.cpp \
../testing/Unit_Testing_Utilities/test_templatePolyhedra.cpp 

OBJS += \
./testing/Unit_Testing_Utilities/test_directions.o \
./testing/Unit_Testing_Utilities/test_postAssignment.o \
./testing/Unit_Testing_Utilities/test_standardVector.o \
./testing/Unit_Testing_Utilities/test_templatePolyhedra.o 

CPP_DEPS += \
./testing/Unit_Testing_Utilities/test_directions.d \
./testing/Unit_Testing_Utilities/test_postAssignment.d \
./testing/Unit_Testing_Utilities/test_standardVector.d \
./testing/Unit_Testing_Utilities/test_templatePolyhedra.d 


# Each subdirectory must supply rules for building sources it contributes
testing/Unit_Testing_Utilities/%.o: ../testing/Unit_Testing_Utilities/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -D DEBUG -I/usr/local/include/ -I/usr/local/include/UnitTest++/ -I"/home/rajarshi/eclipse-workspac../XSpeed" -O3 -g -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


