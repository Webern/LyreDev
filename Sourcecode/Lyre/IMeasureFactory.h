//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMeasure.h"
#include "Lyre/ITimeSignature.h"

namespace Lyre
{
    enum class PUBLIC MeasureFactoryType
    {
        Standard = 0
    };

    FORWARD_DECLARE(IMeasureFactory)
    FORWARD_DECLARE(IBeatPattern)
    
    PUBLIC IMeasureFactoryUP
        createMeasureFactory(
            MeasureFactoryType t = 
            MeasureFactoryType::Standard );

    class PUBLIC IMeasureFactory
    {
    public:
        virtual ~IMeasureFactory() {}
        virtual IMeasureUP create() const = 0;
        virtual IMeasureUP create( int timeSignatureTop, int timeSignatureBottom ) const = 0;
        virtual IMeasureUP create( const ITimeSignatureUP& timeSignature ) const = 0;
    };
}
