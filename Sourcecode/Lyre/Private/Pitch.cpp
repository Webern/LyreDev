#include "Lyre/Private/Pitch.h"
#include "Lyre/Private/PitchName.h"
#include <string>
#include <sstream>

namespace Lyre
{
    namespace Private
    {
        class Pitch::PitchImpl
        {
        public:
            ~PitchImpl(){}
            
            PitchImpl()
            :myPitchName{ 0, 0 }
            ,myOctave{ 0 }
            {}
            
            PitchImpl( const Integer step, const Integer alter, const Integer octave )
            :myPitchName{ step, alter }
            ,myOctave{ octave }
            {}
            
            PitchName myPitchName;
            Integer myOctave;
            static const Integer ourMiddleCValue;
            static const Pitch ourMiddleCPitch;
        };
        
        const Integer Pitch::PitchImpl::ourMiddleCValue = 60;
        const Pitch Pitch::PitchImpl::ourMiddleCPitch{ 0, 0, 4 };
        
        Pitch::~Pitch(){}
        
        Pitch::Pitch()
        :myImpl{ new PitchImpl{} }
        {}
        
        Pitch::Pitch( const Integer step, const Integer alter, const Integer octave )
        :myImpl( new PitchImpl{ step, alter, octave } )
        {}
        
        Pitch::Pitch( const String& str )
        :myImpl{ new PitchImpl{} }
        {
            parse( str );
        }
        
        Pitch::Pitch( const Pitch& other )
        :myImpl( new PitchImpl{ *other.myImpl } )
        {}
        
        Pitch::Pitch( Pitch&& other ) noexcept
        :myImpl( std::move( other.myImpl ) )
        {}
        
        Pitch& Pitch::operator=( const Pitch& other )
        {
            auto temp = other;
            Pitch::swap( temp, *this );
            return *this;
        }
        
        Pitch& Pitch::operator=( Pitch&& other ) noexcept
        {
            Pitch::swap( other, *this );
            return *this;
        }
        
        
        IPitchUP Pitch::clone() const
        {
            IPitchUP value{ new Pitch{ *this } };
            return std::move( value );
        }
        
        Integer Pitch::getValue() const
        {
            Integer octave = myImpl->myOctave;
            Integer alter = myImpl->myPitchName.getAlterValue();
            bool alterNegative = ( alter < 0 );
            if ( alterNegative )
            {
                alter *= -1;
            }
            Integer octaveOffset = 0;
            PitchName tempPitchName{ myImpl->myPitchName.getStepValue(), 0 };
            for ( Integer i = 0; i < alter; ++i )
            {
                if ( alterNegative )
                {
                    tempPitchName.decrementAlter();
                    if ( tempPitchName.getValue() == 11 )
                    {
                        ++octaveOffset;
                    }
                }
                else
                {
                    tempPitchName.incrementAlter();
                    if ( tempPitchName.getValue() == 0 )
                    {
                        ++octaveOffset;
                    }
                }
            }
            if ( alterNegative )
            {
                octave -= octaveOffset;
            }
            else
            {
                octave += octaveOffset;
            }
            Integer answer = myImpl->myPitchName.getValue();
            answer += ( 12 * octave );
            answer += ( myImpl->ourMiddleCValue ) - ( 12 * 4 );
            return answer;
        }
        
        void Pitch::setValue( const Integer pitchValue )
        {
            if ( pitchValue != getValue() )
            {
                //TODO Test Correctness of Algorithm
                //TODO Better Algorithm
                Integer increment = 1;
                if ( pitchValue < getValue() )
                {
                    increment = -1;
                }
                for ( Integer i = getValue(); i != pitchValue; i += increment )
                {
                    if ( increment == 1 )
                    {
                        incrementAlter();
                    }
                    else if ( increment == -1 )
                    {
                        decrementAlter();
                    }
                }
                while ( getAlterValue() >= 12 )
                {
                    incrementOctave();
                    setAlterValue( getAlterValue() - 12 );
                }
                while ( getAlterValue() > 1 )
                {
                    auto curStep = getStepValue();
                    if ( curStep != 2 && curStep != 6 )
                    {
                        decrementAlter();
                    }
                    decrementAlter();
                    if ( curStep == 6 )
                    {
                        incrementOctave();
                    }
                    if ( curStep == 6 )
                    {
                        curStep = 0;
                    }
                    else
                    {
                        ++curStep;
                    }
                    setStepValue( curStep );
                }
                while ( getAlterValue() <= -12 )
                {
                    decrementOctave();
                    setAlterValue( getAlterValue() + 12 );
                }
                while ( getAlterValue() < -1 )
                {
                    auto curStep = getStepValue();
                    if ( curStep != 0 && curStep != 3 )
                    {
                        incrementAlter();
                    }
                    incrementAlter();
                    if ( curStep == 0 )
                    {
                        decrementOctave();
                    }
                    if ( curStep == 0 )
                    {
                        curStep = 6;
                    }
                    else
                    {
                        --curStep;
                    }
                    setStepValue( curStep );
                }
            }
            int step = getStepValue();
            int alter = getAlterValue();
            switch ( step )
            {
                case 0:
                {
                    if ( alter == -1 ) // change Cb to B
                    {
                        decrementOctave();
                        setStepValue( 6 );
                        setAlterValue( 0 );
                    }
                }
                    break;
                case 1:
                {
                    if ( alter == -1 ) // change Db to C#
                    {
                        setStepValue( 0 );
                        setAlterValue( 1 );
                    }
                    if ( alter == 1 ) // change D# to Eb
                    {
                        setStepValue( 2 );
                        setAlterValue( -1 );
                    }
                }
                    break;
                case 2:
                {
                    if ( alter == 1 ) // change E# to F
                    {
                        setStepValue( 3 );
                        setAlterValue( 0 );
                    }
                }
                    break;
                case 3:
                {
                    if ( alter == -1 ) // change Fb to E
                    {
                        setStepValue( 2 );
                        setAlterValue( 0 );
                    }
                }
                    break;
                case 4:
                {
                    if ( alter == -1 ) // change Gb to F#
                    {
                        setStepValue( 3 );
                        setAlterValue( 1 );
                    }
                    if ( alter == 1 ) // change G# to Ab
                    {
                        setStepValue( 5 );
                        setAlterValue( -1 );
                    }
                }
                    break;
                case 5:
                {
                    if ( alter == 1 ) // change A# to Bb
                    {
                        setStepValue( 6 );
                        setAlterValue( -1 );
                    }
                }
                    break;
                case 6:
                {
                    if ( alter == 1 ) // change B# to C
                    {
                        incrementOctave();
                        setStepValue( 0 );
                        setAlterValue( 0 );
                    }
                }
                    break;
                default:
                    break;
            }
        }
        
