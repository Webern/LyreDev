#pragma once
#include <memory>
#include "IEngravable.h"

namespace music
{
	class IPart;
	using IPartPtr = std::shared_ptr<IPart>;
	using IPartUPtr = std::shared_ptr<IPart>;
	
    class IPart : public IEngravable
	{
	public:
		virtual ~IPart() = default;
		IPartPtr clone() const = 0;
		IPartUPtr uclone() const = 0;
		bool getIsHidden() const = 0;
		void setIsHidden( const bool ) = 0;
	};
}