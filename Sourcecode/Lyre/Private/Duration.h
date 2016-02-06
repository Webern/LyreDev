//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDuration.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/IDurDotFactory.h"
#include "Lyre/ForwardDec.h"

namespace Lyre
{
    FORWARD_DECLARE(IDurDot)
    
    namespace Private
    {
        class EXPORT_FOR_TESTS Duration : public IDuration
        {
        public:
            virtual ~Duration();
            
            Duration();
            
            Duration( const String& durName );

            
            Duration(
                const String& durName,
                const Integer dotCount );

            
            Duration(
                const VecITupletDefSPC& tuplets,
                const String& durName,
                const Integer dotCount );
            
            IDurationUP clone() const;
            Rational getDurBaseValue() const;
            String getDurBaseName() const;
            Integer getDotCount() const;
            Rational getDottedBaseValue() const;
            String getDottedBaseName() const;
            
            bool getIsTuplet() const;
            bool getIsNestedTuplet() const;
            int getTupletNestingCount() const;
            VecITupletDefSPCIterC getTupletsBegin() const;
            VecITupletDefSPCIterC getTupletsEnd() const;
            
            Rational getValue() const;

            virtual std::ostream& toStream( std::ostream& os ) const;
            virtual String toString() const;
            
        private:
            IDurDotFactoryUP myDurDotFactory;
            IDurDotUP myDurDot;
            VecITupletDefSPC myTuplets;
        };
    }
}
