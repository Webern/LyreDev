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
        
        INoteUP f2Half()
        {
            pitch->setPitch( 40 );
            auto d = duration->createDuration( "16th" );
            return note->createNote( pitch->createPitch(), d );
        }
    };
    
    inline INoteGroupUP newNoteGroup() { return INoteGroupUP{ new NoteGroup{} }; }
    inline INoteGroupUP newNestedGroup1()
    {
        Factories f;
        auto noteGroup = newNoteGroup();
        auto subGroup = newNoteGroup();
        auto subSubGroup = newNoteGroup();
        subSubGroup->add( f.c4Quarter() );  // 1 / 1 ~ #2
        subSubGroup->add( f.f2Half() );     // 2 / 1 ~ #3
        subGroup->add( f.d4Eighth() );      // 1 / 2 ~ #1
        subGroup->addGroup( subSubGroup );
        subGroup->add( f.d4Eighth() );      // 1 / 2 ~ #4
        noteGroup->add( f.e2Sixteenth() );  // 1 / 4 ~ #0
        noteGroup->addGroup( subGroup );
        noteGroup->add( f.e2Sixteenth() );  // 1 / 4 ~ #5
        return std::move( noteGroup );
    }
    inline INoteGroupUP newNestedGroup2()
    {
        Factories f;
        auto noteGroup = newNoteGroup();
        auto subGroup = newNoteGroup();
        auto subSubGroup = newNoteGroup();
        subSubGroup->add( f.c4Quarter() );
        subSubGroup->add( f.f2Half() );
        subGroup->add( f.d4Eighth() );
        subGroup->addGroup( subSubGroup );
        noteGroup->add( f.e2Sixteenth() );
        noteGroup->addGroup( subGroup );
        noteGroup->add( f.e2Sixteenth() );
        return std::move( noteGroup );
    }
}

TEST( ctor, NoteGroup )
{
    NoteGroup noteGroup;
    CHECK_EQUAL( 0, noteGroup.getCount() )
}
T_END

TEST( copyCtor, NoteGroup )
{
    Factories f;
    NoteGroup noteGroup;
    noteGroup.add( f.e2Sixteenth() );
    NoteGroup copied{ noteGroup };
    CHECK_EQUAL( 1, noteGroup.getCount() )
    CHECK_EQUAL( 1, copied.getCount() )
}
T_END

TEST( moveCtor, NoteGroup )
{
    Factories f;
    NoteGroup noteGroup;
    noteGroup.add( f.e2Sixteenth() );
    NoteGroup copied{ std::move( noteGroup ) };
    CHECK_EQUAL( 1, copied.getCount() )
}
T_END

TEST( assignment, NoteGroup )
{
    Factories f;
    NoteGroup noteGroup;
    noteGroup.add( f.e2Sixteenth() );
    NoteGroup copied;
    copied = noteGroup;
    CHECK_EQUAL( 1, noteGroup.getCount() )
    CHECK_EQUAL( 1, copied.getCount() )
}
T_END

TEST( moveAssignment, NoteGroup )
{
    Factories f;
    NoteGroup noteGroup;
    noteGroup.add( f.e2Sixteenth() );
    NoteGroup copied;
    copied = std::move( noteGroup );
    CHECK_EQUAL( 1, copied.getCount() )
}
T_END

TEST( clone, NoteGroup )
{
    Factories f;
    INoteGroupUP noteGroup{ new NoteGroup{} };
    noteGroup->add( f.c4Quarter() );
    CHECK_EQUAL( 1, noteGroup->getCount() )
    INoteGroupUP cloned = noteGroup->clone();
    CHECK_EQUAL( 1, cloned->getCount() )
    CHECK( noteGroup.get() != cloned.get() )
}
T_END

TEST( copy, NoteGroup )
{
    Factories f;
    NoteGroupUP noteGroup{ new NoteGroup{} };
    noteGroup->add( f.c4Quarter() );
    CHECK_EQUAL( 1, noteGroup->getCount() )
    NoteGroupUP copied = noteGroup->copy();
    CHECK_EQUAL( 1, copied->getCount() )
    CHECK( noteGroup.get() != copied.get() )
}
T_END

TEST( toStream, NoteGroup )
{
    auto noteGroup = newNestedGroup1();
    std::stringstream ss;
    noteGroup->toStream( ss );
    String expected = "somenotes";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString, NoteGroup )
{
    auto noteGroup = newNestedGroup1();
    String expected = "somenotes";
    String actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamOperator, NoteGroup )
{
    auto noteGroup = newNestedGroup1();
    std::stringstream ss;
    ss << ( *noteGroup );
    String expected = "somenotes";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getIsEmpty_true, NoteGroup )
{
    auto noteGroup = newNoteGroup();
    CHECK( noteGroup->getIsEmpty() )
}
T_END

