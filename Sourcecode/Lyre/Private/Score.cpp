#include "Lyre/Private/Score.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        Score::~Score()
        {
        }

        Score::Score()
        {

        }

        Score::Score( const Score& other )
        {
            UNUSED_PARAMETER( other )
        }

        Score::Score( Score&& other )
        {
            UNUSED_PARAMETER( other )
        }

        Score& Score::operator=( const Score& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        Score& Score::operator=( Score&& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        IScoreUP Score::clone() const
        {
            return IScoreUP{ new Score{ *this } };
        }

        std::ostream& Score::toStream( std::ostream& os ) const
        {
            return os << "Score not implemented";
        }
    }
}
