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
        : myPtr( ptr )
        {}
        
        T& operator*()
        {
            return *myPtr;
        }
        
        const T& operator*() const
        {
            return *myPtr;
        }
        
        T* operator->()
        {
            return myPtr;
        }
        
        T* const operator->() const
        {
            return *myPtr;
        }
        
        T* get()
        {
            return myPtr;
        }
        
        T* const get() const
        {
            return myPtr;
        }

		operator bool() const
		{
			return myPtr != nullptr;
		}
        
    private:
        T* myPtr;
    };


	template<typename T>
	class Handle<std::unique_ptr<T>>
	{
	public:
		Handle( const std::unique_ptr<T>& ptr )
			: myPtr( ptr.get() )
		{}

		T& operator*()
		{
			return *myPtr;
		}

		const T& operator*() const
		{
			return *myPtr;
		}

		T* operator->()
		{
			return myPtr;
		}

		T* const operator->() const
		{
			return myPtr;
		}

		T* get()
		{
			return myPtr;
		}

		T* const get() const
		{
			return myPtr;
		}

		operator bool() const
		{
			return myPtr != nullptr;
		}

	private:
		T* myPtr;
	};


    template<typename T>
    class HandleConst
    {
    public:
        HandleConst( T* ptr )
        : myPtr( ptr )
        {}
        
        HandleConst( Handle<T*> nonConstHandle )
        :myPtr( nonConstHandle.operator->() )
        {}
        
        const T& operator*() const
        {
            return *myPtr;
        }
        
        T* const operator->() const
        {
            return myPtr;
        }

		operator bool() const
		{
			return myPtr != nullptr;
		}
        
    private:
        T* myPtr;
    };


	template<typename T>
	class HandleConst<std::unique_ptr<T>>
	{
	public:
		HandleConst( const std::unique_ptr<T>& ptr )
			: myPtr( ptr.get() )
		{}

		const T& operator*() const
		{
			return *myPtr;
		}

		T* const operator->() const
		{
			return myPtr;
		}

		T* const get() const
		{
			return myPtr;
		}

		operator bool() const
		{
			return myPtr != nullptr;
		}

	private:
		T* myPtr;
	};
    
}
