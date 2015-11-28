//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDurBase.h"
#include "Lyre/Rational.h"
#include <memory>

namespace Lyre
{
    namespace Private
    {
        class DurBaseBreve;
        using DurBaseBreveSP = std::shared_ptr<DurBaseBreve>;
        using DurBaseBreveUP = std::unique_ptr<DurBaseBreve>;
        
        class DurBaseBreve : public IDurBase
        {
        public:
            virtual ~DurBaseBreve();
            virtual IDurBaseUP clone() const;
            virtual // void copyTo( IDurBaseUP& output ) const;
            
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}
