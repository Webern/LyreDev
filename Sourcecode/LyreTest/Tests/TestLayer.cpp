//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Ilayer->h"
#include "Lyre/ILayerFactory.h"
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
    
    inline ILayerUP newLayer() { return createLayerFactory()->createLayer(); }
    inline ILayerUP newNestedGroup1()
    {
        Factories f;
        auto Layer = newLayer();
        auto subGroup = newLayer();
        auto subSubGroup = newLayer();
        subSubGroup->add( f.c4Quarter() );  // 1 / 1 ~ #2
        subSubGroup->add( f.f2Half() );     // 2 / 1 ~ #3
        subGroup->add( f.d4Eighth() );      // 1 / 2 ~ #1
        subGroup->addGroup( subSubGroup->clone() );
        subGroup->add( f.d4Eighth() );      // 1 / 2 ~ #4
        layer->add( f.e2Sixteenth() );  // 1 / 4 ~ #0
        layer->addGroup( subGroup->clone() );
        layer->add( f.e2Sixteenth() );  // 1 / 4 ~ #5
        return std::move( Layer );
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
    inline ILayerUP newNestedGroup2()
    {
        Factories f;
        auto Layer = newLayer();
        auto subGroup = newLayer();
        auto subSubGroup = newLayer();
        subSubGroup->add( f.c4Quarter() );
        subSubGroup->add( f.f2Half() );
        subGroup->add( f.d4Eighth() );
        subGroup->addGroup( subSubGroup->clone() );
        layer->add( f.e2Sixteenth() );
        layer->addGroup( subGroup->clone() );
        layer->add( f.e2Sixteenth() );
        return std::move( Layer );
    }
    
    inline int cVal( const int octave )
    {
        int twelve = 12;
        return ( twelve ) + ( twelve * octave );
    }
    inline ILayerUP newNestedGroup3()
    {
        Factories f;
        auto mainLayer = newLayer();
        auto sub1 = newLayer();
        auto sub2 = newLayer();
        auto sub3 = newLayer();
        auto sub4 = newLayer();
        auto sub5 = newLayer();
        auto sub6 = newLayer();
        auto sub7 = newLayer();
        
        String dur = "Quarter";
        
        mainlayer->add( f.makeNote( cVal( 0 ), dur ) );
        sub2->add( f.makeNote( cVal( 1 ), dur ) );
        sub2->add( f.makeNote( cVal( 2 ), dur ) );
        sub2->add( f.makeNote( cVal( 3 ), dur ) );
        mainlayer->addGroup( sub2->clone() );
        
        sub3->add( f.makeNote( cVal( 5 ), dur ) );
        sub4->add( f.makeNote( cVal( 6 ), dur ) );
        sub5->add( f.makeNote( cVal( 7 ), dur ) );
        sub5->add( f.makeNote( cVal( 8 ), dur ) );
        sub5->add( f.makeNote( cVal( 9 ), dur ) );
        sub4->addGroup( sub5->clone() );
        sub4->add( f.makeNote( cVal( 10 ), dur ) );
        sub3->addGroup( sub4->clone() );
        sub3->add( f.makeNote( cVal( 11 ), dur ) );
        
        mainlayer->add( f.makeNote( cVal( 4 ), dur ) );
        mainlayer->addGroup( sub3->clone() );
        
        sub6->add( f.makeNote( cVal( 12 ), dur ) );
        sub6->add( f.makeNote( cVal( 13 ), dur ) );
        
        mainlayer->addGroup( sub6->clone() );
        mainlayer->add( f.makeNote( cVal( 14 ), dur ) );
        
        return std::move( mainLayer );
    }
}

TEST( ctor, Layer )
{
    ILayerUP layer = createLayerFactory()->createLayer();
    CHECK_EQUAL( 0, layer->getCount() )
}
T_END

TEST( copyCtor, Layer )
{
    Factories f;
    ILayerUP layer = createLayerFactory()->createLayer();
    layer->add( f.e2Sixteenth() );
    ILayerUP copied = layer->copyLayer();
    CHECK_EQUAL( 1, layer->getCount() )
    CHECK_EQUAL( 1, copied->getCount() )
}
T_END

