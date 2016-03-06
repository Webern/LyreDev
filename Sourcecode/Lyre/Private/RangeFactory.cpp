#include "Lyre/Private/RangeFactory.h"
#include "Lyre/IRange.h"
#include "Lyre/Private/Range.h"


namespace Lyre
{
    namespace Private
    {
        RangeFactory::~RangeFactory() {}
        
        IRangeUP RangeFactory::create()
        {
            return IRangeUP{ new Range{} };
        }
    }
}
