//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMeasure.h"
#include "Lyre/IMeasureStrategy.h"
#include "Lyre/IBeatPattern.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE( BeamingStrategy );
        
        class EXPORT_FOR_TESTS BeamingStrategy : public IMeasureStrategy
        {
        public:
            virtual ~BeamingStrategy();
            BeamingStrategy();
            BeamingStrategy( const IBeatPatternUP& beatPattern );
            BeamingStrategy( const BeamingStrategy& other );
            BeamingStrategy& operator=( const BeamingStrategy& other );
            IMeasureStrategyUP clone() const;
            void applyStrategy( const IMeasureUP& measure );
        private:
            IBeatPatternUP myBeatPattern;
            IBeatPatternUP chooseCorrectBeatPattern(  const IMeasureUP& measure );
        };
    }

}
