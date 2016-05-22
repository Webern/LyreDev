//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "LyreTest/Mock/MockDurBase.h"
#include "Lyre/IDurBase.h"
#include "Lyre/IDurBaseFactory.h"

using namespace Lyre;
using namespace Lyre::Mock;
using namespace std;

TEST( createMockDur, IDurBase )
{
    Rational val{ 3, 4 };
    String name{ "Test01" };
    IDurBaseUP d = createMockDurBase( val, name );
    CHECK( d != nullptr )
}
T_END

TEST( getValue, IDurBase )
{
    Rational val{ 4, 3 };
    String name{ "Test02" };
    IDurBaseUP d = createMockDurBase( val, name );
    CHECK_EQUAL( val, d->getValue() )
}
T_END

TEST( toStream, IDurBase )
{
    Rational val{ 9, 7 };
    String name{ "Test03" };
    IDurBaseUP d = createMockDurBase( val, name );
    stringstream ss;
    d->toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( streamingOperator, IDurBase )
{
    Rational val{ 9, 7 };
    String name{ "Test04" };
    IDurBaseUP d = createMockDurBase( val, name );
    stringstream ss;
    ss << (*d);
    CHECK_EQUAL( name, ss.str() )
}
T_END

TEST( toString, IDurBase )
{
    Rational val{ 12, 13 };
    String name{ "Test05" };
    IDurBaseUP d = createMockDurBase( val, name );
    CHECK_EQUAL( name, d->toString() )
}
T_END

TEST( isEqualTo1, IDurBase )
{
    IDurBaseFactoryUP factory = createDurBaseFactory( DurBaseFactoryType::Standard );
    auto durA = factory->createDur( STR_EIGHTH );
    auto durB = createMockDurBase( Rational{ 1, 2 }, STR_EIGHTH );
    CHECK(   durA->isIdenticalTo( *durB ) )
    CHECK(   durA->isIdenticalTo( *durB ) )
    CHECK(   durA->isEqualTo( *durB ) )
    CHECK(   durB->isEqualTo( *durA ) )
    CHECK( ! durA->isGreaterThan( *durB ) )
    CHECK( ! durB->isGreaterThan( *durA ) )
    CHECK( ! durA->isLessThan( *durB ) )
    CHECK( ! durB->isLessThan( *durA ) )
    
    CHECK(   ( *durA == *durB ) )
    CHECK(   ( *durB == *durA ) )
    CHECK( ! ( *durA != *durB ) )
    CHECK( ! ( *durB != *durA ) )
    CHECK(   ( *durA >= *durB ) )
    CHECK(   ( *durB >= *durA ) )
    CHECK(   ( *durA <= *durB ) )
    CHECK(   ( *durB <= *durA ) )
    CHECK( ! ( *durA > *durB ) )
    CHECK( ! ( *durB > *durA ) )
    CHECK( ! ( *durA < *durB ) )
    CHECK( ! ( *durB < *durA ) )
}
T_END

TEST( isEqualTo2, IDurBase )
{
    IDurBaseFactoryUP factory = createDurBaseFactory( DurBaseFactoryType::Standard );
    auto durA = factory->createDur( STR_EIGHTH );
    auto durB = createMockDurBase( Rational{ 1, 2 }, "Different" );
    CHECK( ! durA->isIdenticalTo( *durB ) )
    CHECK( ! durA->isIdenticalTo( *durB ) )
    CHECK(   durA->isEqualTo( *durB ) )
    CHECK(   durB->isEqualTo( *durA ) )
    CHECK( ! durA->isGreaterThan( *durB ) )
    CHECK( ! durB->isGreaterThan( *durA ) )
    CHECK( ! durA->isLessThan( *durB ) )
    CHECK( ! durB->isLessThan( *durA ) )
    
    CHECK(   ( *durA == *durB ) )
    CHECK(   ( *durB == *durA ) )
    CHECK( ! ( *durA != *durB ) )
    CHECK( ! ( *durB != *durA ) )
    CHECK(   ( *durA >= *durB ) )
    CHECK(   ( *durB >= *durA ) )
    CHECK(   ( *durA <= *durB ) )
    CHECK(   ( *durB <= *durA ) )
    CHECK( ! ( *durA > *durB ) )
    CHECK( ! ( *durB > *durA ) )
    CHECK( ! ( *durA < *durB ) )
    CHECK( ! ( *durB < *durA ) )
}
T_END

TEST( isGreaterThan, IDurBase )
{
    IDurBaseFactoryUP factory = createDurBaseFactory( DurBaseFactoryType::Standard );
    auto durA = factory->createDur( STR_HALF );
    auto durB = createMockDurBase( Rational{ 1, 1 }, STR_QUARTER );
    CHECK( ! durA->isIdenticalTo( *durB ) )
    CHECK( ! durA->isIdenticalTo( *durB ) )
    CHECK( ! durA->isEqualTo( *durB ) )
    CHECK( ! durB->isEqualTo( *durA ) )
    CHECK(   durA->isGreaterThan( *durB ) )
    CHECK( ! durB->isGreaterThan( *durA ) )
    CHECK( ! durA->isLessThan( *durB ) )
    CHECK(   durB->isLessThan( *durA ) )
    
    CHECK( ! ( *durA == *durB ) )
    CHECK( ! ( *durB == *durA ) )
    CHECK(   ( *durA != *durB ) )
    CHECK(   ( *durB != *durA ) )
    CHECK(   ( *durA >= *durB ) )
    CHECK( ! ( *durB >= *durA ) )
    CHECK( ! ( *durA <= *durB ) )
    CHECK(   ( *durB <= *durA ) )
    CHECK(   ( *durA > *durB ) )
    CHECK( ! ( *durB > *durA ) )
    CHECK( ! ( *durA < *durB ) )
    CHECK(   ( *durB < *durA ) )
}
T_END

TEST( isLessThan, IDurBase )
{
    IDurBaseFactoryUP factory = createDurBaseFactory( DurBaseFactoryType::Standard );
    auto durA = factory->createDur( STR_128TH );
    auto durB = createMockDurBase( Rational{ 1000, 1 }, "Very Large" );
    CHECK( ! durA->isIdenticalTo( *durB ) )
    CHECK( ! durA->isIdenticalTo( *durB ) )
    CHECK( ! durA->isEqualTo( *durB ) )
    CHECK( ! durB->isEqualTo( *durA ) )
    CHECK( ! durA->isGreaterThan( *durB ) )
    CHECK(   durB->isGreaterThan( *durA ) )
    CHECK(   durA->isLessThan( *durB ) )
    CHECK( ! durB->isLessThan( *durA ) )
    
    CHECK( ! ( *durA == *durB ) )
    CHECK( ! ( *durB == *durA ) )
    CHECK(   ( *durA != *durB ) )
    CHECK(   ( *durB != *durA ) )
    CHECK( ! ( *durA >= *durB ) )
    CHECK(   ( *durB >= *durA ) )
    CHECK(   ( *durA <= *durB ) )
    CHECK( ! ( *durB <= *durA ) )
    CHECK( ! ( *durA > *durB ) )
    CHECK(   ( *durB > *durA ) )
    CHECK(   ( *durA < *durB ) )
    CHECK( ! ( *durB < *durA ) )
}
T_END
