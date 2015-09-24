#include "Alter.h"
#include "Enum.h"
#include <limits>

namespace lyre
{
    std::shared_ptr<Strings> ALTERS242152 = std::make_shared<Strings>( Strings{ "C","D","E","F","G","A","B" } );
    
    class Alter::AlterImpl
    {
    public:
        AlterImpl() : myValue{ 0 } {}
        AlterImpl( const Integer value ) : myValue{ value } {}
        Integer getValue() const { return myValue; }
        void setValue( const Integer value ) { myValue = value; }
        char doubleFlat() const { return 'd'; }
        char flat() const { return 'b'; }
        char sharp() const { return '#'; }
        char doubleSharp() const { return 'x'; }
        bool sharpDirection() const { return myValue > 0; }
        bool flatDirection() const { return myValue < 0; }
    private:
        Integer myValue;
    };
    Alter::~Alter() {}
    Alter::Alter() : myImpl( new AlterImpl{} ) {}
    
    Alter::Alter( const Integer value ) : myImpl( new AlterImpl{ value } ) {}
    
    Alter::Alter( const String& value ) : myImpl( new AlterImpl{} )
    {
        parse( value );
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
    
    void Alter::setValue( const Integer value )
    {
        myImpl->setValue( value );
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
        auto c = str.cbegin();
        auto end = str.cend();
        bool success = false;
        Integer value = 0;
        if ( c == end )
        {
            success = true;
        }
        else // if ( c != end )
        {
            Integer direction = 0;
            bool singleFound = false;
            
            if ( *c == myImpl->sharp() || *c == myImpl->doubleSharp() )
            {
                direction = 1;
            }
            else if ( *c == myImpl->flat() || *c == myImpl->doubleFlat() )
            {
                direction = -1;
            }
            else
            {
                return false;
            }
            
            while ( c != end )
            {
                
                
                if ( *c == myImpl->doubleSharp() || myImpl->doubleFlat() )
                {
                    value += 2;
                }
                else if ( *c == myImpl->flat() || *c == myImpl->sharp() )
                {
                    value += 1;
                }
                else
                {
                    return false;
                }
                ++c;
            }
            
        }
        
        if ( success )
        {
            myImpl->setValue( value );
        }
        return success;
    }
    
    std::ostream& Alter::toStream( std::ostream& os ) const
    {
        /*
        if ( myImpl->getValue() != 0 )
        {
            Integer val = myImpl->getValue();
            char dbl = myImpl->doubleSharp();
            char sgl = myImpl->sharp();
            if ( myImpl->flatDirection() )
            {
                val *= -1;
                dbl = myImpl->doubleFlat();
                sgl = myImpl->flat();
            }
            for ( Integer i = 2; i <= val; i += 2 )
            {
                os << String{ dbl };
            }
            if ( val % 2 != 0 )
            {
                os << String{ sgl };
            }
        }
         */
        return os;
    }
    
    void Alter::increment()
    {
        myImpl->setValue( myImpl->getValue() + 1 );
    }
    
    void Alter::decrement()
    {
        myImpl->setValue( myImpl->getValue() - 1 );
    }
    
    void Alter::swap( Alter& left, Alter& right ) noexcept
    {
        std::swap( left.myImpl, right.myImpl );
    }
}