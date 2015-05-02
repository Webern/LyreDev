#include "TestHarness.h"
#include "IPiece.h"
#include "Piece.h"
#include <string>

using namespace music;

TEST( PieceAcceptence01, Piece )
{
    PiecePtr = Piece::make();
    Piece->setTitle( "Orbital Music" );
    Piece->setComposer( "Matthew James Briggs" );
    Piece->setLyricist( "" );
    Piece->setCopyrightString( "© 2015 by Matthew James Briggs (ASCAP)" );
    
    
    A Piece can have one or many Movements.
    A Piece has a Title.
    A Piece has a Composer.
    A Piece has a CompletionDate.
    A Piece has a CopyrightDate.
    A Piece has a CopyrightString.
    A Piece has a Lyricist.
    A Piece has zero or many Name Value string pairs for OtherCredits.
        A Piece will return an IMovementIterator.
}