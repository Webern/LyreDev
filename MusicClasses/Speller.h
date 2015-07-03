#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "TypeDefs.h"

namespace music
{
    class Speller;
    using SpellerPtr = std::shared_ptr<Speller>;
    using SpellerUPtr = std::unique_ptr<Speller>;
    using SpellerSet = std::vector<SpellerPtr>;
    using SpellerSetIter = SpellerSet::iterator;
    using SpellerSetIterConst = SpellerSet::const_iterator;
    inline SpellerPtr makeSpeller() { return std::make_shared<Speller>(); }
    
    class Speller
    {
    public:
        ~Speller() = default;
        
    };
}