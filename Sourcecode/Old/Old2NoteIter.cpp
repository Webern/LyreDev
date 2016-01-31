#include "Lyre/NoteIter.h"
#include "Lyre/NoteGroup.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
	class NoteIter::Impl
    {
    public:
        Impl( NoteGroup* noteGroupP )
        :myNoteGroupP( 0 )
        ,myCurrent( 0 )
        {
            myNoteGroupP = noteGroupP;
            THROW_IF_NULL( myNoteGroup );
        }
        INoteGroup* myNoteGroupP;
        int myCurrent;
    };
    
#define NOTEGRP ( * ( myImplP->myNoteGroupP ) )
#define CURRENT ( myImplP->myCurrent )
    
    NoteIter::NoteIter( NoteGroup* noteGroupP )
    :myImplP( new Impl( noteGroupP ) )
    {
        THROW_IF_NULL( myImplP );
    }
    
    NoteIter::NoteIter( const NoteIter& other )
    :myImplP( new Impl( *( other.myImplP ) ) )
    {
        THROW_IF_NULL( myImplP );
    }
    
    NoteIter::NoteIter( NoteIter&& other )
    :myImplP( std::move( other.myImplP ) )
    {
        THROW_IF_NULL( myImplP );
    }
    
    NoteIter& NoteIter::operator=( const NoteIter& other )
    {
        myImplP = new Impl( *( other.myImplP ) );
        THROW_IF_NULL( myImplP );
        return *this;
    }
    
    NoteIter& NoteIter::operator=( NoteIter&& other )
    {
        myImplP = std::move( other.myImplP );
        THROW_IF_NULL( myImplP );
        return *this;
    }
    
    NoteIter::~NoteIter()
    {
        delete myImplP;
        myImplP = 0;
    }
    
    const INoteSP NoteIter::getPrevious() const
    {
        if ( CURRENT <= 0 )
        {
            THROW( "current position is 0, previous does not exist" )
        }
        return NOTEGRP.getNote( CURRENT - 1 );
    }
    
    const INoteSP NoteIter::getCurrent() const
    {
        
    }
    
    const INoteSP NoteIter::getNext() const
    {
        
    }
    
    const INoteSP NoteIter::getFirst() const
    {
        
    }
    
    const INoteSP NoteIter::getLast() const
    {
        
    }
    
    bool NoteIter::getIsEnd() const
    {
        
    }
    
    bool NoteIter::getIsBegin() const
    {
        
    }
    
    void NoteIter::setBegin()
    {
        
    }
    
    void NoteIter::setEnd()
    {
        
    }
    
    bool NoteIter::next()
    {
        
    }
    
    bool NoteIter::previous()
    {
        
    }
    
    void NoteIter::jump( const int index )
    {
        
    }
}