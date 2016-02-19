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

        }

        XXXX::XXXX( XXXX&& other )
        {

        }

        XXXX& XXXX::operator=( const XXXX& other )
        {
            return *this;
        }

        XXXX& XXXX::operator=( XXXX&& other )
        {
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
