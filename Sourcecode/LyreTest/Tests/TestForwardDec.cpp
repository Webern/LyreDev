//PRIVATE
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include <memory>

using namespace std;

FORWARD_DECLARE( TestFake )
class TestFake
{

};

TEST( forwardTest, FORWARD_DECLARE )
{
    
    TestFakeUP up{ new TestFake{} };
    TestFakeSP sp = std::make_shared<TestFake>();
    TestFakeUPC upc{ new TestFake{} };
    TestFakeSPC spc = std::make_shared<TestFake>();
    
    VecTestFakeSP vecSP;
    vecSP.push_back( sp );
    VecTestFakeUP vecUP;
    vecUP.push_back( std::move( up ) );
    VecTestFakeSPC vecSPC;
    vecSPC.push_back( spc );
    VecTestFakeUPC vecUPC;
    vecUPC.push_back( std::move( upc ) );

	CHECK_EQUAL( 1, static_cast<int>( vecSP.size() ) )
}
T_END
