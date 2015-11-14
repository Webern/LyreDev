#include "Lyre/INote.h"
#include <sstream>

namespace Lyre
{
    String INote::toString() const
    {
        std::stringstream ss;
        toStream( ss );
        return ss.str();
    }
    
    std::ostream& operator<<( std::ostream& os, const INote& object )
    {
        return object.toStream( os );
    }
}