//PRIVATE
#pragma once
#include "Lyre/IPitch.h"
#include "Lyre/ForwardDec.h"
#include "Lyre/Private/PitchName.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(Pitch)
        
        class Pitch : public IPitch
        {
        public:
            virtual ~Pitch();
            Pitch();
            
            explicit Pitch(
                const Integer step,
                const Integer alter,
                const Integer octave );
            
            explicit Pitch( const String& str );
            
            /* return a deep copy of "this" */
            virtual IPitchUP clone() const;
            
            /* return the Pitch Class value, e.g. C = 0,
             C# = 1, Db = 1, D = 2, D# = 3, Eb = 3 ...*/
            virtual Integer getValue() const;
            
            /* set the value as an Integer,
             for example, C4 = 60, C#4 = 61, etc. */
            virtual void setValue( const Integer pitchValue );
            
            /* parse a string, set value from string, return true if
             successful, return false if string was un-parseable */
            virtual bool parse( const String& str );
            
            /* stream the Pitch's string representation to an ostream
             object. this will be called by toString and operator<< */
            virtual std::ostream& toStream( std::ostream& os ) const;
            
            /* return the Pitch as a string, this has a definition
             which calls toStream.
             virtual String toString() const; */
            
            /* compares the return values of getValue()
             virtual bool isLessThan( const Pitch& other ) const;
             virtual bool isGreaterThan( const Pitch& other ) const;
             virtual bool isEqualTo( const Pitch& other ) const; */
            
            /* returns true if the two objects are identical in value,
             e.g. Ab4 is not identical to G#3 even though isEqualTo
             returns true */
            virtual bool isIdenticalTo( const IPitch& other ) const;
            
            /* Step Functions */
            
            /* return the Step as an integer */
            virtual Integer getStepValue() const;
            
            /* set the value from an int */
            virtual void setStepValue( const Integer val );
            
            /* increments/decrements the Step value,
             should wrap around to min/max */
            virtual void incrementStep();
            virtual void decrementStep();
            
            /* Alter Functions */
            
            /* return the Alter as an integer */
            virtual Integer getAlterValue() const;
            
            /* set the value from an int */
            virtual void setAlterValue( const Integer val );
            
            /* increments/decrements, should wraps around to min/max */
            virtual void incrementAlter();
            virtual void decrementAlter();
            
            /* Octave Functions */
            
            virtual Integer getOctaveValue() const;
            virtual void setOctaveValue( const Integer val );
            virtual void incrementOctave();
            virtual void decrementOctave();
            
        private:
            Private::PitchName myPitchName;
            Integer myOctave;
            void seekPitch( const Integer pitchValue );
            void collapseOctaves();
            void collapseSteps();
            void respellToEnharmonicDefault();
        };
    }
}
