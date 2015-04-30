#include "PitchAlter.h"

namespace music
{
    PitchAlter::PitchAlter()
    :myValue( 0 )
    {}
    
    PitchAlter::PitchAlter( const Integer value )
    :myValue( value )
    {}
    
    PitchAlter::~PitchAlter()
    {}
    
    PitchAlterPtr PitchAlter::make( const Integer value )
    {
        return std::make_shared<PitchAlter>( value );
    }
    
    Integer PitchAlter::getValue() const
    {
        return myValue.getValue();
    }
    
    void PitchAlter::setValue( const Integer value )
    {
        myValue.setValue( value );
    }
    
    PitchAlter& PitchAlter::add( const Integer value )
    {
        myValue.add( value );
        return *this;
    }
    
    PitchAlter& PitchAlter::subtract( const Integer value )
    {
        myValue.subtract( value );
        return *this;
    }
    
}