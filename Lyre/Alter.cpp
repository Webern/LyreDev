#include "Alter.h"
#include "Enum.h"
#include <limits>
#include <sstream>

namespace lyre
{
    namespace impl
    {
        std::shared_ptr<Strings> ALTERS242152 = std::make_shared<Strings>( Strings{ "C","D","E","F","G","A","B" } );
        
        class Alter::AlterImpl
        {
        public:
            AlterImpl() : myValue{ 0 } {}
            AlterImpl( const Integer value ) : myValue{ value } {}
            Integer getValue() const { return myValue; }
            void setValue( const Integer value ) { myValue = value; }
            char doubleFlatSymbol() const { return 'd'; }
            char flatSymbol() const { return 'b'; }
            char sharpSymbol() const { return '#'; }
            char doubleSharpSymbol() const { return 'x'; }
            bool isSharp() const { return myValue > 0; };
            bool isFlat() const { return myValue < 0; };
            char singleSymbol() const
            {
                if ( isFlat() )
                {
                    return flatSymbol();
                }
                else if ( isSharp() )
                {
                    return sharpSymbol();
                }
                return 0;
            }
            char doubleSymbol() const
            {
                if ( isFlat() )
                {
                    return doubleFlatSymbol();
                }
                else if ( isSharp() )
                {
                    return doubleSharpSymbol();
                }
                return 0;
            }
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
        
        IAlterUP Alter::clone() const
        {
            IAlterUP value{ new Alter{ *this } };
            return value;
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
            return std::numeric_limits<Integer>::min();
        }
        
        Integer Alter::getMax() const
        {
            return std::numeric_limits<Integer>::max();
        }
        
        bool Alter::parse( const String& str )
        {
            auto c = str.cbegin();
            auto end = str.cend();
            Integer value = 0;
            if ( c == end )
            {
                myImpl->setValue( 0 );
                return true;
            }
            else // if ( c != end )
            {
                bool flat = true; /* determine whether we are dealing with
                                   flatSymbols or sharps */
                bool singleFound = false;
                
                if ( *c == myImpl->sharpSymbol() || *c == myImpl->doubleSharpSymbol() )
                {
                    flat = false;
                }
                while ( c != end )
                {
                    /* early return if sharp symbols are mixed
                     with flatSymbol symbols */
                    if ( ( flat && ( *c == myImpl->sharpSymbol() || *c == myImpl->doubleSharpSymbol() ) ) )
                    {
                        return false;
                    }
                    if ( ( !flat && ( *c == myImpl->flatSymbol() || *c == myImpl->doubleFlatSymbol() ) ) )
                    {
                        return false;
                    }
                    
                    /* a previous iteration of this loop found
                     a "single" symbol, then the string is
                     illegal, early return false */
                    if ( singleFound )
                    {
                        return false;
                    }
                    
                    if ( *c == myImpl->doubleSharpSymbol() || *c == myImpl->doubleFlatSymbol() )
                    {
                        value += 2;
                        singleFound = false;
                    }
                    else if ( *c == myImpl->flatSymbol() || *c == myImpl->sharpSymbol() )
                    {
                        value += 1;
                        singleFound = true;
                    }
                    else
                    {
                        return false;
                    }
                    ++c;
                }
                /* successful parse, set the value */
                if ( flat )
                {
                    myImpl->setValue( -1 * value );
                }
                else
                {
                    myImpl->setValue( value );
                }
                
            }
            
            return true;
        }
        
        std::ostream& Alter::toStream( std::ostream& os ) const
        {
            std::stringstream doubleSs;
            std::stringstream singleSs;
            doubleSs << myImpl->doubleSymbol();
            singleSs << myImpl->singleSymbol();
            String dbl = doubleSs.str();
            String sgl = singleSs.str();
            if ( myImpl->getValue() != 0 )
            {
                Integer val = myImpl->getValue();
                if ( myImpl->isFlat() )
                {
                    val *= -1;
                }
                for ( Integer i = 2; i <= val; i += 2 )
                {
                    os << dbl;
                }
                if ( val % 2 != 0 )
                {
                    os << sgl;
                }
            }
            return os;
        }
        
        bool Alter::isIdenticalTo( const IAlter& other ) const
        {
            if ( getValue() != other.getValue() )
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
        
        void Alter::increment()
        {
            if ( myImpl->getValue() == std::numeric_limits<Integer>::max() )
            {
                myImpl->setValue( std::numeric_limits<Integer>::min() );
            }
            else
            {
                myImpl->setValue( myImpl->getValue() + 1 );
            }
        }
        
        void Alter::decrement()
        {
            if ( myImpl->getValue() == std::numeric_limits<Integer>::min() )
            {
                myImpl->setValue( std::numeric_limits<Integer>::max() );
            }
            else
            {
                myImpl->setValue( myImpl->getValue() - 1 );
            }
        }
        
        void Alter::swap( Alter& left, Alter& right ) noexcept
        {
            std::swap( left.myImpl, right.myImpl );
        }
    }
}