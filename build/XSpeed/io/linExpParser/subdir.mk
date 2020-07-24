################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../io/linExpParser/lex.linexp.cpp \
../io/linExpParser/linexp.tab.cpp 

OBJS += \
./XSpeed/io/linExpParser/lex.linexp.o \
./XSpeed/io/linExpParser/linexp.tab.o 

CPP_DEPS += \
./XSpeed/io/linExpParser/lex.linexp.d \
./XSpeed/io/linExpParser/linexp.tab.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/io/linExpParser/%.o: ../io/linExpParser/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I/usr/local/include/UnitTest++/ -I"../" -O3 -g -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


