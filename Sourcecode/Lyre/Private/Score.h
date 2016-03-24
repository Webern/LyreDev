//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IScore.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(Score)
        
        class Score : public IScore
        {
        public:
            virtual ~Score();
            Score();
            Score( const Score& other );
            Score( Score&& other );
            Score& operator=( const Score& other );
            Score& operator=( Score&& other );
            
            virtual IScoreUP clone() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
            
        private:
            
        };
    } 
}
