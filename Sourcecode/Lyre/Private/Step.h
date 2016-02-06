//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IStep.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    namespace Private
    {
        enum class StepValue
        {
            C = 0,
            D = 1,
            E = 2,
            F = 3,
            G = 4,
            A = 5,
            B = 7
        };
        
        FORWARD_DECLARE(Step)
        
        class Step : public IStep
        {
        public:
            virtual ~Step();
            Step();
            explicit Step( const Integer value );
            explicit Step( const StepValue value );
            explicit Step( const String& value );
            Step( const Step& other );
            Step( Step&& other ) noexcept;
            Step& operator=( const Step& other );
            Step& operator=( Step&& other ) noexcept;
            
            /* return a deep copy of "this" */
            virtual IStepUP clone() const;
            
            /* return the Step as an integer */
            virtual Integer getValue() const;
            virtual StepValue getStepValue() const;
            
            /* set the value from an int */
            virtual void setValue( const Integer value );
            virtual void setValue( const StepValue value );
            
            /* get the min/max allowable Step values */
            virtual Integer getMin() const;
            virtual Integer getMax() const;
            
            /* parse a string, set value from string, return true if
             successful, return false if string was un-parseable */
            virtual bool parse( const String& str );
            
            /* stream the Step name's string representation to an ostream
             object. this will be called by toString and operator<< */
            virtual std::ostream& toStream( std::ostream& os ) const;
            
            /* return the Step as a string, this has a definition
             which calls toStream. */
            /* virtual String toString() const; */
            
            /* compares the return values of getValue()
             virtual bool isLessThan( const Step& other ) const;
             virtual bool isGreaterThan( const Step& other ) const;
             virtual bool isEqualTo( const Step& other ) const;  */
            
            /* returns true if the two objects are identical in value,
             e.g. Ab is not identical to G# even though isEqualTo
             returns true */
            virtual bool isIdenticalTo( const IStep& other ) const;
            
            /* increments/decrements, should wraps around to min/max */
            virtual void increment();
            virtual void decrement();
            
            /* return pitch class equivalent
             for the step: C = 0, D = 2, E = 4, F = 5... */
            Integer getPitchClassValue() const;
            
        private:
            class StepImpl;
            using StepImplUP = std::unique_ptr<StepImpl>;
            StepImplUP myImpl;
            static void swap( Step& left, Step& right ) noexcept;
        };
        
        /* this calls toStream... syntactic sugar
         std::ostream& operator<<( std::ostream& os, const IStep& StepName ); */
    }
}
