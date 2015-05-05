#pragma once
#include <memory>
#include <vector>

namespace music
{
	class IEngravable;
	using IEngravablePtr = std::shared_ptr<IEngravable>;
	using IEngravableUPtr = std::shared_ptr<IEngravable>;
	using IEngravableSet = std::vector<IEngravablePtr>;
    using IEngravableIterator = IEngravableSet::iterator;
    using IEngravableIteratorConst = IEngravableSet::const_iterator;
    
    class IEngravable
	{
	public:
		virtual ~IEngravable() = default;
		virtual bool getIsHidden() const = 0;
		virtual void setIsHidden( const bool ) = 0;
	};
}