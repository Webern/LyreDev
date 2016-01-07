#include "Lyre/Private/Note.h"
#include "Lyre/Private/throw.h"
#include <string>
#include <sstream>

namespace Lyre
{
    namespace Private
    {
        Note::~Note() {}
        
        Note::Note( const IPitchUP& pitch, const IDurationUP& duration )
        :myPitch( nullptr )
        ,myDuration( nullptr )
        ,myIsRest( false )
        {
            THROW_IF_NULL( pitch )
            THROW_IF_NULL( duration )
            myPitch = pitch->clone();
            myDuration = duration->clone();
        }
        
        INoteUP Note::clone() const
        {
            return INoteUP{ new Note{ myPitch, myDuration } };
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
