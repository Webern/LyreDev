#include "Lyre/ITupletDef.h"

#include <sstream>

namespace Lyre
{
    String ITupletDef::toString() const
    {
        std::stringstream ss;
        this->toStream( ss );
        return String{ ss.str() };
    }
    std::ostream& operator<<( std::ostream& os, const ITupletDef& StepName )
    {
        return StepName.toStream( os );
    }
}
