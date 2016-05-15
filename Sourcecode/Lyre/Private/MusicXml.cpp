#include "Lyre/Private/MusicXml.h"
#include "Lyre/Lyre.h"
#include "Lyre/Private/throw.h"
#include "Mx/Elements.h"
#include "Mx/Utility.h"

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
            mx::utility::setTitle( doc, title );
        }
        
        
        void setMovementTitle( const MxDoc& doc, const std::string& title )
        {
            mx::utility::setMovementTitle( doc, title );
        }
        
        
        void setMovementNumber( const MxDoc& doc, int movementNumber )
        {
            mx::utility::setMovementNumber( doc, movementNumber );
        }
        
        
        void setComposer( const MxDoc& doc, const std::string& composer )
        {
            mx::utility::setComposer( doc, composer );
        }
        
        
        void setCopyright( const MxDoc& doc, const std::string& copyright )
        {
            mx::utility::setCopyright( doc, copyright );
        }
        
        
        void setSoftware( const MxDoc& doc, const std::string& software )
        {
            mx::utility::setSoftware( doc, software );
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
                    mx::utility::PartGroupParams pgParams;
                    pgParams.number = groupIndex + 1;
                    pgParams.name = (*groupIter)->getName();
                    pgParams.abbreviation = (*groupIter)->getShortName();
                    mx::utility::startPartGroup( doc, pgParams );
                }
                
                mx::utility::PartParams pParams;
                pParams.name = (*partIter)->getName();
                pParams.uniqueId = (*partIter)->getUniqueId();
                pParams.abbreviation = (*partIter)->getInstrument()->getShortName();
                pParams.instrumentUniqueId = (*partIter)->getUniqueId() + StringType( "_INSTR" );
                pParams.instrumentName = (*partIter)->getInstrument()->getName();
                pParams.instrumentAbbreviation = (*partIter)->getInstrument()->getShortName();
                mx::utility::addPart( doc, pParams );
                
                
                if ( isGroupEnd )
                {
                    mx::utility::stopPartGroup( doc, groupIndex + 1 );
                    ++groupIter;
                    ++groupIndex;
                }
            }
        }
        
        
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
            for( int i = 0; i < lyreNote->getDuration()->getDotCount(); ++i )
            {
                noteElement->addDot( makeDot() );
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
