//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/ITimeSignatureFactory.h"
#include "Lyre/ITimeSignature.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(TimeSignatureFactory)
        
        class TimeSignatureFactory : public ITimeSignatureFactory
        {
        public:
            virtual ~TimeSignatureFactory();
            
            virtual ITimeSignatureUP create(
                const IBeatPatternUP& beatPattern,
                int top, int bottom ) const;
            
            virtual ITimeSignatureUP create( int top, int bottom ) const;
        };
    }
}


