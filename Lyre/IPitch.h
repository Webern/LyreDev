#pragma once
#include "TypeDefs.h"
#include <memory>

namespace lyre
{
    class IPitch;
    using IPitchPtr = std::shared_ptr<IPitch>;
    using IPitchUPtr = std::unique_ptr<IPitch>;
    
    class IPitch
    {
    public:
        virtual ~IPitch() = default;
        
        /* return a deep copy of "this" */
        virtual IPitchUPtr clone() const = 0;
        
        /* deep copy to "output", note
         the use of static_cast, be careful */
        template <typename T>
        void copyTo( std::unique_ptr<T>& output ) const
        {
            output = std::move( std::unique_ptr<T>{ new T{ *(static_cast<T*>( clone().get() )) } } );
        }
        
        /* return the value as an Integer,
         for example, C4 = 60, C#4 = 61, etc. */
        virtual Integer getValue() const = 0;
        
        /* parse a string, set value from string, return true if
         successful, return false if string was un-parseable */
        virtual bool parse( const String& str ) = 0;
        
        /* stream the Pitch's string representation to an ostream
         object. this will be called by toString and operator<< 
         e.g. C#5m A-1 Bd-1 etc*/
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        /* calls toStream. */
        virtual String toString() const;
        
        /* compares the return values of getValue() */
        virtual bool lessThan( const IPitch& other ) const;
        virtual bool greaterThan( const IPitch& other ) const;
        virtual bool equals( const IPitch& other ) const;
        
        /* Step Functions */
        
        /* return the Step as an integer */
        virtual Integer getStepValue() const = 0;
        
        /* set the value from an int */
        virtual void setStepValue( const Integer val ) = 0;
        
        /* increments/decrements the Step value,
         should wrap around to min/max */
        virtual void incrementStep() = 0;
        virtual void decrementStep() = 0;
        
        /* Alter Functions */
        
        /* return the Alter as an integer */
        virtual Integer getAlterValue() const = 0;
        
        /* set the value from an int */
        virtual void setAlterValue( const Integer val ) = 0;
        
        /* increments/decrements, should wraps around to min/max */
        virtual void incrementAlter() = 0;
        virtual void decrementAlter() = 0;
        
        /* Octave Functions */
        
        virtual Integer getOctaveValue() const = 0;
        virtual void setOctaveValue() const = 0;
        virtual void incrementOctave() const = 0;
        virtual void decrementOctave() const = 0;
        
    };
    
    /* this calls toStream... syntactic sugar */
    std::ostream& operator<<( std::ostream& os, const IPitch& object );
}