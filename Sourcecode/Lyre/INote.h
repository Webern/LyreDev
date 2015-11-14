//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include <memory>

namespace Lyre
{
    class INote;
    using INoteSP = std::shared_ptr<INote>;
    using INoteUP = std::unique_ptr<INote>;
    
    class IPitch;
    using IPitchSP = std::shared_ptr<IPitch>;
    using IPitchUP = std::unique_ptr<IPitch>;
    
    class IDur;
    using IDurSP = std::shared_ptr<IDur>;
    using IDurUP = std::unique_ptr<IDur>;
    
    class INote
    {
    public:
        virtual ~INote() = default;
        
        virtual IDurUP getDur() const =0;
        virtual IPitchUP getPitch() const =0;
        
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        virtual String toString() const;
    };
    
    /* this calls toStream... syntactic sugar */
    std::ostream& operator<<( std::ostream& os, const INote& object );
}