#pragma once
#include <iostream>
#include "Definitions.h"
#include "Mod.h"

namespace music
{
    class IntervalSpecies;
    using IntervalSpeciesPtr = std::shared_ptr<IntervalSpecies>;
    
    class IntervalSpecies
    {
    public:
        
        /* Construction */
        IntervalSpecies();
        explicit IntervalSpecies( const Integer value );
        explicit IntervalSpecies( const PitchSpellerPtr& speller, const Integer value );
        virtual ~IntervalSpecies();
        static IntervalSpeciesPtr make();
        static IntervalSpeciesPtr make( const Integer value );
        static IntervalSpeciesPtr make( const IntervalSpeciesPtr& other );
        
        /* Copy */
        IntervalSpecies( const IntervalSpecies& other );
        IntervalSpecies( IntervalSpecies&& other );
        IntervalSpecies& operator=( const IntervalSpecies& other );
        IntervalSpecies& operator=( IntervalSpecies&& other );
        
        /* Get Set */
        virtual Integer getValue() const final;
        virtual void setValue( const Integer value ) final;
        
        /* Math */
        virtual IntervalSpecies& add( const Integer value );
        virtual IntervalSpecies& subtract( const Integer value );
        
        /* Increment */
        virtual IntervalSpecies& operator++();
        virtual IntervalSpecies operator++(int);
        virtual IntervalSpecies& operator--();
        virtual IntervalSpecies operator--(int);
        
        /* Spelling */
        Integer getDiatonicSteps() const;
        Integer getAlter() const;
        
    private:
        Mod<Integer,12> myValue;
        SpellerUPtr mySpeller;
    };
}