#include "Lyre/Private/Measure.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"
#include "Lyre/Private/throw.h"
#include "Lyre/NoteGroup.h"

namespace Lyre
{
    namespace Private
    {
        Measure::~Measure()
        {
            
        }
        
        Measure::Measure( const ITimeSignatureUP& timeSignature )
        :myCurrentLayer( 0 )
        ,myLayers()
        ,myMaxLayers( MAX_NUMBER_OF_LAYERS )
        ,myTimeSignature( timeSignature->clone() )
        ,myMaxDur( timeSignature->getTotalDuration() )
        {
            if ( myMaxLayers <= 0 )
            {
                THROW( "max layers must be positive" )
            }
            for ( int i = 0; i < myMaxLayers; ++i )
            {
                myLayers[i] = INoteGroupUP{ new NoteGroup{} };
            }
        }

        Measure::Measure( const Measure& other )
        :myCurrentLayer( other.myCurrentLayer )
        ,myLayers()
        ,myMaxLayers( MAX_NUMBER_OF_LAYERS )
        ,myTimeSignature( other.myTimeSignature->clone() )
        ,myMaxDur( other.myTimeSignature->getTotalDuration() )
        {
            copyLayers( other.myLayers );
        }

        Measure::Measure( Measure&& other )
        :myCurrentLayer( std::move( other.myCurrentLayer ) )
        ,myLayers( std::move( other.myLayers ) )
        ,myMaxLayers( std::move( other.myMaxLayers ) )
        ,myTimeSignature( std::move( other.myTimeSignature ) )
        ,myMaxDur( std::move( other.myMaxDur ) )
        {
            
        }

        Measure& Measure::operator=( const Measure& other )
        {
            myCurrentLayer = other.myCurrentLayer;
            copyLayers( other.myLayers );
            myTimeSignature = other.myTimeSignature->clone();
            myMaxDur = other.myMaxDur;
            return *this;
        }

        Measure& Measure::operator=( Measure&& other )
        {
            myCurrentLayer = std::move( other.myCurrentLayer );
            myLayers = std::move( other.myLayers );
            myTimeSignature = std::move( other.myTimeSignature );
            myMaxDur = std::move( other.myMaxDur );
            return *this;
        }

        IMeasureUP Measure::clone() const
        {
            return IMeasureUP{ new Measure{ *this } };
        }

        IMeasureUP Measure::move()
        {
            Measure* measureP = new Measure( myTimeSignature );
            measureP->myCurrentLayer = std::move( myCurrentLayer );
            measureP->myLayers = std::move( myLayers );
            myCurrentLayer = 0;
            myLayers = Layers();
            return IMeasureUP( measureP );
        }

        std::ostream& Measure::toStream( std::ostream& os ) const
        {
            return os << "Measure not implemented";
        }
        
        void Measure::setLayerContext( int layer )
        {
            if ( layer < 0 || layer > myMaxLayers - 1 )
            {
                THROW( "index out of range" )
            }
            myCurrentLayer = layer;
        }
        
        int Measure::getLayerContext() const
        {
            return myCurrentLayer;
        }

        ITimeSignatureUP Measure::getTimeSignature() const
        {
            return myTimeSignature->clone();
        }

#define LAYER getLayer()->second
        
        bool Measure::getIsEmpty() const
        {
            return LAYER->getIsEmpty();
        }

        bool Measure::getIsComplete() const
        {
            return getTotalDuration() == myMaxDur;
        }
        
        int Measure::getCount() const
        {
            return LAYER->getCount();
        }
        
        Rational Measure::getTotalDuration() const
        {
            return LAYER->getTotalDuration();
        }
        
        INoteUP Measure::getNote( int noteIndex ) const
        {
            return LAYER->getNote( noteIndex );
        }
        
        void Measure::addNote( const INoteUP& note )
        {
            Rational curTot = LAYER->getTotalDuration();
            Rational noteDur = note->getDuration()->getValue();
            if ( ( curTot + noteDur ) <= myMaxDur )
            {
                LAYER->addNote( note );
            }
            else
            {
                THROW( "beyond capacity" )
            }
        }
        
        void Measure::removeNote( int noteIndex )
        {
            LAYER->removeNote( noteIndex );
        }
        
        int Measure::getGroupCount() const
        {
            return LAYER->getGroupCount();
        }
        
        bool Measure::getIsInGroup( int noteIndex ) const
        {
            return LAYER->getIsInGroup( noteIndex );
        }
        
        int Measure::getGroupIndex( int noteIndex ) const
        {
            return LAYER->getGroupIndex( noteIndex );
        }
        
        INoteGroupUP Measure::getGroup( int groupIndex ) const
        {
            return LAYER->getGroup( groupIndex );
        }
        
        void Measure::addGroup( const INoteGroupUP& group )
        {
            Rational curTot = LAYER->getTotalDuration();
            Rational groupDur = group->getTotalDuration();
            if ( ( curTot + groupDur ) <= myMaxDur )
            {
                LAYER->addGroup( group );
            }
            else
            {
                THROW( "beyond capacity" )
            }
        }
        
        void Measure::removeGroup( int groupIndex )
        {
            LAYER->removeGroup( groupIndex );
        }
        
        LayerIter Measure::getLayer()
        {
            LayerIter it = myLayers.find( myCurrentLayer );
            if ( it == myLayers.end() )
            {
                THROW( "bad internal state" )
            }
            return it;
        }
        
        LayerIterConst Measure::getLayer() const
        {
            LayerIterConst it = myLayers.find( myCurrentLayer );
            if ( it == myLayers.cend() )
            {
                THROW( "bad internal state" )
            }
            return it;
        }
        
        void Measure::copyLayers( const Layers& layers )
        {
            myLayers.clear();
            for ( auto i = layers.cbegin(); i != layers.cend(); ++i )
            {
                if ( i->second )
                {
                    myLayers[i->first] = i->second->clone();
                }
            }
        }
    }
}
