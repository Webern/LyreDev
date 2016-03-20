#include "Lyre/Private/Movement.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        Movement::~Movement()
        {
        }

        Movement::Movement()
        {

        }

        Movement::Movement( const Movement& other )
        {
            UNUSED_PARAMETER( other )
        }

        Movement::Movement( Movement&& other )
        {
            UNUSED_PARAMETER( other )
        }

        Movement& Movement::operator=( const Movement& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        Movement& Movement::operator=( Movement&& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        IMovementUP Movement::clone() const
        {
            return IMovementUP{ new Movement{ *this } };
        }

        std::ostream& Movement::toStream( std::ostream& os ) const
        {
            return os << "Movement not implemented";
        }
    }
}
