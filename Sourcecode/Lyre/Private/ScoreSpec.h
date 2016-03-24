//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IScoreSpec.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(ScoreSpec)
        
        class ScoreSpec : public IScoreSpec
        {
        public:
            virtual ~ScoreSpec();
            ScoreSpec();

			// not needed, no ptrs
			#if 1==0
            ScoreSpec( const ScoreSpec& other );
            ScoreSpec( ScoreSpec&& other );
            ScoreSpec& operator=( const ScoreSpec& other );
            ScoreSpec& operator=( ScoreSpec&& other );
			#endif

            virtual IScoreSpecUP clone() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
            
			String getTitle() const;
			String getComposer() const;
			String getCopyright() const;
			String getStartDate() const;
			String getCompletionDate() const;

			void setTitle( const String& value );
			void setComposer( const String& value );
			void setCopyright( const String& value );
			void setStartDate( const String& value );
			void setCompletionDate( const String& value );

        private:
			String myTitle;
			String myComposer;
			String myCopyright;
			String myStartDate;
			String myCompletionDate;
        };
    } 
}
