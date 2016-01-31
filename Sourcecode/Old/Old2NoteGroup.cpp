#include "Lyre/NoteGroup.h"
#include "Lyre/INote.h"
#include "Lyre/Private/throw.h"
#include "Lyre/NoteIter.h"

namespace Lyre
{
    class NoteGroup::Impl
    {
    public:
        VecINoteSP myNotes;
    };
    
#define NOTES ( myImplP->myNotes )
    
    NoteGroup::NoteGroup()
    :myImplP( new NoteGroup::Impl() )
    {
        THROW_IF_NULL( myImplP );
    }
    
    NoteGroup::NoteGroup( const NoteGroup& other )
    :myImplP( new Impl( *( other.myImplP ) ) )
    {
        THROW_IF_NULL( myImplP );
    }
    
    NoteGroup::NoteGroup( NoteGroup&& other )
    :myImplP( std::move( other.myImplP ) )
    {
        THROW_IF_NULL( myImplP );
    }
    
    NoteGroup& NoteGroup::operator=( const NoteGroup& other )
    {
        myImplP = new Impl( *( other.myImplP ) );
        THROW_IF_NULL( myImplP );
        return *this;
    }
    
    NoteGroup& NoteGroup::operator=( NoteGroup&& other )
    {
        myImplP = std::move( other.myImplP );
        THROW_IF_NULL( myImplP );
        return *this;
    }
    
    NoteGroup::~NoteGroup()
    {
        delete myImplP;
        myImplP = 0;
    }
    
    INoteGroupUP NoteGroup::clone() const
    {
        return INoteGroupUP{ new NoteGroup( *this ) };
    }
    
    bool NoteGroup::getIsEmpty() const
    {
        return getCount() == 0;
    }
    
    int NoteGroup::getCount() const
    {
        return static_cast<int>( NOTES.size() );
    }
    
    Rational NoteGroup::getDurationValue() const
    {
        Rational total{ 0, 1 };
        for ( auto it = NOTES.cbegin();
              it != NOTES.cend();
              ++it )
        {
            total += (*it)->getDuration()->getValue();
        }
        total.reduce();
        return total;
    }
    
    void NoteGroup::add( const INoteSP& note )
    {
        THROW_IF_NULL( note );
        NOTES.push_back( note );
    }
    
    void NoteGroup::remove( const INoteSP& note )
    {
        THROW_IF_NULL( note );
        for ( auto it = NOTES.cbegin();
              it != NOTES.cend();
              ++it )
        {
            if ( note.get() == it->get() )
            {
                NOTES.erase( it );
                return;
            }
        }
        THROW( "note was not found" )
    }
    
    INoteIterUP NoteGroup::getIterator() const
    {
        if ( getIsEmpty() )
        {
            THROW( "iterator requested for an empty NoteGroup" )
        }
        return INoteIterUP{ new NoteIter{ *this } };
    }
    
//protected:
    const INoteSP NoteGroup::getNote( int index ) const
    {
        if ( index < 0 )
        {
            THROW( "index out-of-bounds (negative)" );
        }
        if ( index > ( getCount() - 1 ) )
        {
            THROW( "index out-of-bounds (too large)" );
        }
        return NOTES[static_cast<size_t>( index )];
    }
}
