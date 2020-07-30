################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../testing/Unit_Testing_Math/test_2d_geometry.cpp \
../testing/Unit_Testing_Math/test_NLPsolver.cpp \
../testing/Unit_Testing_Math/test_ProjectionDist.cpp \
../testing/Unit_Testing_Math/test_glpk.cpp \
../testing/Unit_Testing_Math/test_hausdorffDist.cpp \
../testing/Unit_Testing_Math/test_math_matrix.cpp \
../testing/Unit_Testing_Math/test_nlopt.cpp \
../testing/Unit_Testing_Math/test_ode_solution.cpp \
../testing/Unit_Testing_Math/test_randNumberGenerator.cpp \
../testing/Unit_Testing_Math/test_simplex.cpp \
../testing/Unit_Testing_Math/test_simulation.cpp 

OBJS += \
./XSpeed/testing/Unit_Testing_Math/test_2d_geometry.o \
./XSpeed/testing/Unit_Testing_Math/test_NLPsolver.o \
./XSpeed/testing/Unit_Testing_Math/test_ProjectionDist.o \
./XSpeed/testing/Unit_Testing_Math/test_glpk.o \
./XSpeed/testing/Unit_Testing_Math/test_hausdorffDist.o \
./XSpeed/testing/Unit_Testing_Math/test_math_matrix.o \
./XSpeed/testing/Unit_Testing_Math/test_nlopt.o \
./XSpeed/testing/Unit_Testing_Math/test_ode_solution.o \
./XSpeed/testing/Unit_Testing_Math/test_randNumberGenerator.o \
./XSpeed/testing/Unit_Testing_Math/test_simplex.o \
./XSpeed/testing/Unit_Testing_Math/test_simulation.o 

CPP_DEPS += \
./XSpeed/testing/Unit_Testing_Math/test_2d_geometry.d \
./XSpeed/testing/Unit_Testing_Math/test_NLPsolver.d \
./XSpeed/testing/Unit_Testing_Math/test_ProjectionDist.d \
./XSpeed/testing/Unit_Testing_Math/test_glpk.d \
./XSpeed/testing/Unit_Testing_Math/test_hausdorffDist.d \
./XSpeed/testing/Unit_Testing_Math/test_math_matrix.d \
./XSpeed/testing/Unit_Testing_Math/test_nlopt.d \
./XSpeed/testing/Unit_Testing_Math/test_ode_solution.d \
./XSpeed/testing/Unit_Testing_Math/test_randNumberGenerator.d \
./XSpeed/testing/Unit_Testing_Math/test_simplex.d \
./XSpeed/testing/Unit_Testing_Math/test_simulation.d 


# Each subdirectory must supply rules for building sources it contributes
XSpeed/testing/Unit_Testing_Math/%.o: ../testing/Unit_Testing_Math/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -I/usr/local/include/ -I"/home/rajarshi/eclipse-workspace/XSpeed-plan/XSpeed" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


