//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IMeasureFactory.h"
#include "Lyre/IMeasure.h"
#include "Lyre/ITimeSignatureFactory.h"
#include "Lyre/INoteFactory.h"
#include "Lyre/IPitchFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/NoteGroup.h"

#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
    struct Factories
    {
        IMeasureFactoryUP measureFactory;
        ITimeSignatureFactoryUP timeSignatureFactory;
        INoteFactoryUP noteFactory;
        IPitchFactoryUP pitchFactory;
        IDurationFactoryUP durationFactory;

        Factories()
            :measureFactory( createMeasureFactory() )
            ,timeSignatureFactory( createTimeSignatureFactory() )
            ,noteFactory( createNoteFactory() )
            ,pitchFactory( createPitchFactory() )
            ,durationFactory( createDurationFactory() )
        {}

        inline IMeasureUP defaultMeasure()
        {
            return measureFactory->create();
        }

        inline IMeasureUP fourFour()
        {
            return measureFactory->create( 4, 4 );
        }

        inline IMeasureUP threeFour()
        {
            auto timeSig = timeSignatureFactory->create( 3, 4 );
            return measureFactory->create( timeSig );
        }

        inline IMeasureUP sevenEight()
        {
            auto timeSig = timeSignatureFactory->create( 7, 8 );
            return measureFactory->create( timeSig );
        }
        
        inline INoteUP note( int pitchValue, String durValue )
        {
			pitchFactory->setPitch( pitchValue );
			auto p = pitchFactory->createPitch();
			auto d = durationFactory->createDuration( durValue );
			return noteFactory->createNote( p, d );
        }
        
        inline INoteGroupUP noteGroup1()
        {
            INoteGroupUP noteGroup{ new NoteGroup{} };
            noteGroup->addNote( note( 1, STR_QUARTER) );
            noteGroup->addNote( note( 2, STR_QUARTER) );
            noteGroup->addNote( note( 3, STR_QUARTER) );
            return std::move( noteGroup );
        }
        
        inline INoteGroupUP noteGroup2()
        {
            INoteGroupUP noteGroup{ new NoteGroup{} };
            noteGroup->addNote( note( 11, STR_EIGHTH) );
            noteGroup->addNote( note( 12, STR_EIGHTH) );
            noteGroup->addNote( note( 13, STR_EIGHTH) );
            return std::move( noteGroup );
        }
        
        inline INoteGroupUP noteGroup3()
        {
            INoteGroupUP noteGroup{ new NoteGroup{} };
            noteGroup->addNote( note( 21, STR_16TH) );
            noteGroup->addNote( note( 22, STR_16TH) );
            noteGroup->addNote( note( 23, STR_16TH) );
            return std::move( noteGroup );
        }
        
        inline IMeasureUP measureA()
        {
            auto m = threeFour();
            m->addGroup( noteGroup3() );
            m->addGroup( noteGroup3() );
            m->addGroup( noteGroup2() );
            return m;
        }
        
        inline IMeasureUP measureB()
        {
            auto m = sevenEight();
            m->setLayerContext( 1 );
            m->addGroup( noteGroup1() );
            m->removeNote( 0 );
            m->addGroup( noteGroup2() );
            m->setLayerContext( 2 );
            m->addGroup( noteGroup3() );
            m->addGroup( noteGroup3() );
            m->addGroup( noteGroup3() );
            m->addGroup( noteGroup3() );
            m->addNote( note( 55, STR_EIGHTH ) );
            return m;
        }
    };
}

TEST( getTimeSignature_default, Measure )
{
    Factories f;
    IMeasureUP measure = f.defaultMeasure();
    ITimeSignatureUP timeSig = measure->getTimeSignature();
    CHECK_EQUAL( 4, timeSig->getTop() )
    CHECK_EQUAL( 4, timeSig->getBottom() )
}
T_END

