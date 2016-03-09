#include "Lyre/Private/Part.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"
#include "Lyre/Private/throw.h"
#include "Lyre/IInstrument.h"

namespace Lyre
{
    namespace Private
    {
        Part::~Part()
        {
        }

        Part::Part(
                int numStaves,
                int layersPerStaff,
                const IInstrumentUP& instrument )
            : myNumStaves( numStaves )
            , myLayersPerStaff( layersPerStaff )
            , myInstrument( instrument->clone() )
        {

        }
        
        Part::Part( const Part& other )
        {
            UNUSED_PARAMETER( other )
        }

        Part::Part( Part&& other )
        {
            UNUSED_PARAMETER( other )
        }

        Part& Part::operator=( const Part& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        Part& Part::operator=( Part&& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        IPartUP Part::clone() const
        {
            return IPartUP{ new Part{ *this } };
        }

        std::ostream& Part::toStream( std::ostream& os ) const
        {
            String sep( "//////////" );
            String space( "   " );
            return os << sep << space << (*myInstrument) << space << sep;
        }
    }
}
