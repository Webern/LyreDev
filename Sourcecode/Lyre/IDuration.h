//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/Rational.h"
#include <memory>

namespace Lyre
{
    class IDuration;
    using IDurationSP = std::shared_ptr<IDuration>;
    using IDurationUP = std::unique_ptr<IDuration>;
    
    class IDurBase;
    using IDurBaseSP = std::shared_ptr<IDurBase>;
    using IDurBaseUP = std::unique_ptr<IDurBase>;
    
    class IDuration
    {
    public:
        virtual ~IDuration();
        
        virtual IDurationUP clone() const = 0;
        
        virtual void copyTo( IDurationUP& output ) const;
        
        virtual Rational getValue() const = 0;
        virtual Rational getDurBaseValue() const = 0;
        
        virtual Integer getDotCount() const = 0;
        
        virtual void setDotCount( const Integer dots ) = 0;
        
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        virtual std::ostream& durBaseToStream( std::ostream& os ) const = 0;
        
        virtual String toString() const = 0;
        virtual String durBaseToString() const = 0;
        
        virtual bool isEqualTo( const IDuration& other ) const = 0;
        virtual bool isGreaterThan( const IDuration& other ) const = 0;
        virtual bool isLessThan( const IDuration& other ) const = 0;
        virtual bool isIdenticalTo( const IDuration& other ) const = 0;
    };
    
    std::ostream& operator<<( std::ostream& os, const IDuration& object );
    
    bool operator==( const IDuration& l, const IDuration& r );
    bool operator!=( const IDuration& l, const IDuration& r );
    bool operator>=( const IDuration& l, const IDuration& r );
    bool operator<=( const IDuration& l, const IDuration& r );
    bool operator>( const IDuration& l, const IDuration& r );
    bool operator<( const IDuration& l, const IDuration& r );
}
