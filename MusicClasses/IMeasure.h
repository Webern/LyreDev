#pragma once
#include <memory>
#include <vector>
#include "IEngravable.h"

namespace music
{
	class IMeasure;
	using IMeasurePtr = std::shared_ptr<IMeasure>;
	using IMeasureUPtr = std::shared_ptr<IMeasure>;
	
    class IMeasure : public IEngravable
	{
	public:
		virtual ~IMeasure() = default;
		IMeasurePtr clone() const = 0;
		IMeasureUPtr uclone() const = 0;
		bool getIsHidden() const = 0;
		void setIsHidden( const bool ) = 0;
	};
}