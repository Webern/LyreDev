#pragma once
#include <iostream>
#include "Definitions.h"
#include "Mod.h"

namespace music
{
    class PitchSpecies
    {

    public:
        PitchSpecies();
        explicit PitchSpecies( const Integer value );
        virtual ~PitchSpecies();
        virtual Integer getValue() const final;
        virtual void setValue( const Integer value ) final;
        virtual PitchSpecies& add( const Integer value );
        virtual PitchSpecies& subtract( const Integer value );
        virtual PitchSpecies& operator++();
        virtual PitchSpecies operator++(int);
        virtual PitchSpecies& operator--();
        virtual PitchSpecies operator--(int);
        //virtual Integer difference( const PitchSpecies& other ) const;
        //virtual Integer equals( const PitchSpecies& other ) const;
        bool operator==( const PitchSpecies& rhs ) const;
        bool operator!=( const PitchSpecies& rhs ) const;
        bool operator>=( const PitchSpecies& rhs ) const;
        bool operator<=( const PitchSpecies& rhs ) const;
        bool operator>( const PitchSpecies& rhs ) const;
        bool operator<( const PitchSpecies& rhs ) const;
    private:
        Mod<Integer,12> myValue;
    };
}