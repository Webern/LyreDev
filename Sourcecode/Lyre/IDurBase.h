//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/Rational.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    FORWARD_DECLARE(IDurBase)
    
    class IDurBase
    {
    public:
        virtual ~IDurBase();
        virtual IDurBaseUP clone() const = 0;
        
        virtual Rational getValue() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        virtual String toString() const;
        
        virtual bool isEqualTo( const IDurBase& other ) const;
        virtual bool isGreaterThan( const IDurBase& other ) const;
        virtual bool isLessThan( const IDurBase& other ) const;
        virtual bool isIdenticalTo( const IDurBase& other ) const;
    };
    
    std::ostream& operator<<( std::ostream& os, const IDurBase& object );
    
    bool operator==( const IDurBase& l, const IDurBase& r );
    bool operator!=( const IDurBase& l, const IDurBase& r );
    bool operator>=( const IDurBase& l, const IDurBase& r );
    bool operator<=( const IDurBase& l, const IDurBase& r );
    bool operator>( const IDurBase& l, const IDurBase& r );
    bool operator<( const IDurBase& l, const IDurBase& r );
}
