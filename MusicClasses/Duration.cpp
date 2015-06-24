#include "Duration.h"

namespace music
{
    Duration::Duration()
    :myDurationBase{}
    ,myDotCount{ 0 }
    ,myTupletRatio{}
    {}
    
    Duration::Duration( const DurationBase& base )
    :myDurationBase{ base }
    ,myDotCount{ 0 }
    ,myTupletRatio{}
    {}
    
    Duration::Duration( const DurationBase& base, const Int dotCount )
    :myDurationBase{ base }
    ,myDotCount{ 0 }
    ,myTupletRatio{}
    {}
    
    Duration::Duration( const DurationBase& base, const Int dotCount, const TupletRatio& tuplet )
    :myDurationBase{ base }
    ,myDotCount{ dotCount }
    ,myTupletRatio{ tuplet }
    {}
    
    Duration::Duration( const DurationBase& base, const TupletRatio& tuplet )
    :myDurationBase{ base }
    ,myDotCount{ 0 }
    ,myTupletRatio{ tuplet }
    {}
    DurationBase Duration::getDurationBase() const
    {
        return myDurationBase;
    }
    void Duration::setDurationBase( const DurationBase& value )
    {
        myDurationBase = value;
    }
    TupletRatio Duration::getTupletRatio() const
    {
        return myTupletRatio;
    }
    void Duration::setTupletRatio( const TupletRatio& value )
    {
        myTupletRatio = value;
    }
    Int Duration::getDotCount() const
    {
        return myDotCount;
    }
    void Duration::setDotCount( const Int value )
    {
        if ( value < 0 )
        {
            myDotCount = 0;
        }
    }
    Rational Duration::getRational() const
    {
        Rational value = myDurationBase.getRational();
        for ( Int i = 0; i < myDotCount; ++i )
        {
            value *= Rational{ 1, 2 };
        }
        throw std::runtime_error( "missing logic here" );
        return value;
    }
}