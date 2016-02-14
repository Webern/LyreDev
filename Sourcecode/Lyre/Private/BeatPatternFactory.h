//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IBeatPattern.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(BeatPatternFactory)
        
        class BeatPatternFactory : public IBeatPatternFactory
        {
        public:
            virtual ~BeatPatternFactory();
            
            virtual IBeatPatternUP create( Integer count,
                                           const IDurationUP& dur ) const;
            
            virtual IBeatPatternUP create( const VecIDurationUP& durations ) const;
        };
    }
}
