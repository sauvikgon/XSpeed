################################################################################
# Automatically-generated file. Do not edit!
################################################################################

#-include ../../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include XSpeed/utilities/memUtilities/subdir.mk
-include XSpeed/utilities/directions/subdir.mk
-include XSpeed/utilities/cpuUtilities/subdir.mk
-include XSpeed/utilities/subdir.mk
-include XSpeed/io/resetParser/subdir.mk
-include XSpeed/io/linExpParser/subdir.mk
-include XSpeed/io/flowParser/subdir.mk
-include XSpeed/io/subdir.mk
-include XSpeed/counterExample/subdir.mk
-include XSpeed/core/symbolicStates/subdir.mk
-include XSpeed/core/reachability/subdir.mk
-include XSpeed/core/pwl/subdir.mk
-include XSpeed/core/math/point/subdir.mk
-include XSpeed/core/math/numeric/subdir.mk
-include XSpeed/core/math/nlpSolver/subdir.mk
-include XSpeed/core/math/lpSolver/subdir.mk
-include XSpeed/core/math/glpkLpSolver/subdir.mk
-include XSpeed/core/math/subdir.mk
-include XSpeed/core/hybridAutomata/subdir.mk
-include XSpeed/core/discrete/discreteSet/subdir.mk
-include XSpeed/core/continuous/polytope/subdir.mk
-include XSpeed/core/continuous/convexSet/subdir.mk
-include XSpeed/core/continuous/approxModel/subdir.mk
-include XSpeed/application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: xspeed

# Tool invocations
xspeed: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	g++ -std=c++11 -I/usr/local/include/ -L/usr/local/lib/ -L/usr/local/lib/lib/ -L/usr/local/lib/x86_64-linux-gnu/ -o "xspeed" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(C_DEPS)$(CPP_DEPS) xspeed
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets
