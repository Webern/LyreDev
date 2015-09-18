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
    private:
        Dur myDur;
        Integer myDots;
    };
}