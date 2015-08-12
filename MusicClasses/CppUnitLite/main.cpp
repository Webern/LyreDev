
#include "TestHarness.h"
#include <iostream>

int main()
{
	// random number generator used in some tests
	srand(::time_t(NULL));
    
    TestResult tr;
    TestRegistry::runAllTests(tr);
    
#ifndef __clang__
    char ch;
    std::cin >> ch;
#endif
    
    return 0;
}