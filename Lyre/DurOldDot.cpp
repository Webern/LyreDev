#include "DurOldDot.h"
#include <sstream>

namespace lyre
{
    DurOldDot::DurOldDot()
    :myDurOld( DurOld::Quarter )
    ,myDots( 0 )
    {}
    
    DurOldDot::DurOldDot( const DurOld dur )
    :myDurOld( dur )
    ,myDots( 0 )
    {}
    
    DurOldDot::DurOldDot( const DurOld dur, const Integer dots )
    :myDurOld( dur )
    ,myDots( 0 )
    {
        setDots( dots );
    }
    void DurOldDot::setDots( const Integer dots )
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
    void DurOldDot::setDurOld( const DurOld dur )
    {
        myDurOld = dur;
    }
    Integer DurOldDot::getDots() const
    {
        return myDots;
    }
    DurOld DurOldDot::getDurOld() const
    {
        return myDurOld;
    }
    Rational DurOldDot::getRational() const
    {
        Rational value{ 1, 1 };
        try
        {
            value = convert( myDurOld );
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
    String DurOldDot::toString() const
    {
        std::stringstream ss;
        toStream( ss );
        return ss.str();
    }
    std::ostream& DurOldDot::toStream( std::ostream& os ) const
    {
        os << "[";
        os << myDurOld;
        for ( int i = 0; i < myDots; ++i )
        {
            os << ".";
        }
        os << "]";
        return os;
    }
    std::ostream& operator<<( std::ostream& os, const DurOldDot& dd )
    {
        return dd.toStream( os );
    }
    bool operator==( const DurOldDot& l, const DurOldDot& r )
    {
        return ( ! ( l < r ) ) && ( ! ( r < l ) );
    }
    bool operator!=( const DurOldDot& l, const DurOldDot& r )
    {
        return ! ( l == r );
    }
    bool operator<=( const DurOldDot& l, const DurOldDot& r )
    {
        return ( l < r ) || ( l == r );
    }
    bool operator>=( const DurOldDot& l, const DurOldDot& r )
    {
        return ( l > r ) || ( l == r );
    }
    bool operator<( const DurOldDot& l, const DurOldDot& r )
    {
        return l.getRational() < r.getRational();
    }
    bool operator>( const DurOldDot& l, const DurOldDot& r )
    {
        return r < l;
    }
    bool DurOldDot::parse( const String& str )
    {
        if ( str.length() < 3 )
        {
            return false;
        }
        if ( str[0] != '[' || str[str.length()-1] != ']' )
        {
            return false;
        }
        String withoutBrackets = str.substr( 1, str.length() -2 );
        Integer dots = 0;
        for ( auto rit = withoutBrackets.crbegin();
             rit != withoutBrackets.crend() && *rit == '.';
             ++rit )
        {
            ++dots;
        }
        DurOld d = DurOld::Quarter;
        bool success = false;
        try
        {
            d = lyre::parse( withoutBrackets.substr( 0, withoutBrackets.length() - dots ) );
            success = true;
        }
        catch (...) {}
        if ( success )
        {
            setDots( dots );
            setDurOld( d );
            return true;
        }
        return false;
    }
}