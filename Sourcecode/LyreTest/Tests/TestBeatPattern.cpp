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
    IBeatPatternUP ts = factory->create( quarterDottedQuarter() );
    std::stringstream sstr;
    ts->toStream( sstr );
    String expected = "BeatPattern <Quarter,Quarter.>";
    String actual = sstr.str();
    CHECK_EQUAL( expected, actual )
}
