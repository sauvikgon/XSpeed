################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../io/flowParser/flow.tab.cpp \
../io/flowParser/flow.yy.cpp 

OBJS += \
./XSpeed/io/flowParser/flow.tab.o \
./XSpeed/io/flowParser/flow.yy.o 

CPP_DEPS += \
./XSpeed/io/flowParser/flow.tab.d \
./XSpeed/io/flowParser/flow.yy.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/io/flowParser/%.o: ../io/flowParser/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"/home/rajarshi/eclipse-workspace/XSpeed-plan/XSpeed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


