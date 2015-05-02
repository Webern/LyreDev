#pragma once
#include <memory>
#include <vector>
#include "IEngravable.h"

namespace music
{
	class IRest;
	using IRestPtr = std::shared_ptr<IRest>;
	using IRestUPtr = std::shared_ptr<IRest>;
	
    class IRest : public IEngravable
	{
	public:
		virtual ~IRest() = default;
		IRestPtr clone() const = 0;
		IRestUPtr uclone() const = 0;
		bool getIsHidden() const = 0;
		void setIsHidden( const bool ) = 0;
	};
}