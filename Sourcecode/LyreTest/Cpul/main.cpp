#include <iostream>
#include "LyreTest/cpul/cpulRun.h"
#include "LyreTest/Tests/TestTimer.h"
#include "Lyre/Lyre.h"

int main(int argc, const char * argv[])
{
	UNUSED_PARAMETER( argc )
	UNUSED_PARAMETER( argv )
    LyreTest::TestTimer timer;
	cpulRun( true );
	timer.report( "Total runtime for all tests" );
    return 0;
}

