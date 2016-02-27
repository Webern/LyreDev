//PUBLIC
#pragma once
#include "Lyre/INoteGroup.h"

namespace Lyre
{
    FORWARD_DECLARE(INoteGroup)
    FORWARD_DECLARE(INote)
    FORWARD_DECLARE(NoteGroup)
    
    PUBLIC INoteGroupUP createNoteGroup();
    
    class PUBLIC NoteGroup : public INoteGroup
    {
    public:
        virtual ~NoteGroup();
        NoteGroup();
        NoteGroup( const NoteGroup& other );
        NoteGroup( NoteGroup&& other ) noexcept;
        NoteGroup& operator=( const NoteGroup& other );
        NoteGroup& operator=( NoteGroup&& other ) noexcept;
        
        virtual INoteGroupUP clone() const ;
        virtual std::ostream& toStream( std::ostream& os ) const ;
        
        virtual bool getIsEmpty() const ;
        virtual int getCount() const ;
        virtual Rational getTotalDuration() const ;
        virtual INoteUP getNote( int noteIndex ) const ;
        virtual void add( const INoteUP& note ) ;
        virtual void remove( int noteIndex ) ;
        
        virtual int getGroupCount() const ;
        virtual bool getIsInGroup( int noteIndex ) const ;
        virtual int getGroupIndex( int noteIndex ) const ;
        virtual INoteGroupUP getGroup( int groupIndex ) const ;
        virtual void addGroup( const INoteGroupUP& group ) ;
        virtual void removeGroup( int subGroupIndex ) ;
        
    private:
        class Impl;
        Impl* myImplP;
    };
}
