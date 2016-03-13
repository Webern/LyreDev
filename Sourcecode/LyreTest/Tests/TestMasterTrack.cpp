//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IMasterTrackFactory.h"
#include "Lyre/IMasterTrack.h"
#include "Lyre/ITimeSignatureFactory.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IMasterTrackFactoryUP factory =
	createMasterTrackFactory();
    
    struct Factories
    {
        IMasterTrackFactoryUP masterTrackFactory;
        ITimeSignatureFactoryUP timeSignatureFactory;
        ITimeSignatureUPC fourFour;
        ITimeSignatureUPC threeFour;
        
        Factories()
        : masterTrackFactory( createMasterTrackFactory() )
        , timeSignatureFactory( createTimeSignatureFactory() )
        , fourFour( timeSignatureFactory->create( 4, 4 ) )
        , threeFour( timeSignatureFactory->create( 3, 4 ) )
        {}
        
    };
}

TEST( ctorThrowTimeTrackIndex0, MasterTrack )
{
    // TimeTrack must have an initial
    // time signature for measure 0
    Factories f;
    MasterTrackParams params;
    params.measureCount = 10;
    params.timeTrack[1] = f.fourFour->clone();
    bool isExceptionThrown = false;
    try
    {
        IMasterTrackUP masterTrack = factory->create( params );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch( std::exception& e )
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END


TEST( ctorThrowTimeTrackIndexOutOfRange, MasterTrack )
{
    // TimeTrack must not have a measure index
    // greater than measureCount - 1
    Factories f;
    MasterTrackParams params;
    params.measureCount = 10;
    params.timeTrack[0] = f.fourFour->clone();
    params.timeTrack[10] = f.threeFour->clone();
    bool isExceptionThrown = false;
    try
    {
        IMasterTrackUP masterTrack = factory->create( params );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch( std::exception& e )
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END


TEST( ctorThrowMeasureCountNegative, MasterTrack )
{
    // Measure Count must be positive
    Factories f;
    MasterTrackParams params;
    params.measureCount = -1;
    params.timeTrack[0] = f.fourFour->clone();
    bool isExceptionThrown = false;
    try
    {
        IMasterTrackUP masterTrack = factory->create( params );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch( std::exception& e )
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END


TEST( ctorThrowTimeTrackHasNegative, MasterTrack )
{
    // TimeTrack must not have a
    // negative measure index
    Factories f;
    MasterTrackParams params;
    params.measureCount = 10;
    params.timeTrack[0] = f.fourFour->clone();
    params.timeTrack[-1] = f.threeFour->clone();
    bool isExceptionThrown = false;
    try
    {
        IMasterTrackUP masterTrack = factory->create( params );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch( std::exception& e )
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END
