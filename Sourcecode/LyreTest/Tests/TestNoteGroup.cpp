//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
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
T_END

TEST( createNoteGroup, NoteGroup )
{
    INoteGroupUP noteGroup = createNoteGroup();
    CHECK( noteGroup != nullptr );
}
T_END

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
T_END

TEST( getIsEmpty_true, NoteGroup )
{
    INoteGroupUP noteGroup = createNoteGroup();
    CHECK( noteGroup->getIsEmpty() )
}
T_END

TEST( getIsEmpty_false, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.d4Eighth() );
    CHECK( ! noteGroup->getIsEmpty() )
}
T_END

TEST( getCount_0, NoteGroup )
{
    INoteGroupUP noteGroup = createNoteGroup();
    CHECK_EQUAL( 0, noteGroup->getCount() )
}
T_END

TEST( getCount_1, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.d4Eighth() );
    CHECK_EQUAL( 1, noteGroup->getCount() )
}
T_END

TEST( getCount_2, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.d4Eighth() );
    noteGroup->add( f.e2Sixteenth() );
    CHECK_EQUAL( 2, noteGroup->getCount() )
}
T_END

TEST( getTotalDuration_0, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    Rational expected{ 0, 1 };
    Rational actual = noteGroup->getTotalDuration();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTotalDuration_Q, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.c4Quarter() );
    Rational expected{ 1, 1 };
    Rational actual = noteGroup->getTotalDuration();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTotalDuration_QE, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.d4Eighth() );
    Rational expected{ 3, 2 };
    Rational actual = noteGroup->getTotalDuration();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTotalDuration_QES, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.d4Eighth() );
    noteGroup->add( f.e2Sixteenth() );
    Rational expected{ 7, 4 };
    Rational actual = noteGroup->getTotalDuration();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getCurrent_exception, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup{ new NoteGroup{} };
    bool isExceptionThrown = false;
    try
    {
        INoteUP n = noteGroup->getCurrent();
    }
    catch (...)
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( getCurrent, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    INoteUP expectedNote = f.e2Sixteenth();
    noteGroup->add( expectedNote );
    INoteUP actualNote = noteGroup->getCurrent();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}
T_END

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
T_END

TEST( getNext, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.d4Eighth() );
    INoteUP expectedNote = f.e2Sixteenth();
    noteGroup->add( expectedNote );
    INoteUP actualNote = noteGroup->getNext();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}
T_END

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
T_END

TEST( getPrevious, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    INoteUP expectedNote = f.e2Sixteenth();
    noteGroup->add( expectedNote );
    noteGroup->add( f.d4Eighth() );
    noteGroup->next();
    INoteUP actualNote = noteGroup->getPrevious();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}
T_END

TEST( first, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    INoteUP expectedNote = f.e2Sixteenth();
    noteGroup->add( expectedNote );
    noteGroup->add( f.d4Eighth() );
    noteGroup->next();
    noteGroup->first();
    INoteUP actualNote = noteGroup->getCurrent();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}
T_END

TEST( last, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.d4Eighth() );
    noteGroup->add( f.c4Quarter() );
    INoteUP expectedNote = f.e2Sixteenth();
    noteGroup->add( expectedNote );
    noteGroup->last();
    INoteUP actualNote = noteGroup->getCurrent();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}
T_END

TEST( next, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.d4Eighth() );
    noteGroup->add( f.c4Quarter() );
    INoteUP expectedNote = f.e2Sixteenth();
    noteGroup->add( expectedNote );
    INoteUP actualNote = nullptr;
    
    while ( noteGroup->next(), ! noteGroup->getIsEnd() )
    {
        actualNote = noteGroup->getCurrent();
    }
    
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}
T_END

TEST( previous, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    INoteUP expectedNote = f.e2Sixteenth();
    noteGroup->add( expectedNote );noteGroup->add( f.d4Eighth() );
    noteGroup->add( f.c4Quarter() );
    INoteUP actualNote = nullptr;
    noteGroup->last();
    do { actualNote = noteGroup->getCurrent(); } while ( noteGroup->previous() );
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}
T_END

TEST( jump, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    INoteUP expectedNote = f.e2Sixteenth();
    noteGroup->add( expectedNote );noteGroup->add( f.d4Eighth() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->last();
    noteGroup->jump( 3 );
    INoteUP actualNote = noteGroup->getCurrent();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}
T_END

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
T_END

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
T_END

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
T_END

TEST( remove, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup = createNoteGroup();
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.c4Quarter() );
    auto noteUP = f.c4Quarter();
    noteGroup->add( noteUP );
    CHECK_EQUAL( 6, noteGroup->getCount() )
    noteGroup->remove( 5 );
    CHECK_EQUAL( 5, noteGroup->getCount() )
    noteGroup->first();
    for (int i=0; i<noteGroup->getCount(); ++i)
    {
        auto current = noteGroup->getCurrent();
        CHECK( current.get() != noteUP.get() )
        noteGroup->next();
    }
}
T_END
