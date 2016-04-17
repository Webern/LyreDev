#include "Lyre/Private/MusicXmlExporter.h"
#include "Lyre/Private/throw.h"
#include "Lyre/Private/MusicXml.h"

#include "Mx/DocumentPartwise.h"
#include <fstream>

using namespace mx;
using namespace mx::d;
using namespace mx::e;
using namespace mx::t;
using namespace Lyre::MxPrivate;

namespace Lyre
{
    namespace Private
    {
        MusicXmlExporter::~MusicXmlExporter()
        {
            
        }

        
        MusicXmlExporter::MusicXmlExporter( IScoreH score )
        : myScore( score )
        {
            
        }

        
        void MusicXmlExporter::exportMusic( std::ostream& os )
        {
            auto doc = createDocument();
            auto spec = myScore->getSpec();
            setTitle( doc, spec->getTitle() );
            setMovementTitle( doc, spec->getTitle() );
            setMovementNumber( doc, 1 );
            setCopyright( doc, spec->getCopyright() );
            setComposer( doc, spec->getComposer() );
            setSoftware( doc, "Lyre" );
            auto partSpecs = myScore->getSpec()->getPartSpecs();
            auto partGroupSpecs = myScore->getSpec()->getPartGroupSpecs();
            setPartList( doc, partSpecs, partGroupSpecs );
            addParts( doc, partSpecs );
            doc->toStream( os );
            std::ofstream file( "/Volumes/Macintosh HD/Users/mjb/Desktop/out.xml" );
            doc->toStream( file );
        }
    }
}
