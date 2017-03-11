#include "Lyre/Private/BeamingStrategy.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        BeamingStrategy::~BeamingStrategy()
        {
            
        }
        
        
        BeamingStrategy::BeamingStrategy()
            : myBeatPattern( nullptr )
        {
            
        }
        
        
        BeamingStrategy::BeamingStrategy( const IBeatPatternUP& beatPattern )
            : myBeatPattern( beatPattern->clone() )
        {
            
        }
        
        
        BeamingStrategy::BeamingStrategy( const BeamingStrategy& other )
        : myBeatPattern( nullptr )
        {
            if( other.myBeatPattern )
            {
                myBeatPattern = other.myBeatPattern->clone();
            }
        }
        
        
        BeamingStrategy& BeamingStrategy::operator=( const BeamingStrategy& other )
        {
            if( other.myBeatPattern )
            {
                myBeatPattern = other.myBeatPattern->clone();
            }
            return *this;
        }
        
        
        IMeasureStrategyUP BeamingStrategy::clone() const
        {
            return IMeasureStrategyUP{ new BeamingStrategy( *this ) };
        }
        
        
        void BeamingStrategy::applyStrategy( const IMeasureUP& measure )
        {
            if( measure->getIsEmpty() )
            {
                return;
            }
            std::vector<Rational> breakPoints;
            auto beatPattern = chooseCorrectBeatPattern( measure );
            Rational position{ 0, 1 };
            for( int i = 0; i <  beatPattern->getCount(); ++i )
            {
                position += beatPattern->get( i )->getValue();
                breakPoints.push_back( position );
            }
            position = Rational{ 0, 1 };
            auto breakPointsItr = breakPoints.cbegin();
            auto breakPointsEnd = breakPoints.cend();
            for( int i = 0; i < measure->getCount(); ++i )
            {
                int lastIndex = measure->getCount() - 1;
                //bool currIsFirst = i == 0;
                bool currIsLast = i == measure->getCount() - 1;
                //auto prevIndex = ( currIsFirst ? 0 : i - 1 );
                auto nextIndex = ( currIsLast ? lastIndex : i + 1 );
                const auto& currNote = measure->getNote( i );
                //const auto& prevNote = measure->getNote( prevIndex );
                const auto& nextNote = measure->getNote( nextIndex );
                position += currNote->getDuration()->getValue();
                
                // set beams to 0 if we are at a breakpoint,
                // or if we are at the end of the measure
                bool isPrevBreakpoint = false;
                if( breakPointsItr == breakPointsEnd )
                {
                    isPrevBreakpoint = true;
                }
                else if ( position == *breakPointsItr )
                {
                    isPrevBreakpoint = true;
                    ++breakPointsItr;
                }
                
                if( isPrevBreakpoint )
                {
                    currNote->setBeams( 0 );
                }
                
                // set beams if next note is a rest
                else if( !currIsLast && nextNote->getIsRest() )
                {
                    currNote->setBeams( 1 );
                }
                else if( !currIsLast )
                {
                    if ( nextNote->getMaxBeams() < currNote->getMaxBeams() )
                    {
                        currNote->setBeams( nextNote->getMaxBeams() );
                    }
                    else
                    {
                        currNote->setBeams( currNote->getMaxBeams() );
                    }
                }
                else if ( currIsLast )
                {
                    currNote->setBeams( 0 );
                }
            }
            UNUSED_PARAMETER( beatPattern );
        }
        
        // TODO code duplication
        void BeamingStrategy::applyStrategy( const IMeasureH& measure )
        {
            if( measure->getIsEmpty() )
            {
                return;
            }
            std::vector<Rational> breakPoints;
            auto beatPattern = chooseCorrectBeatPattern( measure );
            Rational position{ 0, 1 };
            for( int i = 0; i <  beatPattern->getCount(); ++i )
            {
                position += beatPattern->get( i )->getValue();
                breakPoints.push_back( position );
            }
            position = Rational{ 0, 1 };
            auto breakPointsItr = breakPoints.cbegin();
            auto breakPointsEnd = breakPoints.cend();
            for( int i = 0; i < measure->getCount(); ++i )
            {
                int lastIndex = measure->getCount() - 1;
                //bool currIsFirst = i == 0;
                bool currIsLast = i == measure->getCount() - 1;
                //auto prevIndex = ( currIsFirst ? 0 : i - 1 );
                auto nextIndex = ( currIsLast ? lastIndex : i + 1 );
                const auto& currNote = measure->getNote( i );
                //const auto& prevNote = measure->getNote( prevIndex );
                const auto& nextNote = measure->getNote( nextIndex );
                position += currNote->getDuration()->getValue();
                
                // set beams to 0 if we are at a breakpoint,
                // or if we are at the end of the measure
                bool isPrevBreakpoint = false;
                if( breakPointsItr == breakPointsEnd )
                {
                    isPrevBreakpoint = true;
                }
                else if ( position == *breakPointsItr )
                {
                    isPrevBreakpoint = true;
                    ++breakPointsItr;
                }
                
                if( isPrevBreakpoint )
                {
                    currNote->setBeams( 0 );
                }
                
                // set beams if next note is a rest
                else if( !currIsLast && nextNote->getIsRest() )
                {
                    if( nextNote->getMaxBeams() == 0 || nextNote->getMaxBeams() > currNote->getMaxBeams() )
                    {
                        currNote->setBeams( 0 );
                    }
                    else
                    {
                        currNote->setBeams( currNote->getMaxBeams() - nextNote->getMaxBeams() );
                    }
                }
                else if( !currIsLast )
                {
                    if ( nextNote->getMaxBeams() < currNote->getMaxBeams() )
                    {
                        currNote->setBeams( nextNote->getMaxBeams() );
                    }
                    else
                    {
                        currNote->setBeams( currNote->getMaxBeams() );
                    }
                }
                else if ( currIsLast )
                {
                    currNote->setBeams( 0 );
                }
            }
            UNUSED_PARAMETER( beatPattern );
        }
        
        
        IBeatPatternUP BeamingStrategy::chooseCorrectBeatPattern(  const IMeasureH& measure )
        {
            if( myBeatPattern )
            {
                return myBeatPattern->clone();
            }
            return measure->getTimeSignature()->getBeatPattern();
        }
        
        bool isBeamConnectionIncoming(
                 const IMeasureH& measure,
                 int noteIndex,
                 int beamIndex )
        {
            if ( ! measure )
            {
                return false;
            }
            if ( noteIndex < 1 )
            {
                return false;
            }
            return isBeamConnectionOutgoing( measure, noteIndex - 1, beamIndex );
        }
        
        bool isBeamConnectionOutgoing(
            const IMeasureH& measure,
            int noteIndex,
            int beamIndex )
        {
            if ( ! measure )
            {
                return false;
            }
            if ( noteIndex >= measure->getCount() )
            {
                return false;
            }
            const auto& note = measure->getNote( noteIndex );
            //if ( note->getMaxBeams() == 0 )
            //{
            //    return false;
            //}
            auto highestBeamedIndex = note->getBeams() - 1;
            if( highestBeamedIndex >= beamIndex )
            {
                return true;
            }
            return false;
        }
        
        bool isBeamExistenceRequirementSatisfied(
            const IMeasureH& measure,
            int noteIndex,
            int beamIndex )
        {
            if ( isBeamConnectionIncoming( measure, noteIndex, beamIndex ) )
            {
                return true;
            }
            if ( isBeamConnectionOutgoing( measure, noteIndex, beamIndex ) )
            {
                return true;
            }
            return false;
        }
        
        
        bool isNoteFirstInGroup(
            const IMeasureH& measure,
            int noteIndex,
            const IBeatPatternUP& beatPattern )
        {
            if( noteIndex == 0 )
            {
                return true;
            }
            auto beatPositions = beatPattern->getBeatPositions();

            for ( auto it = beatPositions.cbegin(); it != beatPositions.cend(); ++it )
            {
                if ( *it == measure->getNotePosition( noteIndex ) )
                {
                    return true;
                }
            }
            return false;
        }
        
        
        bool isNoteLastInGroup(
            const IMeasureH& measure,
            int noteIndex,
            const IBeatPatternUP& beatPattern  )
        {
            if ( noteIndex > measure->getCount() - 1 )
            {
                THROW( "noteIndex out of range" );
            }
            if ( noteIndex == measure->getCount() - 1 )
            {
                return true;
            }
            
            // is the next note a "first in group"?
            if( isNoteFirstInGroup( measure, noteIndex + 1, beatPattern ) )
            {
                return true;
            }
            return false;
        }
        
        
        bool isFollowedByRest(
            const IMeasureH& measure,
            int noteIndex )
        {
            if ( noteIndex >= measure->getCount() - 1 )
            {
                return false;
            }
            return measure->getNote( noteIndex + 1 )->getIsRest();
        }
        
        
        bool isPrecededByRest(
            const IMeasureH& measure,
            int noteIndex )
        {
            
            if ( noteIndex <= 0 )
            {
                return false;
            }
            return measure->getNote( noteIndex - 1 )->getIsRest();
        }
    }
}
