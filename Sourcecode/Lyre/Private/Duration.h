//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDuration.h"
#include "Lyre/ITupletDef.h"
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
            virtual ~Duration() = default;
            IDurationUP clone() const;
            Rational getDurBaseValue() const;
            String getDurBaseName() const;
            Integer getDotCount() const;
            Rational getDottedValue() const;
            String getDottedName() const;
            
            bool getIsTuplet() const;
            int getTupletNestingCount() const;
            ITupletDefSPCsIter getTupletsBegin() const;
            ITupletDefSPCsIter getTupletsEnd() const;
            
            Rational getValue() const;

            virtual std::ostream& toStream( std::ostream& os ) const;
            virtual String toString() const;
            
        private:
            IDurDotUP myDurDot;
            ITupletDefSPCs myTuplets;
        };
    }
}
