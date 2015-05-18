#include <iostream>
#include <string>
#include <memory>
#include <vector>

namespace music
{
    class Movement;
    using MovementPtr = std::shared_ptr<Movement>;
    using MovementUPtr = std::unique_ptr<Movement>;
    using MovementSet = std::vector<MovementPtr>;
    using MovementSetIter = MovementSet::iterator;
    using MovementSetIterConst = MovementSet::const_iterator;
    
    class Movement
    {
    public:
        std::string getTitle() const;
    private:
        std::string myTitle;
    };
}