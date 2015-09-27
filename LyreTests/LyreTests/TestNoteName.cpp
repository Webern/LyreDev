#include "cpulTestHarness.h"
#include "NoteName.h"
#include <sstream>

using namespace lyre;
using namespace std;


TEST( defaultConstructor, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    CHECK_EQUAL( 0, n->getStepValue() )
    CHECK_EQUAL( 0, n->getAlterValue() )
    CHECK_EQUAL( 0, n->getValue() )
}
TEST( constructor01, NoteName )
{
    NoteNameUPtr n{ new NoteName{ 1, 2 } };
    CHECK_EQUAL( 1, n->getStepValue() )
    CHECK_EQUAL( 2, n->getAlterValue() )
    CHECK_EQUAL( 4, n->getValue() )
}
TEST( constructor02, NoteName )
{
    NoteNameUPtr n{ new NoteName{ "Ab" } };
    CHECK_EQUAL( 5, n->getStepValue() )
    CHECK_EQUAL( -1, n->getAlterValue() )
    CHECK_EQUAL( 8, n->getValue() )
}
TEST( copyConstructor, NoteName )
{
    NoteName orig{ "B" };
    NoteName copy{ orig };
    CHECK_EQUAL( 11, orig.getValue() )
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 11, orig.getValue() )
    CHECK_EQUAL( 0, copy.getValue() )
}
TEST( moveConstructor, NoteName )
{
    NoteName orig{ "B" };
    NoteName copy{ std::move( orig ) };
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 0, copy.getValue() )
}
TEST( assignment, NoteName )
{
    NoteName orig{ "B" };
    NoteName copy;
    copy = orig;
    CHECK_EQUAL( 11, orig.getValue() )
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 11, orig.getValue() )
    CHECK_EQUAL( 0, copy.getValue() )
}
TEST( moveAssignment, NoteName )
{
    NoteName orig{ "B" };
    NoteName copy;
    copy.operator=( std::move( orig ) );
    CHECK_EQUAL( 11, copy.getValue() )
    copy.setStepValue( 0 );
    CHECK_EQUAL( 0, copy.getValue() )
}
TEST( clone, NoteName )
{
    NoteNameUPtr orig{ new NoteName{ "B" } };
    INoteNameUPtr copy;
    CHECK( ! ( copy ) )
    copy = orig->clone();
    CHECK( ( copy ) )
    CHECK( ! ( copy.get() == orig.get() ) )
    CHECK_EQUAL( 11, orig->getValue() )
    CHECK_EQUAL( 11, copy->getValue() )
    copy->setStepValue( 0 );
    CHECK_EQUAL( 11, orig->getValue() )
    CHECK_EQUAL( 0, copy->getValue() )
}
TEST( copyTo, NoteName )
{
    NoteNameUPtr orig{ new NoteName{ "B" } };
    NoteNameUPtr copy;
    CHECK( ! ( copy ) )
    orig->copyTo( copy );
    CHECK( ( copy ) )
    CHECK( ! ( copy.get() == orig.get() ) )
    CHECK_EQUAL( 11, orig->getValue() )
    CHECK_EQUAL( 11, copy->getValue() )
    copy->setStepValue( 0 );
    CHECK_EQUAL( 11, orig->getValue() )
    CHECK_EQUAL( 0, copy->getValue() )
}

TEST( getValue01, NoteName )
{
    NoteNameUPtr n{ new NoteName{} };
    n->setStepValue( 0 );
    n->setAlterValue( 1 );
    CHECK_EQUAL( 1, n->getValue() )
}