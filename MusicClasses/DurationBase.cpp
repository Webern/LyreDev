#include "DurationBase.h"

namespace music
{
    DurationBase::DurationBase()
    :myValue( DurationName::Quarter )
    {}
    
    DurationBase::DurationBase( const DurationName& value )
    :myValue( value )
    {}
    DurationName DurationBase::getDurationName() const
    {
        return myValue;
    }
    void DurationBase::setDurationName( const DurationName& value )
    {
        myValue = value;
    }
    Rational DurationBase::getRational() const
    {
        switch ( myValue )
        {
            case DurationName::Longa:
            {
                return Rational{ 16, 1 };
            }
                break;
            case DurationName::Breve:
            {
                return Rational{ 8, 1 };
            }
                break;
            case DurationName::Whole:
            {
                return Rational{ 4, 1 };
            }
                break;
            case DurationName::Half:
            {
                return Rational{ 2, 1 };
            }
                break;
            case DurationName::Quarter:
            {
                return Rational{ 1, 1 };
            }
                break;
            case DurationName::Eighth:
            {
                return Rational{ 1, 2 };
            }
                break;
            case DurationName::Sixteenth:
            {
                return Rational{ 1, 4 };
            }
                break;
            case DurationName::ThirtySecond:
            {
                return Rational{ 1, 8 };
            }
                break;
            case DurationName::SixtyFourth:
            {
                return Rational{ 1, 16 };
            }
                break;
            case DurationName::OneTwentyEighth:
            {
                return Rational{ 1, 32 };
            }
                break;
            default:
                break;
        }
    }
}