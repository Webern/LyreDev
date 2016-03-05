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
        {
			THROW_IF_NULL( pitch )
			THROW_IF_NULL( duration )
			//LyreTest::TestTimer pitchTimer;
            myPitch = pitch->clone();
			//pitchTimer.report( "Note::Note - myPitch = pitch->clone();" );
			//LyreTest::TestTimer durTimer;
            myDuration = duration->clone();
			//durTimer.report( "Note::Note - myDuration = duration->clone();" );
        }
        
        INoteUP Note::clone() const
        {
			//LyreTest::TestTimer timer;
			auto ret = INoteUP{ new Note{ myPitch, myDuration } };
			//timer.report( "Note::clone" );
			return std::move( ret );
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
