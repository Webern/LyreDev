#include "Lyre/Private/Movement.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        Movement::~Movement()
        {
            
        }
        
        Movement::Movement()
        {
            
        }

        Movement::Movement( const IMasterTrackSPC& masterTrack )
        {
            UNUSED_PARAMETER( masterTrack )
        }

        Movement::Movement( const Movement& other )
        {
            UNUSED_PARAMETER( other )
        }

        Movement::Movement( Movement&& other ) noexcept
        {
            UNUSED_PARAMETER( other )
        }

        Movement& Movement::operator=( const Movement& other )
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        Movement& Movement::operator=( Movement&& other ) noexcept
        {
            UNUSED_PARAMETER( other )
            return *this;
        }

        
        IMovementUP Movement::clone() const
        {
            return IMovementUP{ new Movement{ *this } };
        }
        
        
        IMovementUP Movement::move() noexcept
        {
            return IMovementUP{};
        }
        

        std::ostream& Movement::toStream( std::ostream& os ) const
        {
            return os << "Movement not implemented";
        }


		int Movement::getPartCount() const
		{
			return 0;
		}


		IPartH Movement::getPart( int measureIndex )
		{
			UNUSED_PARAMETER( measureIndex )
			return IPartH( nullptr );
		}


		const IPartHC Movement::getPart( int measureIndex ) const
		{
			UNUSED_PARAMETER( measureIndex )
			return getPartConst( measureIndex );
		}


		const IPartHC Movement::getPartConst( int measureIndex ) const
		{
			UNUSED_PARAMETER( measureIndex )
			return IPartHC( nullptr );
		}

    }
}
