#include "TestHarness.h"
#include "Piece.h"
#include "PartStack.h"
#include "Movement.h"
#include <string>

using namespace music;

TEST( MovementAcceptence01, Movement )
{
    MovementPtr m1 = makeMovement();
    m1->setTitle( "I. Allegro" );
    PartStackPtr partStack = makePartStack();
    m1->setPartStack( partStack );
    CHECK_EQUAL( "I. Allegro", m1->getTitle() );
}