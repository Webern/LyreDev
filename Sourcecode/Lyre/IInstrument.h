//PUBLIC
#pragma once
#include "Lyre/IRange.h"
#include "Lyre/Lyre.h"

namespace Lyre
{
    
    struct PUBLIC InstrumentName
    {
        String Name;
        String ShortName;
    };

    FORWARD_DECLARE(IInstrument)
    
    class PUBLIC IInstrument : public IStreamable
    {
    public:
        virtual ~IInstrument() {};
        virtual IInstrumentUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        virtual String getName() const = 0;
        virtual String getShortName() const = 0;
        virtual IRangeUP getRange() const = 0;
    };
}
