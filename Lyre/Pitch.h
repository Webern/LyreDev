#pragma once
#include "IPitch.h"

namespace lyre
{
    class Pitch;
    using PitchPtr = std::shared_ptr<Pitch>;
    using PitchUPtr = std::unique_ptr<Pitch>;
    
    class Pitch : public IPitch
    {
    public:
        virtual ~Pitch();
        Pitch();
        explicit Pitch( const Integer step, const Integer alter, const Integer octave );
        explicit Pitch( const String& str );
        Pitch( const Pitch& other );
        Pitch( Pitch&& other ) noexcept;
        Pitch& operator=( const Pitch& other );
        Pitch& operator=( Pitch&& other ) noexcept;
        
        /* return a deep copy of "this" */
        virtual IPitchUPtr clone() const;
        
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
        
        /* stream the Pitch's string representation to an ostream
         object. this will be called by toString and operator<< */
        virtual std::ostream& toStream( std::ostream& os ) const;
        
        /* return the Pitch as a string, this has a definition
         which calls toStream.
         virtual String toString() const; */
        
        /* compares the return values of getValue()
         virtual bool lessThan( const Pitch& other ) const;
         virtual bool greaterThan( const Pitch& other ) const;
         virtual bool equals( const Pitch& other ) const; */
        
        /* Step Functions */
        
        /* return the Step as an integer */
        virtual Integer getStepValue() const;
        
        /* set the value from an int */
        virtual void setStepValue( const Integer val );
        
        /* increments/decrements the Step value,
         should wrap around to min/max */
        virtual void incrementStep();
        virtual void decrementStep();
        
        /* Alter Functions */
        
        /* return the Alter as an integer */
        virtual Integer getAlterValue() const;
        
        /* set the value from an int */
        virtual void setAlterValue( const Integer val );
        
        /* increments/decrements, should wraps around to min/max */
        virtual void incrementAlter();
        virtual void decrementAlter();
        
        /* Octave Functions */
        
        virtual Integer getOctaveValue() const;
        virtual void setOctaveValue( const Integer val );
        virtual void incrementOctave();
        virtual void decrementOctave();
        
    private:
        class PitchImpl;
        using PitchImplUPtr = std::unique_ptr<PitchImpl>;
        PitchImplUPtr myImpl;
        static void swap( Pitch& left, Pitch& right ) noexcept;
    };
}