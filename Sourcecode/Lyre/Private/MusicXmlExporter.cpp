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
            addEmptyMeasures( doc, myScore );

            for ( int p = 0; p < myScore->getMovement( 0 )->getPartCount(); ++ p )
            {
                auto part = myScore->getMovement( 0 )->getPart( p );
                auto mxPart = *( doc->getScorePartwise()->getPartwisePartSet().begin() + p );
                for ( int m = 0; m < part->getMeasureCount(); ++m )
                {
                    auto measure = part->getMeasure( m );
                    auto mxMeasure = *( mxPart->getPartwiseMeasureSet().begin() + m );
                    for( int n = 0; n < measure->getCount(); ++n )
                    {
                        auto note = measure->getNote( n );
                        addNoteToMeasure( mxMeasure, note, 93024 );
                    }
                }
            }
            
            doc->toStream( os );
            std::ofstream file( "/Volumes/Macintosh HD/Users/mjb/Desktop/out.xml" );
            doc->toStream( file );
        }
    }
}
