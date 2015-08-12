#include "cpulTestHarness.h"
#include "Rational.h"
#include "TypeDefs.h"

using namespace lyre::p;

TEST( Constructor01, Rational )
{
    Rational r;
	CHECK_EQUAL( 0 , r.getNumerator() );
}