#include "Movement.h"

namespace music
{
    std::string Movement::getTitle() const
    {
        return myTitle;
    }
    void Movement::setTitle(const std::string& value )
    {
        myTitle = value;
    }
    PartStackPtr Movement::getPartStack() const
    {
        return myPartStack;
    }
    void Movement::setPartStack(const PartStackPtr& value )
    {
        myPartStack = value;
    }
}