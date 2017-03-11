//PUBLIC

#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"
#include "Lyre/ITupletDefFactory.h"
#include "Lyre/ITupletDef.h"

using namespace Lyre;
using namespace std;

TEST( CtorString, IDuration )
{
    String name = STR_EIGHTH;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( name );
    String expected = name;
    String actual = d->getDurBaseName();
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( 0, d->getDotCount() )
    CHECK( ! d->getIsTuplet() )
}
T_END

TEST( CtorStringDots, IDuration )
{
    String name = STR_16TH;
    int dots = 2;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( name, dots );
    
    String expected = name;
    String actual = d->getDurBaseName();
    
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( dots, d->getDotCount() )
    CHECK( ! d->getIsTuplet() )
}
T_END

TEST( CtorTuplet, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 3, STR_EIGHTH, 2, STR_EIGHTH ) );
    
    String name = STR_EIGHTH;
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    String expected = name;
    String actual = d->getDurBaseName();
    
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( dots, d->getDotCount() )
    CHECK( d->getIsTuplet() )
}
T_END

TEST( getDurBaseValue, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 5, STR_16TH, 4, STR_16TH ) );
    
    String name = STR_EIGHTH;
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = Rational{ 1, 2 };
    auto actual = d->getDurBaseValue();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getDurBaseName, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 7, STR_16TH, 4, STR_16TH ) );
    
    String name = STR_32ND;
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = name;
    auto actual = d->getDurBaseName();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getDotCount, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 7, STR_16TH, 4, STR_16TH ) );
    
    String name = STR_32ND;
    int dots = 3;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = dots;
    auto actual = d->getDotCount();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getDottedBaseValue, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 1, STR_WHOLE, 1, STR_WHOLE ) );
    
    String name = STR_32ND;
    int dots = 2;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = Rational{ 7, 32 };
    auto actual = d->getDottedBaseValue();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getDottedBaseName, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 1, STR_WHOLE, 1, STR_WHOLE ) );
    
    String name = STR_HALF;
    int dots = 3;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = String{ "Half..." };
    auto actual = d->getDottedBaseName();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getIsTuplet_false, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 1, STR_WHOLE, 1, STR_WHOLE ) );
    
    String name = STR_HALF;
    int dots = 3;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = false;
    auto actual = d->getIsTuplet();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getIsTuplet_true, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 3, STR_WHOLE, 2, STR_WHOLE ) );
    
    String name = STR_HALF;
    int dots = 3;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = true;
    auto actual = d->getIsTuplet();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getIsNestedTuplet_false_01, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    //VecITupletDefSPC tuplets;
    //tuplets.push_back( tupletFactory->createTupletDef( 3, STR_WHOLE, 2, STR_WHOLE ) );
    
    String name = STR_HALF;
    int dots = 3;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( name, dots );
    
    auto expected = false;
    auto actual = d->getIsNestedTuplet();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getIsNestedTuplet_false_02, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 1, STR_WHOLE, 1, STR_WHOLE ) );
    
    String name = STR_HALF;
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = false;
    auto actual = d->getIsNestedTuplet();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getIsNestedTuplet_false_03, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 1, STR_WHOLE, 1, STR_WHOLE ) );
    tuplets.push_back( tupletFactory->createTupletDef( 1, STR_EIGHTH, 1, STR_EIGHTH ) );
    
    String name = STR_HALF;
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = false;
    auto actual = d->getIsNestedTuplet();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getIsNestedTuplet_false_04, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 1, STR_WHOLE, 1, STR_WHOLE ) );
    tuplets.push_back( tupletFactory->createTupletDef( 3, STR_EIGHTH, 2, STR_EIGHTH ) );
    
    String name = STR_HALF;
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = false;
    auto actual = d->getIsNestedTuplet();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getIsNestedTuplet_true_01, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 5, STR_WHOLE, 4, STR_WHOLE ) );
    tuplets.push_back( tupletFactory->createTupletDef( 3, STR_EIGHTH, 2, STR_EIGHTH ) );
    
    String name = STR_HALF;
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = true;
    auto actual = d->getIsNestedTuplet();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTupletNestingCount_A, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 1, STR_WHOLE, 1, STR_WHOLE ) );
    tuplets.push_back( tupletFactory->createTupletDef( 1, STR_EIGHTH, 1, STR_EIGHTH ) );
    
    String name = STR_HALF;
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = 0;
    auto actual = d->getTupletNestingCount();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTupletNestingCount_B, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 3, STR_WHOLE, 2, STR_WHOLE ) );
    tuplets.push_back( tupletFactory->createTupletDef( 1, STR_EIGHTH, 1, STR_EIGHTH ) );
    
    String name = STR_HALF;
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = 1;
    auto actual = d->getTupletNestingCount();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTupletNestingCount_C, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 3, STR_WHOLE, 2, STR_WHOLE ) );
    tuplets.push_back( tupletFactory->createTupletDef( 5, STR_EIGHTH, 4, STR_EIGHTH ) );
    
    String name = STR_HALF;
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = 2;
    auto actual = d->getTupletNestingCount();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTupletBegin, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 3, STR_WHOLE, 2, STR_WHOLE ) );
    tuplets.push_back( tupletFactory->createTupletDef( 5, STR_EIGHTH, 4, STR_EIGHTH ) );
    
    String name = STR_HALF;
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = 3;
    auto actual = ( *( d->getTupletsBegin() ) )->getCount();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTupletEnd, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 1, STR_WHOLE, 2, STR_WHOLE ) );
    tuplets.push_back( tupletFactory->createTupletDef( 2, STR_EIGHTH, 4, STR_EIGHTH ) );
    tuplets.push_back( tupletFactory->createTupletDef( 3, STR_16TH, 4, STR_16TH ) );
    
    String name = STR_HALF;
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto iter = d->getTupletsBegin();
    auto end = d->getTupletsEnd();
    
    int countIterations = 0;
    for ( ; iter != end; ++iter )
    {
        ++countIterations;
    }
    
    CHECK_EQUAL( 3, countIterations )
}
T_END