TEST( getTimeSignature_fourFour, Measure )
{
    Factories f;
    IMeasureUP measure = f.defaultMeasure();
    ITimeSignatureUP timeSig = measure->getTimeSignature();
    CHECK_EQUAL( 4, timeSig->getTop() )
    CHECK_EQUAL( 4, timeSig->getBottom() )
}
T_END

TEST( getTimeSignature_threeFour, Measure )
{
    Factories f;
    IMeasureUP measure = f.threeFour();
    ITimeSignatureUP timeSig = measure->getTimeSignature();
    CHECK_EQUAL( 3, timeSig->getTop() )
    CHECK_EQUAL( 4, timeSig->getBottom() )
}
T_END

TEST( getTimeSignature_sevenEight, Measure )
{
    Factories f;
    IMeasureUP measure = f.sevenEight();
    ITimeSignatureUP timeSig = measure->getTimeSignature();
    CHECK_EQUAL( 7, timeSig->getTop() )
    CHECK_EQUAL( 8, timeSig->getBottom() )
}
T_END

TEST( getSetLayerContext_default, Measure )
{
    Factories f;
    IMeasureUP measure = f.threeFour();
    CHECK_EQUAL( 0, measure->getLayerContext() )
}
T_END

TEST( getSetLayerContext_0, Measure )
{
    Factories f;
    IMeasureUP measure = f.threeFour();
    measure->setLayerContext( 1 );
    measure->setLayerContext( 0 );
    CHECK_EQUAL( 0, measure->getLayerContext() )
}
T_END

TEST( getSetLayerContext_1, Measure )
{
    Factories f;
    IMeasureUP measure = f.threeFour();
    measure->setLayerContext( 1 );
    CHECK_EQUAL( 1, measure->getLayerContext() )
}
T_END

TEST( getSetLayerContext_throwNegative, Measure )
{
    Factories f;
    IMeasureUP measure = f.threeFour();
    try
    {
        measure->setLayerContext( -1 );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
    }
    CHECK_EQUAL( 0, measure->getLayerContext() )
}
T_END

