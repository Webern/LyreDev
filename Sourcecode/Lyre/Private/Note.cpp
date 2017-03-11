#include "Lyre/Private/Note.h"
#include "Lyre/Private/throw.h"
#include <string>
#include <sstream>
#include "LyreTest/Tests/TestTimer.h"

namespace Lyre
{
    namespace Private
    {
        Note::~Note() {}
        
        Note::Note( const IPitchUP& pitch, const IDurationUP& duration )
        :myPitch( nullptr )
        ,myDuration( nullptr )
        ,myIsRest( false )
        ,myBeams( 0 )
        {
			THROW_IF_NULL( pitch )
			THROW_IF_NULL( duration )
			myPitch = pitch->clone();
			myDuration = duration->clone();
        }
        
        
        Note::Note( const Note& other )
        :myPitch( other.myPitch->clone() )
        ,myDuration( other.myDuration->clone() )
        ,myIsRest( other.myIsRest )
        ,myBeams( other.myBeams )
        {
            
        }
        
        
        Note::Note( Note&& other )
        :myPitch( std::move( other.myPitch ) )
        ,myDuration( std::move( other.myDuration ) )
        ,myIsRest( std::move( other.myIsRest ) )
        ,myBeams( std::move( other.myBeams ) )
        {
            
        }
        
        
        Note& Note::operator=( const Note& other )
        {
            myPitch = other.myPitch->clone();
            myDuration = other.myDuration->clone();
            myIsRest = other.myIsRest;
            myBeams = other.myBeams;
            return *this;
        }
        
        
        Note& Note::operator=( Note&& other )
        {
            myPitch = std::move( other.myPitch );
            myDuration = std::move( myDuration );
            myIsRest = std::move( myIsRest );
            myBeams = std::move( myBeams );
            return *this;
        }
        
        
        INoteUP Note::clone() const
        {
			return INoteUP{ new Note{ *this } };
        }
        
        
        IPitchUP Note::getPitch() const
        {
            return myPitch->clone();
        }
        
        
        void Note::setPitch( const IPitchUP& pitch )
        {
            THROW_IF_NULL( pitch );
            myPitch = pitch->clone();
        }
        
        
        IDurationUP Note::getDuration() const
        {
            return myDuration->clone();
        }
        
        
        bool Note::getIsRest() const
        {
            return myIsRest;
        }
        
        
        void Note::setIsRest( const bool isRest )
        {
            myIsRest = isRest;
        }
        
        
        int Note::getBeams() const
        {
            return myBeams;
        }
        
        
        void Note::setBeams( int value )
        {
            THROW_IF_BAD_VALUE( value, 0, getMaxBeams() )
            myBeams = value;
        }
        
        
        int Note::getMaxBeams() const
        {
            return myDuration->getDurBase()->getMaxBeams();
        }
        
        
        std::ostream& Note::toStream( std::ostream& os ) const
        {
            os << "{ ";
            if ( myIsRest )
            {
                os << "Rest : ";
            }
            else
            {
                os << ( *myPitch ) << " : ";
            }
            os << ( *myDuration ) << " }";
            return os;
        }
        
        
        String Note::toString() const
        {
            std::stringstream ss;
            toStream( ss );
            return ss.str();
        }
        
    }
}
