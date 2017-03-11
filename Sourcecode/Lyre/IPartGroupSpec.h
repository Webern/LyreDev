//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include <set>

namespace Lyre
{
    FORWARD_DECLARE(IPartGroupSpec)
    
    using Indices = std::set<int>;
    
    class PUBLIC IPartGroupSpec : public IStreamable
    {
    public:
        virtual ~IPartGroupSpec() {};
        virtual IPartGroupSpecUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        virtual int getNumber() const = 0;
        virtual String getName() const = 0;
        virtual String getShortName() const = 0;
        virtual const Indices& getPartIndices() const = 0;
        
        virtual void setNumber( int number ) = 0;
        virtual void setName( const String& name ) = 0;
        virtual void setShortName( const String& shortName ) = 0;
        virtual void addPartIndex( int index ) = 0;
        
    };
}
