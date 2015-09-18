#include "DurDot.h"
#include <sstream>

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
        else
        {
            myDots = 0;
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
    Rational DurDot::getRational() const
    {
        Rational value{ 1, 1 };
        try
        {
            value = convert( myDur );
        }
        catch( ... ) {} /* ignore error */
        auto add = value;
        for ( int i=0; i<myDots; ++i )
        {
            add *= Rational{ 1, 2 };
            value += add;
        }
        return value;
    }
    String DurDot::toString() const
    {
        std::stringstream ss;
        toStream( ss );
        return ss.str();
    }
    std::ostream& DurDot::toStream( std::ostream& os ) const
    {
        os << "[";
        os << myDur;
        for ( int i = 0; i < myDots; ++i )
        {
            os << ".";
        }
        os << "]";
        return os;
    }
    std::ostream& operator<<( std::ostream& os, const DurDot& dd )
    {
        return dd.toStream( os );
    }
    bool operator==( const DurDot& l, const DurDot& r )
    {
        return ( ! ( l < r ) ) && ( ! ( r < l ) );
    }
    bool operator!=( const DurDot& l, const DurDot& r )
    {
        return ! ( l == r );
    }
    bool operator<=( const DurDot& l, const DurDot& r )
    {
        return ( l < r ) || ( l == r );
    }
    bool operator>=( const DurDot& l, const DurDot& r )
    {
        return ( l > r ) || ( l == r );
    }
    bool operator<( const DurDot& l, const DurDot& r )
    {
        return l.getRational() < r.getRational();
    }
    bool operator>( const DurDot& l, const DurDot& r )
    {
        return r < l;
    }
}