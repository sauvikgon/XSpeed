################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../io/resetParser/lex.reset.cpp \
../io/resetParser/reset.tab.cpp 

OBJS += \
./XSpeed/io/resetParser/lex.reset.o \
./XSpeed/io/resetParser/reset.tab.o 

CPP_DEPS += \
./XSpeed/io/resetParser/lex.reset.d \
./XSpeed/io/resetParser/reset.tab.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/io/resetParser/%.o: ../io/resetParser/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"/home/rajarshi/eclipse-workspace/XSpeed-plan/XSpeed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


