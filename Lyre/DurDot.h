//PUBLIC
#pragma once
#include "TypeDefs.h"
#include "Dur.h"
#include "Rational.h"

namespace lyre
{
    class DurDot;
    
    class DurDot
    {
    public:
        DurDot();
        DurDot( const Dur d );
        DurDot( const Dur d, const Integer dots );
        void setDots( const Integer dots );
        void setDur( const Dur dur );
        Integer getDots() const;
        Dur getDur() const;
        Rational getRational() const;
        String toString() const;
        std::ostream& toStream( std::ostream& os ) const;
        bool parse( const String& str );
    private:
        Dur myDur;
        Integer myDots;
    };
    
    std::ostream& operator<<( std::ostream& os, const DurDot& dd );
    bool operator==( const DurDot& l, const DurDot& r );
    bool operator!=( const DurDot& l, const DurDot& r );
    bool operator<=( const DurDot& l, const DurDot& r );
    bool operator>=( const DurDot& l, const DurDot& r );
    bool operator<( const DurDot& l, const DurDot& r );
    bool operator>( const DurDot& l, const DurDot& r );
}