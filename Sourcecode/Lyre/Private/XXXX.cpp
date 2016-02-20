#include "Lyre/Private/XXXX.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        XXXX::~XXXX()
        {
        }

        XXXX::XXXX()
        {

        }

        XXXX::XXXX( const XXXX& other )
        {
            UNUSED_PARAMETER( other )
        }

        XXXX::XXXX( XXXX&& other )
        {
            UNUSED_PARAMETER( other )
        }

        XXXX& XXXX::operator=( const XXXX& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        XXXX& XXXX::operator=( XXXX&& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        IXXXXUP XXXX::clone() const
        {
            return IXXXXUP{ new XXXX{ *this } };
        }

        std::ostream& XXXX::toStream( std::ostream& os ) const
        {
            return os << "XXXX not implemented";
        }
    }
}
