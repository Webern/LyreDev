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
        
        
        void setPartList(
            const MxDoc& doc,
            const VecIPartSpecUP& specs,
            const VecIPartGroupSpecUP& groups )
        {
            auto partList = doc->getScorePartwise()->getScoreHeaderGroup()->getPartList();
            auto partIter = specs.cbegin();
            auto partEnd = specs.cend();
            auto partIndex = 0;
            auto groupIter = groups.cbegin();
            auto groupEnd = groups.cend();
            auto groupFirstPartIndex = -1;
            auto groupLastPartIndex = -1;
            PartGroupPtr currentGroup = nullptr;
            
            
            for( ; partIter != partEnd; ++partIter, ++partIndex )
            {
                if( groupIter != groupEnd )
                {
                    groupFirstPartIndex = *(*groupIter)->getPartIndices().cbegin();
                    groupLastPartIndex = *(*groupIter)->getPartIndices().rbegin();
                }
                bool isGroupStart = ( partIndex == groupFirstPartIndex );
                bool isGroupEnd = ( partIndex == groupLastPartIndex );
                if( isGroupStart )
                {
                    currentGroup = makePartGroup();
                    currentGroup->getAttributes()->type = StartStop::start;
                    currentGroup->setHasGroupName( true );
                    currentGroup->getGroupName()->setValue( XsString( (*groupIter)->getName() ) );
                    currentGroup->setHasGroupAbbreviation( true );
                    currentGroup->getGroupAbbreviation()->setValue( XsString( (*groupIter)->getShortName() ) );
                    currentGroup->setHasGroupBarline( true );
                    currentGroup->getGroupBarline()->setValue( GroupBarlineValue::yes );
                    
                    if( partIndex == 0 )
                    {
                        doc->getScorePartwise()->getScoreHeaderGroup()->getPartList()->addPartGroup( currentGroup );
                    }
                    else
                    {
                        auto thisone = makePartGroupOrScorePart();
                        thisone->setChoice( PartGroupOrScorePart::Choice::partGroup );
                        thisone->setPartGroup( currentGroup );
                        doc->getScorePartwise()->getScoreHeaderGroup()->getPartList()->addPartGroupOrScorePart( thisone );
                    }
                }
                
                ScorePartPtr currentPart;
                currentPart = makeScorePart();
                if( partIndex == 0 )
                {
                    currentPart = doc->getScorePartwise()->getScoreHeaderGroup()->getPartList()->getScorePart();
                }
                
                currentPart->getAttributes()->id = XsID( (*partIter)->getUniqueId() );
                currentPart->getPartName()->setValue( XsString( (*partIter)->getInstrument()->getName() ) );
                currentPart->setHasPartAbbreviation( true );
                currentPart->getPartAbbreviation()->setValue( XsString( (*partIter)->getInstrument()->getShortName() ) );
                auto scoreInstrument = makeScoreInstrument();
                scoreInstrument->getInstrumentName()->setValue( XsString( (*partIter)->getInstrument()->getName() ) );
                scoreInstrument->setHasInstrumentAbbreviation( true );
                scoreInstrument->getInstrumentAbbreviation()->setValue( XsString( (*partIter)->getInstrument()->getShortName() ) );
                scoreInstrument->getAttributes()->id = XsID( (*partIter)->getUniqueId() + String( "_INSTR" ) );
                currentPart->addScoreInstrument( scoreInstrument );
                
                if( partIndex > 0 )
                {
                    auto x = makePartGroupOrScorePart();
                    x->setChoice( PartGroupOrScorePart::Choice::scorePart );
                    x->setScorePart( currentPart );
                    doc->getScorePartwise()->getScoreHeaderGroup()->getPartList()->addPartGroupOrScorePart( x );
                }
                
                if ( isGroupEnd )
                {
                    auto endOfGroup = makePartGroup();
                    endOfGroup->getAttributes()->type = StartStop::stop;
                    auto addthis = makePartGroupOrScorePart();
                    addthis->setChoice( PartGroupOrScorePart::Choice::partGroup );
                    addthis->setPartGroup( endOfGroup );
                    doc->getScorePartwise()->getScoreHeaderGroup()->getPartList()->addPartGroupOrScorePart( addthis );
                    ++groupIter;
                }
            }
        }
        
        void addParts(
            const MxDoc& doc,
            const VecIPartSpecUP& specs )
        {
            
            auto partList = doc->getScorePartwise()->getScoreHeaderGroup()->getPartList();
            auto partIter = specs.cbegin();
            auto partEnd = specs.cend();
            auto partIndex = 0;
            PartGroupPtr currentGroup = nullptr;
            
            
            for( ; partIter != partEnd; ++partIter, ++partIndex )
            {
                PartwisePartPtr newPart = makePartwisePart();
                if( partIndex == 0 )
                {
                    newPart = *( doc->getScorePartwise()->getPartwisePartSet().begin() );
                }
                else
                {
                    doc->getScorePartwise()->addPartwisePart( newPart );
                }
                newPart->getAttributes()->id = XsIDREF( (*partIter)->getUniqueId() );

            } // end for loop

        } // end function addParts

    } // end namespace MxPrivate

} // end namespace Lyre
