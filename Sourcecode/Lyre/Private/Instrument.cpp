#include "Lyre/Private/Instrument.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"
#include "Lyre/Private/throw.h"
#include "Lyre/Private/Range.h"

namespace Lyre
{
    namespace Private
    {
        Instrument::~Instrument()
        {
        }

        Instrument::Instrument(
            const String& name,
            const String& shortName,
            const IRangeUP& range )
        :myName( name )
        ,myShortName( shortName )
        ,myRange( range->clone() )
        {
            if ( !myRange )
            {
                myRange = IRangeUP{ new Range{} };
            }
        }

        Instrument::Instrument( const Instrument& other )
        :myName( other.myName )
        ,myShortName( other.myShortName )
        ,myRange( other.myRange->clone() )
        {
            
        }

        Instrument::Instrument( Instrument&& other ) noexcept
        :myName( std::move( other.myName ) )
        ,myShortName( std::move( other.myShortName ) )
        ,myRange( std::move( other.myRange ) )
        {
            
        }

        Instrument& Instrument::operator=( const Instrument& other )
        {
            myName = other.myName;
            myShortName = other.myShortName;
            myRange = other.myRange->clone();
            return *this;
        }

        Instrument& Instrument::operator=( Instrument&& other ) noexcept
        {
            myName = std::move( other.myName );
            myShortName = std::move( other.myShortName );
            myRange = std::move( other.myRange );
            return *this;
        }

        IInstrumentUP Instrument::clone() const
        {
            return IInstrumentUP{ new Instrument{ *this } };
        }

        std::ostream& Instrument::toStream( std::ostream& os ) const
        {
            return os << myName;
        }
        
        String Instrument::getName() const
        {
            return myName;
        }
        
        String Instrument::getShortName() const
        {
            return myShortName;
        }
        
        IRangeUP Instrument::getRange() const
        {
            return myRange->clone();
        }
    }
}