TEST( getSetLayerContext_throwPositive, Measure )
{
    Factories f;
    IMeasureUP measure = f.threeFour();
    int tooBig = MAX_NUMBER_OF_LAYERS;
    try
    {
        measure->setLayerContext( tooBig );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch ( std::runtime_error& e )
    {
        String msg = e.what();
        CHECK( msg.size() > 0 )
    }
    CHECK_EQUAL( 0, measure->getLayerContext() )
}
T_END

TEST( toStreamA, Measure )
{
    Factories f;
    IMeasureUP m = f.measureA();
    std::stringstream ss;
    m->toStream( ss );
    String w2 = "  ";
    String w6 = w2 + w2 +w2;
    std::stringstream ex;
    ex << "Measure" << std::endl;
    ex << "{" << std::endl;
    ex << w2 << "Layer 0" << std::endl;
    ex << w2 << "{" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ B-1 : Eighth }" << std::endl;
    ex << w6 << "{ C0 : Eighth }" << std::endl;
    ex << w6 << "{ C#0 : Eighth }" << std::endl;
    ex << w2 << "}" << std::endl;
    ex << "}";
    String expected = ex.str();
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toStreamB, Measure )
{
    Factories f;
    IMeasureUP m = f.measureB();
    std::stringstream ss;
    m->toStream( ss );
    String w2 = "  ";
    String w6 = w2 + w2 +w2;
    std::stringstream ex;
    ex << "Measure" << std::endl;
    ex << "{" << std::endl;
    ex << w2 << "Layer 1" << std::endl;
    ex << w2 << "{" << std::endl;
    ex << w6 << "{ D-1 : Quarter }" << std::endl;
    ex << w6 << "{ Eb-1 : Quarter }" << std::endl;
    ex << w6 << "{ B-1 : Eighth }" << std::endl;
    ex << w6 << "{ C0 : Eighth }" << std::endl;
    ex << w6 << "{ C#0 : Eighth }" << std::endl;
    ex << w2 << "}" << std::endl;
    ex << w2 << "Layer 2" << std::endl;
    ex << w2 << "{" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ G3 : Eighth }" << std::endl;
    ex << w2 << "}" << std::endl;
    ex << "}";
    String expected = ex.str();
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( toStringA, Measure )
{
    Factories f;
    IMeasureUP m = f.measureA();
    String w2 = "  ";
    String w6 = w2 + w2 +w2;
    std::stringstream ex;
    ex << "Measure" << std::endl;
    ex << "{" << std::endl;
    ex << w2 << "Layer 0" << std::endl;
    ex << w2 << "{" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ B-1 : Eighth }" << std::endl;
    ex << w6 << "{ C0 : Eighth }" << std::endl;
    ex << w6 << "{ C#0 : Eighth }" << std::endl;
    ex << w2 << "}" << std::endl;
    ex << "}";
    String expected = ex.str();
    String actual = m->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( streamingOperatorB, Measure )
{
    Factories f;
    IMeasureUP m = f.measureB();
    std::stringstream ss;
    ss << (*m);
    String w2 = "  ";
    String w6 = w2 + w2 +w2;
    std::stringstream ex;
    ex << "Measure" << std::endl;
    ex << "{" << std::endl;
    ex << w2 << "Layer 1" << std::endl;
    ex << w2 << "{" << std::endl;
    ex << w6 << "{ D-1 : Quarter }" << std::endl;
    ex << w6 << "{ Eb-1 : Quarter }" << std::endl;
    ex << w6 << "{ B-1 : Eighth }" << std::endl;
    ex << w6 << "{ C0 : Eighth }" << std::endl;
    ex << w6 << "{ C#0 : Eighth }" << std::endl;
    ex << w2 << "}" << std::endl;
    ex << w2 << "Layer 2" << std::endl;
    ex << w2 << "{" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ A0 : 16th }" << std::endl;
    ex << w6 << "{ Bb0 : 16th }" << std::endl;
    ex << w6 << "{ B0 : 16th }" << std::endl;
    ex << w6 << "{ G3 : Eighth }" << std::endl;
    ex << w2 << "}" << std::endl;
    ex << "}";
    String expected = ex.str();
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getIsEmpty1, Measure )
{
    Factories f;
    IMeasureUP m = f.measureA();
    m->setLayerContext( 0 );
    for ( int i = 0; i < 9; ++i )
    {
        m->removeNote( 0 );
    }
    CHECK( m->getIsEmpty() )
}
T_END

TEST( getIsEmpty2, Measure )
{
    Factories f;
    IMeasureUP m = f.measureB();
    m->setLayerContext( 0 );
    CHECK( m->getIsEmpty() )
}
T_END

TEST( getIsEmpty3, Measure )
{
    Factories f;
    IMeasureUP m = f.measureFactory->create( 2, 8 );
    m->setLayerContext( MAX_NUMBER_OF_LAYERS - 1 );
    m->addNote( f.note( 33, STR_EIGHTH ) );
    CHECK( ! m->getIsEmpty() )
    m->setLayerContext( 0 );
    CHECK( m->getIsEmpty() );
}
T_END

TEST( getIsEmpty4, Measure )
{
    Factories f;
    IMeasureUP m = f.measureB();
    m->setLayerContext( 1 );
    CHECK( ! m->getIsEmpty() )
}
T_END

TEST( getIsComplete1, Measure )
{
    Factories f;
    IMeasureUP m = f.measureB();
    m->setLayerContext( 1 );
    CHECK( m->getIsComplete() )
    m->removeNote( 0 );
    CHECK( ! m->getIsComplete() )
}
T_END

TEST( getIsComplete2, Measure )
{
    Factories f;
    int size = 100;
    IMeasureUP m = f.measureFactory->create( size, 8 );
    m->setLayerContext( MAX_NUMBER_OF_LAYERS - 1 );
    for ( int i = 0; i < size; ++i )
    {
		m->addNote( f.note( i, STR_EIGHTH ) );
		bool expected = ( i == size - 1 );
        bool actual = m->getIsComplete();
        CHECK_EQUAL( expected, actual )
    }
}
T_END

