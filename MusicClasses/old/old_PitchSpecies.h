#pragma once
#include <iostream>
#include "Definitions.h"
#include "Mod.h"

namespace music
{
    class PitchSpecies;
    using PitchSpeciesPtr = std::shared_ptr<PitchSpecies>;
    
    class PitchSpecies
    {
    public:
        
        /* Construction */
        PitchSpecies();
        explicit PitchSpecies( const Integer value );
        explicit PitchSpecies( const PitchSpellerPtr& speller, const Integer value );
        virtual ~PitchSpecies();
        static PitchSpeciesPtr make();
        static PitchSpeciesPtr make( const Integer value );
        static PitchSpeciesPtr make( const PitchSpeciesPtr& other );
        
        /* Copy */
        PitchSpecies( const PitchSpecies& other );
        PitchSpecies( PitchSpecies&& other );
        PitchSpecies& operator=( const PitchSpecies& other );
        PitchSpecies& operator=( PitchSpecies&& other );
        
        /* Get Set */
        virtual Integer getValue() const final;
        virtual void setValue( const Integer value ) final;
        
        /* Math */
        virtual PitchSpecies& add( const Integer value );
        virtual PitchSpecies& subtract( const Integer value );
        
        /* Increment */
        virtual PitchSpecies& operator++();
        virtual PitchSpecies operator++(int);
        virtual PitchSpecies& operator--();
        virtual PitchSpecies operator--(int);
        
        /* Spelling */
        const PitchStepPtr getPitchStep() const;
        const PitchAlterPtr getPitchAlter() const;
        const PitchSpellerUPtr& getSpeller() const;
        void setSpeller( const PitchSpellerUPtr& speller );
        void setSpeller( PitchSpellerUPtr&& speller );

    private:
        Mod<Integer,12> myValue;
        PitchSpellerUPtr mySpeller;
    };
}