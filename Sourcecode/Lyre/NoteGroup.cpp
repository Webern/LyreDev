#include "Lyre/NoteGroup.h"
#include "Lyre/Private/throw.h"
#include "Lyre/INote.h"

namespace Lyre
{

	class NoteGroup::Impl
	{
	public:
		Impl() : myCurrentIndex(0), myNotes() {}
		int myCurrentIndex;
		VecINoteSPC myNotes;    
	};

#define MY_INDEX ( myImplP->myCurrentIndex )
#define MY_NOTES ( myImplP->myNotes )
    
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
    :myImplP( nullptr )
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
    
    NoteGroup::NoteGroup( NoteGroup&& other )
    :myImplP( 0 )
    {
        myImplP = std::move( other.myImplP );
        THROW_IF_NULL( myImplP )
    }
    
    NoteGroup& NoteGroup::operator=( const NoteGroup& other )
    {
        myImplP = 0;
        myImplP = new Impl( *other.myImplP );
        THROW_IF_NULL( myImplP )
        return *this;
    }
    
    NoteGroup& NoteGroup::operator=( NoteGroup&& other )
    {
        myImplP = 0;
        myImplP = myImplP = std::move( other.myImplP );
        THROW_IF_NULL( myImplP )
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
    
    int NoteGroup::getCount() const
    {
        return static_cast<int>( MY_NOTES.size() );
    }
    
    Rational NoteGroup::getDurationValue() const
    {
        Rational total{ 0, 1 };
        for ( auto note : myImplP->myNotes )
        {
            total += note->getDuration()->getValue();
        }
        total.reduce();
        return total;
    }
    
    const INoteSPC NoteGroup::getCurrent() const
    {
        if ( getIsEmpty() )
        {
            THROW( "note group is empty" )
        }
        return MY_NOTES[ static_cast<VecINoteSPC::size_type>( MY_INDEX ) ];
    }
    
    const INoteSPC NoteGroup::getNext() const
    {
        if ( getIsEmpty() || MY_INDEX >= getCount()-1 )
        {
            THROW( "cannot get next note" )
        }
        return MY_NOTES[ static_cast<VecINoteSPC::size_type>( MY_INDEX+1 ) ];
    }
    
    const INoteSPC NoteGroup::getPrevious() const
    {
        if ( getIsEmpty() || MY_INDEX <= 0 )
        {
            THROW( "cannot get previous note" )
        }
        return MY_NOTES[ static_cast<VecINoteSPC::size_type>( MY_INDEX-1 ) ];
    }
    
    void NoteGroup::first()
    {
        MY_INDEX = 0;
    }
    
    void NoteGroup::last()
    {
        MY_INDEX = 0;
        if ( ! getIsEmpty() )
        {
            MY_INDEX = getCount() - 1;
        }
    }
    
    bool NoteGroup::next()
    {
        if( MY_INDEX < getCount() - 1 )
        {
            ++MY_INDEX;
            return true;
        }
        return false;
    }
    
    bool NoteGroup::previous()
    {
        if( MY_INDEX > 0 )
        {
            --MY_INDEX;
            return true;
        }
        return false;
    }
    
    void NoteGroup::jump( int index )
    {
        if ( getIsEmpty() && index != 0 )
        {
            THROW( "note group is empty cannot jump" )
        }
        if ( index < 0 )
        {
            THROW( "invalid index (negative)" )
        }
        if ( index > getCount()-1 )
        {
            THROW( "invalid index (too big)" )
        }
        MY_INDEX = index;
    }
    
    void NoteGroup::add( const INoteSP& note )
    {
        THROW_IF_NULL( note )
        MY_NOTES.push_back( note );
    }
    
    void NoteGroup::remove( const INoteSP& note )
    {
        for ( auto it = MY_NOTES.cbegin(); it != MY_NOTES.cend(); ++it )
        {
            if ( it->get() == note.get() )
            {
                MY_NOTES.erase( it );
                if ( MY_INDEX > getCount()-1 )
                {
                    MY_INDEX = getCount()-1;
                }
                return;
            }
        }
        THROW( "note could not be found" )
    }
}
