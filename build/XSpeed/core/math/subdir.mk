################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/math/2dGeometry.cpp \
../core/math/analyticOdeSol.cpp \
../core/math/matrix.cpp \
../core/math/matrixExponential.cpp \
../core/math/r8lib.cpp \
../core/math/randNumberGenerator.cpp \
../core/math/uniSphere.cpp 

OBJS += \
./XSpeed/core/math/2dGeometry.o \
./XSpeed/core/math/analyticOdeSol.o \
./XSpeed/core/math/matrix.o \
./XSpeed/core/math/matrixExponential.o \
./XSpeed/core/math/r8lib.o \
./XSpeed/core/math/randNumberGenerator.o \
./XSpeed/core/math/uniSphere.o 

CPP_DEPS += \
./XSpeed/core/math/2dGeometry.d \
./XSpeed/core/math/analyticOdeSol.d \
./XSpeed/core/math/matrix.d \
./XSpeed/core/math/matrixExponential.d \
./XSpeed/core/math/r8lib.d \
./XSpeed/core/math/randNumberGenerator.d \
./XSpeed/core/math/uniSphere.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/core/math/%.o: ../core/math/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I/usr/local/include/UnitTest++/ -I"../" -O3 -g -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


