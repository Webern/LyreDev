//PUBLIC

#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"

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
}

TEST( Placeholder, IDuration )
{
    CHECK_EQUAL( "", "write more duration tests" )
}