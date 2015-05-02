#pragma once
#include <memory>
#include <vector>
#include "IEngravable.h"

namespace music
{
	class INote;
	using INotePtr = std::shared_ptr<INote>;
	using INoteUPtr = std::shared_ptr<INote>;
	
    class INote : public IEngravable
	{
	public:
		virtual ~INote() = default;
		INotePtr clone() const = 0;
		INoteUPtr uclone() const = 0;
		bool getIsHidden() const = 0;
		void setIsHidden( const bool ) = 0;
	};
}