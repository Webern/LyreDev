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
    inline MovementPtr makeMovement() { return std::make_shared<Movement>(); }
    
    class PartStack;
    using PartStackPtr = std::shared_ptr<PartStack>;
    using PartStackUPtr = std::unique_ptr<PartStack>;
    
    class Movement
    {
    public:
        ~Movement() = default;
        std::string getTitle() const;
        void setTitle( const std::string& value );
        PartStackPtr getPartStack() const;
        void setPartStack( const PartStackPtr& value );
        
    private:
        std::string myTitle;
        PartStackPtr myPartStack;
    };
}