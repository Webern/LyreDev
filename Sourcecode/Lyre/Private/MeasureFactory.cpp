#include "Lyre/Private/MeasureFactory.h"
#include "Lyre/IMeasure.h"
#include "Lyre/Private/Measure.h"
#include "Lyre/ITimeSignature.h"
#include "Lyre/ITimeSignatureFactory.h"

namespace Lyre
{
    namespace Private
    {
        MeasureFactory::~MeasureFactory() {}
        
        IMeasureUP MeasureFactory::create() const
        {
            return create( DEFAULT_TIME_SIGNATURE_TOP, DEFAULT_TIME_SIGNATURE_BOTTOM );
        }

        IMeasureUP MeasureFactory::create( int timeSignatureTop, int timeSignatureBottom ) const
        {
            ITimeSignatureFactoryUP t = createTimeSignatureFactory();
            return IMeasureUP{ new Measure{ t->create( timeSignatureTop, timeSignatureBottom ) } };
        }

        IMeasureUP MeasureFactory::create( const ITimeSignatureUP& timeSignature ) const
        {
            return IMeasureUP( new Measure{ timeSignature->clone() } );
        }
    }
}
