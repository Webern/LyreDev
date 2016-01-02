//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDuration.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/IDurDotFactory.h"
#include <memory>

namespace Lyre
{
    class IDurDot;
    using IDurDotSP = std::shared_ptr<IDurDot>;
    using IDurDotUP = std::unique_ptr<IDurDot>;
    
    namespace Private
    {
        class Duration : public IDuration
        {
        public:
            virtual ~Duration();
            
            Duration();
            
            Duration( const String& durName );

            
            Duration(
                const String& durName,
                const Integer dotCount );

            
            Duration(
                const ITupletDefSPCs& tuplets,
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
            ITupletDefSPCsIter getTupletsBegin() const;
            ITupletDefSPCsIter getTupletsEnd() const;
            
            Rational getValue() const;

            virtual std::ostream& toStream( std::ostream& os ) const;
            virtual String toString() const;
            
        private:
            IDurDotFactoryUP myDurDotFactory;
            IDurDotUP myDurDot;
            ITupletDefSPCs myTuplets;
        };
    }
}
