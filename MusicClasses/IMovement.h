#pragma once
#include <memory>
#include <vector>
#include <vector>
#include "IEngravable.h"

namespace music
{
	class IMovement;
	using IMovementPtr = std::shared_ptr<IMovement>;
	using IMovementUPtr = std::shared_ptr<IMovement>;
	u
    class IMovement : public IEngravable
	{
	public:
		virtual ~IMovement() = default;
		IMovementPtr clone() const = 0;
		IMovementUPtr uclone() const = 0;
		bool getIsHidden() const = 0;
		void setIsHidden( const bool ) = 0;
	};
}