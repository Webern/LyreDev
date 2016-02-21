#include "Lyre/Private/NoteGroupImpl.h"
#include "Lyre/Private/throw.h"
#include "Lyre/toShared.h"

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
                myType = other.myType;
                myChildren.clear();
            }
            else if ( other.myType == Type::Parent )
            {
                for ( int i = 0; i < other.getCount(); ++i )
                {
                    auto child = getChild( i );
                    if ( child )
                    {
                        myChildren.push_back( child->clone() );
                    }
                }
                myType = other.myType;
                myNote = nullptr;
            }
            else if ( other.myType == Type::Undecided )
            {
                myNote = nullptr;
                myType = Type::Undecided;
                myChildren.clear();
            }
        }
        
        NoteGroupImpl::NoteGroupImpl( NoteGroupImpl&& other )
        :myNote( std::move( other.myNote ) )
        ,myChildren( std::move( other.myChildren ) )
        ,myType( std::move( other.myType ) )
        {

        }
        
        NoteGroupImpl& NoteGroupImpl::operator=( const NoteGroupImpl& other )
        {
            if ( other.myType == Type::Leaf )
            {
                myChildren.clear();
                myNote = other.myNote->clone();
                myType = other.myType;
            }
            else if ( other.myType == Type::Parent )
            {
                myChildren.clear();
                for ( auto i = myChildren.cbegin();
                      i != myChildren.cend(); ++i )
                {
                    myChildren.push_back( (*i)->clone() );
                }
                myNote = nullptr;
                myType = other.myType;
            }
            else if ( other.myType == Type::Undecided )
            {
                myChildren.clear();
                myNote = nullptr;
                myType = other.myType;
            }
            return *this;
        }
        
        NoteGroupImpl& NoteGroupImpl::operator=( NoteGroupImpl&& other )
        {
            
            myNote = std::move( other.myNote );
            myChildren = std::move( other.myChildren );
            myType = std::move( other.myType );
            return *this;
        }
        
        NoteGroupImplUP NoteGroupImpl::clone() const
        {
            return NoteGroupImplUP{ new NoteGroupImpl{ *this } };
        }
        
        NoteGroupImpl::Type NoteGroupImpl::getType() const
        {
            return myType;
        }
        
        int NoteGroupImpl::getCount() const
        {
            return static_cast<int>( myChildren.size() );
        }
        
        void NoteGroupImpl::setNote( const INoteUP& value )
        {
            if ( myType == Type::Parent )
            {
                THROW( "cannot use this function on a parent" )
            }
            THROW_IF_NULL( value )
            if ( myType == Type::Undecided )
            {
                myType = Type::Leaf;
                myChildren.clear();
            }
            myNote = value->clone();
        }
        
        INoteUP NoteGroupImpl::getNote() const
        {
            if ( myType == Type::Leaf )
            {
                return myNote->clone();
            }
            THROW( "cannot retreive note" )
        }
        
        NoteGroupImplUP NoteGroupImpl::getChild( int index ) const
        {
            if ( myType != Type::Parent )
            {
                THROW( "object is not a parent" )
            }
            if ( index < 0 || index > getCount() - 1 )
            {
                THROW( "index out of range" )
            }
            return ( *( myChildren.cbegin() + index ) )->clone();
        }
        
        void NoteGroupImpl::addChild( const NoteGroupImplUP& child )
        {
            if ( myType == Type::Leaf )
            {
                THROW( "cannot add a child to a leaf" )
            }
            THROW_IF_NULL( child )
            if ( myType == Type::Undecided )
            {
                myType = Type::Parent;
                myNote.release();
                myNote = nullptr;
            }
            myChildren.push_back( child->clone() );
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
    }
}
