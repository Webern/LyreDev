#pragma once
#include <iostream>
#include "Definitions.h"
#include "RangeInt.h"
#include <memory>

namespace music
{
    /* This class represents the number of semitones
     that a given pitch is altered by.  It may be necessary
     to derive from this to handle microtonal music in the
     future. */
    class PitchAlter;
    using PitchAlterPtr = std::shared_ptr<PitchAlter>;
    using PitchAlterUPtr = std::unique_ptr<PitchAlter>;
    
    class PitchAlter
    {
    public:
        PitchAlter();
        virtual ~PitchAlter();
        explicit PitchAlter( const Integer value );
        static PitchAlterPtr make( const Integer value );
        Integer getValue() const;
        void setValue( const Integer value );
        PitchAlter& add( const Integer value );
        PitchAlter& subtract( const Integer value );
    private:
        RangeInt<Integer, -12, 12> myValue;
    };
}