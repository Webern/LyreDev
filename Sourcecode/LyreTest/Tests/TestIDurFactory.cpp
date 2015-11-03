//PUBLIC

#include "LyreTest/cpul/cpulTestHarness.h"
#include "LyreTest/Mock/MockDurFactory.h"
#include "LyreTest/Mock/MockDur.h"

#include "Lyre/IDurFactory.h"

using namespace Lyre;
using namespace Lyre::Mock;
using namespace std;

TEST( createMockDurFactory, IDurFactory )
{
    Mock::MockDurs durs;
    
    Rational val{ 1, 4 };
    String name{ "OneFourth" };
    auto dur = createMockDur( val, name );
    durs.insert( std::pair<String, IDurSP>( name, dur ) );
    
    val = Rational{ 7, 3 };
    name = String{ "SevenThirds" };
    dur = createMockDur( val, name );
    durs.insert( std::pair<String, IDurSP>( name, dur ) );
    
    IDurFactorySP factory = createMockDurFactory( std::move( durs ) );
    
    CHECK( factory != nullptr )
}

TEST( createDur, IDurFactory )
{
    Mock::MockDurs durs;
    
    Rational val{ 13, 1 };
    String name{ "Bones" };
    auto dur = createMockDur( val, name );
    durs.insert( std::pair<String, IDurSP>( name, dur ) );
    
    val = Rational{ 12, 1 };
    name = String{ "Bishop" };
    dur = createMockDur( val, name );
    durs.insert( std::pair<String, IDurSP>( name, dur ) );
    
    IDurFactorySP factory = createMockDurFactory( std::move( durs ) );
    IDurSP d = factory->createDur( "Bones" );
    
    CHECK_EQUAL( ( Rational{ 13, 1 } ), d->getValue() )
    CHECK_EQUAL( "Bones", d->toString() )
}

TEST( createDur2, IDurFactory )
{
    Mock::MockDurs durs;
    
    Rational val{ -1, 2 };
    String name{ "Cheese" };
    auto dur = createMockDur( val, name );
    durs.insert( std::pair<String, IDurSP>( name, dur ) );
    
    val = Rational{ 2, 1 };
    name = String{ "Pizza" };
    dur = createMockDur( val, name );
    durs.insert( std::pair<String, IDurSP>( name, dur ) );
    
    IDurFactorySP factory = createMockDurFactory( std::move( durs ) );
    IDurSP d = factory->createDur( "Cheese" );
    
    CHECK_EQUAL( ( Rational{ -1, 2 } ), d->getValue() )
    CHECK_EQUAL( "Cheese", d->toString() )
}

TEST( throw1, IDurFactory )
{
    Mock::MockDurs durs;
    
    Rational val{ -1, 2 };
    String name{ "Cheese" };
    auto dur = createMockDur( val, name );
    durs.insert( std::pair<String, IDurSP>( name, dur ) );
    
    val = Rational{ 2, 1 };
    name = String{ "Pizza" };
    dur = createMockDur( val, name );
    durs.insert( std::pair<String, IDurSP>( name, dur ) );
    
    IDurFactorySP factory = createMockDurFactory( std::move( durs ) );
    
    String expected{ "invalid mock dur name" };
    String actual{ "" };
    
    try
    {
        IDurSP d = factory->createDur( "Bogus" );
    }
    catch ( std::exception& ex )
    {
        actual = ex.what();
    }
    
    CHECK_EQUAL( expected, actual )
}

TEST( throw2, IDurFactory )
{
    Mock::MockDurs durs;
    
    IDurSP dur;
    durs.insert( std::pair<String, IDurSP>( "Null1", dur ) );
    durs.insert( std::pair<String, IDurSP>( "Null2", dur ) );

    IDurFactorySP factory = createMockDurFactory( std::move( durs ) );
    
    String expected{ "MockDurFactory attempted to dereference a null IDur pointer" };
    String actual{ "" };
    
    try
    {
        IDurSP d = factory->createDur( "Null2" );
    }
    catch ( std::exception& ex )
    {
        actual = ex.what();
    }
    
    CHECK_EQUAL( expected, actual )
}