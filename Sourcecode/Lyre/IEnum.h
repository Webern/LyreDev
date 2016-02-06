//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include <memory>

namespace Lyre
{
    class IEnum;
    using IEnumSP = std::shared_ptr<IEnum>;
    using IEnumUP = std::unique_ptr<IEnum>;
    
    class PUBLIC IEnum
    {
    public:
        virtual ~IEnum() = default;
        
        /* return a deep copy of "this" */
        virtual IEnumUP clone() const = 0;
        
        /* return the Enum as an integer */
        virtual Integer getValue() const = 0;
        
        /* set the value from an int */
        virtual void setValue( const Integer val ) = 0;
        
        /* get the min/max allowable Enum values */
        virtual Integer getMin() const = 0;
        virtual Integer getMax() const = 0;
        
        /* parse a string, set value from string, return true if
         successful, return false if string was un-parseable */
        virtual bool parse( const String& str ) = 0;
        
        /* stream the Enum name's string representation to an ostream
         object. this will be called by toString and operator<< */
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        /* return the Enum as a string, this has a definition
         which calls toStream. */
        virtual String toString() const;
        
        /* compares the return values of getValue() */
        virtual bool isLessThan( const IEnum& other ) const;
        virtual bool isGreaterThan( const IEnum& other ) const;
        virtual bool isEqualTo( const IEnum& other ) const;
        
        /* increments/decrements, should wraps around to min/max */
        virtual void increment() = 0;
        virtual void decrement() = 0;
    };
    
    /* this calls toStream... syntactic sugar */
    PUBLIC std::ostream& operator<<( std::ostream& os, const IEnum& EnumName );
}