TEST( getUnusedRemainingSimple, Measure )
{
    Factories f;
    IMeasureUP m = f.measureFactory->create( 4, 4 );
    Rational expected{ 4, 1 };
    CHECK_EQUAL( expected, m->getUnusedRemaining() );
    
    m->addNote( f.note( 1, STR_QUARTER ) );
    
    expected = Rational{ 3, 1 };
    CHECK_EQUAL( expected, m->getUnusedRemaining() );
}
T_END

TEST( getUnusedRemainingLoop, Measure )
{
    Factories f;
    int size = 10;
    IMeasureUP m = f.measureFactory->create( size, 4 );
    m->setLayerContext( MAX_NUMBER_OF_LAYERS - 1 );
    Rational max{ size, 1 };
    for ( int i = 0; i < size; ++i )
    {
		m->addNote( f.note( i, STR_QUARTER ) );
		Rational added{ ( i + 1 ), 1 };
        Rational expected = max - added;
        Rational actual = m->getUnusedRemaining();
        CHECK_EQUAL( expected, actual )
    }
}
T_END

TEST( getTotalDuration1, Measure )
{
    Factories f;
    IMeasureUP m = f.measureFactory->create( 7, 4 );
    m->setLayerContext( 1 );
    Rational expected{ 0, 1 };
    CHECK_EQUAL( expected, m->getTotalDuration() )
}
T_END

TEST( getTotalDuration2, Measure )
{
    Factories f;
    IMeasureUP m = f.measureFactory->create( 7, 4 );
    m->setLayerContext( 1 );
    m->addNote( f.note( 50, STR_16TH ) );
    m->addNote( f.note( 51, STR_EIGHTH ) );
    Rational expected{ 3, 4 };
    CHECK_EQUAL( expected, m->getTotalDuration() )
}
T_END

TEST( getTotalDuration3, Measure )
{
    Factories f;
    IMeasureUP m = f.measureFactory->create( 4, 4 );
    m->setLayerContext( 1 );
    m->addNote( f.note( 50, STR_16TH ) );
    m->addNote( f.note( 51, STR_EIGHTH ) );
    m->addNote( f.note( 50, STR_16TH ) );
    m->addNote( f.note( 51, STR_EIGHTH ) );
    m->addNote( f.note( 51, STR_EIGHTH ) );
    m->addNote( f.note( 51, STR_HALF ) );
    Rational expected{ 4, 1 };
    CHECK_EQUAL( expected, m->getTotalDuration() )
    m->setLayerContext( 0 );
    
    expected = Rational{ 0, 1 };
    CHECK_EQUAL( expected, m->getTotalDuration() )
    
}
T_END

