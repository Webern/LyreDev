//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/Rational.h"

namespace Lyre
{
    FORWARD_DECLARE(ITupletDef)
    FORWARD_DECLARE(IDurDot)
    
    class PUBLIC ITupletDef
    {
    public:
        virtual ~ITupletDef() = default;
        
        virtual ITupletDefUP clone() const = 0;
        
        virtual Rational getMultiplier() const = 0;
        virtual Rational getTotalLength() const = 0;
        
        virtual int getCount() const = 0;
        virtual IDurDotUPC getCountType() const = 0;
        
        virtual int getInTheSpaceOf() const = 0;
        virtual IDurDotUPC getInTheSpaceOfType() const = 0;
        
        virtual bool getIsValid() const = 0;
        
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        virtual String toString() const = 0;
        
    };
    
    PUBLIC std::ostream& operator<<( std::ostream& os, const ITupletDef& val );
}
