#include "PitchSpeciesSpelled.h"

namespace music
{
    PitchSpeciesSpelled::PitchSpeciesSpelled()
    :PitchSpecies()
    ,mySpeller( PitchSpellerDefault::make() )
    {}
}