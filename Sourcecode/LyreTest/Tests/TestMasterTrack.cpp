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


TEST( getTimeTrack, MasterTrack )
{
    Factories f;
    MasterTrackParams params;
    params.measureCount = 10;
    params.timeTrack[0] = f.fourFour->clone();
    params.timeTrack[6] = f.threeFour->clone();
    IMasterTrackUP masterTrack = factory->create( params );
    ITimeSignatureUPC actual = masterTrack->getTimeSignature( 0 );
    ITimeSignatureUPC expected = f.fourFour->clone();
    CHECK_EQUAL( expected->getTop(), actual->getTop() );
    
    actual = masterTrack->getTimeSignature( 1 );
    expected = f.fourFour->clone();
    CHECK_EQUAL( expected->getTop(), actual->getTop() );
    
    actual = masterTrack->getTimeSignature( 2 );
    expected = f.fourFour->clone();
    CHECK_EQUAL( expected->getTop(), actual->getTop() );
    
    actual = masterTrack->getTimeSignature( 3 );
    expected = f.fourFour->clone();
    CHECK_EQUAL( expected->getTop(), actual->getTop() );
    
    actual = masterTrack->getTimeSignature( 4 );
    expected = f.fourFour->clone();
    CHECK_EQUAL( expected->getTop(), actual->getTop() );
    
    actual = masterTrack->getTimeSignature( 5 );
    expected = f.fourFour->clone();
    CHECK_EQUAL( expected->getTop(), actual->getTop() );
    
    actual = masterTrack->getTimeSignature( 6 );
    expected = f.threeFour->clone();
    CHECK_EQUAL( expected->getTop(), actual->getTop() );
    
    actual = masterTrack->getTimeSignature( 7 );
    expected = f.threeFour->clone();
    CHECK_EQUAL( expected->getTop(), actual->getTop() );
    
    actual = masterTrack->getTimeSignature( 8 );
    expected = f.threeFour->clone();
    CHECK_EQUAL( expected->getTop(), actual->getTop() );
    
    actual = masterTrack->getTimeSignature( 9 );
    expected = f.threeFour->clone();
    CHECK_EQUAL( expected->getTop(), actual->getTop() );
}
T_END

TEST( getTimeSignatureThrowNegative, MasterTrack )
{
    Factories f;
    MasterTrackParams params;
    params.measureCount = 10;
    params.timeTrack[0] = f.fourFour->clone();
    params.timeTrack[5] = f.threeFour->clone();
    IMasterTrackUP masterTrack = factory->create( params );
    bool isExceptionThrown = false;
    try
    {
        auto t  = masterTrack->getTimeSignature( -1 );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch( std::exception& e )
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( getTimeSignatureThrowOutOfRange, MasterTrack )
{
    Factories f;
    MasterTrackParams params;
    params.measureCount = 10;
    params.timeTrack[0] = f.fourFour->clone();
    params.timeTrack[5] = f.threeFour->clone();
    IMasterTrackUP masterTrack = factory->create( params );
    bool isExceptionThrown = false;
    try
    {
        auto t  = masterTrack->getTimeSignature( 10 );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch( std::exception& e )
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END
