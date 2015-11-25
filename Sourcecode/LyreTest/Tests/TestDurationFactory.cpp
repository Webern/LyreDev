//PUBLIC

#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/IDurDotFactory.h"

using namespace Lyre;
using namespace std;

TEST( exists, IDurDotFactory )
{
    IDurDotFactoryUP factory = createDurDotFactory( DurDotFactoryType::Standard );
    CHECK( factory != nullptr )
}
TEST( doesSomething, IDurDotFactory )
{
    IDurDotFactoryUP factory = createDurDotFactory( DurDotFactoryType::Standard );
    IDurDotUP dur = factory->createDurDot( "Quarter", 1 );
    CHECK( dur != nullptr )
}

TEST( doesSomething2, IDurDotFactory )
{
    IDurDotFactoryUP factory = createDurDotFactory( DurDotFactoryType::Standard );
    IDurDotUP dur = factory->createDurDot( "Quarter" );
    CHECK( dur != nullptr )
}
