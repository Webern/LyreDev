#include "Lyre/Private/Layer.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        class Layer::Impl
        {

        };

        Layer::~Layer()
        {
            delete myImplP;
            myImplP = 0;
        }

        Layer::Layer()
            :myImplP( 0 )
        {
            myImplP = new Impl();
        }

        Layer::Layer( const Layer& other )
            :myImplP( 0 )
        {
            myImplP = new Impl( *other.myImplP );
        }

        Layer::Layer( Layer&& other )
            :myImplP( std::move( other.myImplP ) )
        {
            other.myImplP = 0;
        }

        Layer& Layer::operator=( const Layer& other )
        {
            myImplP = new Impl( *other.myImplP );
            return *this;
        }

        Layer& Layer::operator=( Layer&& other )
        {
            myImplP = std::move( other.myImplP );
            other.myImplP = 0;
            return *this;
        }

        INoteGroupUP Layer::clone() const
        {
            return ILayerUP{ new Layer{ *this } };
        }

        ILayerUP Layer::copyLayer() const
        {
            return ILayerUP( new Layer( *this ) );
        }

        std::ostream& Layer::toStream( std::ostream& os ) const
        {
            return os << "Layer not implemented";
        }
    }
}
