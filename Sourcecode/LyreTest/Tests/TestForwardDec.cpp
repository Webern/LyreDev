//PRIVATE
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/ForwardDec.h"
#include <memory>

using namespace std;


TEST( forwardTest, FORWARD_DECLARE )
{
    FORWARD_DECLARE( TestFake )
    class TestFake
    {
        
    };
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
}
