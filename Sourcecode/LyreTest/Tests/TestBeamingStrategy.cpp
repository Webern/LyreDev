//PRIVATE???
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/MusicFactory.h"
#include "Lyre/IMeasure.h"
#include "Lyre/INoteGroup.h"
#include "Lyre/NoteGroup.h"
#include "Lyre/Private/BeamingStrategy.h"

using namespace Lyre;
using namespace Lyre::Private;

namespace
{
    MusicFactory f;

    
    INoteGroupUP pattern1() // ****
    {
        INoteGroupUP grp{ new NoteGroup{} };
        auto pitch = f.pitchFactory->createPitch( 51 );
        auto dur = f.durationFactory->createDuration( STR_16TH );
        auto note = f.noteFactory->createNote( pitch, dur );
        grp->addNote( note );
        grp->addNote( note );
        grp->addNote( note );
        grp->addNote( note );
        return grp;
    }
    
    INoteGroupUP pattern2() // **-
    {
        INoteGroupUP grp{ new NoteGroup{} };
        auto pitch = f.pitchFactory->createPitch( 51 );
        auto dur = f.durationFactory->createDuration( STR_16TH );
        auto note = f.noteFactory->createNote( pitch, dur );
        grp->addNote( note );
        grp->addNote( note );
        dur = f.durationFactory->createDuration( STR_EIGHTH );
        note = f.noteFactory->createNote( pitch, dur );
        grp->addNote( note );
        return grp;
    }
    
    INoteGroupUP pattern3() // * **
    {
        INoteGroupUP grp{ new NoteGroup{} };
        auto pitch = f.pitchFactory->createPitch( 51 );
        auto dur = f.durationFactory->createDuration( STR_EIGHTH );
        auto note = f.noteFactory->createNote( pitch, dur );
        grp->addNote( note );
        dur = f.durationFactory->createDuration( STR_16TH );
        note = f.noteFactory->createNote( pitch, dur );
        grp->addNote( note );
        grp->addNote( note );
        return grp;
    }
    
    
    INoteGroupUP pattern4() // *? *
    {
        INoteGroupUP grp{ new NoteGroup{} };
        auto pitch = f.pitchFactory->createPitch( 51 );
        auto dur = f.durationFactory->createDuration( STR_16TH );
        
        auto note = f.noteFactory->createNote( pitch, dur );
        note->setIsRest( false );
        grp->addNote( note );
        
        dur = f.durationFactory->createDuration( STR_EIGHTH );
        note = f.noteFactory->createNote( pitch, dur );
        note->setIsRest( true );
        grp->addNote( note );
        
        dur = f.durationFactory->createDuration( STR_16TH );
        note = f.noteFactory->createNote( pitch, dur );
        note->setIsRest( false );
        grp->addNote( note );
        return grp;
    }
}

TEST( XXX, BeamingStrategy )
{
    auto measure = f.measureFactory->create( 4, 4 );
    measure->addGroup( pattern1() );
    measure->addGroup( pattern2() );
    measure->addGroup( pattern3() );
    measure->addGroup( pattern4() );
    
    BeamingStrategyUP beamingStrategy{ new BeamingStrategy{ measure->getTimeSignature()->getBeatPattern() } };
    beamingStrategy->applyStrategy( measure );
    
    int noteIndex = 0;
    
    // pattern1 * **
    auto actual = measure->getNote( noteIndex++ )->getBeams();
    CHECK_EQUAL( 2, actual );
    
    actual = measure->getNote( noteIndex++ )->getBeams();
    CHECK_EQUAL( 2, actual );
    
    actual = measure->getNote( noteIndex++ )->getBeams();
    CHECK_EQUAL( 2, actual );
    
    actual = measure->getNote( noteIndex++ )->getBeams();
    CHECK_EQUAL( 0, actual );
    
    // pattern2 **-
    actual = measure->getNote( noteIndex++ )->getBeams();
    CHECK_EQUAL( 2, actual );
    
    actual = measure->getNote( noteIndex++ )->getBeams();
    CHECK_EQUAL( 1, actual );
    
    actual = measure->getNote( noteIndex++ )->getBeams();
    CHECK_EQUAL( 0, actual );
    
    // pattern3 * **
    actual = measure->getNote( noteIndex++ )->getBeams();
    CHECK_EQUAL( 1, actual );
    
    actual = measure->getNote( noteIndex++ )->getBeams();
    CHECK_EQUAL( 2, actual );
    
    actual = measure->getNote( noteIndex++ )->getBeams();
    CHECK_EQUAL( 0, actual );
    
    // pattern4 *? *
    actual = measure->getNote( noteIndex++ )->getBeams();
    CHECK_EQUAL( 1, actual );
    
    actual = measure->getNote( noteIndex++ )->getBeams();
    CHECK_EQUAL( 1, actual );
    
    actual = measure->getNote( noteIndex++ )->getBeams();
    CHECK_EQUAL( 0, actual );
}
T_END