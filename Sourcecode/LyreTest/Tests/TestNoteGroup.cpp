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
    NoteGroup ngrp;
    CHECK( true );
}

TEST( createNoteGroup, NoteGroup )
{
    INoteGroupUP ngrp = createNoteGroup();
    CHECK( ngrp != nullptr );
}


TEST( clone, NoteGroup )
{
    Factories f;
    INoteGroupUP ngrp = createNoteGroup();
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.e2Sixteenth() );
    INoteGroupUP cloned = ngrp->clone();
    CHECK_EQUAL( 2, ngrp->getCount() )
    CHECK_EQUAL( 2, cloned->getCount() )
    CHECK( ngrp.get() != cloned.get() )
}

TEST( getIsEmpty_true, NoteGroup )
{
    INoteGroupUP ngrp = createNoteGroup();
    CHECK( ngrp->getIsEmpty() )
}

TEST( getIsEmpty_false, NoteGroup )
{
    Factories f;
    INoteGroupUP ngrp = createNoteGroup();
    ngrp->add( f.d4Eighth() );
    CHECK( ! ngrp->getIsEmpty() )
}

TEST( getCount_0, NoteGroup )
{
    INoteGroupUP ngrp = createNoteGroup();
    CHECK_EQUAL( 0, ngrp->getCount() )
}

TEST( getCount_1, NoteGroup )
{
    Factories f;
    INoteGroupUP ngrp = createNoteGroup();
    ngrp->add( f.d4Eighth() );
    CHECK_EQUAL( 1, ngrp->getCount() )
}

TEST( getCount_2, NoteGroup )
{
    Factories f;
    INoteGroupUP ngrp = createNoteGroup();
    ngrp->add( f.d4Eighth() );
    ngrp->add( f.e2Sixteenth() );
    CHECK_EQUAL( 2, ngrp->getCount() )
}

TEST( getDurationValue_0, NoteGroup )
{
    Factories f;
    INoteGroupUP ngrp = createNoteGroup();
    Rational expected{ 0, 1 };
    Rational actual = ngrp->getDurationValue();
    CHECK_EQUAL( expected, actual )
}

TEST( getDurationValue_Q, NoteGroup )
{
    Factories f;
    INoteGroupUP ngrp = createNoteGroup();
    ngrp->add( f.c4Quarter() );
    Rational expected{ 1, 1 };
    Rational actual = ngrp->getDurationValue();
    CHECK_EQUAL( expected, actual )
}

TEST( getDurationValue_QE, NoteGroup )
{
    Factories f;
    INoteGroupUP ngrp = createNoteGroup();
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.d4Eighth() );
    Rational expected{ 3, 2 };
    Rational actual = ngrp->getDurationValue();
    CHECK_EQUAL( expected, actual )
}

TEST( getDurationValue_QES, NoteGroup )
{
    Factories f;
    INoteGroupUP ngrp = createNoteGroup();
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.d4Eighth() );
    ngrp->add( f.e2Sixteenth() );
    Rational expected{ 7, 4 };
    Rational actual = ngrp->getDurationValue();
    CHECK_EQUAL( expected, actual )
}

