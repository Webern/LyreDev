//PUBLIC

#include "LyreTest/cpul/cpulTestHarness.h"
#include "LyreTest/Mock/MockPitchFactory.h"

#include "Lyre/IPitchFactory.h"

#include <sstream>
#include <iostream>

using namespace Lyre;
using namespace Lyre::Mock;
using namespace std;



TEST( createPitch_and_next, IPitchFactory )
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
T_END

TEST( createPitch_and_previous, IPitchFactory )
{
    MockPitchFactory f;
    f.setPitch( 100 );
    for ( int i = 100; i > 0; --i )
    {
        auto p = f.createPitch();
        CHECK_EQUAL( i, p->getValue() )
        f.previous();
    }
}
T_END

TEST( standardChromaticExists, IPitchFactory )
{
    IPitchFactoryUP f = createPitchFactory( PitchFactoryType::StandardChromatic );
    CHECK( f != nullptr )
}
T_END

TEST( setPitch, IPitchFactory )
{
    IPitchFactoryUP f = createPitchFactory( PitchFactoryType::StandardChromatic );
    IPitchUP p = f->createPitch();
    p->setAlterValue( 1 );
    p->setStepValue( 5 );
    p->setOctaveValue( 4 );
    f->setPitch( p );
    CHECK_EQUAL( 1, f->createPitch()->getAlterValue() )
    CHECK_EQUAL( 5, f->createPitch()->getStepValue() )
    CHECK_EQUAL( 4, f->createPitch()->getOctaveValue() )
}
T_END