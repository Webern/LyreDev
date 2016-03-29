//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IExporter.h"
#include "Lyre/IScore.h"

namespace Lyre
{
    enum class PUBLIC ExporterFactoryType
    {
        MusicXML = 0
    };

    FORWARD_DECLARE(IExporterFactory)
    
    PUBLIC IExporterFactoryUP
        createExporterFactory(
            ExporterFactoryType t = 
            ExporterFactoryType::MusicXML );

    class PUBLIC IExporterFactory
    {
    public:
        virtual ~IExporterFactory() {}
        
        virtual IExporterUP create( IScoreH score ) const = 0;

    };
}