TEST( getCurrent_exception, NoteGroup )
{
    Factories f;
    INoteGroupUP ngrp = createNoteGroup();
    bool isExceptionThrown = false;
    try
    {
        auto n = ngrp->getCurrent();
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
    INoteGroupUP ngrp = createNoteGroup();
    INoteSP expectedNote = f.e2Sixteenth();
    ngrp->add( expectedNote );
    INoteSPC actualNote = ngrp->getCurrent();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}

TEST( getNext_exception, NoteGroup )
{
    Factories f;
    INoteGroupUP ngrp = createNoteGroup();
    ngrp->add( f.e2Sixteenth() );
    bool isExceptionThrown = false;
    try
    {
        auto n = ngrp->getNext();
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
    INoteGroupUP ngrp = createNoteGroup();
    ngrp->add( f.d4Eighth() );
    INoteSP expectedNote = f.e2Sixteenth();
    ngrp->add( expectedNote );
    INoteSPC actualNote = ngrp->getNext();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}

TEST( getPrevious_exception, NoteGroup )
{
    Factories f;
    INoteGroupUP ngrp = createNoteGroup();
    ngrp->add( f.e2Sixteenth() );
    bool isExceptionThrown = false;
    try
    {
        auto n = ngrp->getPrevious();
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
    INoteGroupUP ngrp = createNoteGroup();
    INoteSP expectedNote = f.e2Sixteenth();
    ngrp->add( expectedNote );
    ngrp->add( f.d4Eighth() );
    ngrp->next();
    INoteSPC actualNote = ngrp->getPrevious();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}

TEST( first, NoteGroup )
{
    Factories f;
    INoteGroupUP ngrp = createNoteGroup();
    INoteSP expectedNote = f.e2Sixteenth();
    ngrp->add( expectedNote );
    ngrp->add( f.d4Eighth() );
    ngrp->next();
    ngrp->first();
    INoteSPC actualNote = ngrp->getCurrent();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}

TEST( last, NoteGroup )
{
    Factories f;
    INoteGroupUP ngrp = createNoteGroup();
    ngrp->add( f.d4Eighth() );
    ngrp->add( f.c4Quarter() );
    INoteSP expectedNote = f.e2Sixteenth();
    ngrp->add( expectedNote );
    ngrp->last();
    INoteSPC actualNote = ngrp->getCurrent();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}

TEST( next, NoteGroup )
{
    Factories f;
    INoteGroupUP ngrp = createNoteGroup();
    ngrp->add( f.d4Eighth() );
    ngrp->add( f.c4Quarter() );
    INoteSP expectedNote = f.e2Sixteenth();
    ngrp->add( expectedNote );
    INoteSPC actualNote = nullptr;
    do { actualNote = ngrp->getCurrent(); } while ( ngrp->next() );
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}

TEST( previous, NoteGroup )
{
    Factories f;
    INoteGroupUP ngrp = createNoteGroup();
    INoteSP expectedNote = f.e2Sixteenth();
    ngrp->add( expectedNote );ngrp->add( f.d4Eighth() );
    ngrp->add( f.c4Quarter() );
    INoteSPC actualNote = nullptr;
    ngrp->last();
    do { actualNote = ngrp->getCurrent(); } while ( ngrp->previous() );
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}

TEST( jump, NoteGroup )
{
    Factories f;
    INoteGroupUP ngrp = createNoteGroup();
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    INoteSP expectedNote = f.e2Sixteenth();
    ngrp->add( expectedNote );ngrp->add( f.d4Eighth() );
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->last();
    ngrp->jump( 3 );
    INoteSPC actualNote = ngrp->getCurrent();
    CHECK_EQUAL( expectedNote.get(), actualNote.get() )
    CHECK_EQUAL( expectedNote->toString(), actualNote->toString())
}

TEST( jump_exception, NoteGroup )
{
    Factories f;
    INoteGroupUP ngrp = createNoteGroup();
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->last();
    bool isExceptionThrown = false;
    try
    {
        ngrp->jump( 7 );
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
    INoteGroupUP ngrp = createNoteGroup();
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->last();
    bool isExceptionThrown = false;
    try
    {
        ngrp->jump( -1 );
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
    INoteGroupUP ngrp = createNoteGroup();
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    auto notAddedUP = f.c4Quarter();
    auto notAddedSP = toShared( notAddedUP );
    bool isExceptionThrown = false;
    try
    {
        ngrp->remove( notAddedSP );
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
    INoteGroupUP ngrp = createNoteGroup();
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    ngrp->add( f.c4Quarter() );
    auto noteToRemoveUP = f.c4Quarter();
    auto noteToRemoveSP = toShared( noteToRemoveUP );
    ngrp->add( noteToRemoveSP );
    CHECK_EQUAL( 6, ngrp->getCount() )
    ngrp->remove( noteToRemoveSP );
    CHECK_EQUAL( 5, ngrp->getCount() )
    ngrp->first();
    for (int i=0; i<ngrp->getCount(); ++i)
    {
        auto current = ngrp->getCurrent();
        CHECK( current.get() != noteToRemoveSP.get() )
        ngrp->next();
    }
}
