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

TEST( ctor, NoteGroup )
{
    NoteGroup noteGroup;
    CHECK_EQUAL( 0, noteGroup.getCount() )
}
T_END

TEST( copyCtor, NoteGroup )
{
    CHECK_FAIL( "copyCtor" )
}
T_END

TEST( moveCtor, NoteGroup )
{
    CHECK_FAIL( "moveCtor" )
}
T_END

TEST( assignment, NoteGroup )
{
    CHECK_FAIL( "assignment" )
}
T_END

TEST( moveAssignment, NoteGroup )
{
    CHECK_FAIL( "moveAssignment" )
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

TEST( toStream, NoteGroup )
{
    CHECK_FAIL( "toStream" )
}
T_END

TEST( toString, NoteGroup )
{
    CHECK_FAIL( "toString" )
}
T_END

TEST( streamOperator, NoteGroup )
{
    CHECK_FAIL( "streamOperator" )
}
T_END

TEST( getIsEmpty_true, NoteGroup )
{
    CHECK_FAIL( "getIsEmpty_true" )
}
T_END

TEST( getIsEmpty_false, NoteGroup )
{
    CHECK_FAIL( "getIsEmpty_false" )
}
T_END

TEST( getCount_0, NoteGroup )
{
    CHECK_FAIL( "getCount_0" )
}
T_END

TEST( getCount_1, NoteGroup )
{
    CHECK_FAIL( "getCount_1" )
}
T_END

TEST( getCount_5_flat, NoteGroup )
{
    CHECK_FAIL( "getCount_5_flat" )
}
T_END

TEST( getCount_5_nested, NoteGroup )
{
    CHECK_FAIL( "getCount_5_nested" )
}
T_END

TEST( getTotalDuration_0, NoteGroup )
{
    CHECK_FAIL( "getTotalDuration_0" )
}
T_END

TEST( getTotalDuration_4Q, NoteGroup )
{
    CHECK_FAIL( "getTotalDuration_4Q" )
}
T_END

TEST( getTotalDuration_3E, NoteGroup )
{
    CHECK_FAIL( "getTotalDuration_3E" )
}
T_END

TEST( getNote_throwEmpty, NoteGroup )
{
    CHECK_FAIL( "getNote_throwEmpty" )
}
T_END

TEST( getNote_throwOutOfRange, NoteGroup )
{
    CHECK_FAIL( "getNote_throwOutOfRange" )
}
T_END

TEST( getNote_flat, NoteGroup )
{
    CHECK_FAIL( "getNote_flat" )
}
T_END

TEST( getNote_nested, NoteGroup )
{
    CHECK_FAIL( "getNote_nested" )
}
T_END

TEST( add_throwNull, NoteGroup )
{
    CHECK_FAIL( "add_throwNull" )
}
T_END

TEST( add, NoteGroup )
{
    CHECK_FAIL( "add" )
}
T_END

TEST( remove_throwEmpty, NoteGroup )
{
    CHECK_FAIL( "remove_throwEmpty" )
}
T_END

TEST( remove_throwOutOfRange, NoteGroup )
{
    CHECK_FAIL( "remove_throwOutOfRange" )
}
T_END

TEST( remove_flat, NoteGroup )
{
    CHECK_FAIL( "remove_flat" )
}
T_END

TEST( remove_nested, NoteGroup )
{
    CHECK_FAIL( "remove_nested" )
}
T_END

TEST( getGroupCount_0, NoteGroup )
{
    CHECK_FAIL( "getGroupCount_0" )
}
T_END

TEST( getGroupCount_2_flat, NoteGroup )
{
    CHECK_FAIL( "getGroupCount_2_flat" )
}
T_END

TEST( getGroupCount_3_nested, NoteGroup )
{
    CHECK_FAIL( "getGroupCount_3_nested" )
}
T_END

TEST( getIsInGroup_throwEmpty, NoteGroup )
{
    CHECK_FAIL( "getIsInGroup_throwEmpty" )
}
T_END

TEST( getIsInGroup_throwOutOfRange, NoteGroup )
{
    CHECK_FAIL( "getIsInGroup_throwOutOfRange" )
}
T_END

TEST( getIsInGroup_true, NoteGroup )
{
    CHECK_FAIL( "getIsInGroup_true" )
}
T_END

TEST( getIsInGroup_false, NoteGroup )
{
    CHECK_FAIL( "getIsInGroup_false" )
}
T_END

TEST( getGroupIndex_throwEmpty, NoteGroup )
{
    CHECK_FAIL( "getGroupIndex_throwEmpty" )
}
T_END

TEST( getGroupIndex_throwOutOfRange, NoteGroup )
{
    CHECK_FAIL( "getGroupIndex_throwOutOfRange" )
}
T_END

TEST( getGroupIndex_Neg1, NoteGroup )
{
    CHECK_FAIL( "getGroupIndex_Neg1" )
}
T_END

TEST( getGroupIndex_0, NoteGroup )
{
    CHECK_FAIL( "getGroupIndex_0" )
}
T_END

TEST( getGroupIndex_2_nested, NoteGroup )
{
    CHECK_FAIL( "getGroupIndex_2_nested" )
}
T_END

TEST( getGroup_throwNoGroups, NoteGroup )
{
    CHECK_FAIL( "getGroup_throwNoGroups" )
}
T_END

TEST( getGroup_throwOutOfRange, NoteGroup )
{
    CHECK_FAIL( "getGroup_throwOutOfRange" )
}
T_END

TEST( getGroup_0, NoteGroup )
{
    CHECK_FAIL( "getGroup_0" )
}
T_END

TEST( getGroup_2, NoteGroup )
{
    CHECK_FAIL( "getGroup_2" )
}
T_END

TEST( addGroup_throwNull, NoteGroup )
{
    CHECK_FAIL( "addGroup_throwNull" )
}
T_END

TEST( addGroup, NoteGroup )
{
    CHECK_FAIL( "addGroup" )
}
T_END

TEST( removeGroup_throwOutOfRange, NoteGroup )
{
    CHECK_FAIL( "removeGroup_throwOutOfRange" )
}
T_END

TEST( removeGroup_2, NoteGroup )
{
    CHECK_FAIL( "removeGroup_2" )
}
T_END

TEST( removeGroup_0, NoteGroup )
{
    CHECK_FAIL( "removeGroup_0" )
}
T_END
