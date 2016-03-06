#include "Lyre/Private/Range.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        Range::~Range()
        {
        }

        Range::Range()
        {

        }

        Range::Range( const Range& other )
        {
            UNUSED_PARAMETER( other )
        }

        Range::Range( Range&& other )
        {
            UNUSED_PARAMETER( other )
        }

        Range& Range::operator=( const Range& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        Range& Range::operator=( Range&& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        IRangeUP Range::clone() const
        {
            return IRangeUP{ new Range{ *this } };
        }

        std::ostream& Range::toStream( std::ostream& os ) const
        {
            return os << "Range not implemented";
        }
        
        IPitchUP Range::getLow() const
        {
            return myLow->clone();
        }
        
        IPitchUP Range::getHigh() const
        {
            return myHigh->clone();
        }
        
        bool Range::check( const int low, const int high ) const
        {
            return low <= high;
        }
    }
}
