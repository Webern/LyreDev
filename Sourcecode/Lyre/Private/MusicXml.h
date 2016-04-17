//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IScore.h"
#include "Lyre/IPartSpec.h"

#include "Mx/DocumentPartwise.h"

using MxDoc = mx::d::DocumentPartwisePtr;

namespace Lyre
{
    namespace MxPrivate
    {
        
        MxDoc createDocument();
        void setTitle( const MxDoc& doc, const std::string& title );
        void setMovementTitle( const MxDoc& doc, const std::string& title );
        void setMovementNumber( const MxDoc& doc, int movementNumber );
        void setComposer( const MxDoc& doc, const std::string& composer  );
        void setCopyright( const MxDoc& doc, const std::string& copyright  );
        void setSoftware( const MxDoc& doc, const std::string& software );
        
        void setPartList(
            const MxDoc& doc,
            const VecIPartSpecUP& specs,
            const VecIPartGroupSpecUP& groups );
        
        void addParts(
            const MxDoc& doc,
            const VecIPartSpecUP& specs );

    }

}
