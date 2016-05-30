//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/MusicFactory.h"
#include "Lyre/Private/BeamingStrategy.h" // TODO private?
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
    auto piano = f.instrumentFactory->create( "Piano", "Pno.", f.rangeFactory->create( "A-1", "C9" ) );
    parts.push_back( f.partSpecFactory->create( 1, flute ) );
    parts.push_back( f.partSpecFactory->create( 1, oboe ) );
    parts.push_back( f.partSpecFactory->create( 1, viola ) );
    parts.push_back( f.partSpecFactory->create( 1, cello ) );
    parts.push_back( f.partSpecFactory->create( 2, piano ) );
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
    masterTrackParams.timeTrack[0] = f.timeSignatureFactory->create( 7, 4 );
    //masterTrackParams.timeTrack[1] = f.timeSignatureFactory->create( 2, 4 );
    //masterTrackParams.timeTrack[3] = f.timeSignatureFactory->create( 3, 4 );
    //masterTrackParams.timeTrack[7] = f.timeSignatureFactory->create( 4, 4 );
    IMasterTrackSPC masterTrack = f.masterTrackFactory->create( std::move( masterTrackParams ) );

    auto movement = f.movementFactory->create(
        movementSpec, parts, masterTrack, f.partFactory->clone());
    
    // create a score
    auto score = f.scoreFactory->create( scoreSpec );
    score->addMovement( movement );
    auto hmovement = score->getMovement( 0 );
    
    // add notes
    for ( int p = 0; p < hmovement->getPartCount(); ++p )
    {
        auto part = hmovement->getPart( p );
        int counter = 1;
        for ( int m = 0; m < part->getMeasureCount(); ++m )
        {
            auto measure = part->getMeasure( m );
            Lyre::Private::BeamingStrategyUP beamingStrategy{ new Lyre::Private::BeamingStrategy {} };
            while ( ! measure->getIsComplete() )
            {
                if( counter > 50 )
                {
                    counter = 0;
                }
                bool isRest = counter % 3 == 0;
                auto pitch = f.pitchFactory->createPitch( counter + 50 );
                auto dur = f.durationFactory->createDuration( STR_16TH, 0 );
                auto note = f.noteFactory->createNote( pitch, dur );
                if( isRest )
                {
                    note->setIsRest( true );
                }
                measure->addNote( note );
                ++counter;
            }
            beamingStrategy->applyStrategy( measure );
            /*
            if ( part->getPartSpec()->getNumStaves() == 2 )
            {
                measure->setLayerContext( 1 );
                part->setStaffContext( 1 );
                while ( ! measure->getIsComplete() )
                {
                    if( counter > 50 )
                    {
                        counter = 0;
                    }
                    bool isRest = counter % 3 == 0;
                    auto pitch = f.pitchFactory->createPitch( counter + 38 );
                    auto dur = f.durationFactory->createDuration( STR_16TH, 0 );
                    auto note = f.noteFactory->createNote( pitch, dur );
                    if( isRest )
                    {
                        note->setIsRest( true );
                    }
                    measure->addNote( note );
                    ++counter;
                }
            }*/
        }
    }
    
    // create musicxml
    auto mx = f.exporterFactory->create( score );
    mx->exportMusic( std::cout );
}
T_END
