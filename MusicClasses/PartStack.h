#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>

namespace music
{
    class PartStack;
    using PartStackPtr = std::shared_ptr<PartStack>;
    using PartStackUPtr = std::unique_ptr<PartStack>;
    using PartStackSet = std::vector<PartStackPtr>;
    using PartStackSetIter = PartStackSet::iterator;
    using PartStackSetIterConst = PartStackSet::const_iterator;
    inline PartStackPtr makePartStack() { return std::make_shared<PartStack>(); }
    
    class PartGroup;
    using PartGroupPtr = std::shared_ptr<PartGroup>;
    using PartGroupUPtr = std::unique_ptr<PartGroup>;
    using PartGroupSet = std::vector<PartGroupPtr>;
    using PartGroupSetIter = PartGroupSet::iterator;
    using PartGroupSetIterConst = PartGroupSet::const_iterator;
    
    class PartProperties;
    using PartPropertiesPtr = std::shared_ptr<PartProperties>;
    using PartPropertiesUPtr = std::unique_ptr<PartProperties>;
    using PartPropertiesSet = std::vector<PartPropertiesPtr>;
    using PartPropertiesSetIter = PartPropertiesSet::iterator;
    using PartPropertiesSetIterConst = PartPropertiesSet::const_iterator;
    
    class Part;
    using PartPtr = std::shared_ptr<Part>;
    using PartUPtr = std::unique_ptr<Part>;
    using PartSet = std::vector<PartPtr>;
    using PartSetIter = PartSet::iterator;
    using PartSetIterConst = PartSet::const_iterator;
    
    class PartStack
    {
    public:
        ~PartStack() = default;
        
        void addPartGroup( const PartGroupPtr& value );
        void removePartGroup( const PartGroupSetIter& iter );
        void clearPartGroupSet();
        const PartGroupSet& getPartGroupSet() const;
        
        void addPart( const PartPtr& value );
        void removePart( const PartSetIter& iter );
        void clearPartSet();
        const PartSet& getPartSet() const;
        
        PartStackPtr clone() const;
        
    private:
        PartGroupSet myPartGroupSet;
        PartSet myPartSet;
    };
}