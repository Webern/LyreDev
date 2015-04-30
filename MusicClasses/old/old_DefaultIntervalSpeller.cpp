#include "DefaultIntervalSpeller.h"

namespace music
{
    Integer DefaultIntervalSpeller::getDiatonicSteps( const IntervalSpecies& value ) const
    {
        switch ( value.getValue() )
        {
            case 0:
                return 0; // alter = 0
                break;
            case 1:
                return 1; // alter = -1
                break;
            case 2:
                return 1; // alter = 0
                break;
            case 3:
                return 2; // alter = -1
                break;
            case 4:
                return 2; // alter = 0
                break;
            case 5:
                return 3; // alter = 0
                break;
            case 6:
                return 3; // alter = 1
                break;
            case 7:
                return 4; // alter = 0
                break;
            case 8:
                return 5; // alter = -1
                break;
            case 9:
                return 5; // alter = 0
                break;
            case 10:
                return 6; // alter = -1
                break;
            case 11:
                return 6; // alter = 0
                break;
            default:
                throw std::runtime_error( "DefaultIntervalSpeller::getDiatonicSteps unknown IntervalSpecies value" );
                break;
        }
    }
    Integer DefaultIntervalSpeller::getAlter( const IntervalSpecies& ) const
    {
        
    }
    DefaultIntervalName DefaultIntervalSpeller::getName() const;
    
    /* Deep Copy */
    DefaultIntervalSpellerUPtr DefaultIntervalSpeller::uclone() const
    {
        return DefaultIntervalSpellerUPtr( new DefaultIntervalSpeller{ *this } );
    }
}