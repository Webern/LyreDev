//PUBLIC

#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/IDurationFactory.h"

using namespace Lyre;
using namespace std;

namespace
{
    auto factory = createDurationFactory( DurationFactoryType::Standard );
}

TEST( durRationLut01, IDurDotFactory )
{
    auto actual = factory->createDuration( Rational{ 1, 1 } );
    auto expected = factory->createDuration( "Quarter" );
    CHECK_EQUAL( expected->toString(), actual->toString() )
}

TEST( durRationLut02, IDurDotFactory )
{
    for ( int i = 0; i < 1000; ++i )
    {
        auto discard = createDurationFactory( DurationFactoryType::Standard );
    }
    auto actual = factory->createDuration( Rational{ 3, 2 } );
    auto expected = factory->createDuration( "Quarter" );
    CHECK_EQUAL( expected->toString(), actual->toString() )
}
