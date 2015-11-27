//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDurDot.h"
#include "Lyre/Rational.h"
#include "Lyre/IDurBase.h"
#include "Lyre/IDurBaseFactory.h"
#include <memory>

namespace Lyre
{
    namespace Private
    {
        class DurDot;
        using DurDotSP = std::shared_ptr<DurDot>;
        using DurDotUP = std::unique_ptr<DurDot>;
        
        class DurDot : public IDurDot
        {
        public:
            DurDot( const String& durName );
            
            DurDot( const String& durName,
                const Integer dotCount );
            
            virtual ~DurDot();
            
            virtual IDurDotUP clone() const;
            
            virtual void copyTo( IDurDotUP& output ) const;
            
            virtual Rational getValue() const;
            virtual Rational getDurBaseValue() const;
            
            virtual Integer getDotCount() const;
            
            virtual void setDotCount( const Integer dots );
            
            virtual std::ostream& toStream( std::ostream& os ) const;
            virtual std::ostream& durBaseToStream( std::ostream& os ) const;
            
            virtual String toString() const;
            virtual String getDurBaseName() const;
            
            virtual bool isEqualTo( const IDurDot& other ) const;
            virtual bool isGreaterThan( const IDurDot& other ) const;
            virtual bool isLessThan( const IDurDot& other ) const;
        
        private:
            IDurBaseFactoryUP myDurBaseFactory;
            IDurBaseUP myDurBase;
            Integer myDotCount;
            
        private:
            void setDurBase( const String& durName );
        };
    }
}
