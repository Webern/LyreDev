#pragma once
#include <memory>
#include <vector>
#include "IEngravable.h"

namespace music
{
	class ITimeSignature;
	using ITimeSignaturePtr = std::shared_ptr<ITimeSignature>;
	using ITimeSignatureUPtr = std::shared_ptr<ITimeSignature>;
	
    class ITimeSignature : public IEngravable
	{
	public:
		virtual ~ITimeSignature() = default;
		ITimeSignaturePtr clone() const = 0;
		ITimeSignatureUPtr uclone() const = 0;
		bool getIsHidden() const = 0;
		void setIsHidden( const bool ) = 0;
	};
}