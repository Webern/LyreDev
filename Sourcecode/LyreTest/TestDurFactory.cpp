//PRIVATE
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/IDur.h"
#include "Lyre/Private/DurFactory.h"

using namespace Lyre;
using namespace Lyre::Private;

TEST( Works, DurFactory )
{
    DurFactory f;
    CHECK( f.createDur( "256th" )->getValue() == Rational( 1, 64 ) )
    CHECK( f.createDur( "128th" )->getValue() == Rational( 1, 32 ) )
    CHECK( f.createDur( "64th" )->getValue() == Rational( 1, 16 ) )
    CHECK( f.createDur( "32nd" )->getValue() == Rational( 1, 8 ) )
    CHECK( f.createDur( "16th" )->getValue() == Rational( 1, 4 ) )
    CHECK( f.createDur( "Eighth" )->getValue() == Rational( 1, 2 ) )
    CHECK( f.createDur( "Quarter" )->getValue() == Rational( 1, 1 ) )
    CHECK( f.createDur( "Half" )->getValue() == Rational( 2, 1 ) )
    CHECK( f.createDur( "Whole" )->getValue() == Rational( 4, 1 ) )
    CHECK( f.createDur( "Breve" )->getValue() == Rational( 8, 1 ) )
    CHECK( f.createDur( "Longa" )->getValue() == Rational( 16, 1 ) )
    
}