//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMovement.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(Movement)
        
        class Movement : public IMovement
        {
        public:
            virtual ~Movement();
            Movement();
            Movement( const Movement& other );
            Movement( Movement&& other );
            Movement& operator=( const Movement& other );
            Movement& operator=( Movement&& other );
            
            virtual IMovementUP clone() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
            
        private:
            
        };
    } 
}
