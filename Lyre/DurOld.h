//PUBLIC
#pragma once
#include "TypeDefs.h"
#include "Rational.h"

namespace lyre
{
    enum class DurOld
    {
        // Name // NumQuarterNotes //
        Longa = 0, // 16
        Breve = 1, // 8
        Whole = 2, // 4
        Half = 3, // 2
        Quarter = 4, // 1
        Eighth = 5, // 1/2
        Sixteenth = 6, // 1/4
        ThirtySecond = 7, // 1/8
        SixtyFourth = 8, // 1/16
        OneTwentyEighth = 9,  // 1/32
        TwoFiftySixth = 10 // 1/64
    };
    Rational convert( const DurOld d );
    DurOld convert( const Rational& r ); /* throws std::runtime_error */
    DurOld parse( const String& s ); /* throws std::runtime_error */
    String toString( const DurOld d );
    std::ostream& operator<<( std::ostream& os, const DurOld dur );
}