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
    
    String expected = name;
    String actual = d->getDurBaseName();
    
    CHECK_EQUAL( expected, actual )
}