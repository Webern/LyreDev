#include "Lyre/NoteGroup.h"
#include "Lyre/Private/throw.h"
#include "Lyre/INote.h"
#include "Lyre/Private/NoteGroupImpl.h"

namespace Lyre
{

	class NoteGroup::Impl
	{
	public:
        Private::NoteGroupImpl myRoot;
        int myCurrent;
        bool myIsEnd;
        Impl() : myRoot(), myCurrent( 0 ), myIsEnd( true ) {}
	};
    
#define ROOT ( myImplP->myRoot )
#define IS_END ( myImplP->myIsEnd )
#define CURR ( myImplP->myCurrent )
    
    INoteGroupUP createNoteGroup()
    {
        auto p = INoteGroupUP{ new NoteGroup{} };
        THROW_IF_NULL( p )
        return std::move( p );
    }
    
	NoteGroup::~NoteGroup()
    {
        delete myImplP;
        myImplP = 0;
    }
    
    NoteGroup::NoteGroup()
    :myImplP()
    {
        myImplP = new Impl();
        THROW_IF_NULL( myImplP )
    }
    
    NoteGroup::NoteGroup( const NoteGroup& other )
    :myImplP( nullptr )
    {
        myImplP = new Impl( *other.myImplP );
        THROW_IF_NULL( myImplP )
    }
    
    NoteGroup::NoteGroup( NoteGroup&& other ) noexcept
    :myImplP( 0 )
    {
		try
		{
			myImplP = std::move( other.myImplP );
		}
		catch ( ... ) {}
    }
    
    NoteGroup& NoteGroup::operator=( const NoteGroup& other )
    {
        myImplP = 0;
        myImplP = new Impl( *other.myImplP );
        THROW_IF_NULL( myImplP )
        return *this;
    }
    
    NoteGroup& NoteGroup::operator=( NoteGroup&& other ) noexcept
    {
		try
		{
			myImplP = std::move( other.myImplP );
		}
		catch ( ... ) {}
        return *this;
    }
    
    INoteGroupUP NoteGroup::clone() const
    {
        auto p = INoteGroupUP{ new NoteGroup{ *this } };
        THROW_IF_NULL( p )
        return std::move( p );
    }
    
    bool NoteGroup::getIsEmpty() const
    {
        return getCount() == 0;
    }
    
    bool NoteGroup::getIsEnd() const
    {
        return IS_END || CURR > getCount() - 1;
    }
    
    int NoteGroup::getCount() const
    {
        return ROOT.getCount();
    }
    
    Rational NoteGroup::getTotalDuration() const
    {
        if( getIsEmpty() )
        {
            return Rational{ 0, 1 };;
        }
        return ROOT.getTotalDuration();
    }
    
    INoteUP NoteGroup::getCurrent() const
    {
        if ( getIsEmpty() )
        {
            THROW( "note group is empty" )
        }
        if ( CURR < 0 || CURR > getCount() - 1 )
        {
            THROW( "index out of range" )
        }
		auto child = ROOT.getChild( CURR );
		auto note = child->getNote();
        return std::move( note );
    }
    
    INoteUP NoteGroup::getNext() const
    {
        if ( CURR < 0 || CURR > getCount() - 1 )
        {
            THROW( "index out of range" )
        }
        return ROOT.getChild( CURR + 1 )->getNote();
    }
    
    INoteUP NoteGroup::getPrevious() const
    {
        if ( CURR < 1 || CURR > getCount() - 1 )
        {
            THROW( "index out of range" )
        }
        return ROOT.getChild( CURR - 1 )->getNote();
    }
    
    void NoteGroup::first()
    {
        CURR = 0;
        if ( ! getIsEmpty() )
        {
            IS_END = false;
        }
    }
    
    void NoteGroup::last()
    {
        if ( ! getIsEmpty() )
        {
            CURR = getCount() - 1;
            IS_END = false;
        }
        else
        {
            CURR = 0;
            IS_END = true;
        }
    }
    
    bool NoteGroup::next()
    {
        if ( CURR < 0 || CURR > getCount() - 1 )
        {
            THROW( "index out of range" )
        }
        ++CURR;
        IS_END = CURR > getCount() - 1;
        return ! IS_END;
    }
    
    bool NoteGroup::previous()
    {
        if ( CURR < 0 || CURR > getCount() - 1 )
        {
            THROW( "index out of range" )
        }
        if ( CURR == 0 )
        {
            return false;
        }
        --CURR;
        return true;
    }
    
    void NoteGroup::jump( int index )
    {
        if ( index < 0 || index > getCount() - 1 )
        {
            THROW( "index out of range" )
        }
        CURR = index;
    }
    
    void NoteGroup::add( const INoteUP& note )
    {
        THROW_IF_NULL( note )
        Private::NoteGroupImplUP newimpl{ new Private::NoteGroupImpl{} };
        
        newimpl->setNote( note->clone() );
        ROOT.addChild( newimpl );
    }
    
    void NoteGroup::remove( int index )
    {
        ROOT.removeChild( index );
    }
}
