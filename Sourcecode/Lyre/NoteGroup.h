//PUBLIC
#pragma once
#include "Lyre/TypeDefs.h"
#include "Lyre/INote.h"
#include <memory>

namespace Lyre
{

    class NoteGroup;
    using NoteGroupUP = std::shared_ptr<NoteGroup>;
    using NoteGroupSP = std::unique_ptr<NoteGroup>;
    using NoteGroupUPC = std::shared_ptr<const NoteGroup>;
    using NoteGroupSPC = std::unique_ptr<const NoteGroup>;
    
    class NoteGroup
    {
    public:
        
        NoteGroup();
        virtual ~NoteGroup();
    
    private:
        class Impl;
    
    public:
        
        class Iter
        {
        public:
            Iter();
            virtual ~Iter();
            virtual bool getIsValid() const;
            virtual bool getIsFirst() const;
            virtual bool getIsLast() const;
            virtual bool getIsEnd() const;
            
            virtual const INoteSPC getCurrentNote() const;
            virtual const INoteSPC getNextNote() const;
            virtual const INoteSPC getPreviousNote() const;
            
            virtual const INoteSP getCurrentNote();
            virtual const INoteSP getNextNote();
            virtual const INoteSP getPreviousNote();
            
            virtual void next();
            virtual void previous();
            
        private:
            Iter( const std::shared_ptr<Impl> implInstance );
            std::weak_ptr<Impl> impl;
        };
        
        class IterConst
        {
        public:
            IterConst();
            virtual ~IterConst();
            virtual bool getIsValid() const;
            virtual bool getIsFirst() const;
            virtual bool getIsLast() const;
            virtual bool getIsEnd() const;
            
            virtual const INoteSPC getCurrentNote() const;
            virtual const INoteSPC getNextNote() const;
            virtual const INoteSPC getPreviousNote() const;
            
            virtual const INoteSP getCurrentNote();
            virtual const INoteSP getNextNote();
            virtual const INoteSP getPreviousNote();
            
            virtual void next();
            virtual void previous();
            
        private:
            IterConst( const std::shared_ptr<Impl> implInstance );
            std::weak_ptr<Impl> impl;
        };
        
        using NoteGroupIter = NoteGroup::Iter;
        
        virtual int getSize() const;
        
        virtual NoteGroupIter getIter();
        virtual const NoteGroupIter getIter( bool makeConst );
        virtual const NoteGroupIter getIter() const;
        
        virtual void addNote( const INoteUP& note );
        virtual void removeNote( const INoteUP& note );
        virtual void removeNote( const NoteGroupIter& noteIter );
        
        virtual void insertNote(
            const INoteUP& note,
            const NoteGroupIter& insertAfterThisNote );
        
    private:
        std::shared_ptr<Impl> impl;
    };
}
