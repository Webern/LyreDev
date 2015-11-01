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
    CHECK_EQUAL( "Write More Tests", "" )
}