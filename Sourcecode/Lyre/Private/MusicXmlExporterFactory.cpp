#include "Lyre/Private/MusicXmlExporterFactory.h"
#include "Lyre/IExporter.h"
#include "Lyre/Private/MusicXmlExporter.h"


namespace Lyre
{
    namespace Private
    {
        MusicXmlExporterFactory::~MusicXmlExporterFactory() {}
        
        IExporterUP MusicXmlExporterFactory::create( IScoreH score ) const
        {
            return IExporterUP{ new MusicXmlExporter{ score } };
        }
    }
}
