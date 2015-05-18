#pragma once
#include <memory>
#include <vector>
#include <vector>

namespace music
{
	class IMovement;
	using IMovementPtr = std::shared_ptr<IMovement>;
	using IMovementUPtr = std::shared_ptr<IMovement>;
	u
    class IMovement
	{
	public:
		virtual ~IMovement() = default;
		IMovementPtr clone() const = 0;
		IMovementUPtr uclone() const = 0;
	};
}