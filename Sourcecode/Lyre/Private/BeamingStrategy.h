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
            void applyStrategy( const IMeasureH& measure );
            
        private:
            IBeatPatternUP myBeatPattern;
            IBeatPatternUP chooseCorrectBeatPattern(  const IMeasureH& measure );
        };
        
        bool isBeamConnectionIncoming(
            const IMeasureH& measure,
            int noteIndex,
            int beamIndex );
        
        bool isBeamConnectionOutgoing(
            const IMeasureH& measure,
            int noteIndex,
            int beamIndex );
        
        bool isBeamExistenceRequirementSatisfied(
            const IMeasureH& measure,
            int noteIndex,
            int beamIndex );
        
        bool isNoteFirstInGroup(
            const IMeasureH& measure,
            int noteIndex,
            const IBeatPatternUP& beatPattern );
        
        bool isNoteLastInGroup(
            const IMeasureH& measure,
            int noteIndex,
            const IBeatPatternUP& beatPattern  );
        
        bool isFollowedByRest(
            const IMeasureH& measure,
            int noteIndex );
        
        bool isPrecededByRest(
            const IMeasureH& measure,
            int noteIndex );
    }
}
