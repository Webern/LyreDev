//PRIVATE
#pragma once
#include "Lyre/Private/makeUnique.h"

namespace Lyre
{
    namespace Private
    {
        template <typename T>
        void copyTo( const T* const input, std::unique_ptr<T>& output )
        {
            if ( input == nullptr )
            {
                throw std::runtime_error( "copyTo received a nullptr as input" );
            }
            auto tempUP = input->clone();
            auto rawP = tempUP.get();
            tempUP.release();
            auto castedP = static_cast<T*>( rawP );
            output = std::unique_ptr<T>{ castedP };
        }
    }
}
