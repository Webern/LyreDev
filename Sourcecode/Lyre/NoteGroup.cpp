#include "Lyre/NoteGroup.h"
#include "Lyre/Private/throw.h"
#include "Lyre/INote.h"

// TODO remove these
#include "Lyre/INoteFactory.h"
#include "Lyre/IPitchFactory.h"
#include "Lyre/IDurationFactory.h"

namespace Lyre
{
    class NoteGroup::Impl
    {
        
    };
    
    NoteGroup::~NoteGroup()
    {
        delete myImplP;
        myImplP = 0;
    }
    
    NoteGroup::NoteGroup()
    :myImplP( 0 )
    {
        myImplP = new Impl{};
        THROW_IF_NULL( myImplP );
    }
    
    NoteGroup::NoteGroup( const NoteGroup& other )
    :myImplP( 0 )
    {
        THROW_IF_NULL( other.myImplP );
        myImplP = new Impl( *other.myImplP );
    }
    
    NoteGroup::NoteGroup( NoteGroup&& other ) noexcept
    :myImplP( std::move( other.myImplP ) )
    {
        other.myImplP = 0;
    }
    
    NoteGroup& NoteGroup::operator=( const NoteGroup& other )
    {
        THROW_IF_NULL( other.myImplP );
        myImplP = new Impl( *other.myImplP );
        return *this;
    }
    
    NoteGroup& NoteGroup::operator=( NoteGroup&& other ) noexcept
    {
        myImplP = std::move( other.myImplP );
        other.myImplP = 0;
        return *this;
    }
    
	INoteGroupUP NoteGroup::clone() const
	{
		return INoteGroupUP{};
	}
    
    NoteGroupUP NoteGroup::copy() const
	{
		return NoteGroupUP{};
	}

	std::ostream& NoteGroup::toStream( std::ostream& os ) const
	{
		return os;
	}

	bool NoteGroup::getIsEmpty() const
	{
		return false;
	}

	int NoteGroup::getCount() const
	{
		return -2;
	}

	Rational NoteGroup::getTotalDuration() const
	{
		return Rational{ -1, 1 };
	}

	INoteUP NoteGroup::getNote( int noteIndex ) const
	{
        UNUSED_PARAMETER( noteIndex )
        auto n = createNoteFactory();
        auto p = createPitchFactory();
        auto d = createDurationFactory();
        p->setPitch( 200 );
		return n->createNote( p->createPitch(), d->createDuration( "256th" ) );
	}

	void NoteGroup::add( const INoteUP& note )
	{
        UNUSED_PARAMETER( note )
	}

	void NoteGroup::remove( int noteIndex )
	{
        UNUSED_PARAMETER( noteIndex )
	}

	int NoteGroup::getGroupCount() const
	{
		return -2;
	}

	bool NoteGroup::getIsInGroup( int noteIndex ) const
	{
        UNUSED_PARAMETER( noteIndex )
		return false;
	}

	int NoteGroup::getGroupIndex( int noteIndex ) const
	{
        UNUSED_PARAMETER( noteIndex )
		return -2;
	}

	INoteGroupUP NoteGroup::getGroup( int groupIndex ) const
	{
        UNUSED_PARAMETER( groupIndex )
		return INoteGroupUP{ new NoteGroup{} };
	}

	void NoteGroup::addGroup( const INoteGroupUP& group )
	{
        UNUSED_PARAMETER( group )
	}

	void NoteGroup::removeGroup( int subGroupIndex )
	{
        UNUSED_PARAMETER( subGroupIndex )
	}

}

