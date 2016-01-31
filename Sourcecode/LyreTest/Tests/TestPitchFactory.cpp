//PUBLIC

#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/IPitchFactory.h"

#include <sstream>
#include <iostream>

using namespace Lyre;
using namespace std;

TEST( C4, PitchFactory )
{
    auto factory = createPitchFactory( PitchFactoryType::StandardChromatic );
    factory->setPitch( 60 );
    CHECK_EQUAL( "C4", factory->createPitch()->toString() )
}

TEST( D6, PitchFactory )
{
    auto factory = createPitchFactory( PitchFactoryType::StandardChromatic );
    factory->setPitch( 59 );
    CHECK_EQUAL( "B3", factory->createPitch()->toString() )
}