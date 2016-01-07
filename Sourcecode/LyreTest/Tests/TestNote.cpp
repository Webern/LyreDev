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

TEST( Compiles, INote )
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
    
    tuplets.push_back( tupletFactory->createTupletDef( 3, 2, "Eighth" ) );
    
    auto duration = durationFactory->createDuration( tuplets, "Eighth", 1 );
    auto note = noteFactory->createNote( pitch, duration );
    
    CHECK_EQUAL( "", note->toString() )
}
