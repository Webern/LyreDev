#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>

namespace music
{
    class PartProperties;
    using PartPropertiesPtr = std::shared_ptr<PartProperties>;
    using PartPropertiesUPtr = std::unique_ptr<PartProperties>;
    using PartPropertiesSet = std::vector<PartPropertiesPtr>;
    using PartPropertiesSetIter = PartPropertiesSet::iterator;
    using PartPropertiesSetIterConst = PartPropertiesSet::const_iterator;
    inline PartPropertiesPtr makePartProperties() { return std::make_shared<PartProperties>(); }
    
    class PartProperties
    {
    public:
        PartGroupPtr getPartGroup() const;
        void setPartGroup( const PartGroupPtr& value ) const;
        InstrumentPtr getInstrument() const;
        void setInstrument( const InstrumentPtr& value );
        
    private:
        
    };
}