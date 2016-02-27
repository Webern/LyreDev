#include "Lyre/NoteGroup.h"
#include "Lyre/Private/throw.h"
#include "Lyre/INote.h"

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
        return *this;
    }
    
	INoteGroupUP NoteGroup::clone() const
	{
		return INoteGroupUP{};
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
		return INoteUP{};
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
		return INoteGroupUP{};
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

