//PRIVATE
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/MusicFactory.h"
#include "Lyre/Lmx/LmxDivisions.h"
#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
    IMeasureUP createSomeMeasure()
    {
        MusicFactory f;
        auto dur = f.durationFactory->createDuration( STR_EIGHTH, 1 );
        auto pitch = f.pitchFactory->createPitch( 37 );
        auto note = f.noteFactory->createNote( pitch, dur );
        auto measure = f.measureFactory->create( 2, 4 );
        measure->addNote( note );
        dur = f.durationFactory->createDuration( STR_16TH );
        note = f.noteFactory->createNote( pitch, dur );
        measure->addNote( note );
        auto tupdef = f.tupletDefFactory->createTupletDef( 5, 4, STR_16TH );
        dur = f.durationFactory->createDuration( tupdef, STR_16TH, 0 );
        note= f.noteFactory->createNote( pitch, dur );
        for ( int i = 0; i < 5; ++i )
        {
            measure->addNote( note );
        }
        return measure;
    }
    
    void addNotesToLayer( const IMeasureUP& measure, const IDurationUP& dur, int layer )
    {
        MusicFactory f;
        int rememberContext = measure->getLayerContext();
        measure->setLayerContext( layer );
        auto note = f.noteFactory->createNote( f.pitchFactory->createPitch( 50 ), dur );
        while ( ! measure->getIsComplete() )
        {
            measure->addNote( note );
        }
        measure->setLayerContext( rememberContext );
    }
}

TEST( findLcmDurDenominatorInCurrentLayer, LmxDivisions )
{
    auto measure = createSomeMeasure();
    int expected = 20;
    int actual = Lmx::findLcmDurDenominatorInCurrentLayer( measure );
    CHECK_EQUAL( expected, actual )
}
T_END


TEST( findLcmDurDenominatorInCurrentLayerDifferentLayer, LmxDivisions )
{
    auto measure = createSomeMeasure();
    measure->setLayerContext( 1 );
    int expected = 1;
    int actual = Lmx::findLcmDurDenominatorInCurrentLayer( measure );
    CHECK_EQUAL( expected, actual )
}
T_END


TEST( findLcmDurDenominatorInAllLayers, LmxDivisions )
{
    auto measure = createSomeMeasure();
    MusicFactory f;
    auto tupdef = f.tupletDefFactory->createTupletDef( 7, 4, STR_16TH );
    addNotesToLayer( measure, f.durationFactory->createDuration( tupdef, STR_16TH, 0 ), 1 );
    measure->setLayerContext( MAX_NUMBER_OF_LAYERS - 1 );
    int expected = 140;
    int actual = Lmx::findLcmDurDenominatorInAllLayers( measure );
    CHECK_EQUAL( expected, actual )
    CHECK_EQUAL( MAX_NUMBER_OF_LAYERS - 1, measure->getLayerContext() );
}
T_END
