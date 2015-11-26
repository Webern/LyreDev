#include "Lyre/ITupletDef.h"
#include "Lyre/Private/copyTo.h"

#include <sstream>

namespace Lyre
{
    std::ostream& operator<<( std::ostream& os, const ITupletDef& val )
    {
        return val.toStream( os );
    }
}
