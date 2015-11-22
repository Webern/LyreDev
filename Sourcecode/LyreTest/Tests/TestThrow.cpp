//PRIVATE
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Private/throw.h"
#include <sstream>

using namespace std;

TEST( Compiles, throwDotH )
{
    std::string message = "no exception was thrown";
    try
    {
        THROW("some error message")
    }
    catch( std::exception& e )
    {
        message = e.what();
    }
    std::string expected = "error in TestThrow.cpp (line 13) runTest: some error message";
    std::string actual = message;
    CHECK_EQUAL( expected, actual )
}
