//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/MusicFactory.h"
#include <sstream>

using namespace Lyre;
using namespace std;


TEST( ScoreItems, MxExporterBasic )
{
    MusicFactory f;
    auto scoreSpec = f.scoreSpecFactory->create();
    scoreSpec->setTitle( "Bishop on the Desk" );
    scoreSpec->setComposer( "Bones the Cat" );
    scoreSpec->setCopyright( "(c) 2016" );
    auto score = f.scoreFactory->create( scoreSpec );
    auto mx = f.exporterFactory->create( score );
    mx->exportMusic( std::cout );
}
T_END
