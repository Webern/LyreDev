//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/Rational.h"
#include <memory>

namespace Lyre
{
    class IDurDot;
    using IDurDotSP = std::shared_ptr<IDurDot>;
    using IDurDotUP = std::unique_ptr<IDurDot>;
    
    class IDurBase;
    using IDurBaseSP = std::shared_ptr<IDurBase>;
    using IDurBaseUP = std::unique_ptr<IDurBase>;
    
    static const Integer DURATION_MAX_DOTS = 20;
    
    class IDurDot
    {
    public:
        virtual ~IDurDot();
        
        virtual IDurDotUP clone() const = 0;
        
        virtual void copyTo( IDurDotUP& output ) const;
        
        virtual Rational getValue() const = 0;
        virtual Rational getDurBaseValue() const = 0;
        
        virtual Integer getDotCount() const = 0;
        
        virtual void setDotCount( const Integer dots ) = 0;
        
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        virtual std::ostream& durBaseToStream( std::ostream& os ) const = 0;
        
        virtual String toString() const = 0;
        virtual String durBaseToString() const = 0;
        
        virtual bool isEqualTo( const IDurDot& other ) const = 0;
        virtual bool isGreaterThan( const IDurDot& other ) const = 0;
        virtual bool isLessThan( const IDurDot& other ) const = 0;
    };
    
    std::ostream& operator<<( std::ostream& os, const IDurDot& object );
    
    bool operator==( const IDurDot& l, const IDurDot& r );
    bool operator!=( const IDurDot& l, const IDurDot& r );
    bool operator>=( const IDurDot& l, const IDurDot& r );
    bool operator<=( const IDurDot& l, const IDurDot& r );
    bool operator>( const IDurDot& l, const IDurDot& r );
    bool operator<( const IDurDot& l, const IDurDot& r );
}
