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
		virtual IClefPtr clone() const = 0;
		virtual IClefUPtr uclone() const = 0;
		virtual bool getIsHidden() const = 0;
		virtual void setIsHidden( const bool ) = 0;
	};
}