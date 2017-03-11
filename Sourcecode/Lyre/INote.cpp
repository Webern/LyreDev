#include "Lyre/INote.h"
#include <sstream>

namespace Lyre
{
    PUBLIC std::ostream& operator<<( std::ostream& os, const INote& note )
    {
        return note.toStream( os );
    }
}
