#pragma once
#include <iostream>
#include "Definitions.h"
#include "Mod.h"
#include <memory>

namespace music
{
    enum class PitchStepName
    {
        c = 0,
        d = 1,
        e = 2,
        f = 3,
        g = 4,
        a = 5,
        b = 6
    };
    class PitchStep;
    using PitchStepPtr = std::shared_ptr<PitchStep>;
    using PitchStepUPtr = std::unique_ptr<PitchStep>;
    class PitchStep
    {
        
    public:
        
        /* Construction */
        PitchStep();
        explicit PitchStep( const Integer value );
        PitchStep( const PitchStepName value );
        virtual ~PitchStep();
        static PitchStepPtr make( const Integer value );

        /* Conversion */
        operator PitchStepName() const;
        
        /* Get Set */
        Integer getValue() const;
        void setValue( const Integer value );
        void setValue( const PitchStepName value );
        Integer getPitchSpeciesEquivalent() const;
        
        /* math */
        PitchStep& add( const Integer value );
        PitchStep& subtract( const Integer value );
        
        /* Increment */
        PitchStep& operator++();
        PitchStep operator++(int);
        PitchStep& operator--();
        PitchStep operator--(int);
        
        /* Comparison */
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