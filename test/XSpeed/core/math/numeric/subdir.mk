################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/math/numeric/approxComparator.cpp 

OBJS += \
./XSpeed/core/math/numeric/approxComparator.o 

CPP_DEPS += \
./XSpeed/core/math/numeric/approxComparator.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/core/math/numeric/%.o: ../core/math/numeric/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"../" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


