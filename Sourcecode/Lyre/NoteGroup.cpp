#include "Lyre/NoteGroup.h"
#include "Lyre/Private/throw.h"
#include "Lyre/INote.h"

// TODO remove these
#include "Lyre/INoteFactory.h"
#include "Lyre/IPitchFactory.h"
#include "Lyre/IDurationFactory.h"

namespace Lyre
{
    enum class NgType
    {
        Note = 0,
        Group = 1,
        Unk = 2
    };

    class NoteGroup::Impl
    {
    public:
        Impl()
        :ngType( NgType::Unk )
        ,note( nullptr )
        ,noteGroups()
        {}
        
        Impl( const INoteUP& inNote )
        :ngType( NgType::Note )
        ,note( inNote->clone() )
        ,noteGroups()
        {
            THROW_IF_NULL( note )
        }
        
        Impl( const VecINoteGroupUP& vector )
        :ngType( NgType::Group )
        ,note( nullptr )
        ,noteGroups()
        {
            for ( auto i = vector.cbegin(); i != vector.cend(); ++i )
            {
                THROW_IF_NULL( (*i) )
                noteGroups.push_back( (*i)->clone() );
            }
        }

        Impl( const Impl& other )
        :ngType( other.ngType )
        ,note( nullptr )
        ,noteGroups()
        {
            if ( other.note )
            {
                note = other.note->clone();
            }
            for ( auto i = other.noteGroups.cbegin();
                  i != other.noteGroups.cend(); ++i )
            {
                THROW_IF_NULL( (*i) )
                noteGroups.push_back( (*i)->clone() );
            }
        }
        
        Impl( Impl&& other )
        :ngType( std::move( other.ngType ) )
        ,note( std::move( other.note ) )
        ,noteGroups( std::move( other.noteGroups ) )
        {
            
        }
        
        Impl& operator=( const Impl& other )
        {
            ngType = other.ngType;
            note = nullptr;
            noteGroups.clear();
            if ( other.note )
            {
                note = other.note->clone();
            }
            for ( auto i = other.noteGroups.cbegin();
                 i != other.noteGroups.cend(); ++i )
            {
                THROW_IF_NULL( (*i) )
                noteGroups.push_back( (*i)->clone() );
            }
            return *this;
        }
        
        Impl& operator=( Impl&& other )
        {
            ngType = std::move( other.ngType );
            note =  std::move( other.note );
            noteGroups = std::move( other.noteGroups );
            return *this;
        }
        
        NgType ngType;
        INoteUP note;
        VecINoteGroupUP noteGroups;
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
		return INoteGroupUP{ new NoteGroup{ *this } };
	}
    
    NoteGroupUP NoteGroup::copy() const
	{
		return NoteGroupUP{ new NoteGroup{ *this } };
	}

	std::ostream& NoteGroup::toStream( std::ostream& os ) const
	{
        for ( int i = 0; i < getCount(); ++i )
        {
            if ( i > 0 )
            {
                os << std::endl;
            }
            os << ( *getNote( i ) );
        }
		return os;
	}

	bool NoteGroup::getIsEmpty() const
	{
		return getCount() == 0;
	}

	int NoteGroup::getCount() const
	{
        if ( myImplP->ngType == NgType::Note )
        {
            return 1;
        }
        else if ( myImplP->ngType == NgType::Unk )
        {
            return 0;
        }
        int count = 0;
        for ( auto i = myImplP->noteGroups.cbegin();
              i != myImplP->noteGroups.cend(); ++i )
        {
            count += (*i)->getCount();
        }
		return count;
	}

	Rational NoteGroup::getTotalDuration() const
	{
        Rational total{ 0, 1 };
        for ( int i = 0; i < getCount(); ++i )
        {
            total += getNote( i )->getDuration()->getValue();
        }
		return total;
	}

	INoteUP NoteGroup::getNote( int noteIndex ) const
	{
        if ( noteIndex < 0 || noteIndex > getCount() - 1 )
        {
            THROW( "index out of range" )
        }
        int counter = 0;
        for ( auto i = myImplP->noteGroups.cbegin();
             i != myImplP->noteGroups.cend(); ++i )
        {
            if ( counter == noteIndex )
            {
                if ( (*i)->getCount() == 1 )
                {
                    return (*i)->getNote( 0 );
                }
            }
        }
        
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

