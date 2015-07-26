#include "DurationCount.h"

namespace music
{
    DurationCount::DurationCount()
    :myDurationBase{ DurationBase{ DurationName::Quarter } }
    ,myCount{ 1 }
    {}
    DurationCount::DurationCount( const DurationBase& base, const Int count )
    :myDurationBase{ base }
    ,myCount{ count }
    {
        setCount( count );
    }
    DurationBase DurationCount::getDurationBase() const
    {
        return myDurationBase;
    }
    void DurationCount::setDurationBase( const DurationBase& value )
    {
        myDurationBase = value;
    }
    Int DurationCount::getCount() const
    {
        return myCount;
    }
    void DurationCount::setCount( const Int value )
    {
        if ( value < 1 )
        {
            myCount = 1;
        }
        else
        {
            myCount = value;
        }
    }
}