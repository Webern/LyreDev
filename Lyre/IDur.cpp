#include "IDur.h"
#include <sstream>

namespace lyre
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