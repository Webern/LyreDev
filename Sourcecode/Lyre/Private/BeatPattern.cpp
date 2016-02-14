#include "Lyre/Private/BeatPattern.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        BeatPattern::~BeatPattern() {}
        
        BeatPattern::BeatPattern()
        :myDurations()
        {}
        
        BeatPattern::BeatPattern( int count, const IDurationUP& dur )
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
            os << "BeatPattern<";
            if ( getIsEmpty() )
            {
                os << "empty>";
                return os;
            }
            for ( int i = 0; i < getCount(); ++i )
            {
                if ( i > 0 )
                {
                    os << ",";
                }
                os << *( myDurations.get( i ) );
                
            }
            os << ">";
            return os;
        }
        
        Rational BeatPattern::getTotalDuration() const
        {
            Rational total{ 0, 1 };
            if ( getIsEmpty() )
            {
                return total;
            }
            for( int i = 0; i < getCount(); ++i )
            {
                total += myDurations.get( i )->getValue();
            }
            return total;
        }
        
        void BeatPattern::loadDurations( int count, const IDurationUP& dur )
        {
            if ( count < 1 )
            {
                THROW( "invalid argument, must be >= 1" );
            }
            myDurations.clear();
            for ( int i = 0; i < count; ++i )
            {
                myDurations.add( dur );
            }
        }
        
        int BeatPattern::getCount() const
        {
            return myDurations.getCount();
        }
        
        bool BeatPattern::getIsEmpty() const
        {
            return myDurations.getIsEmpty();
        }
        
        const IDurationUPC BeatPattern::get( int index ) const
        {
            return myDurations.get( index );
        }
        
        int BeatPattern::getCurrentIndex() const
        {
            return myDurations.getCurrentIndex();
        }
        
        const IDurationUPC BeatPattern::getCurrent() const
        {
            return myDurations.getCurrent();
        }
        
        const IDurationUPC BeatPattern::getPrevious() const
        {
            return myDurations.getPrevious();
        }
        
        const IDurationUPC BeatPattern::getNext() const
        {
            return myDurations.getNext();
        }
        
        void BeatPattern::first()
        {
            myDurations.first();
        }
        
        void BeatPattern::last()
        {
            myDurations.last();
        }
        
        bool BeatPattern::next()
        {
            return myDurations.next();
        }
        
        bool BeatPattern::previous()
        {
            return myDurations.previous();
        }
        
        void BeatPattern::jump( int index )
        {
            myDurations.jump( index );
        }
        
        bool BeatPattern::getIsEnd() const
        {
            return myDurations.getIsEnd();
        }
        
        bool BeatPattern::checkDuration( const IDurationUP& dur ) const
        {
            THROW_IF_NULL( dur )
            return ! dur->getIsTuplet();
        }
        
        bool BeatPattern::checkDurations( const VecIDurationUP& durations ) const
        {
            for ( auto i = durations.cbegin(); i != durations.cend(); ++i )
            {
                if ( ! checkDuration( *i ) )
                {
                    return false;
                }
            }
            return true;
        }
    }
}

