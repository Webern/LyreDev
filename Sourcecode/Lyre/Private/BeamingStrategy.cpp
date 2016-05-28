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
            std::vector<Rational> breakPoints;
            auto beatPattern = chooseCorrectBeatPattern( measure );
            Rational position{ 0, 1 };
            for( int i = 0; i <  beatPattern->getCount(); ++i )
            {
                position += beatPattern->get( i )->getValue();
                breakPoints.push_back( position );
            }
            position = Rational{ 0, 1 };
            //auto lastBreakIter = breakPoints.cbegin();
            //auto beakPointsEnd = breakPoints.cend();
            for( int i = 0; i < measure->getCount(); ++i )
            {
                
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
