#include "Lyre/NoteGroupImpl.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        NoteGroupImpl::~NoteGroupImpl()
        {
            
        }
        
        NoteGroupImpl::NoteGroupImpl()
        :myNote( nullptr )
        ,myChildren()
        ,myType( Type::Undecided )
        {
            
        }
        
        NoteGroupImpl::NoteGroupImpl( const NoteGroupImpl& other )
        :myNote()
        ,myChildren()
        ,myType( other.myType )
        {
            if ( other.myType == Type::Leaf && ( other.myNote ) )
            {
                myNote = other.myNote->clone();
            }
            else if ( other.myType == Type::Parent )
            {
                for ( int i = 0; i < other.getCount(); ++i )
                {
                    auto child = getChild( i );
                    if ( child )
                    {
                        myChildren.push_back( child );
                    }
                }
            }
        }
        
        NoteGroupImpl::NoteGroupImpl( NoteGroupImpl&& other )
        {
            UNUSED_PARAMETER( other )
        }
        
        NoteGroupImpl& NoteGroupImpl::operator=( const NoteGroupImpl& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }
        
        NoteGroupImpl& NoteGroupImpl::operator=( NoteGroupImpl&& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }
        
        NoteGroupImpl::Type NoteGroupImpl::getType() const
        {
            return myType;
        }
        
        void NoteGroupImpl::setType( const NoteGroupImpl::Type t )
        {
            if ( myType != Type::Undecided )
            {
                THROW( "type unless it is currently undecided" )
            }
            else if ( t == Type::Undecided )
            {
                THROW( "cannot set the type to undecided" )
            }
            myType = t;
        }
        
        int NoteGroupImpl::getCount() const
        {
            return static_cast<int>( myChildren.size() );
        }
        
        void NoteGroupImpl::addChild( Child child )
        {
            if ( myType == Type::Leaf )
            {
                THROW( "cannot add child to a leaf node" )
            }
            else if ( myType == Type::Undecided )
            {
                myType = Type::Parent;
                myNote = nullptr;
            }
            THROW_IF_NULL( child )
            myChildren.push_back( child );
        }
        
        void NoteGroupImpl::removeChild( int index )
        {
            if ( myType != Type::Parent )
            {
                THROW( "cannot remove child on leaf or undecided types" )
            }
            if ( index < 0 || index > getCount() - 1 )
            {
                THROW( "bad index" )
            }
            myChildren.erase( myChildren.cbegin() + index );
        }
        
        void NoteGroupImpl::setChildren( const Children& children )
        {
            if ( myType == Type::Leaf )
            {
                THROW( "cannot add child to leaf node" )
            }
            else if ( myType == Type::Undecided )
            {
                myType = Type::Parent;
                myNote = nullptr;
            }
            for ( auto c : children )
            {
                myChildren.push_back( c );
            }
        }
    }
}
