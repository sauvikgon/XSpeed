################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testers/Unit_Testing_Utilities/test_directions.cpp \
../testers/Unit_Testing_Utilities/test_postAssignment.cpp \
../testers/Unit_Testing_Utilities/test_templatePolyhedra.cpp 

OBJS += \
./XSpeed/testers/Unit_Testing_Utilities/test_directions.o \
./XSpeed/testers/Unit_Testing_Utilities/test_postAssignment.o \
./XSpeed/testers/Unit_Testing_Utilities/test_templatePolyhedra.o 

CPP_DEPS += \
./XSpeed/testers/Unit_Testing_Utilities/test_directions.d \
./XSpeed/testers/Unit_Testing_Utilities/test_postAssignment.d \
./XSpeed/testers/Unit_Testing_Utilities/test_templatePolyhedra.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/testers/Unit_Testing_Utilities/%.o: ../testers/Unit_Testing_Utilities/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"../" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


