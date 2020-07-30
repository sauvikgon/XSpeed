################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testFiles/Unit_Testing_Math/test_2d_geometry.cpp \
../testFiles/Unit_Testing_Math/test_NLPsolver.cpp \
../testFiles/Unit_Testing_Math/test_ProjectionDist.cpp \
../testFiles/Unit_Testing_Math/test_glpk.cpp \
../testFiles/Unit_Testing_Math/test_hausdorffDist.cpp \
../testFiles/Unit_Testing_Math/test_math_matrix.cpp \
../testFiles/Unit_Testing_Math/test_nlopt.cpp \
../testFiles/Unit_Testing_Math/test_ode_solution.cpp \
../testFiles/Unit_Testing_Math/test_randNumberGenerator.cpp \
../testFiles/Unit_Testing_Math/test_simplex.cpp \
../testFiles/Unit_Testing_Math/test_simulation.cpp 

OBJS += \
./XSpeed/testFiles/Unit_Testing_Math/test_2d_geometry.o \
./XSpeed/testFiles/Unit_Testing_Math/test_NLPsolver.o \
./XSpeed/testFiles/Unit_Testing_Math/test_ProjectionDist.o \
./XSpeed/testFiles/Unit_Testing_Math/test_glpk.o \
./XSpeed/testFiles/Unit_Testing_Math/test_hausdorffDist.o \
./XSpeed/testFiles/Unit_Testing_Math/test_math_matrix.o \
./XSpeed/testFiles/Unit_Testing_Math/test_nlopt.o \
./XSpeed/testFiles/Unit_Testing_Math/test_ode_solution.o \
./XSpeed/testFiles/Unit_Testing_Math/test_randNumberGenerator.o \
./XSpeed/testFiles/Unit_Testing_Math/test_simplex.o \
./XSpeed/testFiles/Unit_Testing_Math/test_simulation.o 

CPP_DEPS += \
./XSpeed/testFiles/Unit_Testing_Math/test_2d_geometry.d \
./XSpeed/testFiles/Unit_Testing_Math/test_NLPsolver.d \
./XSpeed/testFiles/Unit_Testing_Math/test_ProjectionDist.d \
./XSpeed/testFiles/Unit_Testing_Math/test_glpk.d \
./XSpeed/testFiles/Unit_Testing_Math/test_hausdorffDist.d \
./XSpeed/testFiles/Unit_Testing_Math/test_math_matrix.d \
./XSpeed/testFiles/Unit_Testing_Math/test_nlopt.d \
./XSpeed/testFiles/Unit_Testing_Math/test_ode_solution.d \
./XSpeed/testFiles/Unit_Testing_Math/test_randNumberGenerator.d \
./XSpeed/testFiles/Unit_Testing_Math/test_simplex.d \
./XSpeed/testFiles/Unit_Testing_Math/test_simulation.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/testFiles/Unit_Testing_Math/%.o: ../testFiles/Unit_Testing_Math/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"/home/rajarshi/eclipse-workspace/XSpeed-plan/XSpeed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


