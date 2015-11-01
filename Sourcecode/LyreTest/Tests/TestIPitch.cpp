//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "LyreTest/Mock/MockPitch.h"
#include "Lyre/IPitch.h"
#include <sstream>

using namespace Lyre;
using namespace Lyre::Mock;
using namespace std;



TEST( compiles, IPitch )
{
    IPitchUP p{ new MockPitch{} };
    auto c = p->clone();
    MockPitchUP x;
    p->copyTo( x );
    CHECK( p != c )
    CHECK( p != x )
    CHECK( x != c )
    CHECK( (p) )
    CHECK( (c) )
    CHECK( (x) )
    CHECK_EQUAL( 0, p->getValue() )
    CHECK( p->parse( "" ) )
    stringstream ss;
    p->toStream( ss );
    CHECK_EQUAL( "", ss.str() )
    CHECK_EQUAL( "", p->toString() )
    ss << (*p);
    CHECK_EQUAL( "", ss.str() )
    CHECK( ! p->isLessThan( *x ) )
    CHECK( p->isEqualTo( *x ) )
    CHECK( ! p->isGreaterThan( *c ) )
    CHECK_EQUAL( 0, p->getStepValue() )
    p->setStepValue( 0 );
    p->incrementStep();
    p->decrementStep();
    CHECK_EQUAL( 0, p->getAlterValue() )
    p->setAlterValue( 0 );
    p->incrementAlter();
    p->decrementAlter();
    CHECK_EQUAL( 0, p->getOctaveValue() )
    p->setOctaveValue( 0 );
    p->incrementOctave();
    p->decrementOctave();
    p->isIdenticalTo( *p );
}