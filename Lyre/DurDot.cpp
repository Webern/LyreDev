#include "DurDot.h"

namespace lyre
{
    DurDot::DurDot()
    :myDur( Dur::Quarter )
    ,myDots( 0 )
    {}
    
    DurDot::DurDot( const Dur dur )
    :myDur( dur )
    ,myDots( 0 )
    {}
    
    DurDot::DurDot( const Dur dur, const Integer dots )
    :myDur( dur )
    ,myDots( 0 )
    {
        setDots( dots );
    }
    void DurDot::setDots( const Integer dots )
    {
        if ( dots >= 0 )
        {
            myDots = dots;
        }
    }
    void DurDot::setDur( const Dur dur )
    {
        myDur = dur;
    }
    Integer DurDot::getDots() const
    {
        return myDots;
    }
    Dur DurDot::getDur() const
    {
        return myDur;
    }
}