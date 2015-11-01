#include "Lyre/IDur.h"
#include <sstream>

namespace Lyre
{
    IDur::~IDur() {}
    
    String IDur::toString() const
    {
        std::stringstream ss;
        toStream( ss );
        return ss.str();
    }
    std::ostream& operator<<( std::ostream& os, const IDur& object )
    {
        return object.toStream( os );
    }
}