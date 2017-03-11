#include "Lyre/Private/StepStrings.h"

namespace Lyre
{
    namespace Private
    {
        std::shared_ptr<Strings> StepStrings::ourStrings = std::make_shared<Strings>( Strings{ "C","D","E","F","G","A","B" } );
        
        std::shared_ptr<Strings> StepStrings::getStrings() const
        {
            initialize();
            return ourStrings;
        }
        
        void StepStrings::initialize() const
        {
            if ( ourStrings == nullptr || ourStrings->size() == 0 )
            {
                ourStrings = std::make_shared<Strings>( Strings{ "C","D","E","F","G","A","B" } );
            }
        }
    }
}
