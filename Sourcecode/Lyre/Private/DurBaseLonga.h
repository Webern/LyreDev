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
        class DurBaseLonga;
        using DurBaseLongaSP = std::shared_ptr<DurBaseLonga>;
        using DurBaseLongaUP = std::unique_ptr<DurBaseLonga>;
        
        class DurBaseLonga : public IDurBase
        {
        public:
            virtual ~DurBaseLonga();
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}