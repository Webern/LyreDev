//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IRangeFactory.h"
#include "Lyre/IRange.h"
#include "Lyre/IPitchFactory.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IRangeFactoryUP factory =
	createRangeFactory();
}

TEST( ctorThrowBadRange, Range )
{
    IRangeUP r;
    bool isExceptionThrown = false;
    try
    {
        r = factory->create( "C#4", "C4" );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
        
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( ctorThrowBadRangeInts, Range )
{
    IRangeUP r;
    bool isExceptionThrown = false;
    try
    {
        r = factory->create( 1, 0 );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
        
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( ctorThrowBadRangeNullLow, Range )
{
    IRangeUP r;
    IPitchUP low; // nullptr
    auto high = createPitchFactory()->createPitch( 44 );
    bool isExceptionThrown = false;
    try
    {
        r = factory->create( low, high );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
        
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( ctorThrowBadRangeNullHigh, Range )
{
    IRangeUP r;
    auto low = createPitchFactory()->createPitch( 44 );
    IPitchUP high; // nullptr
    bool isExceptionThrown = false;
    try
    {
        r = factory->create( low, high );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
        
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( clone, Range )
{
    IRangeUP r = factory->create( "Db4", "C#4" );
    IRangeUP cloned = r->clone();
    CHECK( cloned != nullptr )
    CHECK( cloned.get() != r.get() )
    String expected = "Range{ Db4 - C#4 }";
    String actual = cloned->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toStream, Range )
{
    IRangeUP r = factory->create();
    std::stringstream ss;
    r->toStream( ss );
    String expected = "Range{ C0 - C7 }";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperator, Range )
{
    IRangeUP r = factory->create( 33, 49 );
    std::stringstream ss;
    ss << (*r);
    String expected = "Range{ A1 - C#3 }";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString, Range )
{
    IRangeUP r = factory->create( "Db4", "C#4" );
    String expected = "Range{ Db4 - C#4 }";
    String actual = r->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getLow, Range )
{
    IRangeUP r = factory->create( "Db4", "C#4" );
    auto low = r->getLow();
    String expected = "Db4";
    String actual = low->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getHigh, Range )
{
    IRangeUP r = factory->create( "Db4", "C#4" );
    auto low = r->getHigh();
    String expected = "C#4";
    String actual = low->toString();
    CHECK_EQUAL( expected, actual )
}
T_END
