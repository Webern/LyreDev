#include "Lyre/NoteGroup.h"
#include <sstream>
#include "Lyre/Private/throw.h"
#include "Lyre/Private/toShared.h"

namespace
{
    using Notes = std::vector<const Lyre::INoteSP>;
    using NotesIter = Notes::iterator;
    using NotesIterConst = Notes::const_iterator;
}

namespace Lyre
{

//////////////////////////////////////////////////////////////////////////////
// Impl //////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

    class NoteGroup::Impl
    {
    public:
        Impl()
        :myNotes()
        ,myCurrent( myNotes.begin() )
        ,myIsInvalid( false )
        {}
        
        ~Impl() {}
        
        bool getIsValid() const
        {
            if ( myIsInvalid )
            {
                return false;
            }
            if ( getIsEnd() )
            {
                return false;
            }
            if ( getCurrentNote() == nullptr )
            {
                return false;
            }
            if ( getSize() <= 0 )
            {
                return false;
            }
            return true;
        }
        
        bool getIsFirst() const
        {
            return myCurrent == myNotes.begin();
        }
        
        bool getIsLast() const
        {
            if ( getSize() == 0 )
            {
                return true;
            }
            auto lastIter = ( myNotes.end() )-1;
            return myCurrent == lastIter;
        }
        
        bool getIsEnd() const
        {
            return myCurrent == myNotes.end();
        }
        
        const INoteSPC getCurrentNote() const
        {
            if ( ! getIsValid() )
            {
                THROW( "invalid iterator" )
            }
            return *myCurrent;
        }
        
        const INoteSPC getNextNote() const
        {
            if ( myIsInvalid || getIsEnd() )
            {
                THROW( "iterator is invalid" )
            }
            if ( getIsLast() )
            {
                THROW( "current note is last in group, next note does not exist" )
            }
            auto nextNoteIter = myCurrent + 1;
            auto returnValue = *nextNoteIter;
            THROW_IF_NULL( returnValue );
            return returnValue;
        }
        
        const INoteSPC getPreviousNote() const
        {
            if ( myIsInvalid )
            {
                THROW( "iterator is invalid" )
            }
            if ( getIsFirst() )
            {
                THROW( "current note is first in group, previous note does not exist" )
            }
            auto previousNoteIter = myCurrent - 1;
            auto returnValue = *previousNoteIter;
            THROW_IF_NULL( returnValue );
            return returnValue;
        }
        
        const INoteSP getCurrentNote()
        {
            if ( ! getIsValid() )
            {
                THROW( "invalid iterator" )
            }
            return *myCurrent;
        }
        
        const INoteSP getNextNote()
        {
            if ( myIsInvalid || getIsEnd() )
            {
                THROW( "iterator is invalid" )
            }
            if ( getIsLast() )
            {
                THROW( "current note is last in group, next note does not exist" )
            }
            auto nextNoteIter = myCurrent + 1;
            auto returnValue = *nextNoteIter;
            THROW_IF_NULL( returnValue );
            return returnValue;
        }
        
        const INoteSP getPreviousNote()
        {
            if ( myIsInvalid )
            {
                THROW( "iterator is invalid" )
            }
            if ( getIsFirst() )
            {
                THROW( "current note is first in group, previous note does not exist" )
            }
            auto previousNoteIter = myCurrent - 1;
            auto returnValue = *previousNoteIter;
            THROW_IF_NULL( returnValue );
            return returnValue;
        }
        
        void next()
        {
            if ( myIsInvalid )
            {
                THROW( "iterator is invalid" )
            }
            if ( getIsEnd() || getSize() == 0 )
            {
                THROW( "cannot advance end iter" )
            }
            ++myCurrent;
        }
        
        void previous()
        {
            if ( myIsInvalid )
            {
                THROW( "iterator is invalid" )
            }
            if ( getIsFirst() || getSize() == 0 )
            {
                THROW( "cannot move before begin iter" )
            }
            --myCurrent;
        }
        
        int getSize() const
        {
            return static_cast<int>( myNotes.size() );
        }
        
        
        void addNote( const INoteUP& note )
        {
            THROW_IF_NULL( note )
            INoteUP cloned = note->clone();
            const INoteSP shared = Private::toShared( cloned );
            THROW_IF_NULL( shared )
            myNotes.push_back( shared );
        }
        
        void removeNote( const NoteGroupIter& noteIter )
        {
            if ( ! noteIter.getIsValid() )
            {
                THROW( "invalid note iter" );
            }
            for ( auto it = myNotes.cbegin();
                  it != myNotes.cend();
                  ++it )
            {
#if 1==0
                if ( it->get() == noteIter.getCurrentNote().get() )
                {
                    myNotes.erase( it );
                    return;
                }
#endif
            }
            THROW( "note not found in the note group" )
        }
        
        void insertNote(
            const INoteUP& note,
            const NoteGroupIter& insertAfterThisNote )
        {
            note.get();
            insertAfterThisNote.getCurrentNote();
#if 1==0
            THROW_IF_NULL( note )
            INoteUP cloned = note->clone();
            const INoteSP shared = Private::toShared( cloned );
            if ( ! insertAfterThisNote.getIsValid() )
            {
                THROW( "invalid note iter" );
            }
            for ( auto it = myNotes.cbegin();
                 it != myNotes.cend();
                 ++it )
            {
                if ( it->get() == insertAfterThisNote.getCurrentNote().get() )
                {
                    myNotes.insert( it, shared );
                    return;
                }
            }
            THROW( "invalid note iter" )
#endif
        }
        
        
    private:
        Notes myNotes;
        NotesIter myCurrent;
        bool myIsInvalid;
    };

//////////////////////////////////////////////////////////////////////////////
// NoteGroupIter /////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// NoteGroupIterConst ////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// NoteGroup /////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

}
