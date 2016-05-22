//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/Rational.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/DurationConstants.h"

namespace Lyre
{
    FORWARD_DECLARE(IDuration)
    
    class PUBLIC IDuration
    {
    public:
        virtual ~IDuration() = default;
        virtual IDurationUP clone() const = 0;
        virtual Rational getDurBaseValue() const = 0;
        virtual String getDurBaseName() const = 0;
        virtual int getDotCount() const = 0;
        virtual Rational getDottedBaseValue() const = 0;
        virtual String getDottedBaseName() const = 0;
        
        virtual bool getIsTuplet() const = 0;
        virtual bool getIsNestedTuplet() const = 0;
        virtual int getTupletNestingCount() const = 0;
        virtual VecITupletDefSPCIterC getTupletsBegin() const = 0;
        virtual VecITupletDefSPCIterC getTupletsEnd() const = 0;
        
        virtual Rational getValue() const = 0;
        
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        virtual String toString() const = 0;
    };
    
    PUBLIC std::ostream& operator<<( std::ostream& os, const IDuration& object );
}
