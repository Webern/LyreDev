#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "TypeDefs.h"
#include "Rational.h"
#include "DurationBase.h"

namespace music
{

    class DurationCount
    {
    public:
        
        DurationCount();
        explicit DurationCount( const DurationBase& base, const Int count );
        DurationBase getDurationBase() const;
        void setDurationBase( const DurationBase& value );
        Int getCount() const;
        void setCount( const Int value );
    private:
        DurationBase myDurationBase;
        Int myCount;
    };
}