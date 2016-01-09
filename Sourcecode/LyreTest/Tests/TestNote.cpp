//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/INoteFactory.h"
#include "Lyre/INote.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IPitchFactory.h"
#include "Lyre/INote.h"
#include "Lyre/IDuration.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/ITupletDefFactory.h"
#include <sstream>

using namespace Lyre;
using namespace std;

TEST( clone_getPitch_setPitch, INote )
{
    auto pitchFactory = createPitchFactory( PitchFactoryType::StandardChromatic );
    auto durationFactory = createDurationFactory( DurationFactoryType::Standard );
    auto noteFactory = createNoteFactory( NoteFactoryType::Standard );
    
    auto pitch = pitchFactory->createPitch();
    
    pitch->setAlterValue( 1 );
    pitch->setStepValue( 2 );
    pitch->setOctaveValue( 2 );
    
    auto duration = durationFactory->createDuration( "Half", 0 );
    auto orig = noteFactory->createNote( pitch, duration );
    auto cloned = orig->clone();
    
    CHECK( cloned )
    CHECK( orig.get() != cloned.get() )
    CHECK_EQUAL( 2, cloned->getPitch()->getStepValue() )
    
    pitch->setStepValue( 3 );
    cloned->setPitch( pitch );
    
    pitch->setStepValue( 4 );
    orig->setPitch( pitch );
    
    CHECK_EQUAL( 4, orig->getPitch()->getStepValue() )
    CHECK_EQUAL( 3, cloned->getPitch()->getStepValue() )
}
TEST( getDuration, INote )
{
    auto pitchFactory = createPitchFactory( PitchFactoryType::StandardChromatic );
    auto durationFactory = createDurationFactory( DurationFactoryType::Standard );
    auto noteFactory = createNoteFactory( NoteFactoryType::Standard );
    
    auto pitch = pitchFactory->createPitch();
    
    pitch->setAlterValue( 1 );
    pitch->setStepValue( 2 );
    pitch->setOctaveValue( 2 );
    
    auto duration = durationFactory->createDuration( "Half", 0 );
    auto note = noteFactory->createNote( pitch, duration );
    auto copiedDuration = note->getDuration();
    CHECK( copiedDuration != nullptr )
    CHECK( copiedDuration.get() != duration.get() )
    CHECK( duration.get() != nullptr )
    CHECK_EQUAL( duration->getValue() , copiedDuration->getValue() )
}

TEST( isRest, INote )
{
    auto pitchFactory = createPitchFactory( PitchFactoryType::StandardChromatic );
    auto durationFactory = createDurationFactory( DurationFactoryType::Standard );
    auto noteFactory = createNoteFactory( NoteFactoryType::Standard );
    
    auto pitch = pitchFactory->createPitch();
    
    pitch->setAlterValue( 0 );
    pitch->setStepValue( 3 );
    pitch->setOctaveValue( 6 );
    
    auto duration = durationFactory->createDuration( "Half", 0 );
    auto note = noteFactory->createNote( pitch, duration );
    
    CHECK_EQUAL( 0, note->getPitch()->getAlterValue() )
    CHECK_EQUAL( 3, note->getPitch()->getStepValue() )
    CHECK_EQUAL( 6, note->getPitch()->getOctaveValue() )
    CHECK( ! note->getIsRest() )
    
    note->setIsRest( true );
    
    CHECK_EQUAL( 0, note->getPitch()->getAlterValue() )
    CHECK_EQUAL( 3, note->getPitch()->getStepValue() )
    CHECK_EQUAL( 6, note->getPitch()->getOctaveValue() )
    CHECK( note->getIsRest() )
    
    note->setIsRest( false );
    
    CHECK_EQUAL( 0, note->getPitch()->getAlterValue() )
    CHECK_EQUAL( 3, note->getPitch()->getStepValue() )
    CHECK_EQUAL( 6, note->getPitch()->getOctaveValue() )
    CHECK( ! note->getIsRest() )
}

TEST( toString, INote )
{
    auto pitchFactory = createPitchFactory( PitchFactoryType::StandardChromatic );
    auto durationFactory = createDurationFactory( DurationFactoryType::Standard );
    auto noteFactory = createNoteFactory( NoteFactoryType::Standard );
    
    auto pitch = pitchFactory->createPitch();
    
    pitch->setAlterValue( -1 );
    pitch->setStepValue( 1 );
    pitch->setOctaveValue( 5 );
    
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    
    tuplets.push_back( tupletFactory->createTupletDef( 5, 4, "Eighth" ) );
    tuplets.push_back( tupletFactory->createTupletDef( 3, 2, "Eighth" ) );
    
    auto duration = durationFactory->createDuration( tuplets, "Eighth", 1 );
    auto note = noteFactory->createNote( pitch, duration );
    
    String expected =
    "{ Db5 : Eighth.^( 5[Eighth]:4[Eighth] ( 3[Eighth]:2[Eighth] ) ) }";
    
    String actual = note->toString();
    
    CHECK_EQUAL( expected, actual )
}

TEST( toStream, INote )
{
    auto pitchFactory = createPitchFactory( PitchFactoryType::StandardChromatic );
    auto durationFactory = createDurationFactory( DurationFactoryType::Standard );
    auto noteFactory = createNoteFactory( NoteFactoryType::Standard );
    
    auto pitch = pitchFactory->createPitch();
    
    pitch->setAlterValue( 0 );
    pitch->setStepValue( 4 );
    pitch->setOctaveValue( 3 );
    
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    
    tuplets.push_back( tupletFactory->createTupletDef( 5, 4, "16th" ) );
    
    auto duration = durationFactory->createDuration( tuplets, "Quarter", 0 );
    auto note = noteFactory->createNote( pitch, duration );
    
    std::stringstream ss;
    note->toStream( ss );
    
    String expected = "{ G3 : Quarter^( 5[16th]:4[16th] ) }";
    String actual = ss.str();
    
    CHECK_EQUAL( expected, actual )
}

TEST( streamingOperator, INote )
{
    auto pitchFactory = createPitchFactory( PitchFactoryType::StandardChromatic );
    auto durationFactory = createDurationFactory( DurationFactoryType::Standard );
    auto noteFactory = createNoteFactory( NoteFactoryType::Standard );
    
    auto pitch = pitchFactory->createPitch();
    
    pitch->setAlterValue( 2 );
    pitch->setStepValue( 5 );
    pitch->setOctaveValue( 3 );
    
    auto tupletFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
    ITupletDefSPCs tuplets;
    
    tuplets.push_back( tupletFactory->createTupletDef( 1, 1, "16th" ) );
    
    auto duration = durationFactory->createDuration( tuplets, "32nd", 4 );
    auto note = noteFactory->createNote( pitch, duration );
    
    std::stringstream ss;
    ss << ( *note );
    
    String expected = "{ Ax3 : 32nd.... }";
    String actual = ss.str();
    
    CHECK_EQUAL( expected, actual )
}
