//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMovementSpec.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(MovementSpec)
        
        class MovementSpec : public IMovementSpec
        {
        public:
            virtual ~MovementSpec();
            MovementSpec( int number );
            MovementSpec( const MovementSpec& other );
            MovementSpec( MovementSpec&& other );
            MovementSpec& operator=( const MovementSpec& other );
            MovementSpec& operator=( MovementSpec&& other );
            
            virtual IMovementSpecUP clone() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
            
            virtual int getNumber() const;
            virtual String getTitle() const;
            virtual String getDisplayTitle() const;
            
            virtual void setTitle( const String& title );
            virtual void setDisplayTitle( const String& dispTitle );
            
        private:
            int myNumber;
            String myTitle;
            String myDispTitle;
            
        };
    } 
}
