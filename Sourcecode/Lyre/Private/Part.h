//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IPart.h"
#include "Lyre/IMeasure.h"
#include "Lyre/IInstrument.h"
#include "Lyre/IMasterTrack.h"
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

            Part();
            
            Part(
                int numStaves,
                const IInstrumentUP& instrument,
                const IMasterTrackSPC& masterTrack );

            Part( const Part& other );
            Part( Part&& other )  noexcept;
            Part& operator=( const Part& other );
            Part& operator=( Part&& other )  noexcept;

            virtual IPartUP clone() const;
            virtual IPartUP move() noexcept;
            virtual std::ostream& toStream( std::ostream& os ) const;

            void setStaffContext( int staffIndex );
            int getStaffContext() const;
            void setMessureContext( int measureIndex );
            int getMeasureContext() const;
            void setLayerContext( int layerContext );
            int getLayerContext() const;

            virtual ITimeSignatureUP getTimeSignature() const;

            virtual void clearLayer();
            virtual void clearMeasure();
        
            virtual bool getIsEmpty() const;
            virtual bool getIsComplete() const;
            virtual int getCount() const;
            virtual Rational getUnusedRemaining() const;
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
            
            using Measures = VecIMeasureUP;
            using MeasureIter = VecIMeasureUPIter;
            using MeasureIterConst = VecIMeasureUPIterC;
            
            using Staves = std::vector<Measures>;
            using StaffIter = Staves::iterator;
            using StaffIterConst = Staves::const_iterator;
            
            int myNumStaves;
            IInstrumentUPC myInstrument;
            int myStaffContext;
            int myMeasureContext;
            int myLayerContext;
            Staves myStaves;
            IMasterTrackSPC myMasterTrack;

            StaffIter getCurrentStaff();
            StaffIterConst getCurrentStaffConst() const;
            MeasureIter getMeasureIter( int index );
            MeasureIterConst getMeasureIterConst( int index ) const;

            // callbacks from MasterTrack
            // void deleteMeasures( const std::vector<int>& measureToDelete );
            // void appendMeasures( std::map<int, ITimeSignatureUPC>& timeSignatureMap );
        };
    } 
}
