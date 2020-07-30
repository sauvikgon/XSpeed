################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testers/Unit_Testing_Math/test_2d_geometry.cpp \
../testers/Unit_Testing_Math/test_NLPsolver.cpp \
../testers/Unit_Testing_Math/test_ProjectionDist.cpp \
../testers/Unit_Testing_Math/test_glpk.cpp \
../testers/Unit_Testing_Math/test_hausdorffDist.cpp \
../testers/Unit_Testing_Math/test_math_matrix.cpp \
../testers/Unit_Testing_Math/test_nlopt.cpp \
../testers/Unit_Testing_Math/test_ode_solution.cpp \
../testers/Unit_Testing_Math/test_randNumberGenerator.cpp \
../testers/Unit_Testing_Math/test_simplex.cpp \
../testers/Unit_Testing_Math/test_simulation.cpp 

OBJS += \
./XSpeed/testers/Unit_Testing_Math/test_2d_geometry.o \
./XSpeed/testers/Unit_Testing_Math/test_NLPsolver.o \
./XSpeed/testers/Unit_Testing_Math/test_ProjectionDist.o \
./XSpeed/testers/Unit_Testing_Math/test_glpk.o \
./XSpeed/testers/Unit_Testing_Math/test_hausdorffDist.o \
./XSpeed/testers/Unit_Testing_Math/test_math_matrix.o \
./XSpeed/testers/Unit_Testing_Math/test_nlopt.o \
./XSpeed/testers/Unit_Testing_Math/test_ode_solution.o \
./XSpeed/testers/Unit_Testing_Math/test_randNumberGenerator.o \
./XSpeed/testers/Unit_Testing_Math/test_simplex.o \
./XSpeed/testers/Unit_Testing_Math/test_simulation.o 

CPP_DEPS += \
./XSpeed/testers/Unit_Testing_Math/test_2d_geometry.d \
./XSpeed/testers/Unit_Testing_Math/test_NLPsolver.d \
./XSpeed/testers/Unit_Testing_Math/test_ProjectionDist.d \
./XSpeed/testers/Unit_Testing_Math/test_glpk.d \
./XSpeed/testers/Unit_Testing_Math/test_hausdorffDist.d \
./XSpeed/testers/Unit_Testing_Math/test_math_matrix.d \
./XSpeed/testers/Unit_Testing_Math/test_nlopt.d \
./XSpeed/testers/Unit_Testing_Math/test_ode_solution.d \
./XSpeed/testers/Unit_Testing_Math/test_randNumberGenerator.d \
./XSpeed/testers/Unit_Testing_Math/test_simplex.d \
./XSpeed/testers/Unit_Testing_Math/test_simulation.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/testers/Unit_Testing_Math/%.o: ../testers/Unit_Testing_Math/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"../" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


