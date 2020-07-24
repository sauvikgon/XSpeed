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
../testing/Unit_Testing_Math/test_ode_solution.cpp \
../testing/Unit_Testing_Math/test_randNumberGenerator.cpp \
../testing/Unit_Testing_Math/test_simplex.cpp \
../testing/Unit_Testing_Math/test_simulation.cpp 

OBJS += \
./testing/Unit_Testing_Math/test_2d_geometry.o \
./testing/Unit_Testing_Math/test_NLPsolver.o \
./testing/Unit_Testing_Math/test_ProjectionDist.o \
./testing/Unit_Testing_Math/test_glpk.o \
./testing/Unit_Testing_Math/test_hausdorffDist.o \
./testing/Unit_Testing_Math/test_math_matrix.o \
./testing/Unit_Testing_Math/test_ode_solution.o \
./testing/Unit_Testing_Math/test_randNumberGenerator.o \
./testing/Unit_Testing_Math/test_simplex.o \
./testing/Unit_Testing_Math/test_simulation.o 

CPP_DEPS += \
./testing/Unit_Testing_Math/test_2d_geometry.d \
./testing/Unit_Testing_Math/test_NLPsolver.d \
./testing/Unit_Testing_Math/test_ProjectionDist.d \
./testing/Unit_Testing_Math/test_glpk.d \
./testing/Unit_Testing_Math/test_hausdorffDist.d \
./testing/Unit_Testing_Math/test_math_matrix.d \
./testing/Unit_Testing_Math/test_ode_solution.d \
./testing/Unit_Testing_Math/test_randNumberGenerator.d \
./testing/Unit_Testing_Math/test_simplex.d \
./testing/Unit_Testing_Math/test_simulation.d 


# Each subdirectory must supply rules for building sources it contributes
testing/Unit_Testing_Math/%.o: ../testing/Unit_Testing_Math/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++11 -D DEBUG -I/usr/local/include/ -I/usr/local/include/UnitTest++/ -I"/home/rajarshi/eclipse-workspac../XSpeed" -O3 -g -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


