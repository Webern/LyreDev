#include "Lyre/NoteGroup.h"
#include <sstream>
#include "Lyre/Private/throw.h"
#include "Lyre/Private/toShared.h"

namespace
{
    using Notes = std::vector<Lyre::INoteSP>;
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
        
        void removeNote( const NoteGroup::Iter& noteIter )
        {
            if ( ! noteIter.getIsValid() )
            {
                THROW( "invalid note iter" );
            }
            for ( auto it = myNotes.begin();
                  it != myNotes.end();
                  ++it )
            {

                if ( it->get() == noteIter.getCurrentNote().get() )
                {
                    myNotes.erase( it );
                    return;
                }
            }
            THROW( "note not found in the note group" )
        }
        
        void insertNote(
            const NoteGroup::Iter& insertAfterThisNote,
            const INoteUP& note )
        {
            note.get();
            insertAfterThisNote.getCurrentNote();
            THROW_IF_NULL( note )
            INoteUP cloned = note->clone();
            const INoteSP shared = Private::toShared( cloned );
            if ( ! insertAfterThisNote.getIsValid() )
            {
                THROW( "invalid note iter" );
            }
            for ( auto it = myNotes.begin();
                  it != myNotes.end();
                  ++it )
            {
                if ( it->get() == insertAfterThisNote.getCurrentNote().get() )
                {
                    myNotes.insert( it, shared );
                    return;
                }
            }
            THROW( "invalid note iter" )
        }
        
        static std::shared_ptr<Impl> getPtr( std::weak_ptr<NoteGroup::Impl>& weakPtr )
        {
            if ( weakPtr.expired() )
            {
                THROW( "invalid object state" )
            }
            auto temp = weakPtr.lock();
            if ( !temp )
            {
                THROW( "invalid object state" )
            }
            return temp;
        }
        
    private:
        Notes myNotes;
        NotesIter myCurrent;
        bool myIsInvalid;
    };

//////////////////////////////////////////////////////////////////////////////
// NoteGroup::Iter /////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

    template<typename T>
    std::shared_ptr<T> getPtr( const std::weak_ptr<T>& weakPtr )
    {
        if ( weakPtr.expired() )
        {
            THROW( "invalid object state" )
        }
        auto temp = weakPtr.lock();
        if ( !temp )
        {
            THROW( "invalid object state" )
        }
        return std::move( temp );
    }
    
    template<typename T>
    const std::shared_ptr<T>& checkPtr( const std::shared_ptr<T>& ptr )
    {
        if ( !ptr )
        {
            THROW( "invalid object state" )
        }
        return ptr;
    }
    
    template<typename T>
    std::shared_ptr<T>& checkPtr( std::shared_ptr<T>& ptr )
    {
        if ( !ptr )
        {
            THROW( "invalid object state" )
        }
        return ptr;
    }
    
    NoteGroup::Iter::Iter()
    :impl()
    ,myIsValid( false )
    {}
    
    NoteGroup::Iter::Iter( const std::shared_ptr<Impl> implInstance )
    :impl( implInstance )
    ,myIsValid( false )
    {
        auto temp = impl.lock();
        if ( !impl.expired() && temp )
        {
            myIsValid = true;
        }
    }
    
    NoteGroup::Iter::~Iter()
    {
        impl.reset();
    }
    
    bool NoteGroup::Iter::getIsValid() const
    {
        return getPtr( impl )->getIsValid();
    }
    
    bool NoteGroup::Iter::getIsFirst() const
    {
        return getPtr( impl )->getIsFirst();
    }
    
    bool NoteGroup::Iter::getIsLast() const
    {
        return getPtr( impl )->getIsLast();
    }
    
    bool NoteGroup::Iter::getIsEnd() const
    {
        return getPtr( impl )->getIsEnd();
    }
    
    const INoteSPC NoteGroup::Iter::getCurrentNote() const
    {
        return getPtr( impl )->getCurrentNote();
    }
    
    const INoteSPC NoteGroup::Iter::getNextNote() const
    {
        return getPtr( impl )->getNextNote();
    }
    
    const INoteSPC NoteGroup::Iter::getPreviousNote() const
    {
        return getPtr( impl )->getPreviousNote();
    }
    
    const INoteSP NoteGroup::Iter::getCurrentNote()
    {
        return getPtr( impl )->getCurrentNote();
    }
    
    const INoteSP NoteGroup::Iter::getNextNote()
    {
        return getPtr( impl )->getNextNote();
    }
    
    const INoteSP NoteGroup::Iter::getPreviousNote()
    {
        return getPtr( impl )->getPreviousNote();
    }
    
    void NoteGroup::Iter::next()
    {
        getPtr( impl )->next();
    }
    
    void NoteGroup::Iter::previous()
    {
        getPtr( impl )->previous();
    }
    
//////////////////////////////////////////////////////////////////////////////
// NoteGroup::IterConst ////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

    NoteGroup::IterConst::IterConst()
    :impl()
    ,myIsValid( false )
    {}
    
    NoteGroup::IterConst::IterConst( const std::shared_ptr<Impl> implInstance )
    :impl( implInstance )
    ,myIsValid( false )
    {
        auto temp = impl.lock();
        if ( !impl.expired() && temp )
        {
            myIsValid = true;
        }
    }
    
    NoteGroup::IterConst::~IterConst()
    {
        impl.reset();
    }
    
    bool NoteGroup::IterConst::getIsValid() const
    {
        return getPtr( impl )->getIsValid();
    }
    
    bool NoteGroup::IterConst::getIsFirst() const
    {
        return getPtr( impl )->getIsFirst();
    }
    
    bool NoteGroup::IterConst::getIsLast() const
    {
        return getPtr( impl )->getIsLast();
    }
    
    bool NoteGroup::IterConst::getIsEnd() const
    {
        return getPtr( impl )->getIsEnd();
    }
    
    const INoteSPC NoteGroup::IterConst::getCurrentNote() const
    {
        return getPtr( impl )->getCurrentNote();
    }
    
    const INoteSPC NoteGroup::IterConst::getNextNote() const
    {
        return getPtr( impl )->getNextNote();
    }
    
    const INoteSPC NoteGroup::IterConst::getPreviousNote() const
    {
        return getPtr( impl )->getPreviousNote();
    }
    
    void NoteGroup::IterConst::next()
    {
        getPtr( impl )->next();
    }
    
    void NoteGroup::IterConst::previous()
    {
        getPtr( impl )->previous();
    }
    
//////////////////////////////////////////////////////////////////////////////
// NoteGroup /////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    int NoteGroup::getSize() const
    {
    	return checkPtr( impl )->getSize();
    }
        
    NoteGroup::Iter NoteGroup::getIter()
    {
        checkPtr( impl );
        return Iter( impl );
    }

    const NoteGroup::IterConst NoteGroup::getIter( bool makeConst )
    {

    }
    
    const NoteGroup::Iter NoteGroup::getIter() const
    {

    }
    
        
    void NoteGroup::addNote( const INoteUP& note )
    {

    }
    
    void NoteGroup::removeNote( const NoteGroup::Iter& noteIter )
    {

    }
    
    void NoteGroup::removeNote( const NoteGroup::IterConst& noteIter )
    {

    }
        
    void NoteGroup::insertNote(
        const INoteUP& note,
        const NoteGroup::Iter& insertAfterThisNote )
    {

    }
        
    void NoteGroup::insertNote(
        const NoteGroup::IterConst& insertAfterThisNote,
        const INoteUP& note )
    {

    }
}
