#include "PitchName.h"
#include "Step.h"
#include "Alter.h"
#include "Mod.h"

namespace lyre
{
    namespace impl
    {
        class PitchName::PitchNameImpl
        {
        public:
            ~PitchNameImpl(){}
            
            PitchNameImpl()
            :myStep{ 0 }
            ,myAlter{ 0 }
            {}
            
            PitchNameImpl( const Integer step, const Integer alter )
            :myStep{ step }
            ,myAlter{ alter }
            {}
            
            Step myStep;
            Alter myAlter;
        };
        
        PitchName::~PitchName(){}
        
        PitchName::PitchName()
        :myImpl{ new PitchNameImpl{} }
        {}
        
        PitchName::PitchName( const Integer step, const Integer alter )
        :myImpl( new PitchNameImpl{ step, alter } )
        {}
        
        PitchName::PitchName( const String& str )
        :myImpl{ new PitchNameImpl{} }
        {
            parse( str );
        }
        
        PitchName::PitchName( const PitchName& other )
        :myImpl( new PitchNameImpl{ *other.myImpl } )
        {}
        
        PitchName::PitchName( PitchName&& other ) noexcept
        :myImpl( std::move( other.myImpl ) )
        {}
        
        PitchName& PitchName::operator=( const PitchName& other )
        {
            auto temp = other;
            PitchName::swap( temp, *this );
            return *this;
        }
        
        PitchName& PitchName::operator=( PitchName&& other ) noexcept
        {
            PitchName::swap( other, *this );
            return *this;
        }
        
        
        IPitchNameUP PitchName::clone() const
        {
            IPitchNameUP value{ new PitchName{ *this } };
            return value;
        }
        
        Integer PitchName::getValue() const
        {
            Mod<Integer, 12> m{ ( myImpl->myStep.getPitchClassValue() ) + ( myImpl->myAlter.getValue() ) };
            return m.getValue();
        }
        
        bool PitchName::parse( const String& str )
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
        
        std::ostream& PitchName::toStream( std::ostream& os ) const
        {
            os << myImpl->myStep;
            return os << myImpl->myAlter;
        }
        
        Integer PitchName::getStepValue() const
        {
            return myImpl->myStep.getValue();
        }
        
        bool PitchName::isIdenticalTo( const IPitchName& other ) const
        {
            if ( !isEqualTo( other ) )
            {
                return false;
            }
            else if ( getStepValue() != other.getStepValue() )
            {
                return false;
            }
            else if ( getAlterValue() != other.getAlterValue() )
            {
                return false;
            }
            else
            {
                if ( typeid(*this) == typeid(other) )
                {
                    return true;
                }
                else if ( toString() == other.toString() )
                {
                    return true;
                }
            }
            return false;
        }
        
        void PitchName::setStepValue( const Integer val )
        {
            myImpl->myStep.setValue( val );
        }
        
        Integer PitchName::getMinStepValue() const
        {
            return myImpl->myStep.getMin();
        }
        
        Integer PitchName::getMaxStepValue() const
        {
            return myImpl->myStep.getMax();
        }
        
        void PitchName::incrementStep()
        {
            myImpl->myStep.increment();
        }
        
        void PitchName::decrementStep()
        {
            myImpl->myStep.decrement();
        }
        
        Integer PitchName::getAlterValue() const
        {
            return myImpl->myAlter.getValue();
        }
        
        void PitchName::setAlterValue( const Integer val )
        {
            myImpl->myAlter.setValue( val );
        }
        
        Integer PitchName::getMinAlterValue() const
        {
            return myImpl->myAlter.getMin();
        }
        
        Integer PitchName::getMaxAlterValue() const
        {
            return myImpl->myAlter.getMax();
        }
        
        void PitchName::incrementAlter()
        {
            myImpl->myAlter.increment();
        }
        
        void PitchName::decrementAlter()
        {
            myImpl->myAlter.decrement();
        }
        
        void PitchName::swap( PitchName& left, PitchName& right ) noexcept
        {
            std::swap( left.myImpl, right.myImpl );
        }
        
    }
}