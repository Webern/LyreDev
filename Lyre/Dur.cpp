#include "Dur.h"

namespace lyre
{
    Rational convert( const Dur d )
    {
        switch ( d )
        {
            case Dur::Longa:
                return Rational{ 16, 1 };
                break;
            case Dur::Breve:
                return Rational{ 8, 1 };
                break;
            case Dur::Whole:
                return Rational{ 4, 1 };
                break;
            case Dur::Half:
                return Rational{ 2, 1 };
                break;
            case Dur::Quarter:
                return Rational{ 1, 1 };
                break;
            case Dur::Eighth:
                return Rational{ 1, 2 };
                break;
            case Dur::Sixteenth:
                return Rational{ 1, 4 };
                break;
            case Dur::ThirtySecond:
                return Rational{ 1, 8 };
                break;
            case Dur::SixtyFourth:
                return Rational{ 1, 16 };
                break;
            case Dur::OneTwentyEighth:
                return Rational{ 1, 32 };
                break;
            case Dur::TwoFiftySixth:
                return Rational{ 1, 64 };
                break;
            default:
                break;
        }
        return Rational{ 1, 1 };
    }
    Dur convert( const Rational& r )
    {
        if ( r == Rational{ 16, 1 } )
        {
            return Dur::Longa;
        }
        else if ( r == Rational{ 8, 1 } )
        {
            return Dur::Breve;
        }
        else if ( r == Rational{ 4, 1 } )
        {
            return Dur::Whole;
        }
        else if ( r == Rational{ 2, 1 } )
        {
            return Dur::Half;
        }
        else if ( r == Rational{ 1, 1 } )
        {
            return Dur::Quarter;
        }
        else if ( r == Rational{ 1, 2 } )
        {
            return Dur::Eighth;
        }
        else if ( r == Rational{ 1, 4 } )
        {
            return Dur::Sixteenth;
        }
        else if ( r == Rational{ 1, 8 } )
        {
            return Dur::ThirtySecond;
        }
        else if ( r == Rational{ 1, 16 } )
        {
            return Dur::SixtyFourth;
        }
        else if ( r == Rational{ 1, 32 } )
        {
            return Dur::OneTwentyEighth;
        }
        else if ( r == Rational{ 1, 64 } )
        {
            return Dur::TwoFiftySixth;
        }
        else
        {
            throw std::runtime_error( "rational could not be converted to a dur type" );
        }
        return Dur::Quarter;
    }
    Dur parse( const String& s )
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
            return Dur::Longa;
        }
        else if ( s == "Breve" )
        {
            return Dur::Breve;
        }
        else if ( s == "Whole" )
        {
            return Dur::Whole;
        }
        else if ( s == "Half" )
        {
            return Dur::Half;
        }
        else if ( s == "Quarter" )
        {
            return Dur::Quarter;
        }
        else if ( s == "Eighth" )
        {
            return Dur::Eighth;
        }
        else if ( s == "Sixteenth" )
        {
            return Dur::Sixteenth;
        }
        else if ( s == "ThirtySecond" )
        {
            return Dur::ThirtySecond;
        }
        else if ( s == "SixtyFourth" )
        {
            return Dur::SixtyFourth;
        }
        else if ( s == "OneTwentyEighth" )
        {
            return Dur::OneTwentyEighth;
        }
        else if ( s == "TwoFiftySixth" )
        {
            return Dur::TwoFiftySixth;
        }
        throw std::runtime_error( "string could not be parsed to a dur type" );
        return Dur::Quarter;
    }
    String toString( const Dur d )
    {
        switch ( d )
        {
            case Dur::Longa:
                return "Longa";
                break;
            case Dur::Breve:
                return "Breve";
                break;
            case Dur::Whole:
                return "Whole";
                break;
            case Dur::Half:
                return "Half";
                break;
            case Dur::Quarter:
                return "Quarter";
                break;
            case Dur::Eighth:
                return "Eighth";
                break;
            case Dur::Sixteenth:
                return "Sixteenth";
                break;
            case Dur::ThirtySecond:
                return "ThirtySecond";
                break;
            case Dur::SixtyFourth:
                return "SixtyFourth";
                break;
            case Dur::OneTwentyEighth:
                return "OneTwentyEighth";
                break;
            case Dur::TwoFiftySixth:
                return "TwoFiftySixth";
                break;
            default:
                break;
        }
        return "error";
    }
    std::ostream& operator<<( std::ostream& os, const Dur dur )
    {
        os << toString( dur );
        return os;
    }
}