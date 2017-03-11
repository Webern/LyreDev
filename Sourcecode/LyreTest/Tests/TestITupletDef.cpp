//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/ITupletDefFactory.h"
#include "Lyre/ITupletDef.h"
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
        5, *( durDotFactory->createDurDot( STR_16TH, 0 ) ),
        4, *( durDotFactory->createDurDot( STR_32ND, 0 ) ) );
    
    CHECK_EQUAL( 5 , t->getCount() )
    CHECK_EQUAL( STR_16TH , t->getCountType()->toString() )
    CHECK_EQUAL( 4 , t->getInTheSpaceOf() )
    CHECK_EQUAL( STR_32ND , t->getInTheSpaceOfType()->toString() )
}
T_END

TEST( ctor2, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        3, 2, *( durDotFactory->createDurDot( STR_QUARTER, 0 ) ) );
    
    CHECK_EQUAL( 3 , t->getCount() )
    CHECK_EQUAL( STR_QUARTER , t->getCountType()->toString() )
    CHECK_EQUAL( 2 , t->getInTheSpaceOf() )
    CHECK_EQUAL( STR_QUARTER , t->getInTheSpaceOfType()->toString() )
}
T_END

TEST( ctor3, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        7, 6, STR_EIGHTH );
    
    CHECK_EQUAL( 7 , t->getCount() )
    CHECK_EQUAL( STR_EIGHTH , t->getCountType()->toString() )
    CHECK_EQUAL( 6 , t->getInTheSpaceOf() )
    CHECK_EQUAL( STR_EIGHTH , t->getInTheSpaceOfType()->toString() )
}
T_END

TEST( clone, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP orig = tupletFactory->createTupletDef(
        7, 6, STR_EIGHTH );
    ITupletDefUP cloned = orig->clone();
    CHECK( orig.get() != nullptr )
    CHECK( cloned.get() != nullptr )
    CHECK( orig.get() != cloned.get() )
    CHECK( orig->getMultiplier() == cloned->getMultiplier() )
    CHECK( orig->getTotalLength() == cloned->getTotalLength() )
    CHECK( orig->toString() == cloned->toString() )
}
T_END

TEST( getMultiplier1, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefUP t = tupletFactory->createTupletDef(
     3, 2, STR_QUARTER );
    Rational expected{ 2, 3 };
    Rational actual = t->getMultiplier();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getMultiplier2, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefUP t = tupletFactory->createTupletDef(
        7, 6, STR_16TH );
    Rational expected{ 6, 7 };
    Rational actual = t->getMultiplier();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getMultiplier3, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefUP t = tupletFactory->createTupletDef(
        7, 6, STR_32ND );
    Rational expected{ 6, 7 };
    Rational actual = t->getMultiplier();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTotalLength1, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        6, *( durDotFactory->createDurDot( STR_16TH, 0 ) ),
        5, *( durDotFactory->createDurDot( STR_32ND, 0 ) ) );
    auto expected = Rational{ 1, 8 } * Rational( 5, 1 );
    auto actual = t->getTotalLength();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTotalLength2, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        3, 2, *( durDotFactory->createDurDot( STR_QUARTER, 0 ) ) );
    auto expected = Rational{ 2, 1 };
    auto actual = t->getTotalLength();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTotalLength3, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        7, 6, STR_EIGHTH );
    auto expected = Rational{ 3, 1 };
    auto actual = t->getTotalLength();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTotalLength4, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        4, *( durDotFactory->createDurDot( STR_QUARTER, 0 ) ),
        2, *( durDotFactory->createDurDot( STR_QUARTER, 1 ) ) );
    auto expected = Rational{ 3, 1 };
    auto actual = t->getTotalLength();
    CHECK_EQUAL( expected, actual )

    expected = Rational{ 3, 4 };
    actual = t->getMultiplier();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getters, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    auto countType = durDotFactory->createDurDot( STR_16TH, 2 );
    auto itspoType = durDotFactory->createDurDot( STR_128TH, 3 );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        15, *countType, 17, *itspoType );
    
    CHECK_EQUAL( 15 , t->getCount() )
    CHECK_EQUAL( *countType, *( t->getCountType() ) )
    CHECK_EQUAL( 17 , t->getInTheSpaceOf() )
    CHECK_EQUAL( *itspoType, *( t->getInTheSpaceOfType() ) )
}
T_END

TEST( toStream, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    auto countType = durDotFactory->createDurDot( STR_16TH, 2 );
    auto itspoType = durDotFactory->createDurDot( STR_128TH, 3 );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        15, *countType, 17, *itspoType );
    
    std::stringstream ss;
    t->toStream( ss ) ;
    String expected = "15[16th..]:17[128th...]";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperator, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    auto countType = durDotFactory->createDurDot( STR_QUARTER, 0 );
    auto itspoType = durDotFactory->createDurDot( STR_QUARTER, 0 );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        3, *countType, 2, *itspoType );
    
    std::stringstream ss;
    ss << ( *t );
    String expected = "3[Quarter]:2[Quarter]";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    auto countType = durDotFactory->createDurDot( STR_32ND, 0 );
    auto itspoType = durDotFactory->createDurDot( STR_32ND, 0 );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        9, *countType, 8, *itspoType );

    String expected = "9[32nd]:8[32nd]";
    String actual = t->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getIsValid1, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefUP t = tupletFactory->createTupletDef(
        1, 1, STR_32ND );
    CHECK( ! ( t->getIsValid() ) )
}
T_END

TEST( getIsValid2, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefUP t = tupletFactory->createTupletDef(
        3, 2, STR_32ND );
    CHECK( t->getIsValid() )
}
T_END