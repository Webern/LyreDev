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

    // add parts
    VecIPartSpecUP parts;
    auto flute = f.instrumentFactory->create( "Flute", "Fl.", f.rangeFactory->create( "C4", "C7" ) );
    auto oboe = f.instrumentFactory->create( "Oboe", "Ob.", f.rangeFactory->create( "C4", "E6" ) );
    auto viola = f.instrumentFactory->create( "Viola", "Vla.", f.rangeFactory->create( "C3", "C6" ) );
    auto cello = f.instrumentFactory->create( "Cello", "Vlc.", f.rangeFactory->create( "C2", "C5" ) );
    parts.push_back( f.partSpecFactory->create( 1, flute ) );
    parts.push_back( f.partSpecFactory->create( 1, oboe ) );
    parts.push_back( f.partSpecFactory->create( 1, viola ) );
    parts.push_back( f.partSpecFactory->create( 1, cello ) );
    scoreSpec->setPartSpecs( parts );
    
    // group parts
    VecIPartGroupSpecUP partGroups;
    auto ww = f.partGroupSpecFactory->create();
    ww->setName( "Woodwinds" );
    ww->setShortName( "Ww." );
    ww->setNumber( 1 );
    ww->addPartIndex( 0 );
    ww->addPartIndex( 1 );
    partGroups.push_back( std::move( ww ) );
    auto str = f.partGroupSpecFactory->create();
    str->setName( "Strings" );
    str->setShortName( "Str." );
    str->setNumber( 2 );
    str->addPartIndex( 2 );
    str->addPartIndex( 3 );
    partGroups.push_back( std::move( str ) );
    scoreSpec->setPartGroupSpecs( partGroups );
    
    auto score = f.scoreFactory->create( scoreSpec );
    auto mx = f.exporterFactory->create( score );
    mx->exportMusic( std::cout );
}
T_END
