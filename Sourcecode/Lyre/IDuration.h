//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/Rational.h"
#include "Lyre/ITupletDef.h"
#include <memory>

namespace Lyre
{
    class IDuration;
    using IDurationSP = std::shared_ptr<IDuration>;
    using IDurationUP = std::unique_ptr<IDuration>;
    
    class IDuration
    {
    public:
        virtual ~IDuration() = default;
        virtual IDurationUP clone() const = 0;
        virtual Rational getDurBaseValue() const = 0;
        virtual String getDurBaseName() const = 0;
        virtual Integer getDotCount() const = 0;
        virtual Rational getDottedBaseValue() const = 0;
        virtual String getDottedBaseName() const = 0;
        
        virtual bool getIsTuplet() const = 0;
        virtual bool getIsNestedTuplet() const = 0;
        virtual int getTupletNestingCount() const = 0;
        virtual ITupletDefSPCsIter getTupletsBegin() const = 0;
        virtual ITupletDefSPCsIter getTupletsEnd() const = 0;
        
        virtual Rational getValue() const = 0;
        
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        virtual String toString() const = 0;
    };
    
    std::ostream& operator<<( std::ostream& os, const IDuration& object );
}
