/*
 * memory_usages.cpp
 *
 *  Created on: 26-Nov-2014
 *      Author: amit
 */

#include "memory_usages.h"
#include "stdio.h"
#include "stdlib.h"
#include  <iostream>
#include <mach/mach.h>
#include <sys/sysctl.h>
#include <sys/types.h>
using namespace std ;



long parseLine(char* line) {
	long i = strlen(line);
	while (*line < '0' || *line > '9')
		line++;
	line[i - 3] = '\0';
	i = atoi(line);
	return i;
}

/*
 * Returns the Virtual Memory currently used by current process
 *
 * Actually, virtual memory = part in RAM + part on disk + virtual address space not mapped to physical memory
 *  + memory mapped files + shared memory.
 * So to measure memory consumption, VmSize is pretty useless.
 *
 */

size_t getVMused_CurrentProcess()//Function to get VM used by current process in MacOS
{
	struct mach_task_basic_info info;
	mach_msg_type_number_t infoCount = MACH_TASK_BASIC_INFO_COUNT;
	if ( task_info( mach_task_self( ), MACH_TASK_BASIC_INFO,
		(task_info_t)&info, &infoCount ) != KERN_SUCCESS )
		return (size_t)0L;

	return (size_t)info.virtual_size;

}
long getCurrentProcess_VirtualMemoryUsed() { //Note: this value is in KB!
	FILE* file = fopen("/proc/self/status", "r");	//reading the Linux resource file
	long result = -1;
	char line[128];
	if(file==NULL)
		{
			result=getVMused_CurrentProcess()/1024;
		}
	else
	{while (fgets(line, 128, file) != NULL) {
		if (strncmp(line, "VmSize:", 7) == 0) {		//VmSize : Virtual Memory Size currently used
			result = parseLine(line);
			break;
		}
	}
	}
	fclose(file);
	return result;
}

/*
 * Returns the Physical Memory currently used by current process:
 */
size_t getCurrentRSS()//Process resident set size retrieval process for macOS machines. Value will come in bytes
{
	struct mach_task_basic_info info;
	mach_msg_type_number_t infoCount = MACH_TASK_BASIC_INFO_COUNT;
	if ( task_info( mach_task_self( ), MACH_TASK_BASIC_INFO,
		(task_info_t)&info, &infoCount ) != KERN_SUCCESS )
		return (size_t)0L;		/* Can't access? */
	return (size_t)info.resident_size;
}
long getCurrentProcess_PhysicalMemoryUsed() { //Note: this value is in KB!
	FILE* file = fopen("/proc/self/status", "r");	//reading the Linux resource file
	long result = -1;
	char line[128];
	if(file==NULL)//if the source file is not found, machine is running macOS
			{
				result=getCurrentRSS()/1024;

			}
	else {
	while (fgets(line, 128, file) != NULL) {
		if (strncmp(line, "VmRSS:", 6) == 0) {		//VmRSS : Virtual Memory Size currently used
			result = parseLine(line);
			break;
		}
	}
	}
	fclose(file);
	return result;
}
