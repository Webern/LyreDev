//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMeasure.h"
#include "Lyre/Handle.h"

namespace Lyre
{
    FORWARD_DECLARE(IPart)
    FORWARD_DECLARE(IPartSpec)
    using IPartH = Handle<IPartUP>;
    using IPartHC = HandleConst<IPartUP>;

    class PUBLIC IPart : public IStreamable
    {
    public:
        virtual ~IPart() {};
        virtual IPartUP clone() const = 0;
        virtual IPartUP move() noexcept = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        virtual void setStaffContext( int staffIndex ) = 0;
        virtual int getStaffContext() const = 0;
        
        virtual IPartSpecUP getPartSpec() const = 0;
        
        virtual int getMeasureCount() const = 0;
        virtual IMeasureH getMeasure( int measureIndex ) = 0;
		virtual const IMeasureHC getMeasure( int measureIndex ) const = 0;
        virtual const IMeasureHC getMeasureConst( int measureIndex ) const = 0;
    };
}
