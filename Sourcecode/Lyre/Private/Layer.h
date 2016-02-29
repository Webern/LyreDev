//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/ILayer.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(Layer)
        
        class Layer : public ILayer
        {
        public:
            virtual ~Layer();
            Layer();
            Layer( const Layer& other );
            Layer( Layer&& other );
            Layer& operator=( const Layer& other );
            Layer& operator=( Layer&& other );
            
            virtual ILayerUP clone() const;
            virtual std::ostream& toStream( std::ostream& os ) const;
            
        private:
            
        };
    } 
}
