#include "Step.h"
#include "Enum.h"

namespace lyre
{
    std::shared_ptr<Strings> STEPS23408 = std::make_shared<Strings>( Strings{ "C","D","E","F","G","A","B" } );
    
    class Step::StepImpl : public Enum
    {
    public:
        StepImpl( const Integer value ) :Enum( value, STEPS23408, 0 ) {}
        StepImpl() :Enum( 0, STEPS23408, 0 ) {}
    };
    Step::~Step() {}
    Step::Step() : myImpl( new StepImpl{} ) {}

    Step::Step( const Integer value ) : myImpl( new StepImpl{ value } ) {}
    Step::Step( const StepValue value ) : myImpl( new StepImpl{} )
    {
        setValue( value );
    }
    
    Step::Step( const String& value ) : myImpl( new StepImpl{} )
    {
        myImpl->parse( value );
    }
    
    Step::Step( const Step& other ) : myImpl( new StepImpl{ *other.myImpl } ) {}
    
    Step::Step( Step&& other ) noexcept : myImpl( std::move( other.myImpl ) ) {}
    
    Step& Step::operator=( const Step& other )
    {
        auto temp = other;
        Step::swap( *this, temp );
        return *this;
    }
    Step& Step::operator=( Step&& other ) noexcept
    {
        Step::swap( *this, other );
        return *this;
    }
    
    IStepPtr Step::clone() const
    {
        return std::make_shared<Step>( *this );
    }
    
    Integer Step::getValue() const
    {
        return myImpl->getValue();
    }
    
    StepValue Step::getStepValue() const
    {
        auto value = StepValue::C;
        switch ( myImpl->getValue() )
        {
            case 0:
                value = StepValue::C;
                break;
            case 1:
                value = StepValue::D;
                break;
            case 2:
                value = StepValue::E;
                break;
            case 3:
                value = StepValue::F;
                break;
            case 4:
                value = StepValue::G;
                break;
            case 5:
                value = StepValue::A;
                break;
            case 6:
                value = StepValue::B;
                break;
            default:
                break;
        }
        return value;
    }
    
    void Step::setValue( const Integer value )
    {
        myImpl->setValue( value );
    }
    
    void Step::setValue( const StepValue value )
    {
        switch ( value )
        {
            case StepValue::C:
                myImpl->setValue( 0 );
                break;
            case StepValue::D:
                myImpl->setValue( 1 );
                break;
            case StepValue::E:
                myImpl->setValue( 2 );
                break;
            case StepValue::F:
                myImpl->setValue( 3 );
                break;
            case StepValue::G:
                myImpl->setValue( 4 );
                break;
            case StepValue::A:
                myImpl->setValue( 5 );
                break;
            case StepValue::B:
                myImpl->setValue( 6 );
                break;
            default:
                break;
        }
    }
    
    Integer Step::getMin() const
    {
        return myImpl->getMin();
    }
    
    Integer Step::getMax() const
    {
        return myImpl->getMax();
    }
    
    bool Step::parse( const String& str )
    {
        return myImpl->parse( str );
    }
    
    std::ostream& Step::toStream( std::ostream& os ) const
    {
        return myImpl->toStream( os );
    }
    
    void Step::increment()
    {
        myImpl->increment();
    }
    
    void Step::decrement()
    {
        myImpl->decrement();
    }
    
    void Step::swap( Step& left, Step& right ) noexcept
    {
        std::swap( left.myImpl, right.myImpl );
    }
}