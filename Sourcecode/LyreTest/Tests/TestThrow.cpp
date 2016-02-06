//PRIVATE
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Private/throw.h"
#include <sstream>
#include <locale>

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
    
    // some differences between the clang and visual
    // studio preprocessors make the string a little
    // different between the two platforms, so this
    // test checks the parts of the string that are
    // similar (after eliminating casing differences)
    
    std::string expected = "error in TestThrow.cpp (line 14) runTest: some error message";
    std::string actual = message;
	std::locale loc;
    for ( auto it = expected.begin(); it != expected.end(); ++it )
    {
        *it = std::tolower( *it, loc );
    }
    for ( auto it = actual.begin(); it != actual.end(); ++it )
    {
        *it = std::tolower( *it, loc );
    }
    CHECK_EQUAL( expected.substr( 0, 33 ), actual.substr( 0, 33 ) )
    CHECK_EQUAL( expected.substr( expected.size()-13 ), actual.substr( actual.size()-13 ) )
}
