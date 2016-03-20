#include "Lyre/Private/PartSpec.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        PartSpec::~PartSpec()
        {
        }

        PartSpec::PartSpec( const IInstrumentUP& instrument )
        : myName( "default name" )
        , myId( "default id" )
        , myInstrument( nullptr )
        {
            THROW_IF_NULL( instrument )
            myInstrument = instrument->clone();
        }

        
        PartSpec::PartSpec( const PartSpec& other )
        : myName( other.myName )
        , myId( other.myId )
        , myInstrument( nullptr )
        {
            THROW_IF_NULL( other.myInstrument )
            myInstrument = other.myInstrument->clone();
        }

        
        PartSpec::PartSpec( PartSpec&& other )
        : myName( std::move( other.myName ) )
        , myId( std::move( other.myId ) )
        , myInstrument( std::move( other.myInstrument ) )
        {

        }

        
        PartSpec& PartSpec::operator=( const PartSpec& other )
        {
            THROW_IF_NULL( other.myInstrument )
            myName = other.myName;
            myId = other.myId;
            myInstrument = other.myInstrument->clone();
            return *this;
        }

        
        PartSpec& PartSpec::operator=( PartSpec&& other )
        {
            myName = std::move( other.myName );
            myId = std::move( other.myId );
            myInstrument = std::move( other.myInstrument );
            return *this;
        }

        
        IPartSpecUP PartSpec::clone() const
        {
            return IPartSpecUP{ new PartSpec{ *this } };
        }

        
        std::ostream& PartSpec::toStream( std::ostream& os ) const
        {
            os << "{ " << getName();
            os << ": " << getUniqueId();
            os << ": " << myInstrument->getName();
            os << " }";
            return os;
        }
        
        
        String PartSpec::getName() const
        {
            return myName;
        }
        
        
        String PartSpec::getUniqueId() const
        {
            return myId;
        }
        
        
        IInstrumentUP PartSpec::getInstrument() const
        {
            THROW_IF_NULL( myInstrument )
            return myInstrument->clone();
        }
        
        
        void PartSpec::setName( const String& name )
        {
            myName = name;
        }
        
        
        void PartSpec::setUniqueId( const String& uniqueId )
        {
            if( uniqueId.size() < 1 )
            {
                THROW( "unique id cannot be zero length" )
            }
            myId = uniqueId;
        }
        
        
        void PartSpec::setInstrument( const IInstrumentUP& instrument )
        {
            THROW_IF_NULL( instrument )
            myInstrument = instrument->clone();
        }
        
    }
}
