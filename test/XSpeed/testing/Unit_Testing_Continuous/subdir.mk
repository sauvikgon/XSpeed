################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testing/Unit_Testing_Continuous/test_Zreach.cpp \
../testing/Unit_Testing_Continuous/test_lp_solver.cpp \
../testing/Unit_Testing_Continuous/test_matrix.cpp \
../testing/Unit_Testing_Continuous/test_polytope.cpp \
../testing/Unit_Testing_Continuous/test_polytope_enumerate_vertices.cpp \
../testing/Unit_Testing_Continuous/test_sf_utility.cpp 

OBJS += \
./XSpeed/testing/Unit_Testing_Continuous/test_Zreach.o \
./XSpeed/testing/Unit_Testing_Continuous/test_lp_solver.o \
./XSpeed/testing/Unit_Testing_Continuous/test_matrix.o \
./XSpeed/testing/Unit_Testing_Continuous/test_polytope.o \
./XSpeed/testing/Unit_Testing_Continuous/test_polytope_enumerate_vertices.o \
./XSpeed/testing/Unit_Testing_Continuous/test_sf_utility.o 

CPP_DEPS += \
./XSpeed/testing/Unit_Testing_Continuous/test_Zreach.d \
./XSpeed/testing/Unit_Testing_Continuous/test_lp_solver.d \
./XSpeed/testing/Unit_Testing_Continuous/test_matrix.d \
./XSpeed/testing/Unit_Testing_Continuous/test_polytope.d \
./XSpeed/testing/Unit_Testing_Continuous/test_polytope_enumerate_vertices.d \
./XSpeed/testing/Unit_Testing_Continuous/test_sf_utility.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/testing/Unit_Testing_Continuous/%.o: ../testing/Unit_Testing_Continuous/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"/home/rajarshi/eclipse-workspace/XSpeed-plan/XSpeed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


