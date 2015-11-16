//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/Rational.h"
#include "Lyre/Private/copyTo.h"
#include <memory>

namespace Lyre
{
    class IDurBase;
    using IDurBaseSP = std::shared_ptr<IDurBase>;
    using IDurBaseUP = std::unique_ptr<IDurBase>;
    
    class IDurBase
    {
    public:
        virtual ~IDurBase();
        virtual IDurBaseUP clone() const = 0;
        virtual void copyTo( IDurBaseUP& output ) const = 0; // copy to downcasted pointer
        
        virtual Rational getValue() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        virtual String toString() const;
        // virtual bool equalTo( const IDurBase& other ) const = 0; // MJBTODO
    };
    
    std::ostream& operator<<( std::ostream& os, const IDurBase& object );
}
