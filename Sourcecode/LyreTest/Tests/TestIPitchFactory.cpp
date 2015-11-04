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

TEST( standardChromaticExists, IPitchFactory )
{
    IPitchFactoryUP f = IPitchFactory::createPitchFactory( PitchFactoryType::StandardChromatic );
    CHECK( f != nullptr )
}

TEST( clone, IPitchFactory )
{
    IPitchFactoryUP f = IPitchFactory::createPitchFactory( PitchFactoryType::StandardChromatic );
    f->setPitch( 50 );
    IPitchFactoryUP c;
    c = f->clone();
    
    CHECK( f != nullptr )
    CHECK( c != nullptr )
    CHECK( f.get() != c.get() )
    CHECK_EQUAL( 50, f->createPitch()->getValue() )
    CHECK_EQUAL( 50, c->createPitch()->getValue() )
}

TEST( setPitch, IPitchFactory )
{
    IPitchFactoryUP f = IPitchFactory::createPitchFactory( PitchFactoryType::StandardChromatic );
    IPitchUP p = f->createPitch();
    p->setAlterValue( 1 );
    p->setStepValue( 5 );
    p->setOctaveValue( 4 );
    f->setPitch( p );
    CHECK_EQUAL( 1, f->createPitch()->getAlterValue() )
    CHECK_EQUAL( 5, f->createPitch()->getStepValue() )
    CHECK_EQUAL( 4, f->createPitch()->getOctaveValue() )
}