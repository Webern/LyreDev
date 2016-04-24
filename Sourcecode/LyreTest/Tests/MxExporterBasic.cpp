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
    
    // create a movement
    auto movementSpec = f.movementSpecFactory->create( 1 );
    movementSpec->setTitle( "Movement Number 1" );
    movementSpec->setDisplayTitle( "Movement Number 1" );
    MasterTrackParams masterTrackParams;
    masterTrackParams.measureCount = 10;
    masterTrackParams.timeTrack[0] = f.timeSignatureFactory->create( 4, 4 );
    masterTrackParams.timeTrack[1] = f.timeSignatureFactory->create( 2, 4 );
    masterTrackParams.timeTrack[3] = f.timeSignatureFactory->create( 3, 4 );
    masterTrackParams.timeTrack[7] = f.timeSignatureFactory->create( 4, 4 );
    IMasterTrackSPC masterTrack = f.masterTrackFactory->create( std::move( masterTrackParams ) );

    auto movement = f.movementFactory->create(
        movementSpec, parts, masterTrack, f.partFactory->clone());
    
    // create a score
    auto score = f.scoreFactory->create( scoreSpec );
    score->addMovement( movement );
    
    // add notes
    for ( int p = 0; p < movement->getPartCount(); ++p )
    {
        auto part = movement->getPart( p );
        int m = 0;
        auto measure = part->getMeasure( m );
        int counter = 1;
        while ( m < part->getMeasureCount() )
        {
            while ( ! measure->getIsComplete() )
            {
                bool isRest = ! ( ( counter % (p+1) == 0 ) || ( counter % 15 == 0 ) );
                auto pitch = f.pitchFactory->createPitch( p + m + 50 );
                auto dur = f.durationFactory->createDuration( "16th" );
                auto note = f.noteFactory->createNote( pitch, dur );
                note->setIsRest( isRest );
                measure->addNote( note );
                ++counter;
            }
            ++m;
        }
    }
    
    // create musicxml
    auto mx = f.exporterFactory->create( score );
    mx->exportMusic( std::cout );
}
T_END
