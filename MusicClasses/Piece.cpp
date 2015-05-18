#include "Piece.h"

namespace music
{
    IPiecePtr Piece::clone() const
    {
        return std::make_shared<Piece>( *this );
    }
    IPieceUPtr Piece::uclone() const
    {
        return PieceUPtr( new Piece( * this ) );
    }
}