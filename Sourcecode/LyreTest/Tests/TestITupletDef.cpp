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
        5, *( durDotFactory->createDurDot( "16th", 0 ) ),
        4, *( durDotFactory->createDurDot( "32nd", 0 ) ) );
    
    CHECK_EQUAL( 5 , t->getCount() )
    CHECK_EQUAL( "16th" , t->getCountType()->toString() )
    CHECK_EQUAL( 4 , t->getInTheSpaceOf() )
    CHECK_EQUAL( "32nd" , t->getInTheSpaceOfType()->toString() )
}

TEST( ctor2, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        3, 2, *( durDotFactory->createDurDot( "Quarter", 0 ) ) );
    
    CHECK_EQUAL( 3 , t->getCount() )
    CHECK_EQUAL( "Quarter" , t->getCountType()->toString() )
    CHECK_EQUAL( 2 , t->getInTheSpaceOf() )
    CHECK_EQUAL( "Quarter" , t->getInTheSpaceOfType()->toString() )
}

TEST( ctor3, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        7, 6, "Eighth" );
    
    CHECK_EQUAL( 7 , t->getCount() )
    CHECK_EQUAL( "Eighth" , t->getCountType()->toString() )
    CHECK_EQUAL( 6 , t->getInTheSpaceOf() )
    CHECK_EQUAL( "Eighth" , t->getInTheSpaceOfType()->toString() )
}

TEST( clone, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP orig = tupletFactory->createTupletDef(
        7, 6, "Eighth" );
    ITupletDefUP cloned = orig->clone();
    CHECK( orig.get() != nullptr )
    CHECK( cloned.get() != nullptr )
    CHECK( orig.get() != cloned.get() )
    CHECK( orig->getMultiplier() == cloned->getMultiplier() )
    CHECK( orig->getTotalLength() == cloned->getTotalLength() )
    CHECK( orig->toString() == cloned->toString() )
}

TEST( copyTo, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP orig = tupletFactory->createTupletDef(
        8, 9, "128th" );
    
    ITupletDefUP copied;
    orig->copyTo( copied );
    
    CHECK( orig.get() != nullptr )
    CHECK( copied.get() != nullptr )
    CHECK( orig.get() != copied.get() )
    CHECK( orig->getMultiplier() == copied->getMultiplier() )
    CHECK( orig->getTotalLength() == copied->getTotalLength() )
    CHECK( orig->toString() == copied->toString() )
}

TEST( getMultiplier1, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefUP t = tupletFactory->createTupletDef(
     3, 2, "Quarter" );
    Rational expected{ 2, 3 };
    Rational actual = t->getMultiplier();
    CHECK_EQUAL( expected, actual )
}

TEST( getMultiplier2, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefUP t = tupletFactory->createTupletDef(
        7, 6, "16th" );
    Rational expected{ 6, 7 };
    Rational actual = t->getMultiplier();
    CHECK_EQUAL( expected, actual )
}

TEST( getMultiplier3, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefUP t = tupletFactory->createTupletDef(
        7, 6, "32nd" );
    Rational expected{ 9, 8 };
    Rational actual = t->getMultiplier();
    CHECK_EQUAL( expected, actual )
}

TEST( getTotalLength1, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        6, *( durDotFactory->createDurDot( "16th", 0 ) ),
        5, *( durDotFactory->createDurDot( "32nd", 0 ) ) );
    auto expected = Rational{ 1, 8 } * Rational( 5, 1 );
    auto actual = t->getTotalLength();
    CHECK_EQUAL( expected, actual )
}

TEST( getTotalLength2, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        3, 2, *( durDotFactory->createDurDot( "Quarter", 0 ) ) );
    auto expected = Rational{ 2, 1 };
    auto actual = t->getTotalLength();
    CHECK_EQUAL( expected, actual )
}

TEST( getTotalLength3, ITupletDef )
{
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        7, 6, "Eighth" );
    auto expected = Rational{ 3, 1 };
    auto actual = t->getTotalLength();
    CHECK_EQUAL( expected, actual )
}

TEST( getTotalLength4, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        4, *( durDotFactory->createDurDot( "Quarter", 0 ) ),
        2, *( durDotFactory->createDurDot( "Quarter", 1 ) ) );
    auto expected = Rational{ 3, 1 };
    auto actual = t->getTotalLength();
    CHECK_EQUAL( expected, actual )

    expected = Rational{ 3, 4 };
    actual = t->getMultiplier();
    CHECK_EQUAL( expected, actual )
}

TEST( getters, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    auto countType = durDotFactory->createDurDot( "16th", 2 );
    auto itspoType = durDotFactory->createDurDot( "128th", 3 );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        15, *countType, 17, *itspoType );
    
    CHECK_EQUAL( 15 , t->getCount() )
    CHECK_EQUAL( *countType, *( t->getCountType() ) )
    CHECK_EQUAL( 17 , t->getInTheSpaceOf() )
    CHECK_EQUAL( *itspoType, *( t->getInTheSpaceOfType() ) )
}

TEST( toStream, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    auto countType = durDotFactory->createDurDot( "16th", 2 );
    auto itspoType = durDotFactory->createDurDot( "128th", 3 );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        15, *countType, 17, *itspoType );
    
    std::stringstream ss;
    t->toStream( ss ) ;
    String expected = "15[16th..]:17[128th...]";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}

TEST( streamingOperator, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    auto countType = durDotFactory->createDurDot( "Quarter", 0 );
    auto itspoType = durDotFactory->createDurDot( "Quarter", 0 );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        3, *countType, 2, *itspoType );
    
    std::stringstream ss;
    ss << ( *t );
    String expected = "3[Quarter]:2[Quarter]";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}


TEST( toString, ITupletDef )
{
    auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
    ITupletDefFactoryUP tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    
    auto countType = durDotFactory->createDurDot( "32nd", 0 );
    auto itspoType = durDotFactory->createDurDot( "32nd", 0 );
    
    ITupletDefUP t = tupletFactory->createTupletDef(
        9, *countType, 8, *itspoType );

    String expected = "9[32nd]:8[32nd]";
    String actual = t->toString();
    CHECK_EQUAL( expected, actual )
}