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

namespace
{
    NoteGroupImpl createNoteGroupImpl()
    {
        NoteGroupImpl notes;
        std::unique_ptr<NoteGroupImpl> note0{ new NoteGroupImpl{} };
        std::unique_ptr<NoteGroupImpl> note1{ new NoteGroupImpl{} };
        std::unique_ptr<NoteGroupImpl> group2{ new NoteGroupImpl{} };
        std::unique_ptr<NoteGroupImpl> note3{ new NoteGroupImpl{} };
        std::unique_ptr<NoteGroupImpl> child4{ new NoteGroupImpl{} };
        std::unique_ptr<NoteGroupImpl> child5{ new NoteGroupImpl{} };
        std::unique_ptr<NoteGroupImpl> child6{ new NoteGroupImpl{} };
        
        pitchFac->setPitch( 30 ); // F#
        auto pitch = pitchFac->createPitch();
        auto dur = durFac->createDuration( "16th" );
        note0->setNote( noteFac->createNote( pitch, dur ) );
        
        pitchFac->setPitch( 31 ); // G
        pitch = pitchFac->createPitch();
        dur = durFac->createDuration( "Eighth" );
        note1->setNote( noteFac->createNote( pitch, dur ) );
        
        pitchFac->setPitch( 33 ); // A
        pitch = pitchFac->createPitch();
        dur = durFac->createDuration( "Quarter" );
        note3->setNote( noteFac->createNote( pitch, dur ) );
        
        pitchFac->setPitch( 34 ); // Bb
        pitch = pitchFac->createPitch();
        dur = durFac->createDuration( "Half" );
        child4->setNote( noteFac->createNote( pitch, dur ) );
        
        pitchFac->setPitch( 35 ); // B
        pitch = pitchFac->createPitch();
        dur = durFac->createDuration( "Whole" );
        child5->setNote( noteFac->createNote( pitch, dur ) );
        
        pitchFac->setPitch( 36 ); // C
        pitch = pitchFac->createPitch();
        dur = durFac->createDuration( "Breve" );
        child6->setNote( noteFac->createNote( pitch, dur ) );
        
        group2->addChild( child4 );
        group2->addChild( child5 );
        group2->addChild( child6 );
        
        notes.addChild( note0 );
        notes.addChild( note1 );
        notes.addChild( group2 );
        notes.addChild( note3 );
        
        return std::move( notes );
    }
}

TEST( getChild, NoteGroupImpl )
{
    NoteGroupImpl notes = createNoteGroupImpl();
    
    String expected = "{ F#1 : 16th }";
    auto actualNoteGroupImpl = notes.getChild( 0 );
    auto actualNote = actualNoteGroupImpl->getNote();
    String actual = actualNote->toString();
    CHECK_EQUAL( expected, actual )
    
    expected = "{ G1 : Eighth }";
    actualNoteGroupImpl = notes.getChild( 1 );
    actualNote = actualNoteGroupImpl->getNote();
    actual = actualNote->toString();
    CHECK_EQUAL( expected, actual )
    
    expected = "{ Bb1 : Half }";
    actualNoteGroupImpl = notes.getChild( 2 );
    auto actualChild = actualNoteGroupImpl->getChild( 0 );
    actualNote = actualChild->getNote();
    actual = actualNote->toString();
    CHECK_EQUAL( expected, actual )
    
    expected = "{ B1 : Whole }";
    actualNoteGroupImpl = notes.getChild( 2 );
    actualChild = actualNoteGroupImpl->getChild( 1 );
    actualNote = actualChild->getNote();
    actual = actualNote->toString();
    CHECK_EQUAL( expected, actual )
    
    expected = "{ C2 : Breve }";
    actualNoteGroupImpl = notes.getChild( 2 );
    actualChild = actualNoteGroupImpl->getChild( 2 );
    actualNote = actualChild->getNote();
    actual = actualNote->toString();
    CHECK_EQUAL( expected, actual )
    
    expected = "{ A1 : Quarter }";
    actualNoteGroupImpl = notes.getChild( 3 );
    actualNote = actualNoteGroupImpl->getNote();
    actual = actualNote->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( addChild, NoteGroupImpl )
{
    NoteGroupImpl notes = createNoteGroupImpl();
    
    pitchFac->setPitch( 99 );
    auto pitch = pitchFac->createPitch();
    auto dur = durFac->createDuration( "16th" );
    auto child = NoteGroupImplUP{ new NoteGroupImpl{} };
    child->setNote( noteFac->createNote( pitch, dur ) );
    notes.addChild( child );
    
    String expected = "{ Eb7 : 16th }";
    auto actualNoteGroupImpl = notes.getChild( 4 );
    auto actualNote = actualNoteGroupImpl->getNote();
    String actual = actualNote->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( removeChild, NoteGroupImpl )
{
    NoteGroupImpl notes = createNoteGroupImpl();
    
    CHECK_EQUAL( 4, notes.getCount() )
    
    notes.removeChild( 2 );
    
    CHECK_EQUAL( 3, notes.getCount() )
    
    String expected = "{ F#1 : 16th }";
    auto actualNoteGroupImpl = notes.getChild( 0 );
    auto actualNote = actualNoteGroupImpl->getNote();
    String actual = actualNote->toString();
    CHECK_EQUAL( expected, actual )
    
    expected = "{ G1 : Eighth }";
    actualNoteGroupImpl = notes.getChild( 1 );
    actualNote = actualNoteGroupImpl->getNote();
    actual = actualNote->toString();
    CHECK_EQUAL( expected, actual )
    
    expected = "{ A1 : Quarter }";
    actualNoteGroupImpl = notes.getChild( 2 );
    actualNote = actualNoteGroupImpl->getNote();
    actual = actualNote->toString();
    CHECK_EQUAL( expected, actual )
}
T_END
