//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMeasureFactory.h"
#include "Lyre/IMeasure.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(MeasureFactory)
        
        class MeasureFactory : public IMeasureFactory
        {
        public:
            virtual ~MeasureFactory();
            virtual IMeasureUP create();
            virtual IMeasureUP create( int timeSignatureTop, int timeSignatureBottom );
            virtual IMeasureUP create( const ITimeSignatureUP& timeSignature );
        };
    }
}
