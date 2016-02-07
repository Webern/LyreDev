//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        template <typename TYPE>
        class EXPORT_FOR_TESTS IEnumerable
        {
        private:
            using T_UP = std::unique_ptr<TYPE>;
            using T_UPC = std::unique_ptr<const TYPE>;
            using T_VEC = std::vector<T_UP>;
            T_VEC myItems;
            Integer myCurrent;
            bool myIsEnd;
            
        public:
            virtual ~IEnumerable() {}
            
            IEnumerable()
            :myItems()
            ,myCurrent( 0 )
            ,myIsEnd( true )
            {}
            
            IEnumerable( const T_VEC& items )
            :myItems()
            ,myCurrent( 0 )
            ,myIsEnd( true )
            {
                loadItems( items );
            }
            
            virtual Integer getCount() const
            {
                return static_cast<Integer>( myItems.size() );
            }
            
            virtual bool getIsEmpty() const
            {
                return getCount() == 0;
            }
            
            virtual T_UP getCurrent() const
            {
                throwIfBadCurrent();
                return myItems[ toSize(myCurrent)]->clone();
            }
            
            virtual T_UP getNext() const
            {
                throwIfBadCurrent();
                if ( myCurrent == getCount() - 1 )
                {
                    THROW( "current item is last, cannot get next" )
                }
                return myItems[ toSize( myCurrent ) + 1 ]->clone();
            }
            
            virtual T_UP getPrevious() const
            {
                throwIfBadCurrent();
                if ( myCurrent == 0 )
                {
                    THROW( "current item is first, cannot get previous" )
                }
                return myItems[ toSize( myCurrent ) - 1 ]->clone();
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
            
            virtual void add( const T_UP& item )
            {
                THROW_IF_NULL( item )
                myItems.push_back( item->clone() );
            }
            
            virtual bool remove( const T_UP& item )
            {
                if ( item == nullptr )
                {
                    return false;
                }
                for ( auto i = myItems.cbegin(); i != myItems.cend(); ++i )
                {
                    if ( i->get() == item.get() )
                    {
                        myItems.erase( i );
                        if ( getIsEmpty() )
                        {
                            myCurrent = 0;
                            myIsEnd = true;
                            return true;
                        }
                        first();
                        return true;
                    }
                }
                return false;
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
                    THROW_IF_NULL( (*i) )
                    myItems.push_back( (*i)->clone() );
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
