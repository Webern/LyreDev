//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IInstrument.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(Instrument)
        
        class Instrument : public IInstrument
        {
        public:
            virtual ~Instrument();

            Instrument(
                const String& name,
                const String& shortName,
                const IRangeUP& range );
            
            Instrument( const Instrument& other );
            Instrument( Instrument&& other ) noexcept;
            Instrument& operator=( const Instrument& other );
            Instrument& operator=( Instrument&& other ) noexcept;
            
            virtual IInstrumentUP clone() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
            
            virtual String getName() const;
            virtual String getShortName() const;
            virtual IRangeUP getRange() const;
            
        private:
            String myName;
            String myShortName;
            IRangeUP myRange;
        };
    } 
}
