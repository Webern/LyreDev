#include "Lyre/Private/MusicXml.h"
#include <string>
#include <sstream>

using namespace mx;
using namespace mx::d;
using namespace mx::e;
using namespace mx::t;

namespace Lyre
{
    namespace MxPrivate
    {
        DocumentPartwisePtr createDocument()
        {
            return makeDocumentPartwise();
        }
        
        void setTitle( const MxDoc& doc, const std::string& title )
        {
            auto header = doc->getScorePartwise()->getScoreHeaderGroup();
            header->setHasWork( true );
            header->getWork()->setHasWorkTitle( true );
            header->getWork()->getWorkTitle()->setValue( XsString( title ) );
        }
        
        
        void setMovementTitle( const MxDoc& doc, const std::string& title )
        {
            auto header = doc->getScorePartwise()->getScoreHeaderGroup();
            header->setHasMovementTitle( true );
            header->getMovementTitle()->setValue( XsString( title ) );
        }
        
        
        void setMovementNumber( const MxDoc& doc, int movementNumber )
        {
            std::stringstream num;
            num << movementNumber;
            auto header = doc->getScorePartwise()->getScoreHeaderGroup();
            header->setHasMovementNumber( true );
            header->getMovementNumber()->setValue( XsString( num.str() ) );
        }
        
        
        void setComposer( const MxDoc& doc, const std::string& composer )
        {
            auto header = doc->getScorePartwise()->getScoreHeaderGroup();
            auto composerCreator = makeCreator();
            composerCreator->getAttributes()->hasType = true;
            composerCreator->getAttributes()->type = XsToken( "composer" );
            composerCreator->setValue( XsString( composer ) );
            header->setHasIdentification( true );
            header->getIdentification()->addCreator( composerCreator );
        }
        
        
        void setCopyright( const MxDoc& doc, const std::string& copyright )
        {
            auto header = doc->getScorePartwise()->getScoreHeaderGroup();
            auto copyrightObj = makeRights();
            copyrightObj->getAttributes()->hasType = true;
            copyrightObj->getAttributes()->type = XsToken( "copyright" );
            copyrightObj->setValue( XsString( copyright ) );
            header->setHasIdentification( true );
            header->getIdentification()->addRights( copyrightObj );
        }
        
        
        void setSoftware( const MxDoc& doc, const std::string& software )
        {
            auto header = doc->getScorePartwise()->getScoreHeaderGroup();
            header->setHasIdentification( true );
            header->getIdentification()->setHasEncoding( true );
            header->getIdentification()->getEncoding()->setChoice( Encoding::Choice::software );
            header->getIdentification()->getEncoding()->getSoftware()->setValue( XsString( software ) );
        }
        
        
        void setPartList( const MxDoc& doc, const VecIPartSpecUP& specs )
        {
            int partNumber = 1;
            auto partList = doc->getScorePartwise()->getScoreHeaderGroup()->getPartList();
            for ( auto p = specs.cbegin(); p != specs.cend(); ++p )
            {
                const IPartSpecUP& part = *p;
                PartGroupPtr mxPartGroup;
                if ( p == specs.cbegin() )
                {
                    mxPartGroup = partList->getPartGroup( partList->getPartGroupSet().cbegin() );
                }
                else
                {
                    mxPartGroup = makePartGroup();
                    partList->addPartGroup( mxPartGroup );
                }
                mxPartGroup->getAttributes()->hasNumber = true;
                mxPartGroup->getAttributes()->number = XsToken( std::to_string( partNumber ) );
                // oh no, I need to group my parts
                ++partNumber;
                UNUSED_PARAMETER( part );
            }
        }
    }
}
