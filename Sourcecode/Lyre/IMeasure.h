//PUBLIC
#pragma once
#include "Lyre/Lyre.h"

namespace Lyre
{
    FORWARD_DECLARE(IMeasure)
    
    static const int MAX_NUMBER_OF_LAYERS = 4;
    
    class PUBLIC IMeasure : public IStreamable
    {
    public:
        virtual ~IMeasure() {};
        virtual IMeasureUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
    };
}
