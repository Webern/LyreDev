/* matthew james briggs */

#pragma once
#include <iostream>
#include "Definitions.h"

namespace music
{
    class PitchSpecies
    {

    public:
        PitchSpecies();
        PitchSpecies( const Integer value );
        virtual ~PitchSpecies();
        Integer getValue() const;
        void setValue( const Integer value );
        operator Integer() const;
        PitchSpecies& operator++();
        PitchSpecies operator++(int);
        PitchSpecies& operator--();
        PitchSpecies operator--(int);
    private:
        Integer myValue;
    };
    
    bool operator==( const PitchSpecies& lhs, const PitchSpecies& rhs );
    bool operator!=( const PitchSpecies& lhs, const PitchSpecies& rhs );
    bool operator>=( const PitchSpecies& lhs, const PitchSpecies& rhs );
    bool operator<=( const PitchSpecies& lhs, const PitchSpecies& rhs );
    bool operator>( const PitchSpecies& lhs, const PitchSpecies& rhs );
    bool operator<( const PitchSpecies& lhs, const PitchSpecies& rhs );
    PitchSpecies operator+( const PitchSpecies& lhs, const PitchSpecies& rhs );
    PitchSpecies operator-( const PitchSpecies& lhs, const PitchSpecies& rhs );
}