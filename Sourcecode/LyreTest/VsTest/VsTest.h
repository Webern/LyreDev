#pragma once
#include <cmath>

#define T_END };  \
      \


#define TEST( functionName, className ) \
    \
using namespace Microsoft::VisualStudio::TestTools::UnitTesting; \
    \
[TestClass] \
    \
public ref class Test##className##functionName \
{ \
public: \
\
    [TestMethod] \
    void className##_##functionName####() \


#define COMBINE1(X,Y) X##Y  // helper macro
#define COMBINE(X,Y) COMBINE1(X,Y)
#define FAKE_FUNC void COMBINE(fakeFunc,__LINE__)() {

#undef CHECK
#ifndef CHECK
#define CHECK(statementToCheck) \
    Assert::IsTrue(!(!(##statementToCheck))); 
#endif

#ifndef CHECK_EQUAL
#define CHECK_EQUAL( expected, actual ) \
    Assert::IsTrue( (##expected ) == (##actual ) ); 
#endif

#define CHECK_DOUBLES_EQUAL(expected,actual,epsilon) \
    CHECK( std::abs((##expected)-(##actual))<(##epsilon) )