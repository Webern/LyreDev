#include "LyreTest/Cpul/cpulRun.h"
//#include "LyreTest/Cpul/cpulTestHarness.h"

void cpulRun( bool runTests, bool holdConsole )
{
#ifndef USE_VS_TEST
    if ( runTests )
    {
        // random number generator used in some tests
        srand(::time_t(NULL));
        
        TestResult tr;
        TestRegistry::runAllTests(tr);
        
        // force console screen to hold
        if ( holdConsole )
        {
            char ch;
            std::cin >> ch;
        }
    }
#endif
}