//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IMovement.h"
#include "Lyre/IPartFactory.h"

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(Movement)
        
        class Movement : public IMovement
        {
        public:
            virtual ~Movement();
            
            Movement();
            
            Movement(
                const IMovementSpecUP& info,
                const VecIPartSpecUP& partSpecs,
                const IMasterTrackSPC& masterTrack,
                const IPartFactoryUP& partFactory );
            
            Movement( const Movement& other );
            Movement( Movement&& other )  noexcept;
            Movement& operator=( const Movement& other );
            Movement& operator=( Movement&& other )  noexcept;
            
            virtual IMovementUP clone() const;
            virtual IMovementUP move() noexcept;
            virtual std::ostream& toStream( std::ostream& os ) const;
            
            virtual const IMovementSpecUPC getInfo() const;
            
			virtual int getPartCount() const;
			virtual IPartH getPart( int measureIndex );
			virtual const IPartHC getPart( int measureIndex ) const;
			virtual const IPartHC getPartConst( int measureIndex ) const;
            
		private:
            
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE TYPEDEFS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            
            
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE DATA
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            IMovementSpecUP myInfo;
            IMasterTrackSPC myMasterTrack;
            VecIPartUP myParts;
            
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE FUNCTIONS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            void initializeParts(
                const VecIPartSpecUP& partSpecs,
                const IPartFactoryUP& partFactory );
            
            
        };
    } 
}
