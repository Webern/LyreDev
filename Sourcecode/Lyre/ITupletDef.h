//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/Rational.h"
#include <memory>

namespace Lyre
{
    class ITupletDef;
    using ITupletDefSP = std::shared_ptr<ITupletDef>;
    using ITupletDefUP = std::unique_ptr<ITupletDef>;
    using ITupletDefSPC = std::shared_ptr<const ITupletDef>;
    using ITupletDefUPC = std::unique_ptr<const ITupletDef>;
    
    class IDurDot;
    using IDurDotSP = std::shared_ptr<IDurDot>;
    using IDurDotUP = std::unique_ptr<IDurDot>;
    using IDurDotSPC = std::shared_ptr<const IDurDot>;
    using IDurDotUPC = std::unique_ptr<const IDurDot>;
    
    class ITupletDef
    {
    public:
        virtual ~ITupletDef() = default;
        
        virtual ITupletDefUP clone() const = 0;
        
        virtual // void copyTo( ITupletDefUP& output ) const = 0;
        
        virtual Rational getMultiplier() const = 0;
        virtual Rational getTotalLength() const = 0;
        
        virtual Integer getCount() const = 0;
        virtual IDurDotUPC getCountType() const = 0;
        
        virtual Integer getInTheSpaceOf() const = 0;
        virtual IDurDotUPC getInTheSpaceOfType() const = 0;
        
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        virtual String toString() const = 0;
        
    };
    
    std::ostream& operator<<( std::ostream& os, const ITupletDef& val );
}
