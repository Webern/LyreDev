#include "IStep.h"

#include <sstream>

namespace lyre
{
    String IStep::toString() const
    {
        std::stringstream ss;
        this->toStream( ss );
        return String{ ss.str() };
    }
    std::ostream& operator<<( std::ostream& os, const IStep& StepName )
    {
        return StepName.toStream( os );
    }
    bool IStep::lessThan( const IStep& other ) const
    {
        return getValue() < other.getValue();
    }
    bool IStep::greaterThan( const IStep& other ) const
    {
        return getValue() > other.getValue();
    }
    bool IStep::equals( const IStep& other ) const
    {
        return getValue() == other.getValue();
    }
    void IStep::increment()
    {
        if ( getValue() == getMax() )
        {
            setValue( getMin() );
        }
        else
        {
            setValue( getValue() + 1 );
        }
    }
    void IStep::decrement()
    {
        if ( getValue() == getMin() )
        {
            setValue( getMax() );
        }
        else
        {
            setValue( getValue() - 1 );
        }
    }
}