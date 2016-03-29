#include "Lyre/IExporterFactory.h"
#include "Lyre/Private/MusicXmlExporterFactory.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    IExporterFactoryUP
    createExporterFactory( ExporterFactoryType t )
    {
        switch ( t )
        {
            case ExporterFactoryType::MusicXML:
                return IExporterFactoryUP{ new Private::MusicXmlExporterFactory{} };
                break;
                
            default:
                break;
        }
        THROW( "Unrecognized ExporterFactoryType" )
    }
}
