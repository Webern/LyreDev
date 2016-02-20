#include "Lyre/Private/XXXXFactory.h"
#include "Lyre/IXXXX.h"
#include "Lyre/Private/XXXX.h"


namespace Lyre
{
    namespace Private
    {
        XXXXFactory::~XXXXFactory() {}
        
        IXXXXUP XXXXFactory::create()
        {
            return IXXXXUP{ new XXXX{} };
        }
    }
}
