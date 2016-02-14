//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IDurDot.h"
#include "Lyre/Rational.h"
#include "Lyre/IDurBase.h"
#include "Lyre/IDurBaseFactory.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(DurDot)
        
        class EXPORT_FOR_TESTS DurDot : public IDurDot
        {
        public:
            DurDot();
            
            DurDot( const String& durName );
            
            DurDot( const String& durName,
                const int dotCount );
            
            virtual ~DurDot();
            
            virtual IDurDotUP clone() const;
            
            virtual Rational getValue() const;
            virtual Rational getDurBaseValue() const;
            
            virtual int getDotCount() const;
            
            virtual void setDotCount( const int dots );
            
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
            int myDotCount;
            
        private:
            void setDurBase( const String& durName );
        };
    }
}
