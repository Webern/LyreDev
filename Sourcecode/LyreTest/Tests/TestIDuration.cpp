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
    std::string name = "Eighth";
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( name );
    std::string expected = name;
    std::string actual = d->getDurBaseName();
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( 0, d->getDotCount() )
    CHECK( ! d->getIsTuplet() )
}

TEST( CtorStringDots, IDuration )
{
    std::string name = "16th";
    int dots = 2;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( name, dots );
    
    std::string expected = name;
    std::string actual = d->getDurBaseName();
    
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( dots, d->getDotCount() )
    CHECK( ! d->getIsTuplet() )
}

TEST( CtorTuplet, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 3, "Eighth", 2, "Eighth" ) );
    
    std::string name = "Eighth";
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    std::string expected = name;
    std::string actual = d->getDurBaseName();
    
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( dots, d->getDotCount() )
    CHECK( d->getIsTuplet() )
}

TEST( getDurBaseValue, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 5, "16th", 4, "16th" ) );
    
    std::string name = "Eighth";
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = Rational{ 1, 2 };
    auto actual = d->getDurBaseValue();
    
    CHECK_EQUAL( expected, actual )
}

TEST( getDurBaseName, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 7, "16th", 4, "16th" ) );
    
    std::string name = "32nd";
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = name;
    auto actual = d->getDurBaseName();
    
    CHECK_EQUAL( expected, actual )
}

TEST( getDotCount, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 7, "16th", 4, "16th" ) );
    
    std::string name = "32nd";
    int dots = 3;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = dots;
    auto actual = d->getDotCount();
    
    CHECK_EQUAL( expected, actual )
}

TEST( getDottedBaseValue, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 1, "Whole", 1, "Whole" ) );
    
    std::string name = "32nd";
    int dots = 2;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = Rational{ 7, 32 };
    auto actual = d->getDottedBaseValue();
    
    CHECK_EQUAL( expected, actual )
}

TEST( getDottedBaseName, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 1, "Whole", 1, "Whole" ) );
    
    std::string name = "Half";
    int dots = 3;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = String{ "Half..." };
    auto actual = d->getDottedBaseName();
    
    CHECK_EQUAL( expected, actual )
}

TEST( getIsTuplet_false, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 1, "Whole", 1, "Whole" ) );
    
    std::string name = "Half";
    int dots = 3;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = false;
    auto actual = d->getIsTuplet();
    
    CHECK_EQUAL( expected, actual )
}

TEST( getIsTuplet_true, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 3, "Whole", 2, "Whole" ) );
    
    std::string name = "Half";
    int dots = 3;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = true;
    auto actual = d->getIsTuplet();
    
    CHECK_EQUAL( expected, actual )
}

TEST( getIsNestedTuplet_false_01, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    //ITupletDefSPCs tuplets;
    //tuplets.push_back( tupletFactory->createTupletDef( 3, "Whole", 2, "Whole" ) );
    
    std::string name = "Half";
    int dots = 3;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( name, dots );
    
    auto expected = false;
    auto actual = d->getIsNestedTuplet();
    
    CHECK_EQUAL( expected, actual )
}

TEST( getIsNestedTuplet_false_02, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 1, "Whole", 1, "Whole" ) );
    
    std::string name = "Half";
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = false;
    auto actual = d->getIsNestedTuplet();
    
    CHECK_EQUAL( expected, actual )
}

TEST( getIsNestedTuplet_false_03, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 1, "Whole", 1, "Whole" ) );
    tuplets.push_back( tupletFactory->createTupletDef( 1, "Eighth", 1, "Eighth" ) );
    
    std::string name = "Half";
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = false;
    auto actual = d->getIsNestedTuplet();
    
    CHECK_EQUAL( expected, actual )
}

TEST( getIsNestedTuplet_false_04, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 1, "Whole", 1, "Whole" ) );
    tuplets.push_back( tupletFactory->createTupletDef( 3, "Eighth", 2, "Eighth" ) );
    
    std::string name = "Half";
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = false;
    auto actual = d->getIsNestedTuplet();
    
    CHECK_EQUAL( expected, actual )
}

TEST( getIsNestedTuplet_true_01, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 5, "Whole", 4, "Whole" ) );
    tuplets.push_back( tupletFactory->createTupletDef( 3, "Eighth", 2, "Eighth" ) );
    
    std::string name = "Half";
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = true;
    auto actual = d->getIsNestedTuplet();
    
    CHECK_EQUAL( expected, actual )
}

TEST( getTupletNestingCount_A, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 1, "Whole", 1, "Whole" ) );
    tuplets.push_back( tupletFactory->createTupletDef( 1, "Eighth", 1, "Eighth" ) );
    
    std::string name = "Half";
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = 0;
    auto actual = d->getTupletNestingCount();
    
    CHECK_EQUAL( expected, actual )
}

TEST( getTupletNestingCount_B, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 3, "Whole", 2, "Whole" ) );
    tuplets.push_back( tupletFactory->createTupletDef( 1, "Eighth", 1, "Eighth" ) );
    
    std::string name = "Half";
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = 1;
    auto actual = d->getTupletNestingCount();
    
    CHECK_EQUAL( expected, actual )
}

TEST( getTupletNestingCount_C, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 3, "Whole", 2, "Whole" ) );
    tuplets.push_back( tupletFactory->createTupletDef( 5, "Eighth", 4, "Eighth" ) );
    
    std::string name = "Half";
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = 2;
    auto actual = d->getTupletNestingCount();
    
    CHECK_EQUAL( expected, actual )
}

TEST( getTupletBegin, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 3, "Whole", 2, "Whole" ) );
    tuplets.push_back( tupletFactory->createTupletDef( 5, "Eighth", 4, "Eighth" ) );
    
    std::string name = "Half";
    int dots = 0;
    auto f = createDurationFactory( DurationFactoryType::Standard );
    auto d = f->createDuration( tuplets, name, dots );
    
    auto expected = 3;
    auto actual = ( *( d->getTupletsBegin() ) )->getCount();
    
    CHECK_EQUAL( expected, actual )
}

TEST( getTupletEnd, IDuration )
{
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    tuplets.push_back( tupletFactory->createTupletDef( 1, "Whole", 2, "Whole" ) );
    tuplets.push_back( tupletFactory->createTupletDef( 2, "Eighth", 4, "Eighth" ) );
    tuplets.push_back( tupletFactory->createTupletDef( 3, "16th", 4, "16th" ) );
    
    std::string name = "Half";
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

TEST( moreTests, IDuration )
{
    
    CHECK_EQUAL( "", "write more tests" )
}