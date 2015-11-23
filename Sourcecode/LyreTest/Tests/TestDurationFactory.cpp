//PUBLIC

#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/IDurationFactory.h"

using namespace Lyre;
using namespace std;

TEST( exists, IDurationFactory )
{
    IDurationFactoryUP factory = createDurationFactory( DurationFactoryType::Standard );
    CHECK( factory != nullptr )
}
TEST( doesSomething, IDurationFactory )
{
    IDurationFactoryUP factory = createDurationFactory( DurationFactoryType::Standard );
    IDurationUP dur = factory->createDuration( "Quarter", 1 );
    CHECK( dur != nullptr )
}

TEST( doesSomething2, IDurationFactory )
{
    IDurationFactoryUP factory = createDurationFactory( DurationFactoryType::Standard );
    IDurationUP dur = factory->createDuration( "Quarter" );
    CHECK( dur != nullptr )
}