TEST( getNote1, Measure )
{
    Factories f;
    IMeasureUP m = f.measureB();
    m->setLayerContext( 1 );
    auto& n = m->getNote( 0 );
    String expected = "{ D-1 : Quarter }";
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getNote2, Measure )
{
    Factories f;
    IMeasureUP m = f.measureB();
    m->setLayerContext( 1 );
    auto& n = m->getNote( 1 );
    String expected = "{ Eb-1 : Quarter }";
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( getNote3Throw, Measure )
{
    Factories f;
    IMeasureUP m = f.measureB();
    m->setLayerContext( 1 );
    bool isExceptionThrown = false;
    try
    {
        auto& n = m->getNote( 5 );
        String expected = "unreachable code";
        String actual = n->toString();
        CHECK_EQUAL( expected, actual )
        CHECK_FAIL( "exception was expected but not thrown" );
    } catch ( ... )
    {
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( getNote4Throw, Measure )
{
    Factories f;
    IMeasureUP m = f.measureB();
    m->setLayerContext( 1 );
    bool isExceptionThrown = false;
    try
    {
        auto& n = m->getNote( -1 );
        String expected = "unreachable code";
        String actual = n->toString();
        CHECK_EQUAL( expected, actual )
        CHECK_FAIL( "exception was expected but not thrown" );
    } catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( getNote5, Measure )
{
    Factories f;
    IMeasureUP m = f.measureB();
    m->setLayerContext( 2 );
    auto& n = m->getNote( 1 );
    String expected = "{ Bb0 : 16th }";
    String actual = n->toString();
    CHECK_EQUAL( expected, actual )
}
T_END

TEST( addNote, Measure )
{
    Factories f;
    IMeasureUP m = f.measureFactory->create( 2, 4 );
    CHECK( m->getIsEmpty() )
    m->addNote( f.note( 77, STR_HALF ) );
    CHECK( m->getIsComplete() );
}
T_END

TEST( addNoteThrowFull, Measure )
{
    Factories f;
    IMeasureUP m = f.measureFactory->create( 2, 4 );
    m->setLayerContext( 1 );
    m->addNote( f.note( 77, STR_HALF ) );
    bool isExceptionThrown = false;
    try
    {
        m->addNote( f.note( 31, STR_16TH ) );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e );
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( addNoteNull, Measure )
{
    Factories f;
    IMeasureUP m = f.measureFactory->create( 2, 4 );
    m->setLayerContext( 1 );
    m->addNote( f.note( 77, STR_HALF ) );
    bool isExceptionThrown = false;
    try
    {
        m->addNote( INoteUP{} );
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch ( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e );
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( removeNote, Measure )
{
    Factories f;
    int quarters = 5;
    IMeasureUP m = f.measureFactory->create( quarters, 4 );
    m->setLayerContext( 1 );
    m->addNote( f.note( 100, STR_QUARTER ) );
    m->addNote( f.note( 101, STR_QUARTER ) );
    m->addNote( f.note( 102, STR_QUARTER ) ); // remove this
    m->addNote( f.note( 103, STR_QUARTER ) );
    m->addNote( f.note( 104, STR_QUARTER ) );
    CHECK_EQUAL( quarters, m->getCount() )
    int index = 2;
    m->removeNote( index );
    CHECK_EQUAL( quarters-1, m->getCount() )
    auto& n = m->getNote( index );
    CHECK_EQUAL( 103, n->getPitch()->getValue() )
}
T_END

TEST( removeNoteAll, Measure )
{
    Factories f;
    int quarters = 5;
    IMeasureUP m = f.measureFactory->create( quarters, 4 );
    m->setLayerContext( 1 );
    m->addNote( f.note( 100, STR_QUARTER ) );
    m->addNote( f.note( 101, STR_QUARTER ) );
    m->addNote( f.note( 102, STR_QUARTER ) );
    m->addNote( f.note( 103, STR_QUARTER ) );
    m->addNote( f.note( 104, STR_QUARTER ) );
    CHECK_EQUAL( quarters, m->getCount() )
    m->removeNote( --quarters );
    m->removeNote( --quarters );
    m->removeNote( --quarters );
    m->removeNote( --quarters );
    m->removeNote( --quarters );
    CHECK_EQUAL( 0, m->getCount() )
}
T_END

TEST( getGroupCountA3, Measure )
{
    Factories f;
    auto m = f.measureA();
    CHECK_EQUAL( 3, m->getGroupCount() )
}
T_END

TEST( getGroupCountA0, Measure )
{
    Factories f;
    auto m = f.measureA();
    m->setLayerContext( 1 );
    CHECK_EQUAL( 0, m->getGroupCount() )
}
T_END

TEST( getGroupA2_0, Measure )
{
    Factories f;
    auto m = f.measureA();
    auto& group = m->getGroup( 2 );
    auto& n = group->getNote( 0 );
    CHECK_EQUAL( 11, n->getPitch()->getValue() )
}
T_END

TEST( getGroupA2_1, Measure )
{
    Factories f;
    auto m = f.measureA();
    auto& group = m->getGroup( 2 );
    auto& n = group->getNote( 1 );
    CHECK_EQUAL( 12, n->getPitch()->getValue() )
}
T_END

TEST( getGroupA2_2, Measure )
{
    Factories f;
    auto m = f.measureA();
    auto& group = m->getGroup( 2 );
    auto& n = group->getNote( 2 );
    CHECK_EQUAL( 13, n->getPitch()->getValue() )
}
T_END

TEST( getGroupA3Throw, Measure )
{
    Factories f;
    auto m = f.measureA();
    auto& group = m->getGroup( 2 );
    bool isExceptionThrown = false;
    try
    {
        auto& n = group->getNote( 3 );
        CHECK_EQUAL( 13, n->getPitch()->getValue() )
        CHECK_FAIL( "exception was expected but not thrown" )
    }
    catch( std::runtime_error& e )
    {
        UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    
}
T_END

TEST( getGroupIndex0, Measure )
{
    Factories f;
    auto m = f.measureB();
    m->setLayerContext( 2 );
    CHECK_EQUAL( 0, m->getGroupIndex( 0 ) )
}
T_END

TEST( getGroupIndex1, Measure )
{
    Factories f;
    auto m = f.measureB();
    m->setLayerContext( 2 );
    CHECK_EQUAL( 0, m->getGroupIndex( 1 ) )
}
T_END

TEST( getGroupIndex2, Measure )
{
    Factories f;
    auto m = f.measureB();
    m->setLayerContext( 2 );
    CHECK_EQUAL( 0, m->getGroupIndex( 2 ) )
}
T_END

TEST( getGroupIndex3, Measure )
{
    Factories f;
    auto m = f.measureB();
    m->setLayerContext( 2 );
    CHECK_EQUAL( 1, m->getGroupIndex( 3 ) )
}
T_END

TEST( getGroupIndex4, Measure )
{
    Factories f;
    auto m = f.measureB();
    m->setLayerContext( 2 );
    CHECK_EQUAL( 1, m->getGroupIndex( 4 ) )
}
T_END

TEST( getGroupIndex5, Measure )
{
    Factories f;
    auto m = f.measureB();
    m->setLayerContext( 2 );
    CHECK_EQUAL( 1, m->getGroupIndex( 5 ) )
}
T_END

TEST( getGroupIndex6, Measure )
{
    Factories f;
    auto m = f.measureB();
    m->setLayerContext( 2 );
    CHECK_EQUAL( 2, m->getGroupIndex( 6 ) )
}
T_END

TEST( getGroupIndex7, Measure )
{
    Factories f;
    auto m = f.measureB();
    m->setLayerContext( 2 );
    CHECK_EQUAL( 2, m->getGroupIndex( 7 ) )
}
T_END

TEST( getGroupIndex8, Measure )
{
    Factories f;
    auto m = f.measureB();
    m->setLayerContext( 2 );
    CHECK_EQUAL( 2, m->getGroupIndex( 8 ) )
}
T_END

TEST( getGroupIndex9, Measure )
{
    Factories f;
    auto m = f.measureB();
    m->setLayerContext( 2 );
    CHECK_EQUAL( 3, m->getGroupIndex( 9 ) )
}
T_END

TEST( getGroupIndex10, Measure )
{
    Factories f;
    auto m = f.measureB();
    m->setLayerContext( 2 );
    CHECK_EQUAL( 3, m->getGroupIndex( 10 ) )
}
T_END

TEST( getGroupIndex11, Measure )
{
    Factories f;
    auto m = f.measureB();
    m->setLayerContext( 2 );
    CHECK_EQUAL( 3, m->getGroupIndex( 11 ) )
}
T_END

TEST( getGroupIndex12, Measure )
{
    Factories f;
    auto m = f.measureB();
    m->setLayerContext( 2 );
    CHECK_EQUAL( -1, m->getGroupIndex( 12 ) )
}
T_END

TEST( getGroupIndex13Throw, Measure )
{
    Factories f;
    auto m = f.measureB();
    m->setLayerContext( 2 );
    bool isExceptionThrown = false;
    try
    {
        int index = m->getGroupIndex( 13 );
        CHECK_EQUAL( -1, index )
        CHECK_FAIL( "excpected exception but none was thrown" )
    }
    catch ( std::exception& e )
    {
		UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( addGroup, Measure )
{
    Factories f;
    auto m = f.measureFactory->create( 3, 4 );
    m->setLayerContext( 1 );
    INoteGroupUP ng{ new NoteGroup{} };
    ng->addNote( f.note( 50, STR_QUARTER ) );
    ng->addNote( f.note( 51, STR_QUARTER ) );
    ng->addNote( f.note( 52, STR_QUARTER ) );
    CHECK_EQUAL( 0, m->getGroupCount() )
    m->addGroup( ng );
    CHECK_EQUAL( 1, m->getGroupCount() )
}
T_END

TEST( addGroupThrowTooBig, Measure )
{
    Factories f;
    auto m = f.measureFactory->create( 3, 4 );
    m->setLayerContext( 1 );
    INoteGroupUP ng{ new NoteGroup{} };
    ng->addNote( f.note( 50, STR_QUARTER ) );
    ng->addNote( f.note( 51, STR_QUARTER ) );
    ng->addNote( f.note( 52, STR_QUARTER ) );
    ng->addNote( f.note( 53, STR_QUARTER ) );
    CHECK_EQUAL( 0, m->getGroupCount() )
    bool isExceptionThrown = false;
    try
    {
        m->addGroup( ng );
        CHECK_EQUAL( 1, m->getGroupCount() )
        CHECK_FAIL( "excpected exception but none was thrown" )
    }
    catch ( std::exception& e )
    {
		UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( addGroupThrowNull, Measure )
{
    Factories f;
    auto m = f.measureFactory->create( 3, 4 );
    m->setLayerContext( 1 );
    INoteGroupUP ng{};
    CHECK_EQUAL( 0, m->getGroupCount() )
    bool isExceptionThrown = false;
    try
    {
        m->addGroup( ng );
        CHECK_EQUAL( 1, m->getGroupCount() )
        CHECK_FAIL( "excpected exception but none was thrown" )
    }
    catch ( std::exception& e )
    {
		UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END

TEST( removeGroup, Measure )
{
    Factories f;
    auto m = f.measureFactory->create( 3, 4 );
    m->setLayerContext( 1 );
    INoteGroupUP ng{ new NoteGroup{} };
    ng->addNote( f.note( 50, STR_QUARTER ) );
    ng->addNote( f.note( 51, STR_QUARTER ) );
    ng->addNote( f.note( 52, STR_QUARTER ) );
    m->addGroup( ng );
    CHECK_EQUAL( 1, m->getGroupCount() )
    m->removeGroup( 0 );
    CHECK_EQUAL( 0, m->getGroupCount() )
}
T_END

TEST( removeThrow, Measure )
{
    Factories f;
    auto m = f.measureFactory->create( 3, 4 );
    m->setLayerContext( 1 );
    INoteGroupUP ng{ new NoteGroup{} };
    ng->addNote( f.note( 50, STR_QUARTER ) );
    ng->addNote( f.note( 51, STR_QUARTER ) );
    ng->addNote( f.note( 52, STR_QUARTER ) );
    m->addGroup( ng );
    CHECK_EQUAL( 1, m->getGroupCount() )
    bool isExceptionThrown = false;
    try
    {
        m->removeGroup( 1 );
        CHECK_EQUAL( 0, m->getGroupCount() )
        CHECK_FAIL( "excpected exception but none was thrown" )
    }
    catch ( std::exception& e )
    {
		UNUSED_PARAMETER( e )
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown )
}
T_END