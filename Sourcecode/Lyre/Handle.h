//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include <memory>

namespace Lyre
{
    template<typename T>
    class Handle
    {
    public:
        Handle( T* ptr )
        :myPtr( ptr )
        {}
        
        T& operator*()
        {
            return *myPtr;
        }
        
        const T& operator*() const
        {
            return *myPtr;
        }
        
        T* const operator->()
        {
            return myPtr;
        }
        
        const T* const operator->() const
        {
            return *myPtr;
        }
        
        T* const get()
        {
            return myPtr;
        }
        
        const T* const get() const
        {
            return myPtr;
        }
        
    private:
        T* myPtr;
    };
    
    template<typename T>
    class HandleConst
    {
    public:
        HandleConst( T* ptr )
        :myPtr( ptr )
        {}
        
        HandleConst( Handle<T*> nonConstHandle )
        :myPtr( nonConstHandle.operator->() )
        {}
        
        const T& operator*() const
        {
            return *myPtr;
        }
        
        const T* const operator->() const
        {
            return myPtr;
        }
        
    private:
        const T* myPtr;
    };
    
}
