#include "Lyre/Private/MusicXmlExporter.h"
#include "Lyre/Private/throw.h"

#include "Mx/DocumentPartwise.h"

using namespace mx;
using namespace mx::d;
using namespace mx::e;
using namespace mx::t;

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
            auto doc = makeDocumentPartwise();
            auto score = makeScorePartwise();
            doc->setScorePartwise( score );
            
            score->getAttributes()->version = XsToken{ "3.0" };
            auto header = score->getScoreHeaderGroup();
            header->setHasWork( true );
            header->getWork()->setHasWorkTitle( true );
            header->getWork()->getWorkTitle()->setValue( XsString( myScore->getSpec()->getTitle() ) );
            header->setHasIdentification( true );
            header->setHasMovementTitle( true );
            header->getMovementTitle()->setValue( XsString( myScore->getSpec()->getTitle() ) );
            header->setHasMovementNumber( true );
            header->getMovementNumber()->setValue( XsString( "1" ) );
            
            
            
            auto identification = header->getIdentification();
            auto composerCreator = makeCreator();
            composerCreator->getAttributes()->type = XsToken( "composer" );
            composerCreator->setValue( XsString( myScore->getSpec()->getComposer() ) );
            identification->addCreator( composerCreator );
            
            identification->setHasEncoding( true );
            identification->getEncoding()->setChoice( Encoding::Choice::software );
            identification->getEncoding()->getSoftware()->setValue( XsString( "Lyre" ) );
            
            auto copyright = makeRights();
            copyright->getAttributes()->type = XsToken( "copyright" );
            copyright->getAttributes()->hasType = true;
            copyright->setValue( XsString( myScore->getSpec()->getCopyright() ) );
            identification->addRights( copyright );
            
            doc->toStream( os );
        }
    }
}
