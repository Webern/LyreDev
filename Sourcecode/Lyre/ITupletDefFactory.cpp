#include "Lyre/ITupletDefFactory.h"
#include "Lyre/Private/TupletDefFatory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    ITupletDefFactoryUP createTupletDefFactory( const TupletDefFactoryType  t )
    {
        switch ( t )
        {
            case TupletDefFactoryType::Standard:
                return ITupletDefFactoryUP{ new Private::TupletDefFactory{} };
                break;
            default:
                break;
        }
		THROW( "Unsupported TupletDefFactoryType" )
    }
}
