//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include <memory>

namespace Lyre
{
    class IPitchName;
    using IPitchNameSP = std::shared_ptr<IPitchName>;
    using IPitchNameUP = std::unique_ptr<IPitchName>;
    
    class IPitchName
    {
    public:
        virtual ~IPitchName() = default;
        
        /* return a deep copy of "this" */
        virtual IPitchNameUP clone() const = 0;
        
        /* deep copy to "output", note
         the use of static_cast, be careful */
        template <typename T>
        void copyTo( std::unique_ptr<T>& output ) const
        {
            output = std::move( std::unique_ptr<T>{ new T{ *(static_cast<T*>( clone().get() )) } } );
        }
        
        /* return the Pitch Class value, e.g. C = 0,
         C# = 1, Db = 1, D = 2, D# = 3, Eb = 3 ...*/
        virtual Integer getValue() const = 0;
        
        /* parse a string, set value from string, return true if
         successful, return false if string was un-parseable */
        virtual bool parse( const String& str ) = 0;
        
        /* stream the PitchName's string representation to an ostream
         object. this will be called by toString and operator<< */
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        /* return the PitchName as a string, this has a definition
         which calls toStream. */
        virtual String toString() const;
        
        /* compares the return values of getValue() */
        virtual bool isLessThan( const IPitchName& other ) const;
        virtual bool isGreaterThan( const IPitchName& other ) const;
        virtual bool isEqualTo( const IPitchName& other ) const;
        
        /* Step Functions */
        
        /* return the Step as an integer */
        virtual Integer getStepValue() const = 0;
        
        /* set the value from an int */
        virtual void setStepValue( const Integer val ) = 0;
        
        /* get the min/max allowable Step values */
        virtual Integer getMinStepValue() const = 0;
        virtual Integer getMaxStepValue() const = 0;
        
        /* increments/decrements the Step value,
         should wrap around to min/max */
        virtual void incrementStep() = 0;
        virtual void decrementStep() = 0;
        
        /* Alter Functions */
        
        /* return the Alter as an integer */
        virtual Integer getAlterValue() const = 0;
        
        /* set the value from an int */
        virtual void setAlterValue( const Integer val ) = 0;
        
        /* get the min/max allowable Alter values */
        virtual Integer getMinAlterValue() const = 0;
        virtual Integer getMaxAlterValue() const = 0;
        
        /* returns true if the two objects are identical in value,
         e.g. Ab is not identical to G# even though isEqualTo
         returns true */
        virtual bool isIdenticalTo( const IPitchName& other ) const = 0;
        
        /* increments/decrements, should wraps around to min/max */
        virtual void incrementAlter() = 0;
        virtual void decrementAlter() = 0;
        
    };
    
    /* this calls toStream... syntactic sugar */
    std::ostream& operator<<( std::ostream& os, const IPitchName& object );
}