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
        class DurBase32nd;
        using DurBase32ndSP = std::shared_ptr<DurBase32nd>;
        using DurBase32ndUP = std::unique_ptr<DurBase32nd>;
        
        class DurBase32nd : public IDurBase
        {
        public:
            virtual ~DurBase32nd();
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
