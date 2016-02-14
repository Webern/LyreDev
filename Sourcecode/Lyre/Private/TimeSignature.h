//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/ITimeSignature.h"
#include "Lyre/IBeatPattern.h"

namespace Lyre
{
    FORWARD_DECLARE(TimeSignature)
    
    class TimeSignature : public ITimeSignature
    {
    public:
        virtual ~TimeSignature();
        TimeSignature();
        TimeSignature( int top, int bottom );
        
        TimeSignature( const IBeatPatternUP& beatPattern,
                       int top,
                       int bottom );
        
        TimeSignature( const TimeSignature& other );
        TimeSignature( TimeSignature&& other );
        TimeSignature& operator=( const TimeSignature& other );
        TimeSignature& operator=( TimeSignature&& other );
        
        virtual ITimeSignatureUP clone() const;
        virtual std::ostream& toStream( std::ostream& os ) const;
        
        virtual IBeatPatternUP getBeatPattern() const;
        virtual int getTop() const;
        virtual int getBottom() const;
        virtual Rational getTotalDuration();
        
    private:
        int myTop;
        int myBottom;
        IBeatPatternUP myBeatPattern;
        void setTop( int top );
        void setBottom( int bottom );
        void guessBeatPattern();
        void setBeatPattern( const IBeatPatternUP& beatPattern );
        Rational getTotalFromDurVec( const VecIDurationUP& durs ) const;
    };
}
