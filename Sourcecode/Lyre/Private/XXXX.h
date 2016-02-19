//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IXXXX.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(XXXX)
    
        class XXXX : public IXXXX
        {
        public:
            virtual ~XXXX();
            XXXX();
            XXXX( const XXXX& other );
            XXXX( XXXX&& other );
            XXXX& operator=( const XXXX& other );
            XXXX& operator=( XXXX&& other );
        
            virtual IXXXXUP clone() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        
        private:

        };
    } 
}
