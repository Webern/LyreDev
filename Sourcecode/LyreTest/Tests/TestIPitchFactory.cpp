//PUBLIC

#include "LyreTest/cpul/cpulTestHarness.h"
#include "LyreTest/Mock/MockPitchFactory.h"

#include "Lyre/IPitchFactory.h"

#include <sstream>
#include <iostream>

using namespace Lyre;
using namespace Lyre::Mock;
using namespace std;



TEST( compiles, IPitchFactory )
{
    MockPitchFactory f;
    f.setPitch( 0 );
    for ( int i = 0; i < 100; ++i )
    {
        auto p = f.createPitch();
        CHECK_EQUAL( i, p->getValue() )
        f.next();
    }
}

TEST( standardChromaticExists, IPitchFactory )
{
    IPitchFactorySP f = IPitchFactory::createPitchFactory( PitchFactoryType::StandardChromatic );
    CHECK( f != nullptr )
}

TEST( moretestsneeded, IPitchFactory )
{
    CHECK_EQUAL( "more tests needed", "" )
}