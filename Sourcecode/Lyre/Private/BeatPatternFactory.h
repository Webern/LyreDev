//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IBeatPattern.h"

#if 1 == 0
namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(BeatPatternFactory)
        
        class BeatPatternFactory : public IBeatPatternFactory
        {
        public:
            virtual ~BeatPatternFactory();
            virtual IBeatPatternUP create();
        };
    }
}
#endif
