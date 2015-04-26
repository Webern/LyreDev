#pragma once
#include <iostream>
#include "Definitions.h"
#include "Mod.h"

namespace music
{
    class PitchStep
    {
        
    public:
        PitchStep();
        explicit PitchStep( const Integer value );
        virtual ~PitchStep();
        Integer getValue() const;
        void setValue( const Integer value );
        PitchStep& add( const Integer value );
        PitchStep& subtract( const Integer value );
        PitchStep& operator++();
        PitchStep operator++(int);
        PitchStep& operator--();
        PitchStep operator--(int);
        bool operator==( const PitchStep& rhs ) const;
        bool operator!=( const PitchStep& rhs ) const;
        bool operator>=( const PitchStep& rhs ) const;
        bool operator<=( const PitchStep& rhs ) const;
        bool operator>( const PitchStep& rhs ) const;
        bool operator<( const PitchStep& rhs ) const;
    private:
        Mod<Integer,7> myValue;
    };
}