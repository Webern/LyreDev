#include "LyreTest/Tests/TestMx.h"


using namespace std;
using namespace mx;
using namespace mx::d;
using namespace mx::e;
using namespace mx::t;


TEST( Compiles, TestMx )
{
    auto doc = makeDocumentPartwise();
    auto score = makeScorePartwise();
    doc->setScorePartwise( score );

    score->getAttributes()->version = XsToken{ "3.0" };
    auto header = score->getScoreHeaderGroup();
    header->setHasWork( true );
    header->getWork()->setHasWorkTitle( true );
    header->getWork()->getWorkTitle()->setValue( XsString( "Work Title" ) );
    header->setHasIdentification( true );
    auto identification = header->getIdentification();
    auto composerCreator = makeCreator();
    composerCreator->getAttributes()->type = XsToken( "composer" );
    composerCreator->setValue( XsString( "Matthew James Briggs" ) );
    identification->addCreator( composerCreator );
    auto copyright = makeRights();
    copyright->getAttributes()->type = XsToken( "copyright" );
    copyright->setValue( XsString( "(c) 2016 by Matthew James Briggs" ) );
    identification->addRights( copyright );

    
    
    doc->toStream( std::cout );
    CHECK( true )
}
T_END