//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IPart.h"
#include "Lyre/IMeasure.h"
#include "Lyre/IInstrument.h"
#include "Lyre/IMasterTrack.h"
#include "Lyre/IPartSpec.h"
#include <map>

namespace Lyre
{
    namespace Private
    {
        FORWARD_DECLARE(Part)

        class Part : public IPart
        {
        public:
            virtual ~Part();
            
            Part(
                const IPartSpecUP& spec,
                const IMasterTrackSPC& masterTrack );

            Part( const Part& other );
            Part( Part&& other )  noexcept;
            Part& operator=( const Part& other );
            Part& operator=( Part&& other )  noexcept;

            virtual IPartUP clone() const;
            virtual IPartUP move() noexcept;
            virtual std::ostream& toStream( std::ostream& os ) const;

            virtual void setStaffContext( int staffIndex );
            virtual int getStaffContext() const;
            
            virtual int getMeasureCount() const;
            virtual IMeasureH getMeasure( int measureIndex );
			virtual const IMeasureHC getMeasure( int measureIndex ) const;
            virtual const IMeasureHC getMeasureConst( int measureIndex ) const;

		private:

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE TYPEDEFS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

            using Measures = VecIMeasureUP;
            using MeasureIter = VecIMeasureUPIter;
            using MeasureIterConst = VecIMeasureUPIterC;
            
            using Staves = std::vector<Measures>;
            using StaffIter = Staves::iterator;
            using StaffIterConst = Staves::const_iterator;
            
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE DATA
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            IPartSpecUP myPartSpec;
            IMasterTrackSPC myMasterTrack;
            Staves myStaves;
			int myStaffContext;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE FUNCTIONS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            Part();
            void initializeMeasures( int numStaves );
            void cloneStaves( const Staves& otherStaves );
        };
    } 
}
