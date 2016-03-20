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

		T* const operator->()
		{
			return myPtr.get();
		}

		const T* const operator->() const
		{
			return myPtr.get();
		}

		T* const get()
		{
			return myPtr.get();
		}

		const T* const get() const
		{
			return myPtr.get();
		}

		operator bool() const
		{
			return myPtr != nullptr;
		}

	private:
		const std::unique_ptr<T>& myPtr;
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
        
        const T* const operator->() const
        {
            return myPtr;
        }

		operator bool() const
		{
			return myPtr != nullptr;
		}
        
    private:
        const T* myPtr;
    };


	template<typename T>
	class HandleConst<std::unique_ptr<T>>
	{
	public:
		HandleConst( const std::unique_ptr<T>& ptr )
			: myPtr( ptr )
		{}

		const T& operator*() const
		{
			return *myPtr;
		}

		const T* const operator->() const
		{
			return myPtr.get();
		}

		const T* const get() const
		{
			return myPtr.get();
		}

		operator bool() const
		{
			return myPtr != nullptr;
		}

	private:
		const std::unique_ptr<T>& myPtr;
	};
    
}
