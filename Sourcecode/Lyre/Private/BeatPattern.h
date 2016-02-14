//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IBeatPattern.h"
#include "Lyre/IDuration.h"
#include "Lyre/Private/Collection.h"
#if 1==0
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
            virtual void first();
            virtual void last();
            virtual bool next();
            virtual bool previous();
            virtual void jump( int index );
            
            
        private:
        // data
            Collection<IDurationUP> myDurations;
        
        // functions
            bool checkDuration( const IDurationUP& dur );
            bool checkDurations( const VecIDurationUP& durations );
            void loadDurations( Integer count, const IDurationUP& dur );
        };
    }
    
    
    
}
#endif

