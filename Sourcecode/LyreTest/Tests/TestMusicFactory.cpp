//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/MusicFactory.h"
#include <sstream>

using namespace Lyre;
using namespace std;


TEST( compiles, MusicFactory )
{
    MusicFactory f;
    CHECK( f.beatPatternFactory != nullptr );
    CHECK( f.durationFactory != nullptr );
    CHECK( f.durBaseFactory != nullptr );
    CHECK( f.durDotFactory != nullptr );
    CHECK( f.exporterFactory != nullptr );
    CHECK( f.instrumentFactory != nullptr );
    CHECK( f.masterTrackFactory != nullptr );
    CHECK( f.measureFactory != nullptr );
    CHECK( f.movementFactory != nullptr );
    CHECK( f.movementSpecFactory != nullptr );
    CHECK( f.noteFactory != nullptr );
    CHECK( f.partFactory != nullptr );
    CHECK( f.partSpecFactory != nullptr );
    CHECK( f.pitchFactory != nullptr );
    CHECK( f.rangeFactory != nullptr );
    CHECK( f.scoreFactory != nullptr );
    CHECK( f.scoreSpecFactory != nullptr );
    CHECK( f.timeSignatureFactory != nullptr );
    CHECK( f.tupletDefFactory != nullptr );
}
T_END
