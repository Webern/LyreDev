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
    
    class PitchSpeller;
    using PitchSpellerPtr = std::shared_ptr<PitchSpeller>;
    using PitchSpellerUPtr = std::unique_ptr<PitchSpeller>;
    
    class DefaultPitchSpeller;
    using DefaultPitchSpellerPtr = std::shared_ptr<DefaultPitchSpeller>;
    using DefaultPitchSpellerUPtr = std::unique_ptr<DefaultPitchSpeller>;
    
    class IntervalSpecies;
    using IntervalSpeciesPtr = std::shared_ptr<IntervalSpecies>;
    using IntervalSpeciesUPtr = std::unique_ptr<IntervalSpecies>;
    
    class IntervalSpeller;
    using IntervalSpellerPtr = std::shared_ptr<IntervalSpeller>;
    using IntervalSpellerUPtr = std::unique_ptr<IntervalSpeller>;
    
}