#pragma once
#include "TypeDefs.h"

namespace lyre
{
    class IAlter;
    using IAlterPtr = std::shared_ptr<IAlter>;
    using IAlterUPtr = std::unique_ptr<IAlter>;
    class IAlter
    {
    public:
        virtual ~IAlter() = default;
        
        /* return a deep copy of "this" */
        virtual IAlterPtr clone() const = 0;
        
        /* deep copy to "output", note
         the use of static_pointer_cast,
         be careful */
        template <typename T>
        void copyTo( std::shared_ptr<T>& output ) const
        {
            auto copy = clone();
            output = std::static_pointer_cast<T>( copy );
        }
        
        /* return the Alter as an integer */
        virtual Integer getValue() const = 0;
        
        /* set the value from an int */
        virtual void setValue( const Integer val ) = 0;
        
        /* get the min/max allowable Alter values */
        virtual Integer getMin() const = 0;
        virtual Integer getMax() const = 0;
        
        /* parse a string, set value from string, return true if
         successful, return false if string was un-parseable */
        virtual bool parse( const String& str ) = 0;
        
        /* stream the Alter name's string representation to an ostream
         object. this will be called by toString and operator<< */
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        /* return the Alter as a string, this has a definition
         which calls toStream. */
        virtual String toString() const;
        
        /* compares the return values of getValue() */
        virtual bool lessThan( const IAlter& other ) const;
        virtual bool greaterThan( const IAlter& other ) const;
        virtual bool equals( const IAlter& other ) const;
        
        /* increments/decrements, should wraps around to min/max */
        virtual void increment() = 0;
        virtual void decrement() = 0;
    };
    
    /* this calls toStream... syntactic sugar */
    std::ostream& operator<<( std::ostream& os, const IAlter& AlterName );
}