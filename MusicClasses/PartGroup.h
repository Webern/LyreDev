#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>

namespace music
{
    class PartGroup;
    using PartGroupPtr = std::shared_ptr<PartGroup>;
    using PartGroupUPtr = std::unique_ptr<PartGroup>;
    using PartGroupSet = std::vector<PartGroupPtr>;
    using PartGroupSetIter = PartGroupSet::iterator;
    using PartGroupSetIterConst = PartGroupSet::const_iterator;
    inline PartGroupPtr makePartGroup() { return std::make_shared<PartGroup>(); }
    
    class PartGroup
    {
    };
}