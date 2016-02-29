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
            pitch->setPitch( 41 );
            auto d = duration->createDuration( "Half" );
            return note->createNote( pitch->createPitch(), d );
        }
        
        inline INoteUP makeNote( int pitchValue, const String& durValue )
        {
            pitch->setPitch( pitchValue );
            return note->createNote( pitch->createPitch(),
                duration->createDuration( durValue ) );
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
    inline String newNestedGroup1String()
    {
        std::stringstream ss;
        ss << "{ E2 : 16th }" <<std::endl;
        ss << "{ D4 : Eighth }" <<std::endl;
        ss << "{ C4 : Quarter }" <<std::endl;
        ss << "{ F2 : Half }" <<std::endl;
        ss << "{ D4 : Eighth }" <<std::endl;
        ss << "{ E2 : 16th }" <<std::endl;
        return ss.str();
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
    
    inline int cVal( const int octave )
    {
        int twelve = 12;
        return ( twelve ) + ( twelve * octave );
    }
    inline INoteGroupUP newNestedGroup3()
    {
        Factories f;
        auto mainNoteGroup = newNoteGroup();
        auto sub1 = newNoteGroup();
        auto sub2 = newNoteGroup();
        auto sub3 = newNoteGroup();
        auto sub4 = newNoteGroup();
        auto sub5 = newNoteGroup();
        auto sub6 = newNoteGroup();
        auto sub7 = newNoteGroup();
        
        String dur = "Quarter";
        
        mainNoteGroup->add( f.makeNote( cVal( 0 ), dur ) );
        sub2->add( f.makeNote( cVal( 1 ), dur ) );
        sub2->add( f.makeNote( cVal( 2 ), dur ) );
        sub2->add( f.makeNote( cVal( 3 ), dur ) );
        mainNoteGroup->addGroup( sub2 );
        
        sub3->add( f.makeNote( cVal( 5 ), dur ) );
        sub4->add( f.makeNote( cVal( 6 ), dur ) );
        sub5->add( f.makeNote( cVal( 7 ), dur ) );
        sub5->add( f.makeNote( cVal( 8 ), dur ) );
        sub5->add( f.makeNote( cVal( 9 ), dur ) );
        sub4->addGroup( sub5 );
        sub4->add( f.makeNote( cVal( 10 ), dur ) );
        sub3->addGroup( sub4 );
        sub3->add( f.makeNote( cVal( 11 ), dur ) );
        
        mainNoteGroup->add( f.makeNote( cVal( 4 ), dur ) );
        mainNoteGroup->addGroup( sub3 );
        
        sub6->add( f.makeNote( cVal( 12 ), dur ) );
        sub6->add( f.makeNote( cVal( 13 ), dur ) );
        
        mainNoteGroup->addGroup( sub6 );
        mainNoteGroup->add( f.makeNote( cVal( 14 ), dur ) );
        
        return std::move( mainNoteGroup );
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

TEST( copyNoteGroup, NoteGroup )
{
    Factories f;
    NoteGroupUP noteGroup{ new NoteGroup{} };
    noteGroup->add( f.c4Quarter() );
    CHECK_EQUAL( 1, noteGroup->getCount() )
    NoteGroupUP copied = noteGroup->copyNoteGroup();
    CHECK_EQUAL( 1, copied->getCount() )
    CHECK( noteGroup.get() != copied.get() )
}
T_END

TEST( toStream, NoteGroup )
{
    auto noteGroup = newNestedGroup1();
    std::stringstream ss;
    noteGroup->toStream( ss );
    String expected = newNestedGroup1String();
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString, NoteGroup )
{
    auto noteGroup = newNestedGroup1();
    String expected = newNestedGroup1String();
    String actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamOperator, NoteGroup )
{
    auto noteGroup = newNestedGroup1();
    std::stringstream ss;
    ss << ( *noteGroup );
    String expected = newNestedGroup1String();
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
    String expected = "{ D4 : Eighth }";
    String actual = noteGroup->getNote( 3 )->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getNote_nested, NoteGroup )
{
    auto noteGroup = newNestedGroup1();
    String expected = "{ F2 : Half }";
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
    auto noteGroup = newNoteGroup(); // Before | After
    noteGroup->add( f.e2Sixteenth() ); // 0    | 0
    noteGroup->add( f.f2Half() );      // 1    | 1
    noteGroup->add( f.c4Quarter() );   // 2*   |
    noteGroup->add( f.d4Eighth() );    // 3    | 2*
    noteGroup->add( f.e2Sixteenth() ); // 4    | 3
    
    CHECK_EQUAL( 5, noteGroup->getCount() )
    
    noteGroup->remove( 2 );
    
    CHECK_EQUAL( 4, noteGroup->getCount() )
    
    String expected = "{ D4 : Eighth }";
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
    
    String expected = "{ D4 : Eighth }";
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
    auto second = newNoteGroup();
    second->add( f.c4Quarter() );
    noteGroup->addGroup( second );
    auto third = newNoteGroup();
    third->add( f.e2Sixteenth() );
    noteGroup->addGroup( third );
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
    CHECK_EQUAL( 0, noteGroup->getGroupIndex( 1 ) )
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
    noteGroup->addGroup( additionalNested );
    CHECK_EQUAL( 3, noteGroup->getGroupIndex( 8 ) )
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
    String expected = "{ D4 : Eighth }";
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
    String expected = "{ E2 : 16th }";
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
    CHECK_EQUAL( 3, noteGroup->getGroupCount() )
}
T_END

TEST( removeGroup_throwOutOfRange, NoteGroup )
{
    auto noteGroup = newNestedGroup1();
    bool isExceptionThrown = false;
    try
    {
        noteGroup->removeGroup( 1 );
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
    auto addedGroup3 = newNoteGroup();
    addedGroup3->add( f.f2Half() );
    noteGroup->addGroup( addedGroup3 );
    CHECK_EQUAL( 9, noteGroup->getCount() )
    CHECK_EQUAL( 4, noteGroup->getGroupCount() )
    noteGroup->removeGroup( 2 );
    CHECK_EQUAL( 8, noteGroup->getCount() )
    CHECK_EQUAL( 3, noteGroup->getGroupCount() )
    auto returnedGroup = noteGroup->getGroup( 2 );
    String expected = "{ F2 : Half }";
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
    auto addedGroup3 = newNoteGroup();
    addedGroup3->add( f.f2Half() );
    noteGroup->addGroup( addedGroup3 );
    CHECK_EQUAL( 9, noteGroup->getCount() )
    CHECK_EQUAL( 4, noteGroup->getGroupCount() )
    noteGroup->removeGroup( 0 );
    CHECK_EQUAL( 5, noteGroup->getCount() )
    CHECK_EQUAL( 3, noteGroup->getGroupCount() )
    auto returnedGroup = noteGroup->getGroup( 0 );
    String expected = "{ C4 : Quarter }";
    String actual = returnedGroup->getNote( 0 )->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( removingAllNotesRemovesGroup_front, NoteGroup )
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

TEST( removingAllNotesRemovesGroup_back, NoteGroup )
{
    Factories f;
    auto noteGroup = newNestedGroup3();
    std::stringstream ssExpected;
    String expected;
    String actual;

    CHECK_EQUAL( 3, noteGroup->getGroupCount() )
    CHECK_EQUAL( 15, noteGroup->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    ssExpected << "{ C3 : Quarter }" << std::endl;
    ssExpected << "{ C4 : Quarter }" << std::endl;
    ssExpected << "{ C5 : Quarter }" << std::endl;
    ssExpected << "{ C6 : Quarter }" << std::endl;
    ssExpected << "{ C7 : Quarter }" << std::endl;
    ssExpected << "{ C8 : Quarter }" << std::endl;
    ssExpected << "{ C9 : Quarter }" << std::endl;
    ssExpected << "{ C10 : Quarter }" << std::endl;
    ssExpected << "{ C11 : Quarter }" << std::endl;
    ssExpected << "{ C12 : Quarter }" << std::endl;
    ssExpected << "{ C13 : Quarter }" << std::endl;
    ssExpected << "{ C14 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )


    noteGroup->remove( 14 );
    CHECK_EQUAL( 3, noteGroup->getGroupCount() )
    CHECK_EQUAL( 14, noteGroup->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    ssExpected << "{ C3 : Quarter }" << std::endl;
    ssExpected << "{ C4 : Quarter }" << std::endl;
    ssExpected << "{ C5 : Quarter }" << std::endl;
    ssExpected << "{ C6 : Quarter }" << std::endl;
    ssExpected << "{ C7 : Quarter }" << std::endl;
    ssExpected << "{ C8 : Quarter }" << std::endl;
    ssExpected << "{ C9 : Quarter }" << std::endl;
    ssExpected << "{ C10 : Quarter }" << std::endl;
    ssExpected << "{ C11 : Quarter }" << std::endl;
    ssExpected << "{ C12 : Quarter }" << std::endl;
    ssExpected << "{ C13 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )
    
    noteGroup->remove( 13 );
    CHECK_EQUAL( 3, noteGroup->getGroupCount() )
    CHECK_EQUAL( 13, noteGroup->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    ssExpected << "{ C3 : Quarter }" << std::endl;
    ssExpected << "{ C4 : Quarter }" << std::endl;
    ssExpected << "{ C5 : Quarter }" << std::endl;
    ssExpected << "{ C6 : Quarter }" << std::endl;
    ssExpected << "{ C7 : Quarter }" << std::endl;
    ssExpected << "{ C8 : Quarter }" << std::endl;
    ssExpected << "{ C9 : Quarter }" << std::endl;
    ssExpected << "{ C10 : Quarter }" << std::endl;
    ssExpected << "{ C11 : Quarter }" << std::endl;
    ssExpected << "{ C12 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )
    
    noteGroup->remove( 12 );
    CHECK_EQUAL( 2, noteGroup->getGroupCount() )
    CHECK_EQUAL( 12, noteGroup->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    ssExpected << "{ C3 : Quarter }" << std::endl;
    ssExpected << "{ C4 : Quarter }" << std::endl;
    ssExpected << "{ C5 : Quarter }" << std::endl;
    ssExpected << "{ C6 : Quarter }" << std::endl;
    ssExpected << "{ C7 : Quarter }" << std::endl;
    ssExpected << "{ C8 : Quarter }" << std::endl;
    ssExpected << "{ C9 : Quarter }" << std::endl;
    ssExpected << "{ C10 : Quarter }" << std::endl;
    ssExpected << "{ C11 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )
    
    noteGroup->remove( 11 );
    CHECK_EQUAL( 2, noteGroup->getGroupCount() )
    CHECK_EQUAL( 11, noteGroup->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    ssExpected << "{ C3 : Quarter }" << std::endl;
    ssExpected << "{ C4 : Quarter }" << std::endl;
    ssExpected << "{ C5 : Quarter }" << std::endl;
    ssExpected << "{ C6 : Quarter }" << std::endl;
    ssExpected << "{ C7 : Quarter }" << std::endl;
    ssExpected << "{ C8 : Quarter }" << std::endl;
    ssExpected << "{ C9 : Quarter }" << std::endl;
    ssExpected << "{ C10 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )
    
    noteGroup->remove( 10 );
    CHECK_EQUAL( 2, noteGroup->getGroupCount() )
    CHECK_EQUAL( 10, noteGroup->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    ssExpected << "{ C3 : Quarter }" << std::endl;
    ssExpected << "{ C4 : Quarter }" << std::endl;
    ssExpected << "{ C5 : Quarter }" << std::endl;
    ssExpected << "{ C6 : Quarter }" << std::endl;
    ssExpected << "{ C7 : Quarter }" << std::endl;
    ssExpected << "{ C8 : Quarter }" << std::endl;
    ssExpected << "{ C9 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )
    
    noteGroup->remove( 9 );
    CHECK_EQUAL( 2, noteGroup->getGroupCount() )
    CHECK_EQUAL( 9, noteGroup->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    ssExpected << "{ C3 : Quarter }" << std::endl;
    ssExpected << "{ C4 : Quarter }" << std::endl;
    ssExpected << "{ C5 : Quarter }" << std::endl;
    ssExpected << "{ C6 : Quarter }" << std::endl;
    ssExpected << "{ C7 : Quarter }" << std::endl;
    ssExpected << "{ C8 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )
    
    noteGroup->remove( 8 );
    CHECK_EQUAL( 2, noteGroup->getGroupCount() )
    CHECK_EQUAL( 8, noteGroup->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    ssExpected << "{ C3 : Quarter }" << std::endl;
    ssExpected << "{ C4 : Quarter }" << std::endl;
    ssExpected << "{ C5 : Quarter }" << std::endl;
    ssExpected << "{ C6 : Quarter }" << std::endl;
    ssExpected << "{ C7 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )
    
    noteGroup->remove( 7 );
    CHECK_EQUAL( 2, noteGroup->getGroupCount() )
    CHECK_EQUAL( 7, noteGroup->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    ssExpected << "{ C3 : Quarter }" << std::endl;
    ssExpected << "{ C4 : Quarter }" << std::endl;
    ssExpected << "{ C5 : Quarter }" << std::endl;
    ssExpected << "{ C6 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )
    
    noteGroup->remove( 6 );
    CHECK_EQUAL( 2, noteGroup->getGroupCount() )
    CHECK_EQUAL( 6, noteGroup->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    ssExpected << "{ C3 : Quarter }" << std::endl;
    ssExpected << "{ C4 : Quarter }" << std::endl;
    ssExpected << "{ C5 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )
    
    noteGroup->remove( 5 );
    CHECK_EQUAL( 1, noteGroup->getGroupCount() )
    CHECK_EQUAL( 5, noteGroup->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    ssExpected << "{ C3 : Quarter }" << std::endl;
    ssExpected << "{ C4 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )
    
    noteGroup->remove( 4 );
    CHECK_EQUAL( 1, noteGroup->getGroupCount() )
    CHECK_EQUAL( 4, noteGroup->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    ssExpected << "{ C3 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )
    
    noteGroup->remove( 3 );
    CHECK_EQUAL( 1, noteGroup->getGroupCount() )
    CHECK_EQUAL( 3, noteGroup->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )
    
    noteGroup->remove( 2 );
    CHECK_EQUAL( 1, noteGroup->getGroupCount() )
    CHECK_EQUAL( 2, noteGroup->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )
    
    noteGroup->remove( 1 );
    CHECK_EQUAL( 0, noteGroup->getGroupCount() )
    CHECK_EQUAL( 1, noteGroup->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )
    
    noteGroup->remove( 0 );
    CHECK_EQUAL( 0, noteGroup->getGroupCount() )
    CHECK_EQUAL( 0, noteGroup->getCount() )
    ssExpected.str( "" );
    expected = ssExpected.str();
    actual = noteGroup->toString();
    CHECK_EQUAL( expected, actual )
}
T_END
