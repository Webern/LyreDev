//PUBLIC
#include "LyreTest/cpul/cpulTestHarness.h"
#include "Lyre/Lyre.h"
#include "Lyre/IMeasureFactory.h"
#include "Lyre/IMeasure.h"
#include "Lyre/ITimeSignatureFactory.h"
#include "Lyre/INoteFactory.h"
#include "Lyre/IPitchFactory.h"
#include "Lyre/IDurationFactory.h"

#include <sstream>

using namespace Lyre;
using namespace std;

namespace
{
	static IMeasureFactoryUP factory =
	createMeasureFactory();

    struct Factories
    {
        IMeasureFactoryUP measureFactory;
        ITimeSignatureFactoryUP timeSignatureFactory;
        INoteFactoryUP noteFactory;
        IPitchFactoryUP pitchFactory;
        IDurationFactoryUP durationFactory;

        Factories()
            :measureFactory( createMeasureFactory() )
            ,timeSignatureFactory( createTimeSignatureFactory() )
            ,noteFactory( createNoteFactory() )
            ,pitchFactory( createPitchFactory() )
            ,durationFactory( createDurationFactory() )
        {}

        inline IMeasureUP defaultMeasure()
        {
            return measureFactory->create();
        }

        inline IMeasureUP fourFour()
        {
            return measureFactory->create( 4, 4 );
        }

        inline IMeasureUP threeFour()
        {
            auto timeSig = timeSignatureFactory->create( 3, 4 );
            return measureFactory->create( timeSig );
        }

        inline IMeasureUP sevenEight()
        {
            auto timeSig = timeSignatureFactory->create( 7, 8 );
            return measureFactory->create( timeSig );
        }

    };
}

TEST( getTimeSignature_default, Measure )
{
    Factories f;
    IMeasureUP measure = f.defaultMeasure();
    ITimeSignatureUP timeSig = measure->getTimeSignature();
    CHECK_EQUAL( 4, timeSig->getTop() )
    CHECK_EQUAL( 4, timeSig->getBottom() )
}
T_END

TEST( getTimeSignature_fourFour, Measure )
{
    Factories f;
    IMeasureUP measure = f.defaultMeasure();
    ITimeSignatureUP timeSig = measure->getTimeSignature();
    CHECK_EQUAL( 4, timeSig->getTop() )
    CHECK_EQUAL( 4, timeSig->getBottom() )
}
T_END

TEST( getTimeSignature_threeFour, Measure )
{
    Factories f;
    IMeasureUP measure = f.threeFour();
    ITimeSignatureUP timeSig = measure->getTimeSignature();
    CHECK_EQUAL( 3, timeSig->getTop() )
    CHECK_EQUAL( 4, timeSig->getBottom() )
}
T_END

TEST( getTimeSignature_sevenEight, Measure )
{
    Factories f;
    IMeasureUP measure = f.sevenEight();
    ITimeSignatureUP timeSig = measure->getTimeSignature();
    CHECK_EQUAL( 7, timeSig->getTop() )
    CHECK_EQUAL( 8, timeSig->getBottom() )
}
T_END

TEST( toStream, Measure )
{
    IMeasureUP ts = factory->create();
    std::stringstream ss;
    ts->toStream( ss );
    String expected = "Measure not implemented";
    String actual = ss.str();
    CHECK_EQUAL( expected, actual )
}
T_END
