#include "Lyre/NoteGroup.h"
#include "Lyre/Private/throw.h"
#include "Lyre/INote.h"

namespace Lyre
{
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
		return INoteUP{};
	}

	void NoteGroup::add( const INoteUP& note )
	{

	}

	void NoteGroup::remove( int noteIndex )
	{

	}

	int NoteGroup::getGroupCount() const
	{
		return -2;
	}

	bool NoteGroup::getIsInGroup( int noteIndex ) const
	{
		return false;
	}

	int NoteGroup::getGroupIndex( int noteIndex ) const
	{
		return -2;
	}

	INoteGroupUP NoteGroup::getGroup( int groupIndex ) const
	{
		return INoteGroupUP{};
	}

	void NoteGroup::addGroup( const INoteGroupUP& group )
	{

	}

	void NoteGroup::removeGroup( int subGroupIndex )
	{

	}

}

