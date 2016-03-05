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
T_END

TEST( durRationLut02, IDurDotFactory )
{
    auto actual = factory->createDuration( Rational{ 3, 2 } );
    auto expected = factory->createDuration( "Quarter", 1 );
    CHECK_EQUAL( expected->toString(), actual->toString() )
}
T_END
