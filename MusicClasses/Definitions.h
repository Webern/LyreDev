#pragma once
#include <iostream>
#include <string>
#include <memory>

namespace music
{
    using Integer = int;
    using String = std::string;
    
    class PitchSpecies;
    using PitchSpeciesPtr = std::shared_ptr<PitchSpecies>;
    using PitchSpeciesUPtr = std::unique_ptr<PitchSpecies>;
    
    class PitchStep;
    using PitchStepPtr = std::shared_ptr<PitchStep>;
    using PitchStepUPtr = std::unique_ptr<PitchStep>;
    
    
    class PitchAlter;
    using PitchAlterPtr = std::shared_ptr<PitchAlter>;
    using PitchAlterUPtr = std::unique_ptr<PitchAlter>;
    
    class SpellerInterface;
    using SpellerPtr = std::shared_ptr<SpellerInterface>;
    using SpellerUPtr = std::unique_ptr<SpellerInterface>;
    
    class DefaultSpeller;
    using DefaultSpellerPtr = std::shared_ptr<DefaultSpeller>;
    using DefaultSpellerUPtr = std::unique_ptr<DefaultSpeller>;
    
    class IntervalSpecies;
    using IntervalSpeciesPtr = std::shared_ptr<IntervalSpecies>;
    using IntervalSpeciesUPtr = std::unique_ptr<IntervalSpecies>;
}