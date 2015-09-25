#pragma once
#include "IStep.h"
#include "IAlter.h"
#include "TypeDefs.h"
#include <memory>

namespace lyre
{
    class INoteName;
    using INoteNamePtr = std::shared_ptr<INoteName>;
    using INoteNameUPtr = std::unique_ptr<INoteName>;
    
    class INoteName
    {
    public:
        virtual ~INoteName() = default;
        
        /* return a deep copy of "this" */
        virtual INoteNameUPtr clone() const = 0;
        
        /* deep copy to "output", note
         the use of static_cast, be careful */
        template <typename T>
        void copyTo( std::unique_ptr<T>& output ) const
        {
            output = std::move( std::unique_ptr<T>{ new T{ *(static_cast<T*>( clone().get() )) } } );
        }
        
        virtual const std::unique_ptr<const IStep> getStep() const = 0;
        virtual const std::unique_ptr<const IAlter> getAlter() const = 0;
        virtual void setStep( IStepUPtr&& value ) = 0;
        virtual void setAlter( IAlterUPtr&& value ) = 0;
        virtual void setStep( const IStepUPtr& value ) = 0;
        virtual void setAlter( const IAlterUPtr& value ) = 0;
        
        /* returns the combined value of getStep()->getValue()
         and getAlter()->getValue() */
        virtual Integer getValue() const = 0;
        
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
    };
    
    /* this calls toStream... syntactic sugar */
    std::ostream& operator<<( std::ostream& os, const IAlter& object );
}