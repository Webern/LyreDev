#include "Lyre/Private/Range.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        const IPitchFactoryUPC Range::ourPitchFactory = createPitchFactory();
        
        Range::~Range()
        {
        }

        Range::Range()
        :myLow( ourPitchFactory->createPitch( DEFAULT_RANGE_LOW) )
        ,myHigh( ourPitchFactory->createPitch( DEFAULT_RANGE_HIGH) )
        {
            check( DEFAULT_RANGE_LOW, DEFAULT_RANGE_HIGH );
        }
        
        Range::Range( int low, int high )
        :Range()
        {
            check( low, high );
            myLow = ourPitchFactory->createPitch( low );
            myHigh = ourPitchFactory->createPitch( high );
        }
        
        Range::Range(
            const IPitchUP& low,
            const IPitchUP& high )
        :Range()
        {
            THROW_IF_NULL( low )
            THROW_IF_NULL( high )
            check( low->getValue(), high->getValue() );
            myLow = low->clone();
            myHigh = high->clone();
        }
        
        Range::Range(
            const String& low,
            const String& high )
        :Range()
        {
            auto lowPitch = ourPitchFactory->createPitch( low );
            auto highPitch = ourPitchFactory->createPitch( high );
            check( lowPitch->getValue(), highPitch->getValue() );
            myLow = std::move( lowPitch );
            myHigh = std::move( highPitch );
        }

        Range::Range( const Range& other )
        :myLow( other.myLow->clone() )
        ,myHigh( other.myHigh->clone() )
        {}

        Range::Range( Range&& other ) noexcept
        :myLow( std::move( other.myLow ) )
        ,myHigh( std::move( other.myHigh ) )
        {}

        Range& Range::operator=( const Range& other )
        {
            myLow = other.myLow->clone();
            myHigh = other.myHigh->clone();
            return *this;
        }

        Range& Range::operator=( Range&& other ) noexcept
        {
            myLow = std::move( other.myLow );
            myHigh = std::move( other.myHigh );
            return *this;
        }

        IRangeUP Range::clone() const
        {
            return IRangeUP{ new Range{ *this } };
        }

        std::ostream& Range::toStream( std::ostream& os ) const
        {
            return os << "Range{ " << (*myLow) << " - " << (*myHigh) << " }";
        }
        
        IPitchUP Range::getLow() const
        {
            return myLow->clone();
        }
        
        IPitchUP Range::getHigh() const
        {
            return myHigh->clone();
        }
        
        void Range::check( const int low, const int high ) const
        {
            if ( low > high )
            {
                THROW( "low note must be lower than or equal to high note" )
            }
        }
    }
}
