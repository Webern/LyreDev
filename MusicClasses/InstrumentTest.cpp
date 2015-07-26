#include "TestHarness.h"
#include "Instrument.h"

using namespace music;

TEST( Constructor01, InstrumentTest )
{
    Instrument x;
    CHECK_EQUAL( "Instrument", x.getName() )
}
TEST( Constructor02, InstrumentTest )
{
    Instrument x{ "Clarinet in Bb" };
    CHECK_EQUAL( "Clarinet in Bb", x.getName() )
}

TEST( setName, InstrumentTest )
{
    Instrument x{ "Clarinet in Bb" };
    x.setName( "Trumpet in C" );
    CHECK_EQUAL( "Trumpet in C", x.getName() )
}