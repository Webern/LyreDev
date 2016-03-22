#include "Lyre/Private/ScoreSpec.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        ScoreSpec::~ScoreSpec()
        {
        }

        ScoreSpec::ScoreSpec()
        {

        }

        ScoreSpec::ScoreSpec( const ScoreSpec& other )
        {
            UNUSED_PARAMETER( other )
        }

        ScoreSpec::ScoreSpec( ScoreSpec&& other )
        {
            UNUSED_PARAMETER( other )
        }

        ScoreSpec& ScoreSpec::operator=( const ScoreSpec& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        ScoreSpec& ScoreSpec::operator=( ScoreSpec&& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        IScoreSpecUP ScoreSpec::clone() const
        {
            return IScoreSpecUP{ new ScoreSpec{ *this } };
        }

        std::ostream& ScoreSpec::toStream( std::ostream& os ) const
        {
            return os << "ScoreSpec not implemented";
        }
    }
}
