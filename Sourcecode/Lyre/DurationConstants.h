//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/Rational.h"

namespace Lyre
{
    
    const Rational VAL_LONGA  { 16, 1 };
    const Rational VAL_BREVE  { 8,  1 };
    const Rational VAL_WHOLE  { 4,  1 };
    const Rational VAL_HALF   { 2,  1 };
    const Rational VAL_QUARTER{ 1,  1 };
    const Rational VAL_EIGHTH { 1,  2 };
    const Rational VAL_16TH   { 1,  4 };
    const Rational VAL_32ND   { 1,  8 };
    const Rational VAL_64TH   { 1, 16 };
    const Rational VAL_128TH  { 1, 32 };
    const Rational VAL_256TH  { 1, 64 };

    const String STR_LONGA  { "Longa"   };
    const String STR_BREVE  { "Breve"   };
    const String STR_WHOLE  { "Whole"   };
    const String STR_HALF   { "Half"    };
    const String STR_QUARTER{ "Quarter" };
    const String STR_EIGHTH { "Eighth"  };
    const String STR_16TH   { "16th"    };
    const String STR_32ND   { "32nd"    };
    const String STR_64TH   { "64th"    };
    const String STR_128TH  { "128th"   };
    const String STR_256TH  { "256th"   };
    
    const int DUR_MAX_BEAMS_LONGA  { 0 };
    const int DUR_MAX_BEAMS_BREVE  { 0 };
    const int DUR_MAX_BEAMS_WHOLE  { 0 };
    const int DUR_MAX_BEAMS_HALF   { 0 };
    const int DUR_MAX_BEAMS_QUARTER{ 0 };
    const int DUR_MAX_BEAMS_EIGHTH { 1 };
    const int DUR_MAX_BEAMS_16TH   { 2 };
    const int DUR_MAX_BEAMS_32ND   { 3 };
    const int DUR_MAX_BEAMS_64TH   { 4 };
    const int DUR_MAX_BEAMS_128TH  { 5 };
    const int DUR_MAX_BEAMS_256TH  { 6 };
}
