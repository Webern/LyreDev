//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "LyreTest/Mock/MockNoteGroup.h"
//#include "Lyre/INoteGroup.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IPitchFactory.h"
#include "Lyre/INoteFactory.h"
#include "Lyre/toShared.h"

#if 1==0

using namespace Lyre;
using namespace std;

TEST( Compiles, INoteGroup )
{
    auto durFactory = createDurationFactory( DurationFactoryType::Standard );
    auto pitchFactory = createPitchFactory( PitchFactoryType::StandardChromatic );
    auto noteFactory = createNoteFactory( NoteFactoryType::Standard );
    
    MockNoteGroup ng;
    
    auto n = noteFactory->createNote(
         pitchFactory->createPitch(),
         durFactory->createDuration( "Quarter" ) );
    
    auto ns = toShared( n );
    
    ng.add( ns );
    
    pitchFactory->next();
    
    n = noteFactory->createNote(
        pitchFactory->createPitch(),
        durFactory->createDuration( "Eighth" ) );
    
    ns = toShared( n );
    
    ng.add( ns );
    
    CHECK_EQUAL( 2, ng.getCount() )
    
}

#endif