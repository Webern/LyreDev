//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IPart.h"
#include "Lyre/IMeasure.h"
#include "Lyre/IInstrument.h"

namespace Lyre
{
    namespace Private
    {
        //FORWARD_DECLARE(Part)

        class Part : public IPart
        {
        public:
            virtual ~Part();

            Part(
                int numStaves,
                const IInstrumentUP& instrument );

            Part( const Part& other );
            Part( Part&& other );
            Part& operator=( const Part& other );
            Part& operator=( Part&& other );

            virtual IPartUP clone() const;
            virtual std::ostream& toStream( std::ostream& os ) const;

            void setStaffContext( int staffIndex );
            int getStaffContext() const;
            void setLayerContext( int layerContext );
            int getLayerContext() const;
            
            IMeasureUP getMeasure( int index ) const;
            void addMeasure( const IMeasureUP&& measure );
            void replaceMeasure( const IMeasureUP&& measure, int index );
            void insertMeasureAfter( const IMeasureUP&& measure, int index );
            void insertMeasureBefore( const IMeasureUP&& measure, int index );
            void removeMeasure( int index );
            void clearMeasure( int index );

        private:
            
            using Staff = VecIMeasureUP;
            using StaffIter = VecIMeasureUPCIter;
            using StaffIterConst = VecIMeasureUPCIterC;
            
            using Staves = std::vector<Staff>;
            using StavesIter = Staves::iterator;
            using StavesIterConst = Staves::const_iterator;
            
            int myNumStaves;
            IInstrumentUPC myInstrument;
            int myStaffContext;
            int myLayerContext;
            Staves myStaves;
        };
    } 
}
