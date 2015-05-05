#pragma once
#include <memory>
#include <vector>
#include "IEngravable.h"

namespace music
{
	class IPiece;
	using IPiecePtr = std::shared_ptr<IPiece>;
	using IPieceUPtr = std::shared_ptr<IPiece>;
	
    class IPiece : public IEngravable
	{
	public:
		virtual ~IPiece() = default;
		virtual IPiecePtr clone() const = 0;
		virtual IPieceUPtr uclone() const = 0;
		virtual bool getIsHidden() const = 0;
		virtual void setIsHidden( const bool ) = 0;
	};
}