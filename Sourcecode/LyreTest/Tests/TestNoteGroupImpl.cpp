//PRIVATE
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Private/NoteGroupImpl.h"
#include "Lyre/INote.h"
#include "Lyre/INoteFactory.h"
#include "Lyre/IPitch.h"
#include "Lyre/IDuration.h"
#include "Lyre/IDurationFactory.cpp"
#include "Lyre/Private/PitchFactory.h"

#include <sstream>

using namespace Lyre;
using namespace Lyre::Private;
using namespace std;

namespace
{
    auto noteFac = createNoteFactory( NoteFactoryType::Standard );
    auto pitchFac = createPitchFactory( PitchFactoryType::StandardChromatic );
    auto durFac = createDurationFactory( DurationFactoryType::Standard );
}

TEST( DefaultCtor, NoteGroupImpl )
{
    NoteGroupImpl notes;
    CHECK( notes.getType() == NoteGroupImpl::Type::Undecided )
    CHECK( notes.getCount() == 0 )
}
T_END

TEST( getType, NoteGroupImpl )
{
    NoteGroupImpl notes;
    auto pitch = pitchFac->createPitch();
    auto dur = durFac->createDuration( "16th" );
    notes.setNote( noteFac->createNote( pitch, dur ) );
    CHECK( notes.getType() == NoteGroupImpl::Type::Leaf )
    CHECK( notes.getCount() == 0 )
}
T_END

TEST( getCount, NoteGroupImpl )
{
    NoteGroupImpl notes;
    std::unique_ptr<NoteGroupImpl> note1{ new NoteGroupImpl{} };
    std::unique_ptr<NoteGroupImpl> note2{ new NoteGroupImpl{} };
    std::unique_ptr<NoteGroupImpl> note3{ new NoteGroupImpl{} };
    
    auto pitch = pitchFac->createPitch();
    auto dur = durFac->createDuration( "16th" );
    
    note1->setNote( noteFac->createNote( pitch, dur ) );
    note2->setNote( noteFac->createNote( pitch, dur ) );
    note3->setNote( noteFac->createNote( pitch, dur ) );
    
    notes.addChild( note1 );
    notes.addChild( note2 );
    notes.addChild( note3 );
    
    
    CHECK( notes.getType() == NoteGroupImpl::Type::Parent )
    CHECK_EQUAL( notes.getCount(), 3 )
}
T_END

TEST( setNote_throw, NoteGroupImpl )
{
    NoteGroupImpl notes;
    std::unique_ptr<NoteGroupImpl> note1{ new NoteGroupImpl{} };
    auto pitch = pitchFac->createPitch();
    auto dur = durFac->createDuration( "16th" );
    note1->setNote( noteFac->createNote( pitch, dur ) );
    notes.addChild( note1 );
    
    bool isExceptionThrown = false;
    try
    {
        notes.setNote( noteFac->createNote( pitch , dur) );
    }
    catch ( std::runtime_error )
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( getChild_0, NoteGroupImpl )
{
    NoteGroupImpl notes;
    std::unique_ptr<NoteGroupImpl> note1{ new NoteGroupImpl{} };
    std::unique_ptr<NoteGroupImpl> note2{ new NoteGroupImpl{} };
    std::unique_ptr<NoteGroupImpl> note3{ new NoteGroupImpl{} };
    
    pitchFac->setPitch( 31 ); // G
    auto pitch = pitchFac->createPitch();
    auto dur = durFac->createDuration( "16th" );
    note1->setNote( noteFac->createNote( pitch, dur ) );
    
    pitchFac->setPitch( 32 ); // Ab
    pitch = pitchFac->createPitch();
    dur = durFac->createDuration( "Eighth" );
    note2->setNote( noteFac->createNote( pitch, dur ) );
    
    pitchFac->setPitch( 33 ); // A
    pitch = pitchFac->createPitch();
    dur = durFac->createDuration( "Quarter" );
    note3->setNote( noteFac->createNote( pitch, dur ) );
    
    notes.addChild( note1 );
    notes.addChild( note2 );
    notes.addChild( note3 );
    
    CHECK_EQUAL( "G1", notes.getChild( 0 )->getNote()->getPitch()->toString() )
    CHECK_EQUAL( "Ab1", notes.getChild( 1 )->getNote()->getPitch()->toString() )
    CHECK_EQUAL( "A1", notes.getChild( 2 )->getNote()->getPitch()->toString() )
}
T_END
