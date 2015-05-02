#pragma once
#include <memory>
#include <vector>

namespace music
{
	class IClef;
	using IClefPtr = std::shared_ptr<IClef>;
	using IClefUPtr = std::shared_ptr<IClef>;

	class IClef : public IEngravable
	{
	public:
		virtual ~IClef() = default;
		IClefPtr clone() const = 0;
		IClefUPtr uclone() const = 0;
		bool getIsHidden() const = 0;
		void setIsHidden( const bool ) = 0;
	};
}