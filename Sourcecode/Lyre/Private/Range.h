//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IRange.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(Range)
        
        class Range : public IRange
        {
        public:
            virtual ~Range();
            Range();
            Range( int low, int high );
            
            Range(
                const IPitch& low,
                const IPitch& high );
            
            Range(
                const String& low,
                const String& high );
            
            Range( const Range& other );
            Range( Range&& other );
            Range& operator=( const Range& other );
            Range& operator=( Range&& other );
            
            virtual IRangeUP clone() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
            
            virtual IPitchUP getLow() const;
            virtual IPitchUP getHigh() const;
            
        private:
            IPitchUP myLow;
            IPitchUP myHigh;
            bool check( const int low, const int high ) const;
        };
    } 
}
