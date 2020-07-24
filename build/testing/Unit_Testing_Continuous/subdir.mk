################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testing/Unit_Testing_Continuous/test_lp_solver.cpp \
../testing/Unit_Testing_Continuous/test_matrix.cpp \
../testing/Unit_Testing_Continuous/test_polytope.cpp \
../testing/Unit_Testing_Continuous/test_polytope_enumerate_vertices.cpp \
../testing/Unit_Testing_Continuous/test_sf_utility.cpp 

OBJS += \
./testing/Unit_Testing_Continuous/test_lp_solver.o \
./testing/Unit_Testing_Continuous/test_matrix.o \
./testing/Unit_Testing_Continuous/test_polytope.o \
./testing/Unit_Testing_Continuous/test_polytope_enumerate_vertices.o \
./testing/Unit_Testing_Continuous/test_sf_utility.o 

CPP_DEPS += \
./testing/Unit_Testing_Continuous/test_lp_solver.d \
./testing/Unit_Testing_Continuous/test_matrix.d \
./testing/Unit_Testing_Continuous/test_polytope.d \
./testing/Unit_Testing_Continuous/test_polytope_enumerate_vertices.d \
./testing/Unit_Testing_Continuous/test_sf_utility.d 


# Each subdirectory must supply rules for building sources it contributes
testing/Unit_Testing_Continuous/%.o: ../testing/Unit_Testing_Continuous/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -D DEBUG -I/usr/local/include/ -I/usr/local/include/UnitTest++/ -I"/home/rajarshi/eclipse-workspac../XSpeed" -O3 -g -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


