//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "LyreTest/Mock/MockNoteGroup.h"
#include "Lyre/NoteGroup.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IPitchFactory.h"
#include "Lyre/INoteFactory.h"
#include "Lyre/toShared.h"


using namespace Lyre;
using namespace std;

namespace
{
    struct Factories
    {
        IPitchFactoryUP pitch;
        IDurationFactoryUP duration;
        INoteFactoryUP note;
        Factories()
        :pitch( createPitchFactory( PitchFactoryType::StandardChromatic ) )
        ,duration( createDurationFactory( DurationFactoryType::Standard ) )
        ,note( createNoteFactory( NoteFactoryType::Standard ) )
        {}
        INoteUP c4Quarter()
        {
            pitch->setPitch( 60 );
            auto d = duration->createDuration( "Quarter" );
            return note->createNote( pitch->createPitch(), d );
        }
        INoteUP d4Eighth()
        {
            pitch->setPitch( 62 );
            auto d = duration->createDuration( "Eighth" );
            return note->createNote( pitch->createPitch(), d );
        }
        INoteUP e2Sixteenth()
        {
            pitch->setPitch( 40 );
            auto d = duration->createDuration( "16th" );
            return note->createNote( pitch->createPitch(), d );
        }
    };
}

TEST( Constructor, NoteGroup )
{
    NoteGroup noteGroup;
    CHECK( true );
}

TEST( createNoteGroup, NoteGroup )
{
    INoteGroupUP noteGroup = createNoteGroup();
    CHECK( noteGroup != nullptr );
}


TEST( clone, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.e2Sixteenth() );
    INoteGroupUP cloned = noteGroup->clone();
    CHECK_EQUAL( 2, noteGroup->getCount() )
    CHECK_EQUAL( 2, cloned->getCount() )
    CHECK( noteGroup.get() != cloned.get() )
}

TEST( getIsEmpty_true, NoteGroup )
{
    INoteGroupUP noteGroup = createNoteGroup();
    CHECK( noteGroup->getIsEmpty() )
}

TEST( getIsEmpty_false, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.d4Eighth() );
    CHECK( ! noteGroup->getIsEmpty() )
}

TEST( getCount_0, NoteGroup )
{
    INoteGroupUP noteGroup = createNoteGroup();
    CHECK_EQUAL( 0, noteGroup->getCount() )
}

TEST( getCount_1, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.d4Eighth() );
    CHECK_EQUAL( 1, noteGroup->getCount() )
}

TEST( getCount_2, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.d4Eighth() );
    noteGroup->add( f.e2Sixteenth() );
    CHECK_EQUAL( 2, noteGroup->getCount() )
}

TEST( getDurationValue_0, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    Rational expected{ 0, 1 };
    Rational actual = noteGroup->getDurationValue();
    CHECK_EQUAL( expected, actual )
}

TEST( getDurationValue_Q, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.c4Quarter() );
    Rational expected{ 1, 1 };
    Rational actual = noteGroup->getDurationValue();
    CHECK_EQUAL( expected, actual )
}

TEST( getDurationValue_QE, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.d4Eighth() );
    Rational expected{ 3, 2 };
    Rational actual = noteGroup->getDurationValue();
    CHECK_EQUAL( expected, actual )
}

TEST( getDurationValue_QES, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.d4Eighth() );
    noteGroup->add( f.e2Sixteenth() );
    Rational expected{ 7, 4 };
    Rational actual = noteGroup->getDurationValue();
    CHECK_EQUAL( expected, actual )
}

TEST( getCurrent_exception, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    bool isExceptionThrown = false;
    try
    {
        auto n = noteGroup->getCurrent();
    }
    catch (...)
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}

TEST( getCurrent, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    INoteSP expectedNote = f.e2Sixteenth();
    noteGroup->add( expectedNote );
    INoteSPC actualNote = noteGroup->getCurrent();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}

TEST( getNext_exception, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.e2Sixteenth() );
    bool isExceptionThrown = false;
    try
    {
        auto n = noteGroup->getNext();
    }
    catch (...)
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}

TEST( getNext, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.d4Eighth() );
    INoteSP expectedNote = f.e2Sixteenth();
    noteGroup->add( expectedNote );
    INoteSPC actualNote = noteGroup->getNext();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}

TEST( getPrevious_exception, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.e2Sixteenth() );
    bool isExceptionThrown = false;
    try
    {
        auto n = noteGroup->getPrevious();
    }
    catch (...)
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}

TEST( getPrevious, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    INoteSP expectedNote = f.e2Sixteenth();
    noteGroup->add( expectedNote );
    noteGroup->add( f.d4Eighth() );
    noteGroup->next();
    INoteSPC actualNote = noteGroup->getPrevious();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}

TEST( first, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    INoteSP expectedNote = f.e2Sixteenth();
    noteGroup->add( expectedNote );
    noteGroup->add( f.d4Eighth() );
    noteGroup->next();
    noteGroup->first();
    INoteSPC actualNote = noteGroup->getCurrent();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}

TEST( last, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.d4Eighth() );
    noteGroup->add( f.c4Quarter() );
    INoteSP expectedNote = f.e2Sixteenth();
    noteGroup->add( expectedNote );
    noteGroup->last();
    INoteSPC actualNote = noteGroup->getCurrent();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}

TEST( next, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.d4Eighth() );
    noteGroup->add( f.c4Quarter() );
    INoteSP expectedNote = f.e2Sixteenth();
    noteGroup->add( expectedNote );
    INoteSPC actualNote = nullptr;
    
    while ( noteGroup->next(), ! noteGroup->getIsEnd() )
    {
        actualNote = noteGroup->getCurrent();
    }
    
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}

TEST( previous, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    INoteSP expectedNote = f.e2Sixteenth();
    noteGroup->add( expectedNote );noteGroup->add( f.d4Eighth() );
    noteGroup->add( f.c4Quarter() );
    INoteSPC actualNote = nullptr;
    noteGroup->last();
    do { actualNote = noteGroup->getCurrent(); } while ( noteGroup->previous() );
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}

TEST( jump, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    INoteSP expectedNote = f.e2Sixteenth();
    noteGroup->add( expectedNote );noteGroup->add( f.d4Eighth() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->last();
    noteGroup->jump( 3 );
    INoteSPC actualNote = noteGroup->getCurrent();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}

TEST( jump_exception, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->last();
    bool isExceptionThrown = false;
    try
    {
        noteGroup->jump( 7 );
    }
    catch (...)
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}

TEST( jump_exception_negative, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->last();
    bool isExceptionThrown = false;
    try
    {
        noteGroup->jump( -1 );
    }
    catch (...)
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}

TEST( remove_exception, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    auto notAddedUP = f.c4Quarter();
    auto notAddedSP = toShared( notAddedUP );
    bool isExceptionThrown = false;
    try
    {
        noteGroup->remove( 99 );
    }
    catch (...)
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}

TEST( remove, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    auto noteToRemoveUP = f.c4Quarter();
    auto noteToRemoveSP = toShared( noteToRemoveUP );
    noteGroup->add( noteToRemoveSP );
    CHECK_EQUAL( 6, noteGroup->getCount() )
    noteGroup->remove( 5 );
    CHECK_EQUAL( 5, noteGroup->getCount() )
    noteGroup->first();
    for (int i=0; i<noteGroup->getCount(); ++i)
    {
        auto current = noteGroup->getCurrent();
        CHECK( current.get() != noteToRemoveSP.get() )
        noteGroup->next();
    }
}
