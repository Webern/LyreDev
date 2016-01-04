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
            bool myIsValid;
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
            bool myIsValid;
        };
        
        virtual int getSize() const;
        
        virtual NoteGroup::Iter getIter();
        virtual const NoteGroup::IterConst getIter( bool makeConst ) const;
        virtual const NoteGroup::IterConst getIter() const;
        
        virtual void addNote( const INoteUP& note );
        virtual void removeNote( const NoteGroup::Iter& noteIter );
        virtual void removeNote( const NoteGroup::IterConst& noteIter );
        
        virtual void insertNote(
            const INoteUP& note,
            const NoteGroup::Iter& insertAfterThisNote );
        
        virtual void insertNote(
            const INoteUP& note,
            const NoteGroup::IterConst& insertAfterThisNote );
        
    private:
        std::shared_ptr<Impl> impl;
    };
}
