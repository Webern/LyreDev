#include <iostream>
#include <string>
#include <memory>
#include <vector>

namespace music
{
    class PartStack;
    using PartStackPtr = std::shared_ptr<PartStack>;
    using PartStackUPtr = std::unique_ptr<PartStack>;
    using PartStackSet = std::vector<PartStackPtr>;
    using PartStackSetIter = PartStackSet::iterator;
    using PartStackSetIterConst = PartStackSet::const_iterator;
    inline PartStackPtr makePartStack() { return std::make_shared<PartStack>(); }
    
    class PartStack
    {
    public:
        ~PartStack() = default;

    private:

    };
}