//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/ITupletDefFactory.h"
#include "Lyre/IDurDotFactory.h"

#include <sstream>
#include <iostream>

using namespace Lyre;
using namespace std;


TEST( ctor1, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        5, *( durDotFactory->createDurDot( "16th", 0 ) ),
        4, *( durDotFactory->createDurDot( "32nd", 0 ) ) );
    CHECK_EQUAL( 5 , t->getNumeratorCount() )
    CHECK_EQUAL( "16th" , t->getNumeratorDurDot()->toString() )
    CHECK_EQUAL( 4 , t->getNumeratorCount() )
    CHECK_EQUAL( "32nd" , t->getNumeratorDurDot()->toString() )
}

TEST( ctor2, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        3, 2, *( durDotFactory->createDurDot( "Quarter", 0 ) ) );
    CHECK_EQUAL( 3 , t->getNumeratorCount() )
    CHECK_EQUAL( "Quarter" , t->getNumeratorDurDot()->toString() )
    CHECK_EQUAL( 2 , t->getNumeratorCount() )
    CHECK_EQUAL( "Quarter" , t->getNumeratorDurDot()->toString() )
}

TEST( ctor3, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        7, 6, "Eighth" );
    CHECK_EQUAL( 7 , t->getNumeratorCount() )
    CHECK_EQUAL( "Eighth" , t->getNumeratorDurDot()->toString() )
    CHECK_EQUAL( 6 , t->getNumeratorCount() )
    CHECK_EQUAL( "Eighth" , t->getNumeratorDurDot()->toString() )
}

TEST( getValue1, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefUP t = tupletFactory->createTupletDef(
     3, 2, "Quarter" );
    Rational expected{ 2, 3 };
    Rational actual = t->getValue();
    CHECK_EQUAL( expected, actual )
}

TEST( getValue2, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefUP t = tupletFactory->createTupletDef(
        7, 6, "16th" );
    Rational expected{ 6, 7 };
    Rational actual = t->getValue();
    CHECK_EQUAL( expected, actual )
}

TEST( getValue3, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefUP t = tupletFactory->createTupletDef(
        7, 6, "32nd" );
    Rational expected{ 9, 8 };
    Rational actual = t->getValue();
    CHECK_EQUAL( expected, actual )
}