#include "Alter.h"
#include "Enum.h"
#include <limits>

namespace lyre
{
    std::shared_ptr<Strings> ALTERS242152 = std::make_shared<Strings>( Strings{ "C","D","E","F","G","A","B" } );
    
    class Alter::AlterImpl : public Enum
    {
    public:
        AlterImpl( const Integer value ) :Enum( value, ALTERS242152, 0 ) {}
        AlterImpl() :Enum( 0, ALTERS242152, 0 ) {}
    };
    Alter::~Alter() {}
    Alter::Alter() : myImpl( new AlterImpl{} ) {}
    
    Alter::Alter( const Integer value ) : myImpl( new AlterImpl{ value } ) {}
    Alter::Alter( const AlterValue value ) : myImpl( new AlterImpl{} )
    {
        setValue( value );
    }
    
    Alter::Alter( const String& value ) : myImpl( new AlterImpl{} )
    {
        myImpl->parse( value );
    }
    
    Alter::Alter( const Alter& other ) : myImpl( new AlterImpl{ *other.myImpl } ) {}
    
    Alter::Alter( Alter&& other ) noexcept : myImpl( std::move( other.myImpl ) ) {}
    
    Alter& Alter::operator=( const Alter& other )
    {
        auto temp = other;
        Alter::swap( *this, temp );
        return *this;
    }
    Alter& Alter::operator=( Alter&& other ) noexcept
    {
        Alter::swap( *this, other );
        return *this;
    }
    
    IAlterPtr Alter::clone() const
    {
        return std::make_shared<Alter>( *this );
    }
    
    Integer Alter::getValue() const
    {
        return myImpl->getValue();
    }
    
    AlterValue Alter::getAlterValue() const
    {
        auto value = AlterValue::C;
        switch ( myImpl->getValue() )
        {
            case 0:
                value = AlterValue::C;
                break;
            case 1:
                value = AlterValue::D;
                break;
            case 2:
                value = AlterValue::E;
                break;
            case 3:
                value = AlterValue::F;
                break;
            case 4:
                value = AlterValue::G;
                break;
            case 5:
                value = AlterValue::A;
                break;
            case 6:
                value = AlterValue::B;
                break;
            default:
                break;
        }
        return value;
    }
    
    void Alter::setValue( const Integer value )
    {
        myImpl->setValue( value );
    }
    
    void Alter::setValue( const AlterValue value )
    {
        switch ( value )
        {
            case AlterValue::C:
                myImpl->setValue( 0 );
                break;
            case AlterValue::D:
                myImpl->setValue( 1 );
                break;
            case AlterValue::E:
                myImpl->setValue( 2 );
                break;
            case AlterValue::F:
                myImpl->setValue( 3 );
                break;
            case AlterValue::G:
                myImpl->setValue( 4 );
                break;
            case AlterValue::A:
                myImpl->setValue( 5 );
                break;
            case AlterValue::B:
                myImpl->setValue( 6 );
                break;
            default:
                break;
        }
    }
    
    Integer Alter::getMin() const
    {
        return std::numeric_limits<Integer>::max();
    }
    
    Integer Alter::getMax() const
    {
        return std::numeric_limits<Integer>::min();
    }
    
    bool Alter::parse( const String& str )
    {
        return myImpl->parse( str );
    }
    
    std::ostream& Alter::toStream( std::ostream& os ) const
    {
        return myImpl->toStream( os );
    }
    
    void Alter::increment()
    {
        myImpl->increment();
    }
    
    void Alter::decrement()
    {
        myImpl->decrement();
    }
    
    void Alter::swap( Alter& left, Alter& right ) noexcept
    {
        std::swap( left.myImpl, right.myImpl );
    }
}