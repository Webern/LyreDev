//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IPartSpec.h"
#include "Lyre/IPartGroupSpec.h"

namespace Lyre
{
    FORWARD_DECLARE(IScoreSpec)
    
    class PUBLIC IScoreSpec : public IStreamable
    {
    public:
        virtual ~IScoreSpec() {};
        virtual IScoreSpecUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
		virtual String getTitle() const = 0;
		virtual String getComposer() const = 0;
		virtual String getCopyright() const = 0;
		virtual String getStartDate() const = 0;
		virtual String getCompletionDate() const = 0;
        virtual VecIPartSpecUP getPartSpecs() const = 0;
        virtual VecIPartGroupSpecUP getPartGroupSpecs() const = 0;
        
		virtual void setTitle( const String& value ) = 0;
		virtual void setComposer( const String& value ) = 0;
		virtual void setCopyright( const String& value ) = 0;
		virtual void setStartDate( const String& value ) = 0;
		virtual void setCompletionDate( const String& value ) = 0;
        virtual void setPartSpecs( const VecIPartSpecUP& parts ) = 0;
        virtual void setPartGroupSpecs( const VecIPartGroupSpecUP& partGroups ) = 0;
    };
}
