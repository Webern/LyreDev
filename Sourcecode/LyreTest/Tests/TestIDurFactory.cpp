//PUBLIC

#include "LyreTest/cpul/cpulTestHarness.h"
#include "LyreTest/Mock/MockDurBaseFactory.h"
#include "LyreTest/Mock/MockDur.h"

#include "Lyre/IDurBaseFactory.h"

using namespace Lyre;
using namespace Lyre::Mock;
using namespace std;

TEST( createMockDurBaseFactory, IDurBaseFactory )
{
    Mock::MockDurs durs;
    
    Rational val{ 1, 4 };
    String name{ "OneFourth" };
    auto dur = createMockDur( val, name );
    durs.insert( std::pair<String, IDurBaseSP>( name, dur ) );
    
    val = Rational{ 7, 3 };
    name = String{ "SevenThirds" };
    dur = createMockDur( val, name );
    durs.insert( std::pair<String, IDurBaseSP>( name, dur ) );
    
    IDurBaseFactorySP factory = createMockDurBaseFactory( std::move( durs ) );
    
    CHECK( factory != nullptr )
}

TEST( createDur, IDurBaseFactory )
{
    Mock::MockDurs durs;
    
    Rational val{ 13, 1 };
    String name{ "Bones" };
    auto dur = createMockDur( val, name );
    durs.insert( std::pair<String, IDurBaseSP>( name, dur ) );
    
    val = Rational{ 12, 1 };
    name = String{ "Bishop" };
    dur = createMockDur( val, name );
    durs.insert( std::pair<String, IDurBaseSP>( name, dur ) );
    
    IDurBaseFactorySP factory = createMockDurBaseFactory( std::move( durs ) );
    IDurBaseSP d = factory->createDur( "Bones" );
    
    CHECK_EQUAL( ( Rational{ 13, 1 } ), d->getValue() )
    CHECK_EQUAL( "Bones", d->toString() )
}

TEST( createDur2, IDurBaseFactory )
{
    Mock::MockDurs durs;
    
    Rational val{ -1, 2 };
    String name{ "Cheese" };
    auto dur = createMockDur( val, name );
    durs.insert( std::pair<String, IDurBaseSP>( name, dur ) );
    
    val = Rational{ 2, 1 };
    name = String{ "Pizza" };
    dur = createMockDur( val, name );
    durs.insert( std::pair<String, IDurBaseSP>( name, dur ) );
    
    IDurBaseFactorySP factory = createMockDurBaseFactory( std::move( durs ) );
    IDurBaseSP d = factory->createDur( "Cheese" );
    
    CHECK_EQUAL( ( Rational{ -1, 2 } ), d->getValue() )
    CHECK_EQUAL( "Cheese", d->toString() )
}

TEST( throw1, IDurBaseFactory )
{
    Mock::MockDurs durs;
    
    Rational val{ -1, 2 };
    String name{ "Cheese" };
    auto dur = createMockDur( val, name );
    durs.insert( std::pair<String, IDurBaseSP>( name, dur ) );
    
    val = Rational{ 2, 1 };
    name = String{ "Pizza" };
    dur = createMockDur( val, name );
    durs.insert( std::pair<String, IDurBaseSP>( name, dur ) );
    
    IDurBaseFactorySP factory = createMockDurBaseFactory( std::move( durs ) );
    
    String expected{ "invalid mock dur name" };
    String actual{ "" };
    
    try
    {
        IDurBaseSP d = factory->createDur( "Bogus" );
    }
    catch ( std::exception& ex )
    {
        actual = ex.what();
    }
    
    CHECK_EQUAL( expected, actual )
}

TEST( throw2, IDurBaseFactory )
{
    Mock::MockDurs durs;
    
    IDurBaseSP dur;
    durs.insert( std::pair<String, IDurBaseSP>( "Null1", dur ) );
    durs.insert( std::pair<String, IDurBaseSP>( "Null2", dur ) );

    IDurBaseFactorySP factory = createMockDurBaseFactory( std::move( durs ) );
    
    String expected{ "MockDurBaseFactory attempted to dereference a null IDurBase pointer" };
    String actual{ "" };
    
    try
    {
        IDurBaseSP d = factory->createDur( "Null2" );
    }
    catch ( std::exception& ex )
    {
        actual = ex.what();
    }
    
    CHECK_EQUAL( expected, actual )
}