#include "Lyre/Private/PartGroupSpecFactory.h"
#include "Lyre/IPartGroupSpec.h"
#include "Lyre/Private/PartGroupSpec.h"


namespace Lyre
{
    namespace Private
    {
        PartGroupSpecFactory::~PartGroupSpecFactory() {}
        
        IPartGroupSpecUP PartGroupSpecFactory::create() const
        {
            return IPartGroupSpecUP{ new PartGroupSpec{} };
        }
    }
}
