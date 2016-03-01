#include "Lyre/Private/MeasureFactory.h"
#include "Lyre/IMeasure.h"
#include "Lyre/Private/Measure.h"
#include "Lyre/Private/TimeSignatureFactory.h"

namespace Lyre
{
    namespace Private
    {
        MeasureFactory::~MeasureFactory() {}
        
        IMeasureUP MeasureFactory::create()
        {
            TimeSignatureFactory t;
            return IMeasureUP{ new Measure{ t.create( 4, 4 ) } };
        }
    }
}
