#include "Lyre/Private/MovementSpec.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        MovementSpec::~MovementSpec()
        {
            
        }

        
        MovementSpec::MovementSpec( int number )
        : myNumber( number )
        , myTitle()
        , myDispTitle()
        {

        }
        

        MovementSpec::MovementSpec( const MovementSpec& other )
        {
            UNUSED_PARAMETER( other )
        }

        
        MovementSpec::MovementSpec( MovementSpec&& other )
        {
            UNUSED_PARAMETER( other )
        }
        

        MovementSpec& MovementSpec::operator=( const MovementSpec& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }
        

        MovementSpec& MovementSpec::operator=( MovementSpec&& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        
        IMovementSpecUP MovementSpec::clone() const
        {
            return IMovementSpecUP{ new MovementSpec{ *this } };
        }

        
        std::ostream& MovementSpec::toStream( std::ostream& os ) const
        {
            return os << getDisplayTitle();
        }
        
        
        int MovementSpec::getNumber() const
        {
            return myNumber;
        }
        
        
        String MovementSpec::getTitle() const
        {
            return myTitle;
        }
        
        
        String MovementSpec::getDisplayTitle() const
        {
            if ( myDispTitle.size() > 0 )
            {
                return myDispTitle;
            }
            std::stringstream ss;
            ss << getNumber();
            ss << ". ";
            ss << getTitle();
            return ss.str();
        }
        
        void MovementSpec::setTitle( const String& title )
        {
            myTitle = title;
        }
        
        
        void MovementSpec::setDisplayTitle( const String& dispTitle )
        {
            myDispTitle = dispTitle;
        }
    }
}
