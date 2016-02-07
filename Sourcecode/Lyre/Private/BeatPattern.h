//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IBeatPattern.h"
#include "Lyre/IDuration.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(BeatPattern)
        
        class BeatPattern : public IBeatPattern
        {
        public:
            virtual ~BeatPattern();
            BeatPattern();
            BeatPattern( Integer count, const IDurationUP& dur );
            BeatPattern( const VecIDurationUP& durations );
            virtual IBeatPatternUP clone() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
            
            Integer getCount() const;
            virtual bool getIsEmpty() const;
            virtual const IDurationUPC getCurrent() const;
            virtual const IDurationUPC getNext() const;
            virtual const IDurationUPC getPrevious() const;
            virtual bool getIsEnd() const;
            //virtual void first();
            //virtual void last();
            //virtual bool next();
            //virtual bool previous();
            //virtual void jump( int index );
            
            
        private:
        // data
            using ULong = VecIDurationUP::size_type;
            VecIDurationUP myDurations;
            Integer myCurrent;
            bool myIsEnd;
        
        // functions
            void loadDurations( Integer count, const IDurationUP& dur );
            void loadDurations( const VecIDurationUP& durations );
        };
    }
    
    
    
}
