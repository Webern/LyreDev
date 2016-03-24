//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IScoreSpecFactory.h"
#include "Lyre/IScoreSpec.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IScoreSpecFactoryUP factory =
	createScoreSpecFactory();
}

TEST( acceptanceTest, ScoreSpec )
{
    IScoreSpecUP spec = factory->create();
	spec->setTitle( "AstroMusic Part 1" );
	spec->setComposer( "Matthew James Briggs" );
	spec->setCompletionDate( "03/23/2016" );
	spec->setCopyright( "© 2016 by Matthew James Briggs" );
	spec->setStartDate( "09/01/2014" );
    std::stringstream ss;
	spec->toStream( ss );
	std::stringstream exp;
	exp << "*******************************************************************" << std::endl;
	exp << "Title           : AstroMusic Part 1"                                 << std::endl;
	exp << "Composer        : Matthew James Briggs"                              << std::endl;
	exp << "Copyright       : © 2016 by Matthew James Briggs"                    << std::endl;
	exp << "Start Date      : 09/01/2014"                                        << std::endl;
	exp << "Completion Date : 03/23/2016"                                        << std::endl;
	exp << "*******************************************************************" << std::endl;
    String expected = exp.str();
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END
