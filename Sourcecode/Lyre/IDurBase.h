//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/Rational.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    FORWARD_DECLARE(IDurBase)
    
    class PUBLIC IDurBase
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
    
    PUBLIC std::ostream& operator<<( std::ostream& os, const IDurBase& object );
    
	PUBLIC bool operator==( const IDurBase& l, const IDurBase& r );
	PUBLIC bool operator!=( const IDurBase& l, const IDurBase& r );
	PUBLIC bool operator>=( const IDurBase& l, const IDurBase& r );
	PUBLIC bool operator<=( const IDurBase& l, const IDurBase& r );
	PUBLIC bool operator>( const IDurBase& l, const IDurBase& r );
	PUBLIC bool operator<( const IDurBase& l, const IDurBase& r );
}
