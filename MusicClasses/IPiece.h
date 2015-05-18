#pragma once
#include <memory>
#include <vector>

namespace music
{
	class IPiece;
	using IPiecePtr = std::shared_ptr<IPiece>;
	using IPieceUPtr = std::shared_ptr<IPiece>;
	
    class IPiece
	{
	public:
		virtual ~IPiece() = default;
		virtual IPiecePtr clone() const = 0;
		virtual IPieceUPtr uclone() const = 0;
	};
}