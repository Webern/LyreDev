#pragma once
#include "IPiece.h"
#include <memory>
#include <vector>

namespace music
{
	class Piece;
	using PiecePtr = std::shared_ptr<IPiece>;
	using PieceUPtr = std::shared_ptr<IPiece>;
	
    class Piece : public IPiece
	{
	public:
		virtual ~Piece() = default;
		virtual IPiecePtr clone() const;
		virtual IPieceUPtr uclone() const;
	};
}