        bool Pitch::parse( const String& str )
        {
            auto octpos = str.find_first_of( "-0123456789" );
            if ( octpos == String::npos )
            {
                return false;
            }
            bool negative = false;
            if ( str.substr( octpos, 1 ) == "-" )
            {
                negative = true;
            }
            auto octstr = str.substr( octpos );
            if ( negative && octstr.length() == 1 )
            {
                return false;
            }
            if ( negative )
            {
                octstr = octstr.substr( 1 );
            }
            if ( octstr.length() == 0 )
            {
                return false;
            }
            auto badcharcheck = octstr.find_first_not_of( "0123456789" );
            if ( badcharcheck != String::npos )
            {
                return false;
            }
            if ( octstr.substr( 0, 1 ) == "0" && negative )
            {
                return false;
            }
            if ( ! negative && octstr.substr( 0, 1 ) == "0" && octstr.length() > 1 )
            {
                return false;
            }
            std::stringstream ss{ octstr };
            Integer octave = 0;
            ss >> octave;
            if ( negative )
            {
                octave *= -1;
            }
            String pnstr = str.substr( 0, octpos );
            PitchName pn;
            bool success = pn.parse( pnstr );
            if ( ! success )
            {
                return false;
            }
            myImpl->myPitchName = pn;
            myImpl->myOctave = octave;
            return true;
        }
        
        std::ostream& Pitch::toStream( std::ostream& os ) const
        {
            os << myImpl->myPitchName;
            return os << std::to_string( myImpl->myOctave );
        }
        bool Pitch::isIdenticalTo( const IPitch& other ) const
        {
            if ( getValue() != other.getValue() )
            {
                return false;
            }
            else if ( getStepValue() != other.getStepValue() )
            {
                return false;
            }
            else if ( getAlterValue() != other.getAlterValue() )
            {
                return false;
            }
            else
            {
                if ( typeid(*this) == typeid(other) )
                {
                    return true;
                }
                else if ( toString() == other.toString() )
                {
                    return true;
                }
            }
            return false;
        }
        Integer Pitch::getStepValue() const
        {
            return myImpl->myPitchName.getStepValue();
        }
        
        void Pitch::setStepValue( const Integer val )
        {
            myImpl->myPitchName.setStepValue( val );
        }
        
        void Pitch::incrementStep()
        {
            myImpl->myPitchName.incrementStep();
        }
        
        void Pitch::decrementStep()
        {
            myImpl->myPitchName.decrementStep();
        }
        
        Integer Pitch::getAlterValue() const
        {
            return myImpl->myPitchName.getAlterValue();
        }
        
        void Pitch::setAlterValue( const Integer val )
        {
            myImpl->myPitchName.setAlterValue( val );
        }
        
        void Pitch::incrementAlter()
        {
            myImpl->myPitchName.incrementAlter();
        }
        
        void Pitch::decrementAlter()
        {
            myImpl->myPitchName.decrementAlter();
        }
        
        void Pitch::swap( Pitch& left, Pitch& right ) noexcept
        {
            std::swap( left.myImpl, right.myImpl );
        }
        
        Integer Pitch::getOctaveValue() const
        {
            return myImpl->myOctave;
        }
        
        void Pitch::setOctaveValue( const Integer val )
        {
            myImpl->myOctave = val;
        }
        
        void Pitch::incrementOctave()
        {
            myImpl->myOctave += 1;
        }
        
        void Pitch::decrementOctave()
        {
            myImpl->myOctave -= 1;
        }
    }
}
