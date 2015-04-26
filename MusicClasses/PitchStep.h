#pragma once
#include <iostream>
#include "Definitions.h"
#include "Mod.h"
#include <memory>

namespace music
{
    class PitchStep;
    using PitchStepPtr = std::shared_ptr<PitchStep>;
    using PitchStepUPtr = std::unique_ptr<PitchStep>;
    class PitchStep
    {
        
    public:
        PitchStep();
        explicit PitchStep( const Integer value );
        virtual ~PitchStep();
        static PitchStepPtr make( const Integer value );
        Integer getValue() const;
        void setValue( const Integer value );
        Integer getPitchSpeciesEquivalent() const;
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