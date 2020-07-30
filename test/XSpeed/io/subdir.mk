################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../io/ioUtility.cpp \
../io/loadModel.cpp \
../io/parser.cpp 

OBJS += \
./XSpeed/io/ioUtility.o \
./XSpeed/io/loadModel.o \
./XSpeed/io/parser.o 

CPP_DEPS += \
./XSpeed/io/ioUtility.d \
./XSpeed/io/loadModel.d \
./XSpeed/io/parser.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/io/%.o: ../io/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"../" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


