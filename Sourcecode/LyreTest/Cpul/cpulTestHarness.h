#pragma once

#define xUSE_VS_TEST
#ifdef USE_VS_TEST

    #include "LyreTest/VsTest/VsTest.h"
    

#else

    #include "LyreTest/Cpul/cpulTest.h"
    #include "LyreTest/Cpul/cpulTestResult.h"
    #include "LyreTest/Cpul/cpulFailure.h"
    #include "LyreTest/Cpul/cpulTestRegistry.h"

#endif

