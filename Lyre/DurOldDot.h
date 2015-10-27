//PUBLIC
#pragma once
#include "TypeDefs.h"
#include "DurOld.h"
#include "Rational.h"

namespace lyre
{
    class DurOldDot;
    
    class DurOldDot
    {
    public:
        DurOldDot();
        DurOldDot( const DurOld d );
        DurOldDot( const DurOld d, const Integer dots );
        void setDots( const Integer dots );
        void setDurOld( const DurOld dur );
        Integer getDots() const;
        DurOld getDurOld() const;
        Rational getRational() const;
        String toString() const;
        std::ostream& toStream( std::ostream& os ) const;
        bool parse( const String& str );
    private:
        DurOld myDurOld;
        Integer myDots;
    };
    
    std::ostream& operator<<( std::ostream& os, const DurOldDot& dd );
    bool operator==( const DurOldDot& l, const DurOldDot& r );
    bool operator!=( const DurOldDot& l, const DurOldDot& r );
    bool operator<=( const DurOldDot& l, const DurOldDot& r );
    bool operator>=( const DurOldDot& l, const DurOldDot& r );
    bool operator<( const DurOldDot& l, const DurOldDot& r );
    bool operator>( const DurOldDot& l, const DurOldDot& r );
}