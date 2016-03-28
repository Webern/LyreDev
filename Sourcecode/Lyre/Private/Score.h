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
            ~Score();
            Score( const IScoreSpecUP& spec );
            Score( const Score& other );
            Score( Score&& other );
            Score& operator=( const Score& other );
            Score& operator=( Score&& other );
            
            IScoreUP clone() const;
            std::ostream& toStream( std::ostream& os ) const;
        
            IScoreSpecUP getSpec() const;
            void setSpec( const IScoreSpecUP spec );

            int getMovementCount() const;
            void addMovement( IMovementUP&& movement );
            void addMovement( const IMovementUP& movement );
            IMovementH getMovement( int movementIndex );
            IMovementHC getMovement( int movementIndex ) const;
            IMovementHC getMovementConst( int movementIndex ) const;
            
        private:
            IScoreSpecUP mySpec;
            VecIMovementUP myMovements;
        };
    } 
}
