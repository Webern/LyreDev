//PRIVATE
#pragma once
#include "Lyre/IPitchName.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(PitchName)
        
        class PitchName : public IPitchName
        {
        public:
            virtual ~PitchName();
            PitchName();
            explicit PitchName( const Integer step, const Integer alter );
            explicit PitchName( const String& str );
            PitchName( const PitchName& other );
            PitchName( PitchName&& other ) noexcept;
            PitchName& operator=( const PitchName& other );
            PitchName& operator=( PitchName&& other ) noexcept;
            
            /* return a deep copy of "this" */
            virtual IPitchNameUP clone() const;
            
            /* deep copy to "output", note
             the use of static_cast, be careful
             template <typename T>
             // void copyTo( std::unique_ptr<T>& output ) const */
            
            /* return the Pitch Class value, e.g. C = 0,
             C# = 1, Db = 1, D = 2, D# = 3, Eb = 3 ...*/
            virtual Integer getValue() const;
            
            /* parse a string, set value from string, return true if
             successful, return false if string was un-parseable */
            virtual bool parse( const String& str );
            
            /* stream the PitchName's string representation to an ostream
             object. this will be called by toString and operator<< */
            virtual std::ostream& toStream( std::ostream& os ) const;
            
            /* return the PitchName as a string, this has a definition
             which calls toStream.
             virtual String toString() const; */
            
            /* compares the return values of getValue()
             virtual bool isLessThan( const PitchName& other ) const;
             virtual bool isGreaterThan( const PitchName& other ) const;
             virtual bool isEqualTo( const PitchName& other ) const; */
            
            /* returns true if the two objects are identical in value,
             e.g. Ab is not identical to G# even though isEqualTo
             returns true */
            virtual bool isIdenticalTo( const IPitchName& other ) const;
            
            /* Step Functions */
            
            /* return the Step as an integer */
            virtual Integer getStepValue() const;
            
            /* set the value from an int */
            virtual void setStepValue( const Integer val );
            
            /* get the min/max allowable Step values */
            virtual Integer getMinStepValue() const;
            virtual Integer getMaxStepValue() const;
            
            /* increments/decrements the Step value,
             should wrap around to min/max */
            virtual void incrementStep();
            virtual void decrementStep();
            
            /* Alter Functions */
            
            /* return the Alter as an integer */
            virtual Integer getAlterValue() const;
            
            /* set the value from an int */
            virtual void setAlterValue( const Integer val );
            
            /* get the min/max allowable Alter values */
            virtual Integer getMinAlterValue() const;
            virtual Integer getMaxAlterValue() const;
            
            /* increments/decrements, should wraps around to min/max */
            virtual void incrementAlter();
            virtual void decrementAlter();
        private:
            class PitchNameImpl;
            using PitchNameImplUP = std::unique_ptr<PitchNameImpl>;
            PitchNameImplUP myImpl;
            static void swap( PitchName& left, PitchName& right ) noexcept;
        };
    }
}