TEST( moveCtor, Layer )
{
    Factories f;
    ILayerUP layer = createLayerFactory()->createLayer();
    layer->add( f.e2Sixteenth() );
    ILayerUP copied{ std::move( layer ) };
    CHECK_EQUAL( 1, copied->getCount() )
}
T_END

TEST( assignment, Layer )
{
    Factories f;
    ILayerUP layer = createLayerFactory()->createLayer();
    layer->add( f.e2Sixteenth() );
    Layer copied;
    copied = Layer;
    CHECK_EQUAL( 1, layer->getCount() )
    CHECK_EQUAL( 1, copied.getCount() )
}
T_END

TEST( moveAssignment, Layer )
{
    Factories f;
    ILayerUP layer = createLayerFactory()->createLayer();
    layer->add( f.e2Sixteenth() );
    Layer copied;
    copied = std::move( Layer );
    CHECK_EQUAL( 1, copied.getCount() )
}
T_END

TEST( clone, Layer )
{
    Factories f;
    ILayerUP Layer{ new Layer{} };
    layer->add( f.c4Quarter() );
    CHECK_EQUAL( 1, layer->getCount() )
    ILayerUP cloned = layer->clone();
    CHECK_EQUAL( 1, cloned->getCount() )
    CHECK( layer->get() != cloned.get() )
}
T_END

TEST( copyLayer, Layer )
{
    Factories f;
    LayerUP Layer{ new Layer{} };
    layer->add( f.c4Quarter() );
    CHECK_EQUAL( 1, layer->getCount() )
    LayerUP copied = layer->copyLayer();
    CHECK_EQUAL( 1, copied->getCount() )
    CHECK( layer->get() != copied.get() )
}
T_END

TEST( toStream, Layer )
{
    auto Layer = newNestedGroup1();
    std::stringstream ss;
    layer->toStream( ss );
    String expected = newNestedGroup1String();
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toString, Layer )
{
    auto Layer = newNestedGroup1();
    String expected = newNestedGroup1String();
    String actual = layer->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamOperator, Layer )
{
    auto Layer = newNestedGroup1();
    std::stringstream ss;
    ss << ( *Layer );
    String expected = newNestedGroup1String();
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getIsEmpty_true, Layer )
{
    auto Layer = newLayer();
    CHECK( layer->getIsEmpty() )
}
T_END

TEST( getIsEmpty_false, Layer )
{
    auto Layer = newNestedGroup1();
    CHECK( ! layer->getIsEmpty() )
}
T_END

