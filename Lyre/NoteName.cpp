#include "NoteName.h"
#include "Step.h"
#include "Alter.h"
#include "Mod.h"

namespace lyre
{
    class NoteName::NoteNameImpl
    {
    public:
        ~NoteNameImpl(){}
        
        NoteNameImpl()
        :myStep{ 0 }
        ,myAlter{ 0 }
        {}
        
        NoteNameImpl( const Integer step, const Integer alter )
        :myStep{ step }
        ,myAlter{ alter }
        {}
        
        Step myStep;
        Alter myAlter;
    };
    
    NoteName::~NoteName(){}

    NoteName::NoteName()
    :myImpl{ new NoteNameImpl{} }
    {}
    
    NoteName::NoteName( const Integer step, const Integer alter )
    :myImpl( new NoteNameImpl{ step, alter } )
    {}
    
    NoteName::NoteName( const String& str )
    :myImpl{ new NoteNameImpl{} }
    {
        parse( str );
    }
    
    NoteName::NoteName( const NoteName& other )
    :myImpl( new NoteNameImpl{ *other.myImpl } )
    {}
    
    NoteName::NoteName( NoteName&& other ) noexcept
    :myImpl( std::move( other.myImpl ) )
    {}
    
    NoteName& NoteName::operator=( const NoteName& other )
    {
        auto temp = other;
        NoteName::swap( temp, *this );
        return *this;
    }
    
    NoteName& NoteName::operator=( NoteName&& other ) noexcept
    {
        NoteName::swap( other, *this );
        return *this;
    }
    
    
    INoteNameUPtr NoteName::clone() const
    {
        INoteNameUPtr value{ new NoteName{ *this } };
        return value;
    }
    
    Integer NoteName::getValue() const
    {
        Mod<Integer, 12> m{ ( myImpl->myStep.getPitchClassValue() ) + ( myImpl->myAlter.getValue() ) };
        return m.getValue();
    }
    
    bool NoteName::parse( const String& str )
    {
        if ( str.length() < 1 )
        {
            return false;
        }
        Step temp_step;
        Alter temp_alter;
        bool step_success = temp_step.parse( str.substr( 0, 1 ) );
        bool alter_success = false;
        if ( str.length() >= 2 )
        {
            alter_success = temp_alter.parse( str.substr( 1 ) );
        }
        else
        {
            alter_success = true;
        }
        if ( step_success && alter_success )
        {
            myImpl->myStep = temp_step;
            myImpl->myAlter = temp_alter;
            return true;
        }
        return false;
    }
    
    std::ostream& NoteName::toStream( std::ostream& os ) const
    {
        os << myImpl->myStep;
        return os << myImpl->myAlter;
    }
    
    Integer NoteName::getStepValue() const
    {
        return myImpl->myStep.getValue();
    }
    
    void NoteName::setStepValue( const Integer val )
    {
        myImpl->myStep.setValue( val );
    }
    
    Integer NoteName::getMinStepValue() const
    {
        return myImpl->myStep.getMin();
    }
    
    Integer NoteName::getMaxStepValue() const
    {
        return myImpl->myStep.getMax();
    }
    
    void NoteName::incrementStep()
    {
        myImpl->myStep.increment();
    }
    
    void NoteName::decrementStep()
    {
        myImpl->myStep.decrement();
    }
    
    Integer NoteName::getAlterValue() const
    {
        return myImpl->myAlter.getValue();
    }
    
    void NoteName::setAlterValue( const Integer val )
    {
        myImpl->myAlter.setValue( val );
    }
    
    Integer NoteName::getMinAlterValue() const
    {
        return myImpl->myAlter.getMin();
    }
    
    Integer NoteName::getMaxAlterValue() const
    {
        return myImpl->myAlter.getMax();
    }
    
    void NoteName::incrementAlter()
    {
        myImpl->myAlter.increment();
    }
    
    void NoteName::decrementAlter()
    {
        myImpl->myAlter.decrement();
    }
    
    void NoteName::swap( NoteName& left, NoteName& right ) noexcept
    {
        std::swap( left.myImpl, right.myImpl );
    }
    
}