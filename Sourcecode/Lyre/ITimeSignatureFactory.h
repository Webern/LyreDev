//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/ITimeSignature.h"

namespace Lyre
{
    enum class PUBLIC TimeSignatureFactoryType
    {
        Standard = 0
    };

    FORWARD_DECLARE(ITimeSignatureFactory)
    FORWARD_DECLARE(IBeatPattern)
    
    PUBLIC ITimeSignatureFactoryUP
        createTimeSignatureFactory(
            TimeSignatureFactoryType t = 
            TimeSignatureFactoryType::Standard );

    class PUBLIC ITimeSignatureFactory
    {
    public:
        virtual ~ITimeSignatureFactory() {}
        virtual ITimeSignatureUP create( int top, int bottom ) = 0;
        
        virtual ITimeSignatureUP create(
            const IBeatPatternUP& beatPattern,
            int top,
            int bottom ) = 0;
    };
}
