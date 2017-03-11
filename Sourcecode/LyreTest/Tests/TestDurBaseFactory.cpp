//PRIVATE
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/IDurBase.h"
#include "Lyre/Private/DurBaseFactory.h"

using namespace Lyre;
using namespace Lyre::Private;

TEST( Works, DurBaseFactory )
{
    DurBaseFactory f;
    CHECK( f.createDur( STR_256TH )->getValue() == Rational( 1, 64 ) )
    CHECK( f.createDur( STR_128TH )->getValue() == Rational( 1, 32 ) )
    CHECK( f.createDur( STR_64TH )->getValue() == Rational( 1, 16 ) )
    CHECK( f.createDur( STR_32ND )->getValue() == Rational( 1, 8 ) )
    CHECK( f.createDur( STR_16TH )->getValue() == Rational( 1, 4 ) )
    CHECK( f.createDur( STR_EIGHTH )->getValue() == Rational( 1, 2 ) )
    CHECK( f.createDur( STR_QUARTER )->getValue() == Rational( 1, 1 ) )
    CHECK( f.createDur( STR_HALF )->getValue() == Rational( 2, 1 ) )
    CHECK( f.createDur( STR_WHOLE )->getValue() == Rational( 4, 1 ) )
    CHECK( f.createDur( STR_BREVE )->getValue() == Rational( 8, 1 ) )
    CHECK( f.createDur( STR_LONGA )->getValue() == Rational( 16, 1 ) )
    
}
T_END

TEST( Throws, DurBaseFactory )
{
    DurBaseFactory f;
    String message;
    try
    {
        f.createDur( "Gobbledeegook" );
    }
    catch (std::exception& e)
    {
        message = e.what();
    }
    String expected = "'Gobbledeegook' is not a valid DurBase name";
    String actual = message;
    CHECK( actual.find( expected ) != String::npos );
}
T_END
