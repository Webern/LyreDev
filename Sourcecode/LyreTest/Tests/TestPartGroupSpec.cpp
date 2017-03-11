//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IPartGroupSpecFactory.h"
#include "Lyre/IPartGroupSpec.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IPartGroupSpecFactoryUP factory =
	createPartGroupSpecFactory();
}

TEST( toStream, PartGroupSpec )
{
    IPartGroupSpecUP pgs = factory->create();
    pgs->setName( "Strings" );
    pgs->setNumber( 10 );
    pgs->setShortName( "Str." );
    std::stringstream ss;
    pgs->toStream( ss );
    String expected = "Part Group [10]: Strings";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getName, PartGroupSpec )
{
    String expected = "Some String of Mine";
    IPartGroupSpecUP pgs = factory->create();
    pgs->setName( expected );
    String actual = pgs->getName();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getShortName, PartGroupSpec )
{
    String expected = "Some String of Mine";
    IPartGroupSpecUP pgs = factory->create();
    pgs->setShortName( expected );
    String actual = pgs->getShortName();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getNumber, PartGroupSpec )
{
    int expected = 55;
    IPartGroupSpecUP pgs = factory->create();
    pgs->setNumber( expected );
    int actual = pgs->getNumber();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getPartIndices, PartGroupSpec )
{
    IPartGroupSpecUP pgs = factory->create();
    pgs->addPartIndex( 15 );
    pgs->addPartIndex( 16 );
    pgs->addPartIndex( 17 );
    auto indices = pgs->getPartIndices();
    auto index = indices.cbegin();
    CHECK_EQUAL( 3, indices.size() )
    CHECK_EQUAL( 15, *index )
    ++index;
    CHECK_EQUAL( 16, *index )
    ++index;
    CHECK_EQUAL( 17, *index )
    ++index;
}
T_END

TEST( addPartIndexRaisesBelow, PartGroupSpec )
{
    IPartGroupSpecUP pgs = factory->create();
    pgs->addPartIndex( 15 );
    pgs->addPartIndex( 16 );
    pgs->addPartIndex( 17 );
    CHECK_RAISES( pgs->addPartIndex( 13 ) );
}
T_END

TEST( addPartIndexNotRaisesBelow, PartGroupSpec )
{
    IPartGroupSpecUP pgs = factory->create();
    pgs->addPartIndex( 15 );
    pgs->addPartIndex( 16 );
    pgs->addPartIndex( 17 );
    CHECK_NOT_RAISES( pgs->addPartIndex( 14 ) );
}
T_END

TEST( addPartIndexRaisesAbove, PartGroupSpec )
{
    IPartGroupSpecUP pgs = factory->create();
    pgs->addPartIndex( 15 );
    pgs->addPartIndex( 16 );
    pgs->addPartIndex( 17 );
    CHECK_RAISES( pgs->addPartIndex( 19 ) );
}
T_END

TEST( addPartIndexNotRaisesAbove, PartGroupSpec )
{
    IPartGroupSpecUP pgs = factory->create();
    pgs->addPartIndex( 15 );
    pgs->addPartIndex( 16 );
    pgs->addPartIndex( 17 );
    CHECK_NOT_RAISES( pgs->addPartIndex( 18 ) );
}
T_END

TEST( addPartIndexRaisesNegative, PartGroupSpec )
{
    IPartGroupSpecUP pgs = factory->create();
    CHECK_RAISES( pgs->addPartIndex( -1 ) );
}
T_END