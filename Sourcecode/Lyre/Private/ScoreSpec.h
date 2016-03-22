//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IScoreSpec.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(ScoreSpec)
        
        class ScoreSpec : public IScoreSpec
        {
        public:
            virtual ~ScoreSpec();
            ScoreSpec();
            ScoreSpec( const ScoreSpec& other );
            ScoreSpec( ScoreSpec&& other );
            ScoreSpec& operator=( const ScoreSpec& other );
            ScoreSpec& operator=( ScoreSpec&& other );
            
            virtual IScoreSpecUP clone() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
            
        private:
            
        };
    } 
}
