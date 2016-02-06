//PRIVATE

#include "LyreTest/cpul/cpulTestHarness.h"

#include "LyreTest/Mock/MockPitchName.h"

#include <sstream>

using namespace Lyre;
using namespace Lyre::Mock;
using namespace std;

TEST( compiles, IPitchName )
{
    IPitchNameUP p{ new MockPitchName{} };
    auto c = p->clone();
    CHECK( p != c )
    CHECK( (p) )
    CHECK( (c) )
    CHECK_EQUAL( 0, p->getValue() )
    CHECK( p->parse( "" ) )
    stringstream ss;
    p->toStream( ss );
    CHECK_EQUAL( "", ss.str() )
    CHECK_EQUAL( "", p->toString() )
    ss << (*p);
    CHECK_EQUAL( "", ss.str() )
    CHECK( ! p->isGreaterThan( *c ) )
    CHECK_EQUAL( 0, p->getStepValue() )
    p->setStepValue( 0 );
    CHECK_EQUAL( 0, p->getMinStepValue() )
    CHECK_EQUAL( 0, p->getMaxStepValue() )
    p->incrementStep();
    p->decrementStep();
    CHECK_EQUAL( 0, p->getAlterValue() )
    p->setAlterValue( 0 );
    CHECK_EQUAL( 0, p->getMinAlterValue() )
    CHECK_EQUAL( 0, p->getMaxAlterValue() )
    p->incrementAlter();
    p->decrementAlter();
    p->isIdenticalTo( *p );
}