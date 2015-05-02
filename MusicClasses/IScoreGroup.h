#pragma once
#include <memory>
#include <vector>
#include "IEngravable.h"

namespace music
{
	class IScoreGroup;
	using IScoreGroupPtr = std::shared_ptr<IScoreGroup>;
	using IScoreGroupUPtr = std::shared_ptr<IScoreGroup>;
	
    class IScoreGroup : public IEngravable
	{
	public:
		virtual ~IScoreGroup() = default;
		IScoreGroupPtr clone() const = 0;
		IScoreGroupUPtr uclone() const = 0;
		bool getIsHidden() const = 0;
		void setIsHidden( const bool ) = 0;
	};
}