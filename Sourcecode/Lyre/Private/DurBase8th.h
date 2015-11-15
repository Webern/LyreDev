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
        class DurBase8th;
        using DurBase8thSP = std::shared_ptr<DurBase8th>;
        using DurBase8thUP = std::unique_ptr<DurBase8th>;
        
        class DurBase8th : public IDurBase
        {
        public:
            virtual ~DurBase8th();
            virtual IDurBaseUP clone() const;
            virtual void copyTo( IDurBaseUP& output ) const;
            
            virtual Rational getValue() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
        private:
            const static Rational ourRational;
            const static String ourName;
        };
    }
}