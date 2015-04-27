#include "PitchSpellerDefault.h"


namespace music
{
    PitchSpellerPtr PitchSpellerDefault::make()
    {
        return std::make_shared<PitchSpellerDefault>();
    }
    const PitchStepPtr PitchSpellerDefault::getPitchStep( const PitchSpecies& pitchSpecies ) const
    {
        switch ( pitchSpecies.getValue() )
        {
            case 0:
                return PitchStep::make( 0 ); // alter=0
                break;
            case 1:
                return PitchStep::make( 0 ); // alter=1
                break;
            case 2:
                return PitchStep::make( 1 ); // alter=0
                break;
            case 3:
                return PitchStep::make( 2 ); // alter=-1
                break;
            case 4:
                return PitchStep::make( 2 ); // alter=0
                break;
            case 5:
                return PitchStep::make( 3 ); // alter=0
                break;
            case 6:
                return PitchStep::make( 3 ); // alter=1
                break;
            case 7:
                return PitchStep::make( 4 ); // alter=0
                break;
            case 8:
                return PitchStep::make( 4 ); // alter=1
                break;
            case 9:
                return PitchStep::make( 5 ); // alter=0
                break;
            case 10:
                return PitchStep::make( 6 ); // alter=-1
                break;
            case 11:
                return PitchStep::make( 6 ); // alter=0
                break;
            default:
                throw std::runtime_error( "PitchSpellerDefault::getPitchStep unknown PitchSpecies value" );
                break;
        }
    }
    const PitchAlterPtr PitchSpellerDefault::getPitchAlter( const PitchSpecies& pitchSpecies ) const
    {
        Integer x = getPitchStep( pitchSpecies )->getPitchSpeciesEquivalent();
        Integer s = pitchSpecies.getValue() - x;
        return PitchAlter::make( s );
    }
}
