//PUBLIC
#pragma once


namespace Lyre
{
    template<typename T, typename... Args>
    inline std::unique_ptr<T> makeUnique( Args&&... args )
    {
        return std::unique_ptr<T>(new T(std::forward<Args>( args )... ) );
    }

}