TEST( getValue01, IDuration )
{
    String name = STR_EIGHTH;
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( name, dots );
    
    auto expected = Rational{ 1, 2};
    auto actual = d->getValue();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getValue02, IDuration )
{
    String name = STR_HALF;
    int dots = 1;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( /*tuplets,*/ name, dots );
    
    auto expected = Rational{ 3, 1};
    auto actual = d->getValue();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getValue03, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 3, STR_EIGHTH, 2, STR_EIGHTH ) );

    String name = STR_QUARTER;
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = Rational{ 2, 3 };
    auto actual = d->getValue();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getValue04, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 3, STR_EIGHTH, 2, STR_EIGHTH ) );
    
    String name = STR_QUARTER;
    int dots = 1;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = Rational{ 1, 1 };
    auto actual = d->getValue();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getValue05, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 3, STR_EIGHTH, 2, STR_EIGHTH ) );
    tuplets.push_back( tupletFactory->createTupletDef( 5, STR_QUARTER, 4, STR_QUARTER ) );
    String name = STR_EIGHTH;
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = Rational{ 4, 15 };
    auto actual = d->getValue();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getValue06, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 3, STR_EIGHTH, 2, STR_EIGHTH ) );
    tuplets.push_back( tupletFactory->createTupletDef( 5, STR_QUARTER, 4, STR_QUARTER ) );
    String name = STR_EIGHTH;
    int dots = 1;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = Rational{ 2, 5 };
    auto actual = d->getValue();
    
    CHECK_EQUAL( expected, actual )
}
T_END

namespace
{
    const static String EXPECTED_STRING = "Eighth.^( 3[Eighth]:2[Eighth] ( 5[Quarter]:4[Quarter] ) )";
}

TEST( toStream, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 3, STR_EIGHTH, 2, STR_EIGHTH ) );
    tuplets.push_back( tupletFactory->createTupletDef( 5, STR_QUARTER, 4, STR_QUARTER ) );
    String name = STR_EIGHTH;
    int dots = 1;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    std::stringstream ss;
    d->toStream( ss );
    auto expected = EXPECTED_STRING;
    auto actual = ss.str();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperator, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 3, STR_EIGHTH, 2, STR_EIGHTH ) );
    tuplets.push_back( tupletFactory->createTupletDef( 5, STR_QUARTER, 4, STR_QUARTER ) );
    String name = STR_EIGHTH;
    int dots = 1;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    std::stringstream ss;
    ss << (*d);
    auto expected = EXPECTED_STRING;
    auto actual = ss.str();
    
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    VecITupletDefSPC tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 3, STR_EIGHTH, 2, STR_EIGHTH ) );
    tuplets.push_back( tupletFactory->createTupletDef( 5, STR_QUARTER, 4, STR_QUARTER ) );
    String name = STR_EIGHTH;
    int dots = 1;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = EXPECTED_STRING;
    auto actual = d->toString();
    
    CHECK_EQUAL( expected, actual )
}
T_END
