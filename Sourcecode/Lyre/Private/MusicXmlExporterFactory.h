//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IExporterFactory.h"
#include "Lyre/IExporter.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(MusicXmlExporterFactory)
        
        class MusicXmlExporterFactory : public IExporterFactory
        {
        public:
            virtual ~MusicXmlExporterFactory();
            
            virtual IExporterUP create( IScoreH score ) const;
        };
    }
}
