//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        // I am a jedi
        
        template <typename TYPE>
        class Copier
        {
        public:
            static TYPE copy( const TYPE& item )
            {
                return item;
            }
        };
        
        template <typename TYPE>
        class Copier<std::unique_ptr<TYPE>>
        {
        public:
            static std::unique_ptr<TYPE> copy( const std::unique_ptr<TYPE>& item )
            {
                THROW_IF_NULL( item )
                return std::move( item->clone() );
            }
        };
        
        template <typename TYPE>
        class Copier<std::shared_ptr<TYPE>>
        {
        public:
            static std::shared_ptr<TYPE> copy( const std::shared_ptr<TYPE>& item )
            {
                THROW_IF_NULL( item )
                return item;
            }
        };
        
        template <typename TYPE>
        class EXPORT_FOR_TESTS Collection
        {
        private:
            using T_VEC = std::vector<TYPE>;
            T_VEC myItems;
            Integer myCurrent;
            bool myIsEnd;
            
        public:
            virtual ~Collection() {}
            
            Collection()
            :myItems()
            ,myCurrent( 0 )
            ,myIsEnd( true )
            {}
            
            Collection( const T_VEC& items )
            :myItems()
            ,myCurrent( 0 )
            ,myIsEnd( true )
            {
                loadItems( items );
            }
            
            Collection( T_VEC&& items )
            :myItems( std::move( items ) )
            ,myCurrent( 0 )
            ,myIsEnd( false )
            {
                if ( getCount() == 0 )
                {
                    myIsEnd = true;
                }
            }
            
            Collection( const Collection& other )
            :myItems()
            ,myCurrent( other.myCurrent )
            ,myIsEnd( other.myIsEnd )
            {
                loadItems( other.myItems );
            }
            
            Collection( Collection&& other ) noexcept
            :myItems( std::move( other.myItems ) )
            ,myCurrent( std::move( other.myCurrent ) )
            ,myIsEnd( std::move( other.myIsEnd ) )
            {
                
            }
            
            Collection& operator=( const Collection& other )
            {
                myCurrent = other.myCurrent;
                myIsEnd = other.myIsEnd;
                myItems.clear();
                loadItems( other.myItems );
            }
            
            Collection& operator=( Collection&& other )
            {
                myCurrent = std::move( other.myCurrent );
                myIsEnd = std::move( other.myIsEnd );
                myItems = std::move( other.myItems );
            }
            
            virtual Integer getCount() const
            {
                return static_cast<Integer>( myItems.size() );
            }
            
            virtual bool getIsEmpty() const
            {
                return getCount() == 0;
            }
            
            virtual TYPE getCurrent() const
            {
                throwIfBadCurrent();
                return Copier<TYPE>::copy( myItems[ toSize(myCurrent)] );
            }
            
            virtual int getCurrentIndex() const
            {
                throwIfBadCurrent();
                return myCurrent;
            }
            
            virtual TYPE getNext() const
            {
                throwIfBadCurrent();
                if ( myCurrent == getCount() - 1 )
                {
                    THROW( "current item is last, cannot get next" )
                }
                return Copier<TYPE>::copy( myItems[ toSize( myCurrent ) + 1 ] );
            }
            
            virtual TYPE getPrevious() const
            {
                throwIfBadCurrent();
                if ( myCurrent == 0 )
                {
                    THROW( "current item is first, cannot get previous" )
                }
                return Copier<TYPE>::copy( myItems[ toSize( myCurrent ) - 1 ] );
            }
            
            virtual bool getIsEnd() const
            {
                return myIsEnd;
            }
            
            virtual void first()
            {
                myCurrent = 0;
                if ( ! getIsEmpty() )
                {
                    myIsEnd = false;
                }
            }
            
            virtual void last()
            {
                if ( getIsEmpty() )
                {
                    myIsEnd = true;
                    myCurrent = 0;
                    return;
                }
                myCurrent = getCount()-1;
                myIsEnd = false;
            }
            
            virtual bool next()
            {
                
                if ( getIsEmpty() )
                {
                    THROW( "cannot advance, container is empty" )
                }
                if ( getIsEnd() )
                {
                    return false;
                }
                throwIfBadCurrent();
                ++myCurrent;
                myIsEnd = myCurrent > getCount() - 1;
                return true;
            }
            
            virtual bool previous()
            {
                if ( getIsEmpty() )
                {
                    THROW( "cannot use previous, container is empty" )
                }
                if ( myCurrent == 0 )
                {
                    return false;
                }
                throwIfBadCurrent();
                --myCurrent;
                myIsEnd = false;
                return true;
            }
            
            virtual void jump( int index )
            {
                if ( getIsEmpty() )
                {
                    THROW( "cannot jump in an empty container" )
                }
                if ( index < 0 )
                {
                    THROW( "invalid index, less than zero" );
                }
                if ( index > getCount() - 1 )
                {
                    THROW( "invalid index, beyond last item" );
                }
                myCurrent = index;
            }
            
            virtual void add( const TYPE& item )
            {
                bool wasEmpty = false;
                if ( getIsEmpty() )
                {
                    wasEmpty = true;
                }
                myItems.push_back( Copier<TYPE>::copy( item ) );
                if( wasEmpty )
                {
                    myCurrent = 0;
                    myIsEnd = false;
                }
            }
            
            virtual void remove( const int index )
            {
                if ( index < 0 || index > getCount() - 1 )
                {
                    THROW( "bad index" )
                }
                myItems.erase( myItems.begin() + index );
                if( myCurrent > index )
                {
                    --myCurrent;
                    throwIfBadCurrent();
                }
            }
            
            virtual void removeCurrent( )
            {
                throwIfBadCurrent();
                remove( myCurrent );
            }
            
            virtual void clear()
            {
                myItems.clear();
                myIsEnd = true;
            }
            
        private:
            void loadItems( const T_VEC& items )
            {
                if ( items.size() == 0 )
                {
                    myIsEnd = true;
                    return;
                }
                clear();
                for ( auto i = items.cbegin(); i != items.cend(); ++i )
                {
                    myItems.push_back( Copier<TYPE>::copy( *i ) );
                }
                myIsEnd = false;
            }
            std::size_t toSize( const Integer value ) const
            {
                return static_cast<std::size_t>( value );
            }
            void throwIfBadCurrent() const
            {
                if ( getIsEmpty() )
                {
                    THROW( "current is invalid because container is empty" )
                }
                if ( myCurrent < 0 )
                {
                    THROW( "current pointer is negative" )
                }
                if ( myCurrent > getCount()-1 )
                {
                    THROW( "current pointer is beyond the last item" )
                }
                if ( getIsEnd() )
                {
                    THROW( "invalid because getIsEnd is true" )
                }
            }
        };
    }
}
