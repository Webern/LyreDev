#include "Lyre/Private/ScoreSpec.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        ScoreSpec::~ScoreSpec()
        {
        }

        ScoreSpec::ScoreSpec()
			: myTitle()
			, myComposer()
			, myCopyright()
			, myStartDate()
			, myCompletionDate()
        {

        }

		// not needed, no ptrs
		#if 1== 0
        ScoreSpec::ScoreSpec( const ScoreSpec& other )
        {
            UNUSED_PARAMETER( other )
        }


        ScoreSpec::ScoreSpec( ScoreSpec&& other )
        {
            UNUSED_PARAMETER( other )
        }


        ScoreSpec& ScoreSpec::operator=( const ScoreSpec& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }


        ScoreSpec& ScoreSpec::operator=( ScoreSpec&& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }
		#endif

        IScoreSpecUP ScoreSpec::clone() const
        {
            return IScoreSpecUP{ new ScoreSpec{ *this } };
        }


        std::ostream& ScoreSpec::toStream( std::ostream& os ) const
        {
			os << "*******************************************************************" << std::endl;
			os << "Title           : " << myTitle << std::endl;
			os << "Composer        : " << myComposer << std::endl;
			os << "Copyright       : " << myCopyright << std::endl;
			os << "Start Date      : " << myStartDate << std::endl;
			os << "Completion Date : " << myCompletionDate << std::endl;
			os << "*******************************************************************" << std::endl;
			return os;
        }


		String ScoreSpec::getTitle() const
		{
			return myTitle;
		}


		String ScoreSpec::getComposer() const
		{
			return myComposer;
		}


		String ScoreSpec::getCopyright() const
		{
			return myCopyright;
		}


		String ScoreSpec::getStartDate() const
		{
			return myStartDate;
		}


		String ScoreSpec::getCompletionDate() const
		{
			return myCompletionDate;
		}


		void ScoreSpec::setTitle( const String & value )
		{
			myTitle = value;
		}


		void ScoreSpec::setComposer( const String & value )
		{
			myComposer = value;
		}


		void ScoreSpec::setCopyright( const String & value )
		{
			myCopyright = value;
		}


		void ScoreSpec::setStartDate( const String & value )
		{
			myStartDate = value;
		}


		void ScoreSpec::setCompletionDate( const String & value )
		{
			myCompletionDate = value;
		}
    }
}