TEST( getIsEmpty_false, NoteGroup )
{
    auto noteGroup = newNestedGroup1();
    CHECK( ! noteGroup->getIsEmpty() )
}
T_END

TEST( getCount_0, NoteGroup )
{
    auto noteGroup = newNoteGroup();
    int expected = 0;
    int actual = noteGroup->getCount();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getCount_1, NoteGroup )
{
    Factories f;
    auto noteGroup = newNoteGroup();
    noteGroup->add( f.e2Sixteenth() );
    int expected = 1;
    int actual = noteGroup->getCount();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getCount_5_flat, NoteGroup )
{
    Factories f;
    auto noteGroup = newNoteGroup();
    noteGroup->add( f.e2Sixteenth() );
    noteGroup->add( f.f2Half() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.d4Eighth() );
    noteGroup->add( f.e2Sixteenth() );
    int expected = 5;
    int actual = noteGroup->getCount();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getCount_5_nested, NoteGroup )
{
    auto noteGroup = newNestedGroup2();
    int expected = 5;
    int actual = noteGroup->getCount();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTotalDuration_0, NoteGroup )
{
    auto noteGroup = newNoteGroup();
    Rational expected{ 0, 1 };
    Rational actual = noteGroup->getTotalDuration();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTotalDuration_4Q, NoteGroup )
{
    Factories f;
    auto noteGroup = newNoteGroup();
    noteGroup->add( f.e2Sixteenth() );
    noteGroup->add( f.f2Half() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.d4Eighth() );
    noteGroup->add( f.e2Sixteenth() );
    Rational expected{ 4, 1 };
    Rational actual = noteGroup->getTotalDuration();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTotalDuration_3E, NoteGroup )
{
    auto noteGroup = newNestedGroup1();
    Rational expected{ 9, 2 };
    Rational actual = noteGroup->getTotalDuration();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getNote_throwEmpty, NoteGroup )
{
    auto noteGroup = newNoteGroup();
    bool isExceptionThrown = false;
    try
    {
        auto n = noteGroup->getNote( 0 );
        CHECK_FAIL( "exception was expected but not thrown" )
        n->setIsRest( true );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown );
}
T_END

TEST( getNote_throwOutOfRange, NoteGroup )
{
    auto noteGroup = newNestedGroup2();
    bool isExceptionThrown = false;
    try
    {
        auto n = noteGroup->getNote( 7 );
        CHECK_FAIL( "exception was expected but not thrown" )
        n->setIsRest( true );
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown );
}
T_END

