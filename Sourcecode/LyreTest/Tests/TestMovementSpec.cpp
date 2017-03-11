//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IMovementSpecFactory.h"
#include "Lyre/IMovementSpec.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IMovementSpecFactoryUP factory =
	createMovementSpecFactory();
}

TEST( toStream1, MovementSpec )
{
    IMovementSpecUP m = factory->create( 1 );
    std::stringstream ss;
    m->toStream( ss );
    String expected = "1. ";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toStream2, MovementSpec )
{
    IMovementSpecUP m = factory->create( 3257834 );
    m->setTitle( "End Game" );
    std::stringstream ss;
    m->toStream( ss );
    String expected = "3257834. End Game";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toStream3, MovementSpec )
{
    IMovementSpecUP m = factory->create( -1 );
    m->setTitle( "Suppose" );
    m->setDisplayTitle( "This is the display title" );
    std::stringstream ss;
    m->toStream( ss );
    String expected = "This is the display title";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getNumber, MovementSpec )
{
    IMovementSpecUP m = factory->create( 2 );
    int expected = 2;
    int actual = m->getNumber();
    CHECK_EQUAL( expected, actual )
}
T_END
