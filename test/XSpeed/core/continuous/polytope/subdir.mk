################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/continuous/polytope/polytope.cpp 

OBJS += \
./XSpeed/core/continuous/polytope/polytope.o 

CPP_DEPS += \
./XSpeed/core/continuous/polytope/polytope.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/core/continuous/polytope/%.o: ../core/continuous/polytope/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"../" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


