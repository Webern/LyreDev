#include "LyreTest/Mock/MockNoteGroup.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    INoteGroupUP MockNoteGroup::clone() const
    {
        MockNoteGroup* temp = new MockNoteGroup( *this );
        return INoteGroupUP( temp );
    }
    
    bool MockNoteGroup::getIsEmpty() const
    {
        return size() == 0;
    }
    
    int MockNoteGroup::getCount() const
    {
        return size();
    }
    
    Rational MockNoteGroup::getDurationValue() const
    {
        Rational total{ 0, 1 };
        for( auto n : myNotes )
        {
            total += n->getDuration()->getValue();
        }
        total.reduce();
        return total;
    }
    
    void MockNoteGroup::add( const INoteSP& note )
    {

        myNotes.push_back( note );
    }
    
    void MockNoteGroup::remove( const INoteSP& note )
    {
        for ( auto it = myNotes.begin(); it != myNotes.end(); ++it )
        {
            if( it->get() == note.get() )
            {
                myNotes.erase( it );
                return;
            }
        }
    }
    
    INoteIterUP MockNoteGroup::getIterator() const
    {
        return INoteIterUP{};
    }
    
    const INoteSP MockNoteGroup::getNote( int index ) const
    {
        if ( getIsEmpty() )
        {
            THROW( "MockNoteGroup is empty" )
        }
        if ( index < 0 || index > size()-1 )
        {
            THROW( "index out of range" )
        }
        return myNotes[index];
    }
    
    int MockNoteGroup::size() const
    {
        return static_cast<int>( myNotes.size() );
    }
}