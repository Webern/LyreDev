//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IAlter.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(Alter)
        
        class EXPORT_FOR_TESTS Alter : public IAlter
        {
        public:
            virtual ~Alter();
            Alter();
            explicit Alter( const Integer value );
            explicit Alter( const String& value );
            Alter( const Alter& other );
            Alter( Alter&& other ) noexcept;
            Alter& operator=( const Alter& other );
            Alter& operator=( Alter&& other ) noexcept;
            
            /* return a deep copy of "this" */
            virtual IAlterUP clone() const;
            
            /* return the Alter as an integer */
            virtual Integer getValue() const;
            
            /* set the value from an int */
            virtual void setValue( const Integer value );
            
            /* get the min/max allowable Alter values */
            virtual Integer getMin() const;
            virtual Integer getMax() const;
            
            /* parse a string, set value from string, return true if
             successful, return false if string was un-parseable */
            virtual bool parse( const String& str );
            
            /* stream the Alter name's string representation to an ostream
             object. this will be called by toString and operator<<
             Double Flat  => d
             Flat         => b
             Natural      =>
             Sharp        => #
             Double Sharp => x
             */
            virtual std::ostream& toStream( std::ostream& os ) const;
            
            /* return the Alter as a string, this has a definition
             which calls toStream. */
            /* virtual String toString() const; */
            
            /* compares the return values of getValue()
             virtual bool isLessThan( const Alter& other ) const;
             virtual bool isGreaterThan( const Alter& other ) const;
             virtual bool isEqualTo( const Alter& other ) const;  */
            
            /* returns true if the two objects are identical in representation,
             two IAlter objects are identical if getValue() == getValue()
             and toString() == toString() */
            virtual bool isIdenticalTo( const IAlter& other ) const;
            
            /* increments/decrements, should wraps around to min/max */
            virtual void increment();
            virtual void decrement();
            
        private: // MJBTODO Implement without Pimpl
            class AlterImpl;
            using AlterImplUP = std::unique_ptr<AlterImpl>;
            AlterImplUP myImpl;
            static void swap( Alter& left, Alter& right ) noexcept;
        };
        
        /* this calls toStream... syntactic sugar
         PUBLIC std::ostream& operator<<( std::ostream& os, const IAlter& AlterName ); */
    }
}
