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
    
    class IDuration;
    using IDurationSP = std::shared_ptr<IDuration>;
    using IDurationUP = std::unique_ptr<IDuration>;
    
    class ITupletDef
    {
    public:
        virtual ~ITupletDef() = default;
        
        virtual ITupletDefUP clone() const = 0;
        
        void copyTo( ITupletDef& output ) const;
        
        virtual Rational getValue() const = 0;
        
        virtual IDurationUP getNumeratorDuration() const = 0;
        
        virtual Integer getNumeratorCount() const = 0;
        
        virtual IDurationUP getDenominatorDuration() const = 0;
        
        virtual Integer getDenominatorCount() const = 0;
        
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        virtual String toString() const;
        
    };
    
    std::ostream& operator<<( std::ostream& os, const ITupletDef& StepName );
}
