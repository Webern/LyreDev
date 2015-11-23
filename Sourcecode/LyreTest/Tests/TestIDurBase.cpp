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
TEST( getValue, IDurBase )
{
    Rational val{ 4, 3 };
    String name{ "Test02" };
    IDurBaseUP d = createMockDurBase( val, name );
    CHECK_EQUAL( val, d->getValue() )
}
TEST( toStream, IDurBase )
{
    Rational val{ 9, 7 };
    String name{ "Test03" };
    IDurBaseUP d = createMockDurBase( val, name );
    stringstream ss;
    d->toStream( ss );
    CHECK_EQUAL( name, ss.str() )
}
TEST( streamingOperator, IDurBase )
{
    Rational val{ 9, 7 };
    String name{ "Test04" };
    IDurBaseUP d = createMockDurBase( val, name );
    stringstream ss;
    ss << (*d);
    CHECK_EQUAL( name, ss.str() )
}
TEST( toString, IDurBase )
{
    Rational val{ 12, 13 };
    String name{ "Test05" };
    IDurBaseUP d = createMockDurBase( val, name );
    CHECK_EQUAL( name, d->toString() )
}
TEST( isEqualTo1, IDurBase )
{
    IDurBaseFactoryUP factory = IDurBaseFactory::createDurBaseFactory( DurBaseFactoryType::Standard );
    auto durA = factory->createDur( "Eighth" );
    auto durB = createMockDurBase( Rational{ 1, 2 }, "Eighth" );
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
TEST( isEqualTo2, IDurBase )
{
    IDurBaseFactoryUP factory = IDurBaseFactory::createDurBaseFactory( DurBaseFactoryType::Standard );
    auto durA = factory->createDur( "Eighth" );
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
TEST( isGreaterThan, IDurBase )
{
    IDurBaseFactoryUP factory = IDurBaseFactory::createDurBaseFactory( DurBaseFactoryType::Standard );
    auto durA = factory->createDur( "Half" );
    auto durB = createMockDurBase( Rational{ 1, 1 }, "Quarter" );
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
TEST( isLessThan, IDurBase )
{
    IDurBaseFactoryUP factory = IDurBaseFactory::createDurBaseFactory( DurBaseFactoryType::Standard );
    auto durA = factory->createDur( "128th" );
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