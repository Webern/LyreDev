#include "Lyre/Private/PartGroupSpec.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        PartGroupSpec::~PartGroupSpec()
        {
            
        }

        
        PartGroupSpec::PartGroupSpec()
            : myNumber( -1 )
            , myName()
            , myShortName()
            , myPartIndices()
        {

        }
        

        IPartGroupSpecUP PartGroupSpec::clone() const
        {
            return IPartGroupSpecUP{ new PartGroupSpec{ *this } };
        }
        

        std::ostream& PartGroupSpec::toStream( std::ostream& os ) const
        {
            os << "Part Group ";
            if ( myNumber >= 0 )
            {
                os << "[" << myNumber << "]";
            }
            os << ": " << myName;
            return os;
        }
        
        
        int PartGroupSpec::getNumber() const
        {
            return myNumber;
        }
        
        
        String PartGroupSpec::getName() const
        {
            return myName;
        }
        
        
        String PartGroupSpec::getShortName() const
        {
            return myShortName;
        }
        
        
        const Indices& PartGroupSpec::getPartIndices() const
        {
            return myPartIndices;
        }
        
        
        void PartGroupSpec::setNumber( int number )
        {
            myNumber = number;
        }
        
        
        void PartGroupSpec::setName( const String& name )
        {
            myName = name;
        }
        
        
        void PartGroupSpec::setShortName( const String& shortName )
        {
            myShortName = shortName;
        }
        
        
        void PartGroupSpec::addPartIndex( int index )
        {
            THROW_IF_BAD_VALUE( index, 0, INT_MAX );
            if ( myPartIndices.size() == 0 )
            {
                myPartIndices.insert( index );
                return;
            }
            int lastIndex = *myPartIndices.rbegin();
            int firstIndex = *myPartIndices.begin();
            if ( ( index < ( firstIndex - 1 ) ) ||
                 ( index > ( lastIndex + 1 ) ) )
            {
                THROW( "part indices must be adjacent" );
            }
            myPartIndices.insert( index );
        }
    }
}
