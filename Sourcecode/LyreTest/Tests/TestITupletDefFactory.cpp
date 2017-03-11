//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/ITupletDefFactory.h"
#include "Lyre/IDurDotFactory.h"

using namespace Lyre;
using namespace std;

TEST( createTupletDefFactory, ITupletDefFactory )
{
    ITupletDefFactoryUP factory = createTupletDefFactory( TupletDefFactoryType::Standard );
    CHECK( factory != nullptr )
}
T_END

TEST( createTupletDef1, ITupletDefFactory )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        3, *( durDotFactory->createDurDot( STR_QUARTER, 0 ) ),
        2, *( durDotFactory->createDurDot( STR_QUARTER, 0 ) ) );
    
    CHECK( t != nullptr )
}
T_END

TEST( createTupletDef2, ITupletDefFactory )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        3, 2, *( durDotFactory->createDurDot( STR_QUARTER, 0 ) ) );
    
    CHECK( t != nullptr )
}
T_END

TEST( createTupletDef3, ITupletDefFactory )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
     3, 2, STR_QUARTER );
    
    CHECK( t != nullptr )
}
T_END
