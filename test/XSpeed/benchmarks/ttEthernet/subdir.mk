################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../benchmarks/ttEthernet/ConvertedTTEthernet_Simplified_5.cpp 

OBJS += \
./XSpeed/benchmarks/ttEthernet/ConvertedTTEthernet_Simplified_5.o 

CPP_DEPS += \
./XSpeed/benchmarks/ttEthernet/ConvertedTTEthernet_Simplified_5.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/benchmarks/ttEthernet/%.o: ../benchmarks/ttEthernet/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"/home/rajarshi/eclipse-workspace/XSpeed-plan/XSpeed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


