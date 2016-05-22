#include "Lyre/Lmx/LmxDivisions.h"
#include "Lyre/Private/throw.h"
#include "Lyre/IPartSpec.h"

namespace Lyre
{
    namespace Lmx
    {
        int findLcmDurDenominatorInCurrentLayer( const IMeasureH& measure )
        {
            std::vector<int> denominators;
            denominators.push_back( 1 );
            for ( int i = 0; i < measure->getCount(); ++i )
            {
                denominators.push_back( measure->getNote( i )->getDuration()->getValue().getDenominator() );
            }
            int denomLcm = Rational::lcm( denominators );
            return denomLcm;
        }
        
        
        int findLcmDurDenominatorInAllLayers( const IMeasureH& measure )
        {
            int rememberLayerContext = measure->getLayerContext();
            std::vector<int> lcms;
            lcms.push_back( 1 );
            for ( int i = 0; i < MAX_NUMBER_OF_LAYERS; ++i )
            {
                measure->setLayerContext( i );
                lcms.push_back( findLcmDurDenominatorInCurrentLayer( measure ) );
            }
            measure->setLayerContext( rememberLayerContext );
            int returnLcm = Rational::lcm( lcms );
            return returnLcm;
        }
        
        
        int findLcmDurDenominatorForAllPartStavesInOneMeasure(
            const IPartH& part,
            int measureIndex )
        {
            std::vector<int> lcms;
            int rememberStaffContext = part->getStaffContext();
            for ( int i = 0; i < part->getPartSpec()->getNumStaves(); ++i )
            {
                part->setStaffContext( i );
                auto measure = part->getMeasure( measureIndex );
                lcms.push_back( findLcmDurDenominatorInAllLayers( measure ) );
            }
            part->setStaffContext( rememberStaffContext );
            int returnLcm = Rational::lcm( lcms );
            return returnLcm;
        }
    }
}
