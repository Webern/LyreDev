#pragma once
#include <memory>
#include <vector>
#include "IEngravable.h"

namespace music
{
	class IMeasureLayer;
	using IMeasureLayerPtr = std::shared_ptr<IMeasureLayer>;
	using IMeasureLayerUPtr = std::shared_ptr<IMeasureLayer>;
	
    class IMeasureLayer : public IEngravable
	{
	public:
		virtual ~IMeasureLayer() = default;
		IMeasureLayerPtr clone() const = 0;
		IMeasureLayerUPtr uclone() const = 0;
		bool getIsHidden() const = 0;
		void setIsHidden( const bool ) = 0;
	};
}