TEST( getNote_flat, NoteGroup )
{
    Factories f;
    auto noteGroup = newNoteGroup();
    noteGroup->add( f.e2Sixteenth() );  // 0
    noteGroup->add( f.f2Half() );       // 1
    noteGroup->add( f.c4Quarter() );    // 2
    noteGroup->add( f.d4Eighth() );     // 3
    noteGroup->add( f.e2Sixteenth() );  // 4
    String expected = "D2, Sixteenth";
    String actual = noteGroup->getNote( 3 )->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getNote_nested, NoteGroup )
{
    auto noteGroup = newNestedGroup1();
    String expected = "F2, Half";
    String actual = noteGroup->getNote( 3 )->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( add_throwNull, NoteGroup )
{
    auto noteGroup = newNoteGroup();
    INoteUP nullnote{ nullptr };
    bool isExceptionThrown = false;
    try
    {
        noteGroup->add( nullnote );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown );
}
T_END

TEST( add, NoteGroup )
{
    Factories f;
    auto noteGroup = newNoteGroup();
    noteGroup->add( f.e2Sixteenth() );
    int expected = 1;
    int actual = noteGroup->getCount();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( remove_throwEmpty, NoteGroup )
{
    auto noteGroup = newNoteGroup();
    bool isExceptionThrown = false;
    try
    {
        noteGroup->remove( 0 );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown );
}
T_END

TEST( remove_throwOutOfRange, NoteGroup )
{
    auto noteGroup = newNestedGroup1();
    bool isExceptionThrown = false;
    try
    {
        noteGroup->remove( 7 );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown );
}
T_END

TEST( remove_flat, NoteGroup )
{
    Factories f;
    auto noteGroup = newNoteGroup();
    noteGroup->add( f.e2Sixteenth() );
    noteGroup->add( f.f2Half() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.d4Eighth() );
    noteGroup->add( f.e2Sixteenth() );
    
    CHECK_EQUAL( 5, noteGroup->getCount() )
    
    noteGroup->remove( 2 );
    
    CHECK_EQUAL( 5, noteGroup->getCount() )
    
    String expected = "D4, Eighth";
    String actual = noteGroup->getNote( 2 )->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( remove_nested, NoteGroup )
{
    Factories f;
    auto noteGroup = newNestedGroup1();
    
    CHECK_EQUAL( 6, noteGroup->getCount() )
    
    noteGroup->remove( 3 );
    
    CHECK_EQUAL( 5, noteGroup->getCount() )
    
    String expected = "D4, Eighth";
    String actual = noteGroup->getNote( 3 )->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getGroupCount_0, NoteGroup )
{
    Factories f;
    auto noteGroup = newNoteGroup();
    noteGroup->add( f.e2Sixteenth() );
    noteGroup->add( f.f2Half() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.d4Eighth() );
    noteGroup->add( f.e2Sixteenth() );
    CHECK_EQUAL( 0, noteGroup->getGroupCount() )
}
T_END

TEST( getGroupCount_3, NoteGroup )
{
    Factories f;
    auto noteGroup = newNestedGroup1();
    auto thirdNested = newNoteGroup();
    thirdNested->add( f.c4Quarter() );
    noteGroup->addGroup( thirdNested );
    CHECK_EQUAL( 3, noteGroup->getGroupCount() )
}
T_END

TEST( getIsInGroup_throwEmpty, NoteGroup )
{
    auto noteGroup = newNoteGroup();
    bool isExceptionThrown = false;
    try
    {
        bool b = noteGroup->getIsInGroup( 0 );
        CHECK_FAIL( "exception was expected but not thrown" )
        if ( b ) { std::cout << "unreachable" << std::endl; }
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown );
}
T_END

TEST( getIsInGroup_throwOutOfRange, NoteGroup )
{
    auto noteGroup = newNestedGroup2();
    bool isExceptionThrown = false;
    try
    {
        bool b = noteGroup->getIsInGroup( 7 );
        CHECK_FAIL( "exception was expected but not thrown" )
        if ( b ) { std::cout << "unreachable" << std::endl; }
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown );
}
T_END

TEST( getIsInGroup_true, NoteGroup )
{
    auto noteGroup = newNestedGroup2();
    CHECK( noteGroup->getIsInGroup( 3 ) )
}
T_END

TEST( getIsInGroup_false, NoteGroup )
{
    auto noteGroup = newNestedGroup2();
    CHECK( ! noteGroup->getIsInGroup( 0 ) )
}
T_END

TEST( getGroupIndex_throwEmpty, NoteGroup )
{
    auto noteGroup = newNoteGroup();
    bool isExceptionThrown = false;
    try
    {
        int x = noteGroup->getGroupIndex( 0 );
        CHECK_FAIL( "exception was expected but not thrown" )
        if ( x > 0 ) { std::cout << "unreachable" << std::endl; }
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown );
}
T_END

TEST( getGroupIndex_throwOutOfRange, NoteGroup )
{
    auto noteGroup = newNestedGroup2();
    bool isExceptionThrown = false;
    try
    {
        int x = noteGroup->getGroupIndex( -1 );
        CHECK_FAIL( "exception was expected but not thrown" )
        if ( x > 0 ) { std::cout << "unreachable" << std::endl; }
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown );
}
T_END

TEST( getGroupIndex_Neg1, NoteGroup )
{
    auto noteGroup = newNestedGroup1();
    CHECK_EQUAL( -1, noteGroup->getGroupIndex( 0 ) )
}
T_END

TEST( getGroupIndex_0, NoteGroup )
{
    auto noteGroup = newNestedGroup1();
    CHECK_EQUAL( 0, noteGroup->getGroupIndex( 3 ) )
}
T_END

TEST( getGroupIndex_2_nested, NoteGroup )
{
    Factories f;
    auto noteGroup = newNestedGroup1();
    auto additionalNested = newNoteGroup();
    additionalNested->add( f.c4Quarter() );
    noteGroup->addGroup( additionalNested );
    noteGroup->addGroup( additionalNested );
    CHECK_EQUAL( 3, noteGroup->getGroupIndex( 7 ) )
}
T_END

TEST( getGroup_throwNoGroups, NoteGroup )
{
    Factories f;
    auto noteGroup = newNoteGroup();
    noteGroup->add( f.e2Sixteenth() );
    noteGroup->add( f.f2Half() );
    noteGroup->add( f.c4Quarter() );
    noteGroup->add( f.d4Eighth() );
    noteGroup->add( f.e2Sixteenth() );
    bool isExceptionThrown = false;
    try
    {
        auto x = noteGroup->getGroup( 0 );
        CHECK_FAIL( "exception was expected but not thrown" )
        if ( x > 0 ) { std::cout << "unreachable" << std::endl; }
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown );
}
T_END

TEST( getGroup_throwOutOfRange, NoteGroup )
{
    auto noteGroup = newNestedGroup1();
    bool isExceptionThrown = false;
    try
    {
        auto x = noteGroup->getGroup( 2 );
        CHECK_FAIL( "exception was expected but not thrown" )
        if ( x > 0 ) { std::cout << "unreachable" << std::endl; }
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown );
}
T_END

TEST( getGroup_0, NoteGroup )
{
    auto noteGroup = newNestedGroup1();
    auto subGroup = noteGroup->getGroup( 0 );
    auto firstSubGroupNote = subGroup->getNote( 0 );
    String expected = "D4, Eighth";
    String actual = firstSubGroupNote->toString();
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( 4, subGroup->getCount() )
}
T_END

TEST( getGroup_2, NoteGroup )
{
    Factories f;
    auto noteGroup = newNestedGroup1();
    auto addedGroup1 = newNoteGroup();
    addedGroup1->add( f.c4Quarter() );
    noteGroup->addGroup( addedGroup1 );
    auto addedGroup2 = newNoteGroup();
    addedGroup2->add( f.e2Sixteenth() );
    noteGroup->addGroup( addedGroup2 );
    auto index2Group = noteGroup->getGroup( 2 );
    auto firstNote = index2Group->getNote( 0 );
    String expected = "E2, Sixteenth";
    String actual = firstNote->toString();
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( 1, index2Group->getCount() )
}
T_END

TEST( addGroup_throwNull, NoteGroup )
{
    INoteGroupUP noteGroup = newNestedGroup2();
    INoteGroupUP nullgroup{ nullptr };
    bool isExceptionThrown = false;
    try
    {
        noteGroup->addGroup( nullgroup );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown );
}
T_END

TEST( addGroup, NoteGroup )
{
    Factories f;
    auto noteGroup = newNestedGroup1();
    auto addedGroup1 = newNoteGroup();
    addedGroup1->add( f.c4Quarter() );
    noteGroup->addGroup( addedGroup1 );
    auto addedGroup2 = newNoteGroup();
    addedGroup2->add( f.e2Sixteenth() );
    noteGroup->addGroup( addedGroup2 );
    CHECK_EQUAL( 3, noteGroup->getCount() )
}
T_END

TEST( removeGroup_throwOutOfRange, NoteGroup )
{
    auto noteGroup = newNestedGroup1();
    bool isExceptionThrown = false;
    try
    {
        noteGroup->remove( 1 );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown );
}
T_END

TEST( removeGroup_2, NoteGroup )
{
    Factories f;
    auto noteGroup = newNestedGroup1();
    auto addedGroup1 = newNoteGroup();
    addedGroup1->add( f.c4Quarter() );
    noteGroup->addGroup( addedGroup1 );
    auto addedGroup2 = newNoteGroup();
    addedGroup2->add( f.e2Sixteenth() );
    noteGroup->addGroup( addedGroup2 );
    CHECK_EQUAL( 6, noteGroup->getCount() )
    noteGroup->removeGroup( 1 );
    auto returnedGroup = noteGroup->getGroup( 1 );
    String expected = "C4, Quarter";
    String actual = returnedGroup->getNote( 0 )->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( removeGroup_0, NoteGroup )
{
    Factories f;
    auto noteGroup = newNestedGroup1();
    auto addedGroup1 = newNoteGroup();
    addedGroup1->add( f.c4Quarter() );
    noteGroup->addGroup( addedGroup1 );
    auto addedGroup2 = newNoteGroup();
    addedGroup2->add( f.e2Sixteenth() );
    noteGroup->addGroup( addedGroup2 );
    CHECK_EQUAL( 8, noteGroup->getCount() )
    noteGroup->removeGroup( 0 );
    CHECK_EQUAL( 2, noteGroup->getCount() )
    auto returnedGroup = noteGroup->getGroup( 0 );
    String expected = "C4, Quarter";
    String actual = returnedGroup->getNote( 0 )->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( removingAllNotesRemovesGroup, NoteGroup )
{
    Factories f;
    auto noteGroup = newNestedGroup1();
    auto addedGroup1 = newNoteGroup();
    addedGroup1->add( f.c4Quarter() );
    noteGroup->addGroup( addedGroup1 );
    auto addedGroup2 = newNoteGroup();
    addedGroup2->add( f.e2Sixteenth() );
    noteGroup->addGroup( addedGroup2 );
    CHECK_EQUAL( 3, noteGroup->getGroupCount() )
    noteGroup->remove( 0 );
    noteGroup->remove( 0 );
    noteGroup->remove( 0 );
    noteGroup->remove( 0 );
    noteGroup->remove( 0 );
    noteGroup->remove( 0 );
    CHECK_EQUAL( 2, noteGroup->getGroupCount() )
    noteGroup->remove( 0 );
    CHECK_EQUAL( 1, noteGroup->getGroupCount() )
    noteGroup->remove( 0 );
    CHECK_EQUAL( 0, noteGroup->getGroupCount() )
}
T_END
