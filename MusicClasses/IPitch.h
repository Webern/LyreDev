#pragma once
#include <memory>
#include "IEngravable.h"

namespace music
{
	class IPitch;
	using IPitchPtr = std::shared_ptr<IPitch>;
	using IPitchUPtr = std::shared_ptr<IPitch>;
	
    class IPitch : public IEngravable
	{
	public:
		virtual ~IPitch() = default;
		IPitchPtr clone() const = 0;
		IPitchUPtr uclone() const = 0;
		bool getIsHidden() const = 0;
		void setIsHidden( const bool ) = 0;
	};
}