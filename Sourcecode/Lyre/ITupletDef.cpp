#include "Lyre/ITupletDef.h"
#include <sstream>

namespace Lyre
{
    PUBLIC std::ostream& operator<<( std::ostream& os, const ITupletDef& val )
    {
        return val.toStream( os );
    }
}
