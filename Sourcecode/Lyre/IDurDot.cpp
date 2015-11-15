#include "Lyre/IDurBase.h"
#include <sstream>

namespace Lyre
{
    IDurBase::~IDurBase() {}
    
    String IDurBase::toString() const
    {
        std::stringstream ss;
        toStream( ss );
        return ss.str();
    }
    std::ostream& operator<<( std::ostream& os, const IDurBase& object )
    {
        return object.toStream( os );
    }
}