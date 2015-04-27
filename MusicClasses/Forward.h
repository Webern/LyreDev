#pragma once
namespace music
{
    class PitchStep;
    using PitchStepPtr = std::shared_ptr<PitchStep>;
    class PitchAlter;
    using PitchAlterPtr = std::shared_ptr<PitchAlter>;
    class PitchSpecies;
    using PitchSpeciesPtr = std::shared_ptr<PitchSpecies>;
    class SpellerInterface;
    using SpellerPtr = std::shared_ptr<SpellerInterface>;
}