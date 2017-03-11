#include "Lyre/Private/RangeFactory.h"
#include "Lyre/IRange.h"
#include "Lyre/Private/Range.h"


namespace Lyre
{
    namespace Private
    {
        RangeFactory::~RangeFactory() {}
        
        IRangeUP RangeFactory::create() const
        {
            return IRangeUP{ new Range{} };
        }
        
        IRangeUP RangeFactory::create( int low, int high ) const
        {
            return IRangeUP{ new Range{ low, high } };
        }
        
        IRangeUP RangeFactory::create(
            const IPitchUP& low,
            const IPitchUP& high ) const
        {
            return IRangeUP{ new Range{ low, high } };
        }
        
        IRangeUP RangeFactory::create(
            const String& low,
            const String& high ) const
        {
            return IRangeUP{ new Range{ low, high } };
        }
    }
}