TEST( getCount_0, Layer )
{
    auto Layer = newLayer();
    int expected = 0;
    int actual = layer->getCount();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getCount_1, Layer )
{
    Factories f;
    auto Layer = newLayer();
    layer->add( f.e2Sixteenth() );
    int expected = 1;
    int actual = layer->getCount();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getCount_5_flat, Layer )
{
    Factories f;
    auto Layer = newLayer();
    layer->add( f.e2Sixteenth() );
    layer->add( f.f2Half() );
    layer->add( f.c4Quarter() );
    layer->add( f.d4Eighth() );
    layer->add( f.e2Sixteenth() );
    int expected = 5;
    int actual = layer->getCount();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getCount_5_nested, Layer )
{
    auto Layer = newNestedGroup2();
    int expected = 5;
    int actual = layer->getCount();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTotalDuration_0, Layer )
{
    auto Layer = newLayer();
    Rational expected{ 0, 1 };
    Rational actual = layer->getTotalDuration();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTotalDuration_4Q, Layer )
{
    Factories f;
    auto Layer = newLayer();
    layer->add( f.e2Sixteenth() );
    layer->add( f.f2Half() );
    layer->add( f.c4Quarter() );
    layer->add( f.d4Eighth() );
    layer->add( f.e2Sixteenth() );
    Rational expected{ 4, 1 };
    Rational actual = layer->getTotalDuration();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getTotalDuration_3E, Layer )
{
    auto Layer = newNestedGroup1();
    Rational expected{ 9, 2 };
    Rational actual = layer->getTotalDuration();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getNote_throwEmpty, Layer )
{
    auto Layer = newLayer();
    bool isExceptionThrown = false;
    try
    {
        auto n = layer->getNote( 0 );
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

TEST( getNote_throwOutOfRange, Layer )
{
    auto Layer = newNestedGroup2();
    bool isExceptionThrown = false;
    try
    {
        auto n = layer->getNote( 7 );
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

TEST( getNote_flat, Layer )
{
    Factories f;
    auto Layer = newLayer();
    layer->add( f.e2Sixteenth() );  // 0
    layer->add( f.f2Half() );       // 1
    layer->add( f.c4Quarter() );    // 2
    layer->add( f.d4Eighth() );     // 3
    layer->add( f.e2Sixteenth() );  // 4
    String expected = "{ D4 : Eighth }";
    String actual = layer->getNote( 3 )->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getNote_nested, Layer )
{
    auto Layer = newNestedGroup1();
    String expected = "{ F2 : Half }";
    String actual = layer->getNote( 3 )->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( add_throwNull, Layer )
{
    auto Layer = newLayer();
    INoteUP nullnote{ nullptr };
    bool isExceptionThrown = false;
    try
    {
        layer->add( nullnote );
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

TEST( add, Layer )
{
    Factories f;
    auto Layer = newLayer();
    layer->add( f.e2Sixteenth() );
    int expected = 1;
    int actual = layer->getCount();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( remove_throwEmpty, Layer )
{
    auto Layer = newLayer();
    bool isExceptionThrown = false;
    try
    {
        layer->remove( 0 );
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

TEST( remove_throwOutOfRange, Layer )
{
    auto Layer = newNestedGroup1();
    bool isExceptionThrown = false;
    try
    {
        layer->remove( 7 );
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

TEST( remove_flat, Layer )
{
    Factories f;
    auto Layer = newLayer(); // Before | After
    layer->add( f.e2Sixteenth() ); // 0    | 0
    layer->add( f.f2Half() );      // 1    | 1
    layer->add( f.c4Quarter() );   // 2*   |
    layer->add( f.d4Eighth() );    // 3    | 2*
    layer->add( f.e2Sixteenth() ); // 4    | 3
    
    CHECK_EQUAL( 5, layer->getCount() )
    
    layer->remove( 2 );
    
    CHECK_EQUAL( 4, layer->getCount() )
    
    String expected = "{ D4 : Eighth }";
    String actual = layer->getNote( 2 )->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( remove_nested, Layer )
{
    Factories f;
    auto Layer = newNestedGroup1();
    
    CHECK_EQUAL( 6, layer->getCount() )
    
    layer->remove( 3 );
    
    CHECK_EQUAL( 5, layer->getCount() )
    
    String expected = "{ D4 : Eighth }";
    String actual = layer->getNote( 3 )->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getGroupCount_0, Layer )
{
    Factories f;
    auto Layer = newLayer();
    layer->add( f.e2Sixteenth() );
    layer->add( f.f2Half() );
    layer->add( f.c4Quarter() );
    layer->add( f.d4Eighth() );
    layer->add( f.e2Sixteenth() );
    CHECK_EQUAL( 0, layer->getGroupCount() )
}
T_END

TEST( getGroupCount_3, Layer )
{
    Factories f;
    auto Layer = newNestedGroup1();
    auto second = newLayer();
    second->add( f.c4Quarter() );
    layer->addGroup( second );
    auto third = newLayer();
    third->add( f.e2Sixteenth() );
    layer->addGroup( third );
    CHECK_EQUAL( 3, layer->getGroupCount() )
}
T_END

TEST( getIsInGroup_throwEmpty, Layer )
{
    auto Layer = newLayer();
    bool isExceptionThrown = false;
    try
    {
        bool b = layer->getIsInGroup( 0 );
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

TEST( getIsInGroup_throwOutOfRange, Layer )
{
    auto Layer = newNestedGroup2();
    bool isExceptionThrown = false;
    try
    {
        bool b = layer->getIsInGroup( 7 );
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

TEST( getIsInGroup_true, Layer )
{
    auto Layer = newNestedGroup2();
    CHECK( layer->getIsInGroup( 3 ) )
}
T_END

TEST( getIsInGroup_false, Layer )
{
    auto Layer = newNestedGroup2();
    CHECK( ! layer->getIsInGroup( 0 ) )
}
T_END

TEST( getGroupIndex_throwEmpty, Layer )
{
    auto Layer = newLayer();
    bool isExceptionThrown = false;
    try
    {
        int x = layer->getGroupIndex( 0 );
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

TEST( getGroupIndex_throwOutOfRange, Layer )
{
    auto Layer = newNestedGroup2();
    bool isExceptionThrown = false;
    try
    {
        int x = layer->getGroupIndex( -1 );
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

TEST( getGroupIndex_Neg1, Layer )
{
    auto Layer = newNestedGroup1();
    CHECK_EQUAL( -1, layer->getGroupIndex( 0 ) )
}
T_END

TEST( getGroupIndex_0, Layer )
{
    auto Layer = newNestedGroup1();
    CHECK_EQUAL( 0, layer->getGroupIndex( 1 ) )
}
T_END

TEST( getGroupIndex_2_nested, Layer )
{
    Factories f;
    auto Layer = newNestedGroup1();
    auto additionalNested = newLayer();
    additionalNested->add( f.c4Quarter() );
    layer->addGroup( additionalNested );
    layer->addGroup( additionalNested );
    layer->addGroup( additionalNested );
    CHECK_EQUAL( 3, layer->getGroupIndex( 8 ) )
}
T_END

TEST( getGroup_throwNoGroups, Layer )
{
    Factories f;
    auto Layer = newLayer();
    layer->add( f.e2Sixteenth() );
    layer->add( f.f2Half() );
    layer->add( f.c4Quarter() );
    layer->add( f.d4Eighth() );
    layer->add( f.e2Sixteenth() );
    bool isExceptionThrown = false;
    try
    {
        auto x = layer->getGroup( 0 );
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

TEST( getGroup_throwOutOfRange, Layer )
{
    auto Layer = newNestedGroup1();
    bool isExceptionThrown = false;
    try
    {
        auto x = layer->getGroup( 2 );
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

TEST( getGroup_0, Layer )
{
    auto Layer = newNestedGroup1();
    auto subGroup = layer->getGroup( 0 );
    auto firstSubGroupNote = subGroup->getNote( 0 );
    String expected = "{ D4 : Eighth }";
    String actual = firstSubGroupNote->toString();
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( 4, subGroup->getCount() )
}
T_END

TEST( getGroup_2, Layer )
{
    Factories f;
    auto Layer = newNestedGroup1();
    auto addedGroup1 = newLayer();
    addedGroup1->add( f.c4Quarter() );
    layer->addGroup( addedGroup1 );
    auto addedGroup2 = newLayer();
    addedGroup2->add( f.e2Sixteenth() );
    layer->addGroup( addedGroup2 );
    auto index2Group = layer->getGroup( 2 );
    auto firstNote = index2Group->getNote( 0 );
    String expected = "{ E2 : 16th }";
    String actual = firstNote->toString();
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( 1, index2Group->getCount() )
}
T_END

TEST( addGroup_throwNull, Layer )
{
    ILayerUP Layer = newNestedGroup2();
    ILayerUP nullgroup{ nullptr };
    bool isExceptionThrown = false;
    try
    {
        layer->addGroup( nullgroup );
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

TEST( addGroup, Layer )
{
    Factories f;
    auto Layer = newNestedGroup1();
    auto addedGroup1 = newLayer();
    addedGroup1->add( f.c4Quarter() );
    layer->addGroup( addedGroup1 );
    auto addedGroup2 = newLayer();
    addedGroup2->add( f.e2Sixteenth() );
    layer->addGroup( addedGroup2 );
    CHECK_EQUAL( 3, layer->getGroupCount() )
}
T_END

TEST( removeGroup_throwOutOfRange, Layer )
{
    auto Layer = newNestedGroup1();
    bool isExceptionThrown = false;
    try
    {
        layer->removeGroup( 1 );
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

TEST( removeGroup_2, Layer )
{
    Factories f;
    auto Layer = newNestedGroup1();
    auto addedGroup1 = newLayer();
    addedGroup1->add( f.c4Quarter() );
    layer->addGroup( addedGroup1 );
    auto addedGroup2 = newLayer();
    addedGroup2->add( f.e2Sixteenth() );
    layer->addGroup( addedGroup2 );
    auto addedGroup3 = newLayer();
    addedGroup3->add( f.f2Half() );
    layer->addGroup( addedGroup3 );
    CHECK_EQUAL( 9, layer->getCount() )
    CHECK_EQUAL( 4, layer->getGroupCount() )
    layer->removeGroup( 2 );
    CHECK_EQUAL( 8, layer->getCount() )
    CHECK_EQUAL( 3, layer->getGroupCount() )
    auto returnedGroup = layer->getGroup( 2 );
    String expected = "{ F2 : Half }";
    String actual = returnedGroup->getNote( 0 )->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( removeGroup_0, Layer )
{
    Factories f;
    auto Layer = newNestedGroup1();
    auto addedGroup1 = newLayer();
    addedGroup1->add( f.c4Quarter() );
    layer->addGroup( addedGroup1 );
    auto addedGroup2 = newLayer();
    addedGroup2->add( f.e2Sixteenth() );
    layer->addGroup( addedGroup2 );
    auto addedGroup3 = newLayer();
    addedGroup3->add( f.f2Half() );
    layer->addGroup( addedGroup3 );
    CHECK_EQUAL( 9, layer->getCount() )
    CHECK_EQUAL( 4, layer->getGroupCount() )
    layer->removeGroup( 0 );
    CHECK_EQUAL( 5, layer->getCount() )
    CHECK_EQUAL( 3, layer->getGroupCount() )
    auto returnedGroup = layer->getGroup( 0 );
    String expected = "{ C4 : Quarter }";
    String actual = returnedGroup->getNote( 0 )->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( removingAllNotesRemovesGroup_front, Layer )
{
    Factories f;
    auto Layer = newNestedGroup1();
    auto addedGroup1 = newLayer();
    addedGroup1->add( f.c4Quarter() );
    layer->addGroup( addedGroup1 );
    auto addedGroup2 = newLayer();
    addedGroup2->add( f.e2Sixteenth() );
    layer->addGroup( addedGroup2 );
    CHECK_EQUAL( 3, layer->getGroupCount() )
    layer->remove( 0 );
    layer->remove( 0 );
    layer->remove( 0 );
    layer->remove( 0 );
    layer->remove( 0 ); 
    layer->remove( 0 );
    CHECK_EQUAL( 2, layer->getGroupCount() )
    layer->remove( 0 );
    CHECK_EQUAL( 1, layer->getGroupCount() )
    layer->remove( 0 );
    CHECK_EQUAL( 0, layer->getGroupCount() )
}
T_END

TEST( removingAllNotesRemovesGroup_back, Layer )
{
    Factories f;
    auto Layer = newNestedGroup3();
    std::stringstream ssExpected;
    String expected;
    String actual;

    CHECK_EQUAL( 3, layer->getGroupCount() )
    CHECK_EQUAL( 15, layer->getCount() )
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
    actual = layer->toString();
    CHECK_EQUAL( expected, actual )


    layer->remove( 14 );
    CHECK_EQUAL( 3, layer->getGroupCount() )
    CHECK_EQUAL( 14, layer->getCount() )
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
    actual = layer->toString();
    CHECK_EQUAL( expected, actual )
    
    layer->remove( 13 );
    CHECK_EQUAL( 3, layer->getGroupCount() )
    CHECK_EQUAL( 13, layer->getCount() )
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
    actual = layer->toString();
    CHECK_EQUAL( expected, actual )
    
    layer->remove( 12 );
    CHECK_EQUAL( 2, layer->getGroupCount() )
    CHECK_EQUAL( 12, layer->getCount() )
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
    actual = layer->toString();
    CHECK_EQUAL( expected, actual )
    
    layer->remove( 11 );
    CHECK_EQUAL( 2, layer->getGroupCount() )
    CHECK_EQUAL( 11, layer->getCount() )
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
    actual = layer->toString();
    CHECK_EQUAL( expected, actual )
    
    layer->remove( 10 );
    CHECK_EQUAL( 2, layer->getGroupCount() )
    CHECK_EQUAL( 10, layer->getCount() )
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
    actual = layer->toString();
    CHECK_EQUAL( expected, actual )
    
    layer->remove( 9 );
    CHECK_EQUAL( 2, layer->getGroupCount() )
    CHECK_EQUAL( 9, layer->getCount() )
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
    actual = layer->toString();
    CHECK_EQUAL( expected, actual )
    
    layer->remove( 8 );
    CHECK_EQUAL( 2, layer->getGroupCount() )
    CHECK_EQUAL( 8, layer->getCount() )
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
    actual = layer->toString();
    CHECK_EQUAL( expected, actual )
    
    layer->remove( 7 );
    CHECK_EQUAL( 2, layer->getGroupCount() )
    CHECK_EQUAL( 7, layer->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    ssExpected << "{ C3 : Quarter }" << std::endl;
    ssExpected << "{ C4 : Quarter }" << std::endl;
    ssExpected << "{ C5 : Quarter }" << std::endl;
    ssExpected << "{ C6 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = layer->toString();
    CHECK_EQUAL( expected, actual )
    
    layer->remove( 6 );
    CHECK_EQUAL( 2, layer->getGroupCount() )
    CHECK_EQUAL( 6, layer->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    ssExpected << "{ C3 : Quarter }" << std::endl;
    ssExpected << "{ C4 : Quarter }" << std::endl;
    ssExpected << "{ C5 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = layer->toString();
    CHECK_EQUAL( expected, actual )
    
    layer->remove( 5 );
    CHECK_EQUAL( 1, layer->getGroupCount() )
    CHECK_EQUAL( 5, layer->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    ssExpected << "{ C3 : Quarter }" << std::endl;
    ssExpected << "{ C4 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = layer->toString();
    CHECK_EQUAL( expected, actual )
    
    layer->remove( 4 );
    CHECK_EQUAL( 1, layer->getGroupCount() )
    CHECK_EQUAL( 4, layer->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    ssExpected << "{ C3 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = layer->toString();
    CHECK_EQUAL( expected, actual )
    
    layer->remove( 3 );
    CHECK_EQUAL( 1, layer->getGroupCount() )
    CHECK_EQUAL( 3, layer->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    ssExpected << "{ C2 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = layer->toString();
    CHECK_EQUAL( expected, actual )
    
    layer->remove( 2 );
    CHECK_EQUAL( 1, layer->getGroupCount() )
    CHECK_EQUAL( 2, layer->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    ssExpected << "{ C1 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = layer->toString();
    CHECK_EQUAL( expected, actual )
    
    layer->remove( 1 );
    CHECK_EQUAL( 0, layer->getGroupCount() )
    CHECK_EQUAL( 1, layer->getCount() )
    ssExpected.str( "" );
    ssExpected << "{ C0 : Quarter }" << std::endl;
    expected = ssExpected.str();
    actual = layer->toString();
    CHECK_EQUAL( expected, actual )
    
    layer->remove( 0 );
    CHECK_EQUAL( 0, layer->getGroupCount() )
    CHECK_EQUAL( 0, layer->getCount() )
    ssExpected.str( "" );
    expected = ssExpected.str();
    actual = layer->toString();
    CHECK_EQUAL( expected, actual )
}
T_END
