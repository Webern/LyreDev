//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/ITimeSignatureFactory.h"
#include "Lyre/ITimeSignature.h"
#if 1==0
namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(TimeSignatureFactory)
        
        class TimeSignatureFactory : public ITimeSignatureFactory
        {
        public:
            virtual ~TimeSignatureFactory();
            virtual ITimeSignatureUP create( int top, int bottom );
        };
    }
}
#endif

