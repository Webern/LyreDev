//PUBLIC

#include "LyreTest/cpul/cpulTestHarness.h"
#include "LyreTest/Mock/MockDurBaseFactory.h"
#include "LyreTest/Mock/MockDurBase.h"

#include "Lyre/IDurBaseFactory.h"

using namespace Lyre;
using namespace Lyre::Mock;
using namespace std;

TEST( createMockDurBaseFactory, IDurBaseFactory )
{
    Mock::MockDurBases durs;
    
    Rational val{ 1, 4 };
    String name{ "OneFourth" };
    auto dur1 = createMockDurBase( val, name );
    durs.insert( std::pair<String, IDurBaseUP>( name, std::move( dur1 ) ) );
    
    val = Rational{ 7, 3 };
    name = String{ "SevenThirds" };
    auto dur2 = createMockDurBase( val, name );
    durs.insert( std::pair<String, IDurBaseUP>( name, std::move( dur2 ) ) );
    
    IDurBaseFactorySP factory = createMockDurBaseFactory( std::move( durs ) );
    
    CHECK( factory != nullptr )
}
T_END

TEST( createDur, IDurBaseFactory )
{
    Mock::MockDurBases durs;

    Rational val{ 13, 1 };
    String name{ "Bones" };
    auto dur1 = createMockDurBase( val, name );
    durs.insert( std::pair<String, IDurBaseUP>( name, std::move( dur1 ) ) );
    
    val = Rational{ 12, 1 };
    name = String{ "Bishop" };
    auto dur2 = createMockDurBase( val, name );
    //durs.insert( std::pair<String, IDurBaseUP>( name, std::move( dur2 ) ) );
    
    IDurBaseFactorySP factory = createMockDurBaseFactory( std::move( durs ) );
    IDurBaseUP d = factory->createDur( "Bones" );

    CHECK_EQUAL( ( Rational{ 13, 1 } ), d->getValue() )
    CHECK_EQUAL( "Bones", d->toString() )
}
T_END

TEST( createDur2, IDurBaseFactory )
{
    Mock::MockDurBases durs;
    
    Rational val{ -1, 2 };
    String name{ "Cheese" };
    auto dur1 = createMockDurBase( val, name );
    durs.insert( std::pair<String, IDurBaseUP>( name, std::move( dur1 ) ) );
    
    val = Rational{ 2, 1 };
    name = String{ "Pizza" };
    auto dur2 = createMockDurBase( val, name );
    durs.insert( std::pair<String, IDurBaseUP>( name, std::move( dur2 ) ) );
    
    IDurBaseFactorySP factory = createMockDurBaseFactory( std::move( durs ) );
    IDurBaseUP d = factory->createDur( "Cheese" );
    
    CHECK_EQUAL( ( Rational{ -1, 2 } ), d->getValue() )
    CHECK_EQUAL( "Cheese", d->toString() )
}
T_END

TEST( throw1, IDurBaseFactory )
{
    Mock::MockDurBases durs;
    
    Rational val{ -1, 2 };
    String name{ "Cheese" };
    auto dur1 = createMockDurBase( val, name );
    durs.insert( std::pair<String, IDurBaseUP>( name, std::move( dur1 ) ) );
    
    val = Rational{ 2, 1 };
    name = String{ "Pizza" };
    auto dur2 = createMockDurBase( val, name );
    durs.insert( std::pair<String, IDurBaseUP>( name, std::move( dur2 ) ) );
    
    IDurBaseFactorySP factory = createMockDurBaseFactory( std::move( durs ) );
    
    String expected{ "invalid mock dur name" };
    String actual{ "" };
    
    try
    {
        IDurBaseUP d = factory->createDur( "Bogus" );
    }
    catch ( std::exception& ex )
    {
        actual = ex.what();
    }
    auto foundPosition = actual.find( expected );
    bool success = ( foundPosition != String::npos );
    CHECK( success )
}
T_END

TEST( throw2, IDurBaseFactory )
{
    Mock::MockDurBases durs;
    
    IDurBaseUP nullDur1;
    IDurBaseUP nullDur2;
    durs.insert( std::pair<String, IDurBaseUP>( "Null1", std::move( nullDur1 ) ) );
    durs.insert( std::pair<String, IDurBaseUP>( "Null2", std::move( nullDur2 ) ) );

    IDurBaseFactorySP factory = createMockDurBaseFactory( std::move( durs ) );
    
    String expected{ "MockDurBaseFactory attempted to dereference a null IDurBase pointer" };
    String actual{ "" };
    
    try
    {
        IDurBaseUP d = factory->createDur( "Null2" );
    }
    catch ( std::exception& ex )
    {
        actual = ex.what();
    }
    auto foundPosition = actual.find( expected );
    bool success = ( foundPosition != String::npos );
    CHECK( success )
}
T_END