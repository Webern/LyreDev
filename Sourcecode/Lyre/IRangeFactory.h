//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IRange.h"

namespace Lyre
{
    enum class PUBLIC RangeFactoryType
    {
        Standard = 0
    };

    FORWARD_DECLARE(IRangeFactory)
    FORWARD_DECLARE(IBeatPattern)
    
    PUBLIC IRangeFactoryUP
        createRangeFactory(
            RangeFactoryType t = 
            RangeFactoryType::Standard );

    class PUBLIC IRangeFactory
    {
    public:
        virtual ~IRangeFactory() {}
        
        virtual IRangeUP create() const = 0;
        
        virtual IRangeUP create( int low, int high ) const = 0;
        
        virtual IRangeUP create(
            const IPitchUP& low,
            const IPitchUP& high ) const = 0;
        
        virtual IRangeUP create(
            const String& low,
            const String& high ) const = 0;


    };
}
