#include "Lyre/Private/PartSpec.h"
#include "Lyre/Private/throw.h"
#include <ctype.h>

namespace Lyre
{
    namespace Private
    {
        int PartSpec::ourUniqueInt = 100000;
        
        PartSpec::~PartSpec()
        {
        }

        PartSpec::PartSpec(
            int numStaves,
            const IInstrumentUP& instrument )
        : myName()
        , myId()
        , myInstrument( nullptr )
        , myNumStaves( numStaves )
        {
            THROW_IF_BAD_VALUE( numStaves, 0, INT_MAX )
            THROW_IF_NULL( instrument )
            myInstrument = instrument->clone();
            deduceName();
            autoGenId( myName );
        }

        
        PartSpec::PartSpec( const PartSpec& other )
        : myName( other.myName )
        , myId( other.myId )
        , myInstrument( nullptr )
        , myNumStaves( other.myNumStaves )
        {
            THROW_IF_NULL( other.myInstrument )
            myInstrument = other.myInstrument->clone();
        }

        
        PartSpec::PartSpec( PartSpec&& other )
        : myName( std::move( other.myName ) )
        , myId( std::move( other.myId ) )
        , myInstrument( std::move( other.myInstrument ) )
        , myNumStaves( std::move( other.myNumStaves ) )
        {

        }

        
        PartSpec& PartSpec::operator=( const PartSpec& other )
        {
            THROW_IF_NULL( other.myInstrument )
            myName = other.myName;
            myId = other.myId;
            myInstrument = other.myInstrument->clone();
            myNumStaves = other.myNumStaves;
            return *this;
        }

        
        PartSpec& PartSpec::operator=( PartSpec&& other )
        {
            myName = std::move( other.myName );
            myId = std::move( other.myId );
            myInstrument = std::move( other.myInstrument );
            myNumStaves = std::move( other.myNumStaves );
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
        
        
        int PartSpec::getNumStaves() const
        {
            return myNumStaves;
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
        
        void PartSpec::autoGenerateUniqueIdFromName()
        {
            autoGenId( myName );
        }
        
        void PartSpec::deduceName()
        {
            myName = myInstrument->getName();
        }
        
        
        void PartSpec::autoGenId( const String& name )
        {
            std::stringstream ss;
            for ( auto c : name )
            {
                if ( c >= 'a' && c <= 'z' )
                {
                    ss << static_cast<char>( toupper( c ) );
                }
                else if ( c >= 'A' && c <= 'Z' )
                {
                    ss << c;
                }
                else if ( c >= '1' && c <= '0' )
                {
                    ss << c;
                }
                else if ( c == ' ' )
                {
                    ss << '_';
                }
            }
            ss << '_' << ourUniqueInt++;
            myId = ss.str();
        }
    }
}
