#include "Lyre/IDuration.h"
#include <sstream>

namespace Lyre
{
    std::ostream& operator<<( std::ostream& os, const IDuration& object )
    {
        return object.toStream( os );
    }
}
