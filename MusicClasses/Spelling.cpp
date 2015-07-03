#include "Spelling.h"

namespace music
{
    Spelling::Spelling( const Step& step, const Int alter )
    :myStep( step )
    ,myAlter( alter )
    {}
    Step Spelling::getStep() const
    {
        return myStep;
    }
    Int Spelling::getAlter() const
    {
        return myAlter;
    }
}