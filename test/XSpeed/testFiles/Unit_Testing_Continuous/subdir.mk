################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testFiles/Unit_Testing_Continuous/test_lp_solver.cpp \
../testFiles/Unit_Testing_Continuous/test_matrix.cpp \
../testFiles/Unit_Testing_Continuous/test_polytope.cpp \
../testFiles/Unit_Testing_Continuous/test_polytope_enumerate_vertices.cpp 

OBJS += \
./XSpeed/testFiles/Unit_Testing_Continuous/test_lp_solver.o \
./XSpeed/testFiles/Unit_Testing_Continuous/test_matrix.o \
./XSpeed/testFiles/Unit_Testing_Continuous/test_polytope.o \
./XSpeed/testFiles/Unit_Testing_Continuous/test_polytope_enumerate_vertices.o 

CPP_DEPS += \
./XSpeed/testFiles/Unit_Testing_Continuous/test_lp_solver.d \
./XSpeed/testFiles/Unit_Testing_Continuous/test_matrix.d \
./XSpeed/testFiles/Unit_Testing_Continuous/test_polytope.d \
./XSpeed/testFiles/Unit_Testing_Continuous/test_polytope_enumerate_vertices.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/testFiles/Unit_Testing_Continuous/%.o: ../testFiles/Unit_Testing_Continuous/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"/home/rajarshi/eclipse-workspace/XSpeed-plan/XSpeed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


