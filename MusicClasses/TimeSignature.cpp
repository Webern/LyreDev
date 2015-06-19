#include "TimeSignature.h"

namespace music
{
    void TimeSignature::setNumerator( const Int value )
    {
        if ( value < 1 )
        {
            myNumerator = 1;
        }
        else
        {
            myNumerator = value;
        }
    }
    void TimeSignature::setDenominator( const Int value )
    {
        if ( value < 1 )
        {
            myDenominator = 1;
        }
        else
        {
            myDenominator = value;
        }
    }
}