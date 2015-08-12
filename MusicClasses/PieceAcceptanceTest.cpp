#include "TestHarness.h"
#include "Piece.h"
#include "Movement.h"
#include <string>

using namespace music;

TEST( PieceAcceptence01, Piece )
{
    PiecePtr p = makePiece();
    p->setTitle( "Orbital Music" );
    p->setComposer( "Matthew James Briggs" );
    p->setCopyrightString( "© 2015 by Matthew James Briggs (ASCAP)" );
    p->setLyricist( "Jack Swallow" );
    MovementPtr m1( new Movement() );
    MovementPtr m2( new Movement() );
    p->addMovement( m1 );
    p->addMovement( m2 );
    CHECK_EQUAL( p->getMovementSet().size(), 2 )
    auto mset = p->getMovementSet();
    for ( auto m : mset )
    {
        CHECK_EQUAL( m->getTitle(), "" )
    }
    CHECK_EQUAL( "Orbital Music", p->getTitle() )
    CHECK_EQUAL( "Matthew James Briggs", p->getComposer() )
    CHECK_EQUAL( "© 2015 by Matthew James Briggs (ASCAP)", p->getCopyrightString() )
    CHECK_EQUAL( "Jack Swallow", p->getLyricist() )
    
    
}