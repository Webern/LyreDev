#include "Lyre/Private/BeatPattern.h"
#include "Lyre/Private/throw.h"
#if 1==0
namespace Lyre
{
    namespace Private
    {
        BeatPattern::~BeatPattern() {}
        
        BeatPattern::BeatPattern()
        :myDurations()
        {}
        
        BeatPattern::BeatPattern( Integer count, const IDurationUP& dur )
        :myDurations()
        {
            if( ! checkDuration( dur ) )
            {
                THROW( "tuplets are not allowed" )
            }
            loadDurations( count, dur );
        }
        
        BeatPattern::BeatPattern( const VecIDurationUP& durations )
        :myDurations()
        {
            if( ! checkDurations( durations ) )
            {
                THROW( "tuplets are not allowed" )
            }
            myDurations = Collection<IDurationUP>{ durations };
        }
        
        IBeatPatternUP BeatPattern::clone() const
        {
            return IBeatPatternUP{ new BeatPattern{ *this } };
        }
        
        std::ostream& BeatPattern::toStream( std::ostream& os ) const
        {
            os << "BeatPattern:< ";
            if ( getIsEmpty() )
            {
                os << "empty >";
                return os;
            }
            int currentIndex = 0;
            bool wasEnd = getIsEnd();
            if ( !wasEnd )
            {
                currentIndex = myDurations.getCurrentIndex();
            }
            for ( int i = 0; i < getCount(); ++i )
            {
                myDurations.jump( i );
                
            }
            return os;
        }

        void BeatPattern::loadDurations( Integer count, const IDurationUP& dur )
        {
            if ( count < 1 )
            {
                THROW( "invalid argument, must be > 1" );
            }
            for ( int i = 0; i < count; ++i )
            {
                myDurations.push_back( dur->clone() );
            }
        }
        
        void BeatPattern::loadDurations( const VecIDurationUP& durations )
        {
            if ( durations.size() == 0 )
            {
                THROW( "invalid argument, durations is empty" );
            }
            for ( auto i = durations.cbegin(); i != durations.cend(); ++i )
            {
                THROW_IF_NULL( (*i) )
                myDurations.push_back( (*i)->clone() );
            }
        }
        
        Integer BeatPattern::getCount() const
        {
            return static_cast<Integer>( myDurations.size() );
        }
        
        bool BeatPattern::getIsEmpty() const
        {
            return getCount() == 0;
        }
        
        const IDurationUPC BeatPattern::getCurrent() const
        {
            if ( myIsEnd )
            {
                THROW( "cannot return when getIsEnd is true" )
            }
            if ( myCurrent < 0 || myCurrent > getCount() - 1 )
            {
                THROW( "current pointer is invalid" )
            }
            return myDurations[static_cast<ULong>( myCurrent )]->clone();
        }
        const IDurationUPC BeatPattern::getPrevious() const
        {
            if ( myIsEnd )
            {
                THROW( "cannot return when getIsEnd is true" )
            }
            if ( myCurrent < 0 || myCurrent > getCount()-1 )
            {
                THROW( "current pointer is invalid" )
            }
            if ( myCurrent == 0 )
            {
                THROW( "cannot get next, pointer is at first entry" )
            }
            return myDurations[static_cast<ULong>( myCurrent-1 )]->clone();
        }
        const IDurationUPC BeatPattern::getNext() const
        {
            if ( myIsEnd )
            {
                THROW( "cannot return when getIsEnd is true" )
            }
            if ( myCurrent < 0 || myCurrent > getCount()-1 )
            {
                THROW( "current pointer is invalid" )
            }
            if ( myCurrent == getCount()-1 )
            {
                THROW( "cannot get next, pointer is at final entry" )
            }
            return myDurations[static_cast<ULong>( myCurrent+1 )]->clone();
        }
        
        bool BeatPattern::getIsEnd() const
        {
            return myIsEnd;
        }
    }
}
#endif
