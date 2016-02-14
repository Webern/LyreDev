//PRIVATE
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Private/makeUnique.h"
#include <memory>
#include <sstream>

#if 1==0

using namespace Lyre;
using namespace Lyre::Private;
using namespace std;

namespace
{
    class Cat
    {
    public:
        String getName() const { return "Bishop"; }
    };
    using CatUP = std::unique_ptr<Cat>;
    
    class Nothing
    {
    public:
        Nothing( int a, int b, int c, int d, int e, int f )
        :myA(a),myB(b),myC(c),myD(d),myE(e),myF(f) {}
        int getSum() const { return myA+myB+myC+myD+myE+myF; }
    private:
        int myA, myB, myC, myD, myE, myF;
    };
    using NothingUP = std::unique_ptr<Nothing>;
}

TEST( NoParams, makeUnique )
{
    CatUP cat = makeUnique<Cat>();
    CHECK_EQUAL( "Bishop", cat->getName() )
}
TEST( Params, makeUnique )
{
    NothingUP nada = makeUnique<Nothing>(1,2,3,4,5,6);
    CHECK_EQUAL( 21, nada->getSum() )
}

#endif