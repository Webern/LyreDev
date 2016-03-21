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

        Movement::Movement(
            const IMovementSpecUP& info,
            const VecIPartSpecUP& partSpecs,
            const IMasterTrackSPC& masterTrack,
            const IPartFactoryUP& partFactory  )
        
        : myInfo( info->clone() )
        , myMasterTrack( masterTrack )
        , myParts()
        {
            THROW_IF_NULL( masterTrack )
            THROW_IF_NULL( partFactory )
            THROW_IF_BAD_VALUE( partSpecs.size(), 0, INT_MAX )
            initializeParts( partSpecs, partFactory );
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

        
        const IMovementSpecUPC Movement::getInfo() const
        {
            return myInfo->clone();
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
        
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE FUNCTIONS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        void Movement::initializeParts(
            const VecIPartSpecUP& partSpecs,
            const IPartFactoryUP& partFactory )
        {
            
            for ( auto it = partSpecs.cbegin(); it != partSpecs.cend(); ++it )
            {
                THROW_IF_NULL( *it )
                UNUSED_PARAMETER( partFactory )
                auto part = partFactory->create( *it, myMasterTrack );
            }
        }
        
    }
}
