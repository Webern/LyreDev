//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMeasure.h"
#include "Lyre/INote.h"
#include "Lyre/INoteGroup.h"
#include "Lyre/ITimeSignature.h"
#include <map>

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(Measure)
        
        using Layer = INoteGroupUP;
        using Layers = std::map<int, Layer>;
        using LayerIter = Layers::iterator;
        using LayerIterConst = Layers::const_iterator;
        
        class Measure : public IMeasure
        {
        public:
            virtual ~Measure();
            Measure( const ITimeSignatureUP& timeSignature );
            Measure( const Measure& other );
            Measure( Measure&& other );
            Measure& operator=( const Measure& other );
            Measure& operator=( Measure&& other );
            
            virtual IMeasureUP clone() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
            
            void setLayerContext( int layer );
            int getLayerContext() const;
            
            virtual bool getIsEmpty() const;
            virtual int getCount() const;
            virtual Rational getTotalDuration() const;
            virtual INoteUP getNote( int noteIndex ) const;
            virtual void addNote( const INoteUP& note );
            virtual void removeNote( int noteIndex );
            
            virtual int getGroupCount() const;
            virtual bool getIsInGroup( int noteIndex ) const;
            virtual int getGroupIndex( int noteIndex ) const;
            virtual INoteGroupUP getGroup( int groupIndex ) const;
            virtual void addGroup( const INoteGroupUP& group );
            virtual void removeGroup( int groupIndex );
            
        private:
            int myCurrentLayer;
            Layers myLayers;
            const int myMaxLayers;
            ITimeSignatureUP myTimeSignature;
            Rational myMaxDur;
            
            LayerIter getLayer();
            LayerIterConst getLayer() const;
            void copyLayers( const Layers& layers );
        };
    } 
}
