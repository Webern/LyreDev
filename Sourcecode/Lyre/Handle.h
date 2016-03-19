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
        Handle( T object )
        :myObject( object )
        {}
        
        T& operator*()
        {
            return myObject;
        }
        
        T& operator*() const
        {
            return myObject;
        }
        
        T& operator->()
        {
            return myObject;
        }
        
        const T& operator->() const
        {
            return myObject;
        }
        
    private:
        T myObject;
    };
    
    template<typename T>
    class Handle<T*>
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
        
        T& operator->()
        {
            return *myPtr;
        }
        
        const T& operator->() const
        {
            return *myPtr;
        }
        
    private:
        T* myPtr;
    };
 
}
