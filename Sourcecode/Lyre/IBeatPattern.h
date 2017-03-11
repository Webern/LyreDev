//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/Rational.h"

namespace Lyre
{
    FORWARD_DECLARE(IBeatPattern)
    FORWARD_DECLARE(IDuration)
    
    class PUBLIC IBeatPattern : public IStreamable
    {
    public:
        virtual ~IBeatPattern() {};
        virtual IBeatPatternUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        virtual Rational getTotalDuration() const = 0;
        virtual std::vector<Rational> getBeatPositions() const = 0;
        
        virtual bool getIsEmpty() const = 0;
        virtual bool getIsEnd() const = 0;
        
        virtual int getCount() const = 0;
        virtual int getCurrentIndex() const = 0;
        
        virtual const IDurationUPC get( int index ) const = 0;
        virtual const IDurationUPC getCurrent() const = 0;
        virtual const IDurationUPC getNext() const = 0;
        virtual const IDurationUPC getPrevious() const = 0;
        
        virtual void first() = 0;
        virtual void last() = 0;
        virtual bool next() = 0;
        virtual bool previous() = 0;
        virtual void jump( int index ) = 0;
    };
}
