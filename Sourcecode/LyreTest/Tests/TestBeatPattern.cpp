//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IBeatPattern.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IBeatPatternFactoryUP factory =
	createBeatPatternFactory();

    inline IDurationFactoryUP durfact()
    {
        return createDurationFactory( DurationFactoryType::Standard );
    }
    inline IDurationUP quarter()
    {
        return durfact()->createDuration( "Quarter" );
    }
    
    inline IDurationUP dottedQuarter()
    {
        return durfact()->createDuration( "Quarter", 1 );
    }
    
    inline VecIDurationUP quarterDottedQuarter()
    {
        VecIDurationUP durs;
        durs.push_back( quarter() );
        durs.push_back( dottedQuarter() );
        return durs;
    }
}

TEST( toStream, BeatPattern )
{
    IBeatPatternUP bp = factory->create( quarterDottedQuarter() );
    std::stringstream sstr;
    bp->toStream( sstr );
    String expected = "BeatPattern<Quarter,Quarter.>";
    String actual = sstr.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTotalDuration, BeatPattern )
{
    IBeatPatternUP bp = factory->create( quarterDottedQuarter() );
    Rational expected{ 5, 2 };
    Rational actual = bp->getTotalDuration();
    CHECK_EQUAL( expected, actual )
}
T_END

// TODO More Tests

