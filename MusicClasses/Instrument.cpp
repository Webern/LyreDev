#include "Instrument.h"

namespace music
{
    Instrument::Instrument()
    :myName( "Instrument" )
    {}
    
    Instrument::Instrument( const String& name )
    :myName( name )
    {}
    
    String Instrument::getName() const
    {
        return myName;
    }
    
    void Instrument::setName( const String& value )
    {
        myName = value;
    }
}