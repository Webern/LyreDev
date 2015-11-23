//PRIVATE
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/IDuration.h"
#include "Lyre/Rational.h"
#include "Lyre/IDurBase.h"
#include "Lyre/IDurBaseFactory.h"
#include <memory>

namespace Lyre
{
    namespace Private
    {
        class Duration;
        using DurationSP = std::shared_ptr<Duration>;
        using DurationUP = std::unique_ptr<Duration>;
        
        class Duration : public IDuration
        {
        public:
            Duration( const String& durName );
            
            Duration( const String& durName,
                const Integer dotCount );
            
            virtual ~Duration();
            
            virtual IDurationUP clone() const;
            
            virtual void copyTo( IDurationUP& output ) const;
            
            virtual Rational getValue() const;
            virtual Rational getDurBaseValue() const;
            
            virtual Integer getDotCount() const;
            
            virtual void setDotCount( const Integer dots );
            
            virtual std::ostream& toStream( std::ostream& os ) const;
            virtual std::ostream& durBaseToStream( std::ostream& os ) const;
            
            virtual String toString() const;
            virtual String durBaseToString() const;
            
            virtual bool isEqualTo( const IDuration& other ) const;
            virtual bool isGreaterThan( const IDuration& other ) const;
            virtual bool isLessThan( const IDuration& other ) const;
        
        private:
            IDurBaseFactoryUP myDurBaseFactory;
            IDurBaseUP myDurBase;
            Integer myDotCount;
            
        private:
            void setDurBase( const String& durName );
        };
    }
}
