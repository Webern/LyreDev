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
            , myPartSpecs()
            , myPartGroupSpecs()
        {

        }


        ScoreSpec::ScoreSpec( const ScoreSpec& other )
        {
            myTitle = other.myTitle;
            myComposer = other.myComposer;
            myCopyright = other.myCopyright;
            myStartDate = other.myStartDate;
            myCompletionDate = other.myCompletionDate;
            myPartSpecs = copyPartSpecs( other.myPartSpecs );
            myPartGroupSpecs = copyPartGroupSpecs( other.myPartGroupSpecs );
        }


        ScoreSpec::ScoreSpec( ScoreSpec&& other )
        {
            myTitle = std::move( other.myTitle );
            myComposer = std::move( other.myComposer );
            myCopyright = std::move( other.myCopyright );
            myStartDate = std::move( other.myStartDate );
            myCompletionDate = std::move( other.myCompletionDate );
            myPartSpecs = std::move( other.myPartSpecs );
            myPartGroupSpecs = std::move( other.myPartGroupSpecs );
        }


        ScoreSpec& ScoreSpec::operator=( const ScoreSpec& other )
        {
            myTitle = other.myTitle;
            myComposer = other.myComposer;
            myCopyright = other.myCopyright;
            myStartDate = other.myStartDate;
            myCompletionDate = other.myCompletionDate;
            myPartSpecs = copyPartSpecs( other.myPartSpecs );
            myPartGroupSpecs = copyPartGroupSpecs( other.myPartGroupSpecs );
            return *this;
        }


        ScoreSpec& ScoreSpec::operator=( ScoreSpec&& other )
        {
            myTitle = std::move( other.myTitle );
            myComposer = std::move( other.myComposer );
            myCopyright = std::move( other.myCopyright );
            myStartDate = std::move( other.myStartDate );
            myCompletionDate = std::move( other.myCompletionDate );
            myPartSpecs = std::move( other.myPartSpecs );
            myPartGroupSpecs = std::move( other.myPartGroupSpecs );
            return *this;
        }


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
        
        
        VecIPartSpecUP ScoreSpec::getPartSpecs() const
        {
            return std::move( copyPartSpecs( myPartSpecs ) );
        }
        
        
        VecIPartGroupSpecUP ScoreSpec::getPartGroupSpecs() const
        {
            return std::move( copyPartGroupSpecs( myPartGroupSpecs ) );
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
        
        
        void ScoreSpec::setPartSpecs( const VecIPartSpecUP& parts )
        {
            myPartSpecs = copyPartSpecs( parts );
        }
        
        
        void ScoreSpec::setPartGroupSpecs( const VecIPartGroupSpecUP& partGroups )
        {
            myPartGroupSpecs = copyPartGroupSpecs( partGroups );
        }
        
        
        VecIPartSpecUP ScoreSpec::copyPartSpecs( const VecIPartSpecUP& partSpecs ) const
        {
            VecIPartSpecUP copy;
            for ( auto it = partSpecs.cbegin(); it != partSpecs.cend(); ++it )
            {
                THROW_IF_NULL( *it );
                copy.push_back( (*it)->clone() );
            }
            return std::move( copy );
        }
        
        
        VecIPartGroupSpecUP ScoreSpec::copyPartGroupSpecs( const VecIPartGroupSpecUP& partGroupSpecs ) const
        {
            VecIPartGroupSpecUP copy;
            for ( auto it = partGroupSpecs.cbegin(); it != partGroupSpecs.cend(); ++it )
            {
                THROW_IF_NULL( *it );
                copy.push_back( (*it)->clone() );
            }
            return std::move( copy );
        }
    }
}
