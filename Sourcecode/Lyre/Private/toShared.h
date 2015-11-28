//PRIVATE
#pragma once
#include <memory>

namespace Lyre
{
    namespace Private
    {
        template <typename T>
        std::shared_ptr<T> toShared( std::unique_ptr<T>& uniquePtr )
        {
            auto rawP = uniquePtr.get();
            uniquePtr.release();
            uniquePtr == nullptr;
            return std::shared_ptr<T>{ rawP };
        }
    }
}
