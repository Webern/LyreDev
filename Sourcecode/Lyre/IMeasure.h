//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/ITimeSignature.h"
#include "Lyre/INote.h"
#include "Lyre/INoteGroup.h"
#include "Lyre/Handle.h"

namespace Lyre
{
    FORWARD_DECLARE(IMeasure)
    using IMeasureH = Handle<IMeasureUP>;
    using IMeasureHC = HandleConst<IMeasureUP>;
    
    static const int MAX_NUMBER_OF_LAYERS = 4;
    
    class PUBLIC IMeasure : public IStreamable
    {
    public:
        virtual ~IMeasure() {}
        virtual IMeasureUP clone() const = 0;
        virtual IMeasureUP move() = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
            
        virtual void setLayerContext( int layer ) = 0;
        virtual int getLayerContext() const = 0;
        virtual ITimeSignatureUP getTimeSignature() const = 0;

        virtual void clearLayer() = 0;
        virtual void clearMeasure() = 0;
        
        virtual bool getIsEmpty() const = 0;
        virtual bool getIsComplete() const = 0;
        virtual int getCount() const = 0;
        virtual Rational getUnusedRemaining() const = 0;
        virtual Rational getTotalDuration() const = 0;
        virtual const INoteUP& getNote( int noteIndex ) const = 0;
        virtual void addNote( const INoteUP& note ) = 0;
        virtual void removeNote( int noteIndex ) = 0;
            
        virtual int getGroupCount() const = 0;
        virtual bool getIsInGroup( int noteIndex ) const = 0;
        virtual int getGroupIndex( int noteIndex ) const = 0;
        virtual const INoteGroupUP& getGroup( int groupIndex ) const = 0;
        virtual void addGroup( const INoteGroupUP& group ) = 0;
        virtual void removeGroup( int groupIndex ) = 0;
        
    };
}
