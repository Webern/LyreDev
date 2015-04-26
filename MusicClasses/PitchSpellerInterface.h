#include <iostream>
#include <memory>
#include <PitchSpecies.h"
#include <PitchStep.h"
#include <PitchAlter.h"

namespace music
{
    class PitchSpellerInterface;
    using PitchSpeller = std::shared_ptr<PitchSpellerInterface>;
    using PitchSpellerUPtr = std::unique_ptr<PitchSpellerInterface>;
    class PitchSpellerInterface
    {
        virtual ~PitchSpellerInterface() = default;
        const PitchAlter& getPitchAlter( const PitchSpecies& );
    };
}