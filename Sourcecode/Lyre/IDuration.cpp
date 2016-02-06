#include "Lyre/IDuration.h"
#include <sstream>

namespace Lyre
{
    PUBLIC std::ostream& operator<<( std::ostream& os, const IDuration& object )
    {
        return object.toStream( os );
    }
}
