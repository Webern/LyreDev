#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "TypeDefs.h"
#include "Step.h"

namespace music
{
    class Spelling;
    using SpellingPtr = std::shared_ptr<Spelling>;
    using SpellingUPtr = std::unique_ptr<Spelling>;
    using SpellingSet = std::vector<SpellingPtr>;
    using SpellingSetIter = SpellingSet::iterator;
    using SpellingSetIterConst = SpellingSet::const_iterator;
    inline SpellingPtr makeSpelling( const Step& step, const Int alter ) { return std::make_shared<Spelling>( step, alter ); }
    
    class Spelling
    {
    public:
        virtual ~Spelling() = default;
        Spelling( const Step& step, const Int alter );
        virtual Step getStep() const;
        virtual Int getAlter() const;
        
    private:
        const Step myStep;
        const Int myAlter;
    };
}