#include "Lyre/Private/Part.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"
#include "Lyre/Private/throw.h"
#include "Lyre/IInstrument.h"
#include "Lyre/Private/Instrument.h"
#include "Lyre/Private/Range.h"

namespace Lyre
{
    namespace Private
    {

        Part::~Part()
        {
            
        }

        Part::Part(
                int numStaves,
                const IInstrumentUP& instrument,
                const IMasterTrackSPC& masterTrack )
        : myNumStaves( 1 )
        , myInstrument( nullptr )
        , myMasterTrack( nullptr )
        , myStaves()
        , myCurrentStaffIndex( 0 )
        , myCurrentStaff()
        , myCurrentMeasureIndex( 0 )
        , myCurrentMeasure()
        {
            THROW_IF_BAD_VALUE( numStaves, 0, INT_MAX )
            myNumStaves = numStaves;
            THROW_IF_NULL( instrument )
            myInstrument = instrument->clone();
            THROW_IF_NULL( masterTrack )
            myMasterTrack = masterTrack;
            initializeMeasures();
            myCurrentStaff = myStaves.begin();
            myCurrentMeasure = myCurrentStaff->begin();
        }

        
        

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    }
}
