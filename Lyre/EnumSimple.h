#pragma once
#include "EnumInterface.h"

namespace lyre
{
    class EnumSimple;
    using EnumSimplePtr = std::shared_ptr<EnumSimple>;
    using EnumSimpleUPtr = std::unique_ptr<EnumSimple>;
    
    class EnumSimple : public EnumInterface
    {
    public:
        EnumSimple( const Integer value, const std::shared_ptr<Strings> strs, const Integer offset = 0 );
        
        /* return a deep copy of "this" */
        virtual EnumPtr clone() const;
        
        /* return the Enum as an integer */
        virtual Integer getValue() const;
        
        /* set the value from an int */
        virtual void setValue( const Integer val );
        
        /* get the min/max allowable Enum values */
        virtual Integer getMin() const;
        virtual Integer getMax() const;
        
        /* parse a string, set value from string, return true if
         successful, return false if string was un-parseable */
        virtual bool parse( const String& str );
        
        /* stream the Enum name's string representation to an ostream
         object. this will be called by toString and operator<< */
        virtual std::ostream& toStream( std::ostream& os ) const;
        
        /* return the Enum as a string, this has a definition
         which calls toStream.
        virtual String toString() const; */
        
        /* compares the return values of getValue()
        virtual bool lessThan( const EnumInterface& other ) const;
        virtual bool greaterThan( const EnumInterface& other ) const;
        virtual bool equals( const EnumInterface& other ) const; */
        
        /* increments/decrements, should wraps around to min/max */
        virtual void increment();
        virtual void decrement();
        
    private:
        std::shared_ptr<Strings> myStrings;
        Integer myOffset;
        Integer myValue;
    };
}