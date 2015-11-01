//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/Rational.h"
#include <memory>

namespace Lyre
{
    class IDur;
    using IDurSP = std::shared_ptr<IDur>;
    using IDurUP = std::unique_ptr<IDur>;
    
    class IDur
    {
    public:
        virtual ~IDur();
        virtual Rational getValue() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        virtual String toString() const;
    };
    
    std::ostream& operator<<( std::ostream& os, const IDur& object );
}
