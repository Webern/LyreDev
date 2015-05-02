#pragma once
#include <memory>
#include <vector>

namespace music
{
	class IEngravable;
	using IEngravablePtr = std::shared_ptr<IEngravable>;
	using IEngravableUPtr = std::shared_ptr<IEngravable>;
	class IEngravable
	{
	public:
		virtual ~IEngravable() = default;
		IEngravablePtr clone() const = 0;
		IEngravableUPtr uclone() const = 0;
		bool getIsHidden() const = 0;
		void setIsHidden( const bool ) = 0;
	};
}