#include "TestHarness.h"
#include "IPiece.h"
#include "Piece.h"
#include "Movement.h"
#include <string>

using namespace music;

TEST( PieceAcceptence01, Piece )
{
    IPiecePtr p = Piece::make();
    p->setTitle( "Orbital Music" );
    p->setComposer( "Matthew James Briggs" );
    p->setCopyrightString( "© 2015 by Matthew James Briggs (ASCAP)" );
    p->setLyricist( "Jack Swallow" );
    MovementPtr m1 = Movement::make();
    MovementPtr m2 = Movement::make();
    p->addMovement( m1 );
    p->addMovement( m2 );
    CHECK_EQUAL( p->getMovementCount(), 2 )
    auto mset = p->getMovementSet();
    for ( auto m : mset )
    {
        CHECK_EQUAL( m->getTitle(), "" )
    }
    CHECK_EQUAL( "Orbital Music", p->getTitle() )
    CHECK_EQUAL( "Matthew Hames Briggs", p->getComposer() )
    CHECK_EQUAL( "© 2015 by Matthew James Briggs (ASCAP)", p->getCopyrightString() )
    CHECK_EQUAL( "Jack Swallow", p->getLyricist() )
    
    /*
    A Piece can have one or many Movements.
    A Piece has a Title.
    A Piece has a Composer.
    A Piece has a CompletionDate.
    A Piece has a CopyrightDate.
    A Piece has a CopyrightString.
    A Piece has a Lyricist.
    // later... if needed A Piece has zero or many Name Value string pairs for OtherCredits.
    A Piece will return an IMovementIterator.
    */
}