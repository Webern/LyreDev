#include "Lyre/NoteGroup.h"
#include "Lyre/Private/throw.h"
#include "Lyre/INote.h"
#include "Lyre/Private/Collection.h"

namespace Lyre
{
    
    class NoteGroup::Impl
	{
	public:
        Private::Collection<INoteSP> myNotes;
		
	};

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
    
    bool NoteGroup::getIsEnd() const
    {
        return MY_NOTES.getIsEnd();
    }
    
    int NoteGroup::getCount() const
    {
        return MY_NOTES.getCount();
    }
    
    Rational NoteGroup::getDurationValue() const
    {
        Rational total{ 0, 1 };
        if( getIsEmpty() )
        {
            return total;
        }
        int rememberCurrent = 0;
        if ( ! getIsEnd() )
        {
            rememberCurrent = MY_NOTES.getCurrentIndex();
        }
        for ( int i = 0; i < getCount(); ++i )
        {
            
            MY_NOTES.jump( i );
            total += MY_NOTES.getCurrent()->getDuration()->getValue();
        }
        total.reduce();
        MY_NOTES.jump( rememberCurrent );
        return total;
    }
    
    const INoteSPC NoteGroup::getCurrent() const
    {
        if ( getIsEmpty() )
        {
            THROW( "note group is empty" )
        }
        return MY_NOTES.getCurrent();
    }
    
    const INoteSPC NoteGroup::getNext() const
    {
        return MY_NOTES.getNext();
    }
    
    const INoteSPC NoteGroup::getPrevious() const
    {
        return MY_NOTES.getPrevious();
    }
    
    void NoteGroup::first()
    {
        MY_NOTES.first();
    }
    
    void NoteGroup::last()
    {
        MY_NOTES.last();
    }
    
    bool NoteGroup::next()
    {
        return MY_NOTES.next();
    }
    
    bool NoteGroup::previous()
    {
        return MY_NOTES.previous();
    }
    
    void NoteGroup::jump( int index )
    {
        MY_NOTES.jump( index );
    }
    
    void NoteGroup::add( const INoteSP& note )
    {
        MY_NOTES.add( note );
    }
    
    void NoteGroup::remove( int index )
    {
        MY_NOTES.remove( index );
    }
}
