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
            ITimeSignatureUP previousTimeSignature;
            auto movement = score->getMovement( 0 );
            for ( int p = 0; p < movement->getPartCount(); ++p )
            {
                auto part = movement->getPart( p );
                for ( int m = 0; m < part->getMeasureCount(); ++m )
                {
                    auto measure = part->getMeasure( m );
                    bool doAddTimeSignature = true;
                    auto timeSignature = measure->getTimeSignature();
                    
                    if( m != 0 )
                    {
                        doAddTimeSignature = !previousTimeSignature;
                        if( previousTimeSignature )
                        {
                            doAddTimeSignature =
                               ( timeSignature->getTop() != previousTimeSignature->getTop() )
                            || ( timeSignature->getBottom() != previousTimeSignature->getBottom() );
                        }
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
                        mx::utility::addTimeSignature( mxMeasure, timeSignature->getTop(), timeSignature->getBottom() );
                    }
                    mx::utility::addStaveCount( mxMeasure, part->getPartSpec()->getNumStaves() );
                    
                    // TODO - refactor - calculate divisions
                    
                    ints denominators;
                    denominators.push_back( 1 );
                    for( int staff = 0; staff < part->getPartSpec()->getNumStaves(); ++ staff )
                    {
                        part->setStaffContext( staff );
                        measure = part->getMeasure( m );
                        for( int layer = 0; layer < MAX_NUMBER_OF_LAYERS; ++layer )
                        {
                            measure->setLayerContext( layer );
                            for(int n = 0; n < measure->getCount(); ++ n )
                            {
                                auto currentNote = measure->getNote( n );
                                denominators.push_back( currentNote->getDuration()->getValue().getDenominator() );
                            }
                        }
                    }
                    measure->setLayerContext( 0 );
                    part->setStaffContext( 0 );
                    measure = part->getMeasure( m );
                    
                    int divisionsPerQuarter = Rational::lcm( denominators );
                    mx::utility::addDivisions( mxMeasure, divisionsPerQuarter );
                    // END - refactor - calculate divisions
                    
                    previousTimeSignature = std::move( timeSignature );
                    
                } // end measure loop
                
            } // end part loop
            
        } // end function addEmptyMeasures
        
        void addNoteToMeasure(
            const MxMeasure& mxMeasure,
            const INoteUP& lyreNote,
            int divisions,
            int voice,
            int staff )
        {
            mx::utility::NoteParams params;
            params.showAccidental = true; // TODO fix this with logic
            params.step = lyreNote->getPitch()->getStepValue();
            params.octave = lyreNote->getPitch()->getOctaveValue();
            params.alter = lyreNote->getPitch()->getAlterValue();
            params.durationDots = lyreNote->getDuration()->getDotCount();
            params.durationType = convertLyreDurBaseToMxNoteType( lyreNote->getDuration()->getDurBaseValue() );
            params.duration = divisions;
            params.isRest = lyreNote->getIsRest();
            params.voiceNumber = voice;
            params.staffNumber = staff;
            auto mdc = mx::utility::createNote( params );
            mxMeasure->getMusicDataGroup()->addMusicDataChoice( mdc );
            
        } // end function addNoteToMeasure
        
        
        mx::t::NoteTypeValue convertLyreDurBaseToMxNoteType( const Rational& durBaseValue )
        {
            auto ntype = NoteTypeValue::oneHundredTwentyEighth;
            if( durBaseValue == VAL_LONGA )
            {
                ntype = NoteTypeValue::long_;
            }
            else if ( durBaseValue == VAL_BREVE )
            {
                ntype = NoteTypeValue::breve;
            }
            else if ( durBaseValue == VAL_WHOLE )
            {
                ntype = NoteTypeValue::whole;
            }
            else if ( durBaseValue == VAL_HALF )
            {
                ntype = NoteTypeValue::half;
            }
            else if ( durBaseValue == VAL_QUARTER )
            {
                ntype = NoteTypeValue::quarter;
            }
            else if ( durBaseValue == VAL_EIGHTH )
            {
                ntype = NoteTypeValue::eighth;
            }
            else if ( durBaseValue == VAL_16TH )
            {
                ntype = NoteTypeValue::sixteenth;
            }
            else if ( durBaseValue == VAL_32ND )
            {
                ntype = NoteTypeValue::thirtySecond;
            }
            else if ( durBaseValue == VAL_64TH )
            {
                ntype = NoteTypeValue::sixtyFourth;
            }
            else if ( durBaseValue == VAL_128TH )
            {
                ntype = NoteTypeValue::oneHundredTwentyEighth;
            }
            return ntype;
        }

    } // end namespace MxPrivate

} // end namespace Lyre
