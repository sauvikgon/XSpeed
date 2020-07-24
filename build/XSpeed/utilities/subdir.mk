################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../utilities/computeInitialPolytope.cpp \
../utilities/directionalApproxError.cpp \
../utilities/dumpAbstractCEList.cpp \
../utilities/flowCostEstimate.cpp \
../utilities/flowpipeCluster.cpp \
../utilities/gradient.cpp \
../utilities/hausdorffDistance.cpp \
../utilities/invariantBoundaryCheck.cpp \
../utilities/postAssignment.cpp \
../utilities/samples.cpp \
../utilities/statistics.cpp \
../utilities/stringParser.cpp \
../utilities/templatePolyhedra.cpp \
../utilities/testPolytopePlotting.cpp \
../utilities/vectorOperations.cpp 

OBJS += \
./XSpeed/utilities/computeInitialPolytope.o \
./XSpeed/utilities/directionalApproxError.o \
./XSpeed/utilities/dumpAbstractCEList.o \
./XSpeed/utilities/flowCostEstimate.o \
./XSpeed/utilities/flowpipeCluster.o \
./XSpeed/utilities/gradient.o \
./XSpeed/utilities/hausdorffDistance.o \
./XSpeed/utilities/invariantBoundaryCheck.o \
./XSpeed/utilities/postAssignment.o \
./XSpeed/utilities/samples.o \
./XSpeed/utilities/statistics.o \
./XSpeed/utilities/stringParser.o \
./XSpeed/utilities/templatePolyhedra.o \
./XSpeed/utilities/testPolytopePlotting.o \
./XSpeed/utilities/vectorOperations.o 

CPP_DEPS += \
./XSpeed/utilities/computeInitialPolytope.d \
./XSpeed/utilities/directionalApproxError.d \
./XSpeed/utilities/dumpAbstractCEList.d \
./XSpeed/utilities/flowCostEstimate.d \
./XSpeed/utilities/flowpipeCluster.d \
./XSpeed/utilities/gradient.d \
./XSpeed/utilities/hausdorffDistance.d \
./XSpeed/utilities/invariantBoundaryCheck.d \
./XSpeed/utilities/postAssignment.d \
./XSpeed/utilities/samples.d \
./XSpeed/utilities/statistics.d \
./XSpeed/utilities/stringParser.d \
./XSpeed/utilities/templatePolyhedra.d \
./XSpeed/utilities/testPolytopePlotting.d \
./XSpeed/utilities/vectorOperations.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/utilities/%.o: ../utilities/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I/usr/local/include/UnitTest++/ -I"../" -O3 -g -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


