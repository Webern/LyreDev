//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/Rational.h"
#include "Lyre/IDurBase.h"

#include <memory>

namespace Lyre
{
    class IDurDot;
    using IDurDotSP = std::shared_ptr<IDurDot>;
    using IDurDotUP = std::unique_ptr<IDurDot>;
    
    class IDurDot
    {
    public:
        virtual ~IDurDot();
        virtual Rational getValue() const = 0;
        
        virtual IntType getDotCount() const = 0;
        virtual IDurBaseUP getDurBase() const = 0;
        
        virtual bool isEqualTo( const IDurDot& other ) const = 0;
        virtual bool isGreaterThan( const IDurDot& other ) const = 0;
        virtual bool isLessThan( const IDurDot& other ) const = 0;
        
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        virtual String toString() const;
    };
    
    std::ostream& operator<<( std::ostream& os, const IDurDot& object );
}
