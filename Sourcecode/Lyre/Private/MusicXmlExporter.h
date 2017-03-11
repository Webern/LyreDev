//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IExporter.h"
#include "Lyre/IScore.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(MusicXmlExporter)
        
        class MusicXmlExporter : public IExporter
        {
        public:
            virtual ~MusicXmlExporter();
            
            MusicXmlExporter( IScoreH score );
            
            
            void exportMusic( std::ostream& os );
            
        private:
            IScoreH myScore;
            
            // not implemented
            MusicXmlExporter( const MusicXmlExporter& other );
            MusicXmlExporter& operator=( const MusicXmlExporter& other );
            
        };
    } 
}
