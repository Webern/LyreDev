#include "Lyre/MusicFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    MusicFactory::MusicFactory()
    : beatPatternFactory( createBeatPatternFactory() )
    , durationFactory( createDurationFactory() )
    , durBaseFactory( createDurBaseFactory() )
    , durDotFactory( createDurDotFactory() )
    , exporterFactory( createExporterFactory() )
    , instrumentFactory( createInstrumentFactory() )
    , masterTrackFactory( createMasterTrackFactory() )
    , measureFactory( createMeasureFactory() )
    , movementFactory( createMovementFactory() )
    , movementSpecFactory( createMovementSpecFactory() )
    , noteFactory( createNoteFactory() )
    , partFactory( createPartFactory() )
    , partSpecFactory( createPartSpecFactory() )
    , partGroupSpecFactory( createPartGroupSpecFactory() )
    , pitchFactory( createPitchFactory() )
    , rangeFactory( createRangeFactory() )
    , scoreFactory( createScoreFactory() )
    , scoreSpecFactory( createScoreSpecFactory() )
    , timeSignatureFactory( createTimeSignatureFactory() )
    , tupletDefFactory( createTupletDefFactory() )
    {
        
    }
}
