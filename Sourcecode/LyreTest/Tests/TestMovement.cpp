//PUBLIC
#include "TestMovment.h"

#include <sstream>

using namespace Lyre;
using namespace std;



TEST( basicTest, Movement )
{
    Factories f;
    auto movement = f.createMovement( 1, "Mladic" );
    CHECK_EQUAL( 3, movement->getPartCount() )
    CHECK_EQUAL( "1. Mladic", movement->getSpec()->getDisplayTitle() )
    auto part = movement->getPart( 0 );
    CHECK_EQUAL( 10, part->getMeasureCount() )
    auto measure = part->getMeasure( 5 );
    CHECK_EQUAL( 7, measure->getTimeSignature()->getTop() )
    CHECK_EQUAL( 8, measure->getTimeSignature()->getBottom() )
    measure->addNote( f.createNote( "G4", "Quarter", 1 ) );
    measure->addNote( f.createNote( "A4", "Quarter" ) );
    measure->addNote( f.createNote( "B4", "Quarter" ) );
    part = movement->getPart( 2 );
    part->setStaffContext( 1 );
    measure = part->getMeasure( 3 );
    measure->setLayerContext( 1 );
    measure->addNote( f.createNote( "B4", "Quarter" ) );
    measure->addNote( f.createNote( "C5", "Quarter" ) );
    measure->addNote( f.createNote( "D6", "Quarter" ) );
    measure->addNote( f.createNote( "E6", "Quarter" ) );
    movement->toStream( std::cout );
    CHECK_EQUAL( "", "." )
}
T_END
