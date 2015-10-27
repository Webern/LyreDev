#include "DurOld.h"

namespace lyre
{
    Rational convert( const DurOld d )
    {
        switch ( d )
        {
            case DurOld::Longa:
                return Rational{ 16, 1 };
                break;
            case DurOld::Breve:
                return Rational{ 8, 1 };
                break;
            case DurOld::Whole:
                return Rational{ 4, 1 };
                break;
            case DurOld::Half:
                return Rational{ 2, 1 };
                break;
            case DurOld::Quarter:
                return Rational{ 1, 1 };
                break;
            case DurOld::Eighth:
                return Rational{ 1, 2 };
                break;
            case DurOld::Sixteenth:
                return Rational{ 1, 4 };
                break;
            case DurOld::ThirtySecond:
                return Rational{ 1, 8 };
                break;
            case DurOld::SixtyFourth:
                return Rational{ 1, 16 };
                break;
            case DurOld::OneTwentyEighth:
                return Rational{ 1, 32 };
                break;
            case DurOld::TwoFiftySixth:
                return Rational{ 1, 64 };
                break;
            default:
                break;
        }
        return Rational{ 1, 1 };
    }
    DurOld convert( const Rational& r )
    {
        if ( r == Rational{ 16, 1 } )
        {
            return DurOld::Longa;
        }
        else if ( r == Rational{ 8, 1 } )
        {
            return DurOld::Breve;
        }
        else if ( r == Rational{ 4, 1 } )
        {
            return DurOld::Whole;
        }
        else if ( r == Rational{ 2, 1 } )
        {
            return DurOld::Half;
        }
        else if ( r == Rational{ 1, 1 } )
        {
            return DurOld::Quarter;
        }
        else if ( r == Rational{ 1, 2 } )
        {
            return DurOld::Eighth;
        }
        else if ( r == Rational{ 1, 4 } )
        {
            return DurOld::Sixteenth;
        }
        else if ( r == Rational{ 1, 8 } )
        {
            return DurOld::ThirtySecond;
        }
        else if ( r == Rational{ 1, 16 } )
        {
            return DurOld::SixtyFourth;
        }
        else if ( r == Rational{ 1, 32 } )
        {
            return DurOld::OneTwentyEighth;
        }
        else if ( r == Rational{ 1, 64 } )
        {
            return DurOld::TwoFiftySixth;
        }
        else
        {
            throw std::runtime_error( "rational could not be converted to a dur type" );
        }
        return DurOld::Quarter;
    }
    DurOld parse( const String& s )
    {
        /*
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
         */
        if ( s == "Longa" )
        {
            return DurOld::Longa;
        }
        else if ( s == "Breve" )
        {
            return DurOld::Breve;
        }
        else if ( s == "Whole" )
        {
            return DurOld::Whole;
        }
        else if ( s == "Half" )
        {
            return DurOld::Half;
        }
        else if ( s == "Quarter" )
        {
            return DurOld::Quarter;
        }
        else if ( s == "Eighth" )
        {
            return DurOld::Eighth;
        }
        else if ( s == "Sixteenth" )
        {
            return DurOld::Sixteenth;
        }
        else if ( s == "ThirtySecond" )
        {
            return DurOld::ThirtySecond;
        }
        else if ( s == "SixtyFourth" )
        {
            return DurOld::SixtyFourth;
        }
        else if ( s == "OneTwentyEighth" )
        {
            return DurOld::OneTwentyEighth;
        }
        else if ( s == "TwoFiftySixth" )
        {
            return DurOld::TwoFiftySixth;
        }
        throw std::runtime_error( "string could not be parsed to a dur type" );
        return DurOld::Quarter;
    }
    String toString( const DurOld d )
    {
        switch ( d )
        {
            case DurOld::Longa:
                return "Longa";
                break;
            case DurOld::Breve:
                return "Breve";
                break;
            case DurOld::Whole:
                return "Whole";
                break;
            case DurOld::Half:
                return "Half";
                break;
            case DurOld::Quarter:
                return "Quarter";
                break;
            case DurOld::Eighth:
                return "Eighth";
                break;
            case DurOld::Sixteenth:
                return "Sixteenth";
                break;
            case DurOld::ThirtySecond:
                return "ThirtySecond";
                break;
            case DurOld::SixtyFourth:
                return "SixtyFourth";
                break;
            case DurOld::OneTwentyEighth:
                return "OneTwentyEighth";
                break;
            case DurOld::TwoFiftySixth:
                return "TwoFiftySixth";
                break;
            default:
                break;
        }
        return "error";
    }
    std::ostream& operator<<( std::ostream& os, const DurOld dur )
    {
        os << toString( dur );
        return os;
    }
}