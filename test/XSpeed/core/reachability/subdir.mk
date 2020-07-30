################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../core/reachability/agjh.cpp \
../core/reachability/asyncBFS.cpp \
../core/reachability/lockAvoidanceUtility.cpp \
../core/reachability/postCParallel.cpp \
../core/reachability/postCSequential.cpp \
../core/reachability/reachability.cpp \
../core/reachability/tpbfs.cpp 

OBJS += \
./XSpeed/core/reachability/agjh.o \
./XSpeed/core/reachability/asyncBFS.o \
./XSpeed/core/reachability/lockAvoidanceUtility.o \
./XSpeed/core/reachability/postCParallel.o \
./XSpeed/core/reachability/postCSequential.o \
./XSpeed/core/reachability/reachability.o \
./XSpeed/core/reachability/tpbfs.o 

CPP_DEPS += \
./XSpeed/core/reachability/agjh.d \
./XSpeed/core/reachability/asyncBFS.d \
./XSpeed/core/reachability/lockAvoidanceUtility.d \
./XSpeed/core/reachability/postCParallel.d \
./XSpeed/core/reachability/postCSequential.d \
./XSpeed/core/reachability/reachability.d \
./XSpeed/core/reachability/tpbfs.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/core/reachability/%.o: ../core/reachability/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"/home/rajarshi/eclipse-workspace/XSpeed-plan/XSpeed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


