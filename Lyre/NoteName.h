#pragma once
#include "INoteName.h"

namespace lyre
{
    class NoteName;
    using NoteNamePtr = std::shared_ptr<NoteName>;
    using NoteNameUPtr = std::unique_ptr<NoteName>;
    
    class NoteName : public INoteName
    {
    public:
        virtual ~NoteName();
        NoteName();
        explicit NoteName( const Integer step, const Integer alter );
        explicit NoteName( const String& str );
        NoteName( const NoteName& other );
        NoteName( NoteName&& other ) noexcept;
        NoteName& operator=( const NoteName& other );
        NoteName& operator=( NoteName&& other ) noexcept;
        
        /* return a deep copy of "this" */
        virtual INoteNameUPtr clone() const;
        
        /* deep copy to "output", note
         the use of static_cast, be careful
        template <typename T>
        void copyTo( std::unique_ptr<T>& output ) const */
        
        /* return the Pitch Class value, e.g. C = 0,
         C# = 1, Db = 1, D = 2, D# = 3, Eb = 3 ...*/
        virtual Integer getValue() const;
        
        /* parse a string, set value from string, return true if
         successful, return false if string was un-parseable */
        virtual bool parse( const String& str );
        
        /* stream the NoteName's string representation to an ostream
         object. this will be called by toString and operator<< */
        virtual std::ostream& toStream( std::ostream& os ) const;
        
        /* return the NoteName as a string, this has a definition
         which calls toStream.
        virtual String toString() const; */
        
        /* compares the return values of getValue()
        virtual bool lessThan( const NoteName& other ) const;
        virtual bool greaterThan( const NoteName& other ) const;
        virtual bool equals( const NoteName& other ) const; */
        
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
        class NoteNameImpl;
        using NoteNameImplUPtr = std::unique_ptr<NoteNameImpl>;
        NoteNameImplUPtr myImpl;
        static void swap( NoteName& left, NoteName& right ) noexcept;
    };
}