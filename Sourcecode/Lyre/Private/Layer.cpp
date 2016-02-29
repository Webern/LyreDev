#include "Lyre/Private/Layer.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        Layer::~Layer()
        {
        }

        Layer::Layer()
        {

        }

        Layer::Layer( const Layer& other )
        {
            UNUSED_PARAMETER( other )
        }

        Layer::Layer( Layer&& other )
        {
            UNUSED_PARAMETER( other )
        }

        Layer& Layer::operator=( const Layer& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        Layer& Layer::operator=( Layer&& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        ILayerUP Layer::clone() const
        {
            return ILayerUP{ new Layer{ *this } };
        }

        std::ostream& Layer::toStream( std::ostream& os ) const
        {
            return os << "Layer not implemented";
        }
    }
}
