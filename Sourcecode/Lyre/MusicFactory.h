//PUBLIC
#pragma once
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDurBaseFactory.h"
#include "Lyre/IDurDotFactory.h"
#include "Lyre/IExporterFactory.h"
#include "Lyre/IInstrumentFactory.h"
#include "Lyre/IMasterTrackFactory.h"
#include "Lyre/IMeasureFactory.h"
#include "Lyre/IMovementFactory.h"
#include "Lyre/IMovementSpecFactory.h"
#include "Lyre/INoteFactory.h"
#include "Lyre/IPartFactory.h"
#include "Lyre/IPartGroupSpecFactory.h"
#include "Lyre/IPartSpecFactory.h"
#include "Lyre/IPitchFactory.h"
#include "Lyre/IRangeFactory.h"
#include "Lyre/IScoreFactory.h"
#include "Lyre/IScoreSpecFactory.h"
#include "Lyre/ITimeSignatureFactory.h"
#include "Lyre/ITupletDefFactory.h"
#include "Lyre/Lyre.h"

namespace Lyre
{
    FORWARD_DECLARE(IMusicFactory)
    
    struct PUBLIC MusicFactory
    {
    public:
        MusicFactory();
        IBeatPatternFactoryUPC beatPatternFactory;
		IDurationFactoryUPC durationFactory;
		IDurBaseFactoryUPC durBaseFactory;
		IDurDotFactoryUPC durDotFactory;
		IExporterFactoryUPC exporterFactory;
		IInstrumentFactoryUPC instrumentFactory;
		IMasterTrackFactoryUPC masterTrackFactory;
		IMeasureFactoryUPC measureFactory;
		IMovementFactoryUPC movementFactory;
		IMovementSpecFactoryUPC movementSpecFactory;
		INoteFactoryUPC noteFactory;
		IPartFactoryUPC partFactory;
		IPartSpecFactoryUPC partSpecFactory;
		IPartGroupSpecFactoryUPC partGroupSpecFactory;
		IPitchFactoryUPC pitchFactory;
		IRangeFactoryUPC rangeFactory;
		IScoreFactoryUPC scoreFactory;
		IScoreSpecFactoryUPC scoreSpecFactory;
		ITimeSignatureFactoryUPC timeSignatureFactory;
		ITupletDefFactoryUPC tupletDefFactory;

    };
}
