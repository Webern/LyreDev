#include "Lyre/Private/Part.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"
#include "Lyre/Private/throw.h"
#include "Lyre/IInstrument.h"
#include "Lyre/Private/Instrument.h"
#include "Lyre/Private/Range.h"
#include "Lyre/Private/Measure.h"

namespace Lyre
{
	namespace Private
	{

		Part::~Part()
		{

		}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		void Part::initializeMeasures()
		{
			for ( int i = 0; i < myNumStaves; ++i )
			{
				myStaves.push_back( std::move( myMasterTrack->createMeasures() ) );
			}
		}
    }
}
