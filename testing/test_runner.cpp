
/*
 * Calls and runs all tests
 */
#include <iostream>
#include "UnitTest++.h"
#include <sys/ptrace.h>
#include <stdio.h>
#include <assert.h>

using namespace std;

int main() {
	std::cout << "testers called\n";
	return UnitTest::RunAllTests();
}
