// PRIVATE
#include "Lyre/Lyre.h"
#include "Lyre/IMeasure.h"
#include "Lyre/IPart.h"

namespace Lyre
{
    namespace Lmx
    {
        int findLcmDurDenominatorInCurrentLayer( const IMeasureH& measure );
        int findLcmDurDenominatorInAllLayers( const IMeasureH& measure );
        int findLcmDurDenominatorForAllPartStavesInOneMeasure(
            const IPartH& part,
            int measureIndex );
    }
}
