#include "EnumInterface.h"

namespace lyre
{
    class StepInterface;
    using StepPtr = std::shared_ptr<StepInterface>;
    using StepUPtr = std::unique_ptr<StepInterface>;
    class StepInterface : public EnumInterface
    {
        
    };
}