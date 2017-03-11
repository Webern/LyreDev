//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IRangeFactory.h"
#include "Lyre/IRange.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(RangeFactory)
        
        class RangeFactory : public IRangeFactory
        {
        public:
            virtual ~RangeFactory();
            
            virtual IRangeUP create() const;
            
            virtual IRangeUP create( int low, int high ) const;
            
            virtual IRangeUP create(
                const IPitchUP& low,
                const IPitchUP& high ) const;
            
            virtual IRangeUP create(
                const String& low,
                const String& high ) const;
            
        };
    }
}
