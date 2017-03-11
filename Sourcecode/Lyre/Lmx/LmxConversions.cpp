#include "Lyre/Lmx/LmxConversions.h"
#include "Lyre/IDurBaseFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Lmx
    {
        mx::t::NoteTypeValue convertDur( const Rational& durBaseValue )
        {
            if( durBaseValue == VAL_LONGA )
            {
                return mx::t::NoteTypeValue::long_;
            }
            else if ( durBaseValue == VAL_BREVE )
            {
                return mx::t::NoteTypeValue::breve;
            }
            else if ( durBaseValue == VAL_WHOLE )
            {
                return mx::t::NoteTypeValue::whole;
            }
            else if ( durBaseValue == VAL_HALF )
            {
                return mx::t::NoteTypeValue::half;
            }
            else if ( durBaseValue == VAL_QUARTER )
            {
                return mx::t::NoteTypeValue::quarter;
            }
            else if ( durBaseValue == VAL_EIGHTH )
            {
                return mx::t::NoteTypeValue::eighth;
            }
            else if ( durBaseValue == VAL_16TH )
            {
                return mx::t::NoteTypeValue::sixteenth;
            }
            else if ( durBaseValue == VAL_32ND )
            {
                return mx::t::NoteTypeValue::thirtySecond;
            }
            else if ( durBaseValue == VAL_64TH )
            {
                return mx::t::NoteTypeValue::sixtyFourth;
            }
            else if ( durBaseValue == VAL_128TH )
            {
                return mx::t::NoteTypeValue::oneHundredTwentyEighth;
            }
            else if ( durBaseValue == VAL_256TH )
            {
                return mx::t::NoteTypeValue::twoHundredFifthySixth;
            }
            THROW( "invalid Rational durBaseValue" );
        }
        
        
        mx::t::NoteTypeValue convertDur( const IDurBaseUP& durBaseValue )
        {
            return convertDur( durBaseValue->getValue() );
        }
        
        
        IDurBaseUP convertDur( const mx::t::NoteTypeValue& mxDurVal )
        {
            auto f = createDurBaseFactory();
            switch ( mxDurVal )
            {
                case mx::t::NoteTypeValue::long_:
                    return f->createDur( STR_LONGA );
                    break;
                case mx::t::NoteTypeValue::breve:
                    return f->createDur( STR_BREVE );
                    break;
                case mx::t::NoteTypeValue::whole:
                    return f->createDur( STR_WHOLE );
                    break;
                case mx::t::NoteTypeValue::half:
                    return f->createDur( STR_HALF );
                    break;
                case mx::t::NoteTypeValue::quarter:
                    return f->createDur( STR_QUARTER );
                    break;
                case mx::t::NoteTypeValue::eighth:
                    return f->createDur( STR_EIGHTH );
                    break;
                case mx::t::NoteTypeValue::sixteenth:
                    return f->createDur( STR_16TH );
                    break;
                case mx::t::NoteTypeValue::thirtySecond:
                    return f->createDur( STR_32ND );
                    break;
                case mx::t::NoteTypeValue::sixtyFourth:
                    return f->createDur( STR_64TH );
                    break;
                case mx::t::NoteTypeValue::oneHundredTwentyEighth:
                    return f->createDur( STR_128TH );
                    break;
                case mx::t::NoteTypeValue::twoHundredFifthySixth:
                    return f->createDur( STR_256TH );
                    break;
                default:
                    THROW( "unsupported mx::t::NoteTypeValue" )
                    break;
            }
            return f->createDur( STR_LONGA );
        }
        
        
    }
}
