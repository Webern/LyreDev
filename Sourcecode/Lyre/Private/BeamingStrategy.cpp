#include "Lyre/Private/BeamingStrategy.h"

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
        
        
        IBeatPatternUP BeamingStrategy::chooseCorrectBeatPattern(  const IMeasureUP& measure )
        {
            if( myBeatPattern )
            {
                return myBeatPattern->clone();
            }
            return measure->getTimeSignature()->getBeatPattern();
        }
        
    }
}
