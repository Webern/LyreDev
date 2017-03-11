//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMeasure.h"

namespace Lyre
{
    FORWARD_DECLARE(IMeasureStrategy)
    
    class PUBLIC IMeasureStrategy
    {
    public:
        virtual ~IMeasureStrategy() {};
        virtual IMeasureStrategyUP clone() const = 0;
        virtual void applyStrategy( const IMeasureUP& measure ) = 0;
    };
}
