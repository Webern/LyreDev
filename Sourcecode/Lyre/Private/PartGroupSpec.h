//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IPartGroupSpec.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(PartGroupSpec)
        
        class PartGroupSpec : public IPartGroupSpec
        {
        public:
            virtual ~PartGroupSpec();
            PartGroupSpec();
            
            IPartGroupSpecUP clone() const;
            std::ostream& toStream( std::ostream& os ) const;
            
            int getNumber() const;
            String getName() const;
            String getShortName() const;
            const Indices& getPartIndices() const;
            
            void setNumber( int number );
            void setName( const String& name );
            void setShortName( const String& shortName );
            void addPartIndex( int index );
            
        private:
            int myNumber;
            String myName;
            String myShortName;
            Indices myPartIndices;
        };
    } 
}
