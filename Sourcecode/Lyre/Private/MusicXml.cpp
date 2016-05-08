#include "Lyre/Private/MusicXml.h"
#include "Lyre/Lyre.h"
#include "Lyre/Private/throw.h"
#include "Mx/Elements.h"
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
            int groupIndex = 0;
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
                    currentGroup->getAttributes()->hasNumber = true;
                    currentGroup->getAttributes()->number = XsToken( std::to_string( groupIndex + 1 ) );
                    currentGroup->setHasGroupName( true );
                    currentGroup->getGroupName()->setValue( XsString( (*groupIter)->getName() ) );
                    currentGroup->setHasGroupAbbreviation( true );
                    currentGroup->getGroupAbbreviation()->setValue( XsString( (*groupIter)->getShortName() ) );
                    currentGroup->setHasGroupBarline( true );
                    currentGroup->getGroupBarline()->setValue( GroupBarlineValue::yes );
                    currentGroup->setHasGroupSymbol( true );
                    currentGroup->getGroupSymbol()->setValue( GroupSymbolValue::bracket );
                    currentGroup->setHasGroupNameDisplay( true );
                    currentGroup->getGroupNameDisplay()->setChoice( GroupNameDisplay::Choice::displayText );
                    currentGroup->getGroupNameDisplay()->getDisplayText()->setValue( XsString( "" ) );
                    currentGroup->setHasGroupAbbreviationDisplay( true );
                    currentGroup->getGroupAbbreviationDisplay()->setChoice( GroupAbbreviationDisplay::Choice::displayText );
                    currentGroup->getGroupAbbreviationDisplay()->getDisplayText()->setValue( XsString( "" ) );
                    
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
                    ++groupIndex;
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
        
        
        void addEmptyMeasures( const MxDoc& doc, const IScoreH& score )
        {
            UNUSED_PARAMETER(doc);
            UNUSED_PARAMETER(score);
            ITimeSignatureUP previousTimeSignature;
            auto movement = score->getMovement( 0 );
            for ( int p = 0; p < movement->getPartCount(); ++p )
            {
                auto part = movement->getPart( p );
                for ( int m = 0; m < part->getMeasureCount(); ++m )
                {
                    auto measure = part->getMeasure( m );
                    auto timeSignature = measure->getTimeSignature();
                    bool doAddTimeSignature = !previousTimeSignature;
                    if( previousTimeSignature )
                    {
                        doAddTimeSignature =
                            ( timeSignature->getTop() != previousTimeSignature->getTop() )
                        ||  ( timeSignature->getBottom() != previousTimeSignature->getBottom() );
                    }
                    
                    
                    auto mxPart = *( doc->getScorePartwise()->getPartwisePartSet().begin() + p );
                    PartwiseMeasurePtr mxMeasure;
                    if( m == 0 )
                    {
                        mxMeasure = *mxPart->getPartwiseMeasureSet().begin();
                    }
                    else
                    {
                        mxMeasure = makePartwiseMeasure();
                        mxPart->addPartwiseMeasure( mxMeasure );
                    }
                
                    mxMeasure->getAttributes()->number = XsToken( std::to_string( m+1 ) );
                    if ( doAddTimeSignature )
                    {
                        auto grp = mxMeasure->getMusicDataGroup();
                        auto sig = makeMusicDataChoice();
                        grp->addMusicDataChoice( sig );
                        sig->setChoice( MusicDataChoice::Choice::properties );
                        auto time = makeTime();
                        sig->getProperties()->addTime( time );
                        time->getTimeChoice()->setChoice( TimeChoice::Choice::timeSignature );
                        time->getTimeChoice()->getTimeSignature()->getBeats()->setValue( XsString( std::to_string( timeSignature->getTop() ) ) );
                        time->getTimeChoice()->getTimeSignature()->getBeatType()->setValue( XsString( std::to_string( timeSignature->getBottom() ) ) );
                    }
                    
                    
                    previousTimeSignature = std::move( timeSignature );
                    
                } // end measure loop
                
            } // end part loop
            
        } // end function addEmptyMeasures
        
        void addNoteToMeasure(
            const MxMeasure& mxMeasure,
            const INoteUP& lyreNote,
            int divisionsPerQuarterNote )
        {
            bool doShowAccidental = true; // note later parameterize
            auto notesChoice = makeMusicDataChoice();
            notesChoice->setChoice( MusicDataChoice::Choice::note );
            auto noteElement = notesChoice->getNote();
            noteElement->getNoteChoice()->setChoice( NoteChoice::Choice::normal );
            noteElement->setHasType( true );
            
            auto durtype = lyreNote->getDuration()->getDurBaseValue();
            auto ntype = NoteTypeValue::oneHundredTwentyEighth;
            if( durtype == Rational{ 16, 1 } )
            {
                ntype = NoteTypeValue::long_;
            }
            else if ( durtype == Rational{ 8, 1 } )
            {
                ntype = NoteTypeValue::breve;
            }
            else if ( durtype == Rational{ 4, 1 } )
            {
                ntype = NoteTypeValue::whole;
            }
            else if ( durtype == Rational{ 2, 1 } )
            {
                ntype = NoteTypeValue::half;
            }
            else if ( durtype == Rational{ 1, 1 } )
            {
                ntype = NoteTypeValue::quarter;
            }
            else if ( durtype == Rational{ 1, 2 } )
            {
                ntype = NoteTypeValue::eighth;
            }
            else if ( durtype == Rational{ 1, 4 } )
            {
                ntype = NoteTypeValue::sixteenth;
            }
            else if ( durtype == Rational{ 1, 8 } )
            {
                ntype = NoteTypeValue::thirtySecond;
            }
            else if ( durtype == Rational{ 1, 16 } )
            {
                ntype = NoteTypeValue::sixtyFourth;
            }
            else if ( durtype == Rational{ 1, 32 } )
            {
                ntype = NoteTypeValue::oneHundredTwentyEighth;
            }
            
            noteElement->getType()->setValue( ntype );
            
            mxMeasure->getMusicDataGroup()->addMusicDataChoice( notesChoice );
            auto note = noteElement->getNoteChoice()->getNormalNoteGroup();
            auto divisionsRational = Rational{ divisionsPerQuarterNote, 1 } * lyreNote->getDuration()->getValue();
            int divisions = divisionsRational.getNumerator() / divisionsRational.getDenominator();
            note->getDuration()->setValue( PositiveDivisionsValue{ static_cast<DecimalType>( divisions ) } );
            if( lyreNote->getIsRest() )
            {
                note->getFullNoteGroup()->getFullNoteTypeChoice()->setChoice( FullNoteTypeChoice::Choice::rest ); 
            }
            else
            {
                auto mxpitch = note->getFullNoteGroup()->getFullNoteTypeChoice()->getPitch();
                note->getFullNoteGroup()->getFullNoteTypeChoice()->setChoice( FullNoteTypeChoice::Choice::pitch );
                switch( lyreNote->getPitch()->getStepValue() )
                {
                    case 0:
                        mxpitch->getStep()->setValue( StepEnum:: c );
                        break;
                    case 1:
                        mxpitch->getStep()->setValue( StepEnum:: d );
                        break;
                    case 2:
                        mxpitch->getStep()->setValue( StepEnum:: e );
                        break;
                    case 3:
                        mxpitch->getStep()->setValue( StepEnum:: f );
                        break;
                    case 4:
                        mxpitch->getStep()->setValue( StepEnum:: g );
                        break;
                    case 5:
                        mxpitch->getStep()->setValue( StepEnum:: a );
                        break;
                    case 6:
                        mxpitch->getStep()->setValue( StepEnum:: b );
                        break;
                }
                mxpitch->getOctave()->setValue( OctaveValue{ lyreNote->getPitch()->getOctaveValue() } );
                mxpitch->setHasAlter( true );
                mxpitch->getAlter()->setValue( Semitones{ static_cast<DecimalType>( lyreNote->getPitch()->getAlterValue() ) } );
                if( doShowAccidental )
                {
                    noteElement->setHasAccidental( doShowAccidental );
                    if( lyreNote->getPitch()->getAlterValue() > 2 ||
                        lyreNote->getPitch()->getAlterValue() < -2 )
                    {
                        THROW( "accidentals beyond x and bb not supported by musicxml" );
                    }
                    AccidentalValue accidental = AccidentalValue::natural;
                    switch ( lyreNote->getPitch()->getAlterValue() )
                    {
                        case -2:
                            accidental = AccidentalValue::flatFlat;
                            break;
                        case -1:
                            accidental = AccidentalValue::flat;
                            break;
                        case 1:
                            accidental = AccidentalValue::sharp;
                            break;
                        case 2:
                            accidental = AccidentalValue::doubleSharp;
                            break;
                        default:
                            break;
                    }
                    noteElement->getAccidental()->setValue( accidental );
                }
            }
            
        } // end function addNotesToMeasure

    } // end namespace MxPrivate

} // end namespace Lyre
