#include "Lyre/Private/Part.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"
#include "Lyre/Private/throw.h"
#include "Lyre/IInstrument.h"
#include "Lyre/Private/Instrument.h"
#include "Lyre/Private/Range.h"

namespace Lyre
{
    namespace Private
    {

        #define LAYER ( getCurrentLayer() )
        #define LAYERC ( getCurrentLayerConst() )
        #define MEASURE( index_number ) ( *getMeasureIter( index_number) )
        #define MEASUREC( index_number ) ( *getMeasureIterConst( index_number) )

        Part::~Part()
        {
        }

        Part::Part()
            : myNumStaves(0)
            , myInstrument( nullptr )
            , myStaffContext( 0 )
            , myMeasureContext( 0 )
            , myLayerContext( 0 )
            , myStaves()
            , myMasterTrack( nullptr )
        {
            // unusable object - do not expose to clients
        }

        Part::Part(
                int numStaves,
                const IInstrumentUP& instrument,
                const IMasterTrackSPC& masterTrack )
            : myNumStaves( numStaves )
            , myInstrument( instrument->clone() )
            , myStaffContext( 0 )
            , myMeasureContext( 0 )
            , myLayerContext( 0 )
            , myStaves( static_cast<std::size_t>( numStaves ) )
            , myMasterTrack( masterTrack )
        {
            THROW_IF_NULL( myMasterTrack )
            if ( numStaves < 1 )
            {
                THROW( "invalid number of staves - must be at least 1" )
            }
        }
        
        Part::Part( const Part& other )
            : myNumStaves( other.myNumStaves )
            , myInstrument( other.myInstrument->clone() )
            , myStaffContext( other.myStaffContext )
            , myMeasureContext( other.myMeasureContext )
            , myLayerContext( other.myLayerContext )
            , myStaves( static_cast<size_t>( other.myNumStaves ) )
            , myMasterTrack( other.myMasterTrack )
        {
            StaffIter my_staff = myStaves.begin();
            for ( StaffIterConst other_staff = other.myStaves.cbegin();
                  other_staff != other.myStaves.cend();
                ++other_staff, ++my_staff )
            {
                for ( auto measure = other_staff->cbegin();
                      measure != other_staff->cend();
                      ++measure )
                {
                    my_staff->push_back( ( *measure )->clone() );
                }
            }
        }

        Part::Part( Part&& other ) noexcept
           :  myNumStaves( std::move( other.myNumStaves ) )
            , myInstrument( std::move( other.myInstrument ) )
            , myStaffContext( std::move( other.myStaffContext ) )
            , myMeasureContext( std::move( other.myMeasureContext ) )
            , myLayerContext( std::move( other.myLayerContext ) )
            , myStaves( std::move( other.myStaves ) )
            , myMasterTrack( std::move(other.myMasterTrack ) )
        {

        }

        Part& Part::operator=( const Part& other )
        {
            myNumStaves = other.myNumStaves;
            myInstrument = other.myInstrument->clone();
            myStaffContext = other.myStaffContext;
            myMeasureContext = other.myMeasureContext;
            myLayerContext = other.myLayerContext;
            myStaves = Staves{ static_cast<std::size_t>( myNumStaves ) };
            myMasterTrack = other.myMasterTrack;
            StaffIter my_staff = myStaves.begin();
            for ( StaffIterConst other_staff = other.myStaves.cbegin();
                  other_staff != other.myStaves.cend();
                ++other_staff, ++my_staff )
            {
                for ( auto measure = other_staff->cbegin();
                      measure != other_staff->cend();
                      ++measure )
                {
                    my_staff->push_back( ( *measure )->clone() );
                }
            }
            return *this;
        }

        Part& Part::operator=( Part&& other ) noexcept
        {
            myNumStaves = std::move( other.myNumStaves );
            myInstrument = std::move( other.myInstrument );
            myStaffContext = std::move( other.myStaffContext );
            myLayerContext = std::move( other.myLayerContext );
            myStaves = std::move( other.myStaves );
            myMasterTrack = std::move( other.myMasterTrack );
            
            return *this;
        }

        IPartUP Part::clone() const
        {
            return IPartUP{ new Part{ *this } };
        }

        IPartUP Part::move() noexcept
        {
            // move the guts of "this"
            Part* part = new Part{};
            part->myNumStaves = this->myNumStaves;
            part->myInstrument = std::move( this->myInstrument );
            part->myStaffContext = std::move( this->myStaffContext );
            part->myLayerContext = std::move( this->myLayerContext );
            part->myStaves = std::move( this->myStaves );
            part->myMasterTrack = this->myMasterTrack;
            IPartUP newPartUP{ part };

            // re-initialize the guts of "this" to avoid nullptr crashes
            this->myNumStaves = 1;
            this->myInstrument = IInstrumentUP{ new Instrument{ InstrumentName{ "default", "default" }, IRangeUP{ new Range{} } } };
            this->myStaffContext = 0;
            this->myMeasureContext = 0;
            this->myLayerContext = 0;
            this->myStaves = Staves( 1 );

            return std::move( newPartUP );
        }

        std::ostream& Part::toStream( std::ostream& os ) const
        {
            String sep( "//////////" );
            String space( "   " );
            return os << sep << space << (*myInstrument) << space << sep;
        }

        void Part::setStaffContext( int staffIndex )
        {
            if ( staffIndex < 0 || staffIndex > myNumStaves - 1 )
            {
                THROW( "index out of range" );
            }
            myStaffContext = staffIndex;
        }

        int Part::getStaffContext() const
        {
            return myStaffContext;
        }

        void Part::setMessureContext( int measureIndex )
        {
            if ( measureIndex < 0 )
            {
                THROW( "index out of range" )
            }
            myMeasureContext = measureIndex;
        }

        int Part::getMeasureContext() const
        {
            return 0;
        }

        void Part::setLayerContext( int layerContext )
        {
            if ( layerContext < 0 || layerContext > MAX_NUMBER_OF_LAYERS - 1 )
            {
                THROW( "index out of range" );
            }
        }

        int Part::getLayerContext() const
        {
            return myLayerContext;
        }

        ITimeSignatureUP Part::getTimeSignature() const
        {
            return ITimeSignatureUP();
        }

        void Part::clearLayer()
        {
        }

        void Part::clearMeasure()
        {
        }

        bool Part::getIsEmpty() const
        {
            return false;
        }

        bool Part::getIsComplete() const
        {
            return false;
        }

        int Part::getCount() const
        {
            return 0;
        }

        Rational Part::getUnusedRemaining() const
        {
            return Rational();
        }

        Rational Part::getTotalDuration() const
        {
            return Rational();
        }

        INoteUP Part::getNote( int noteIndex ) const
        {
            UNUSED_PARAMETER( noteIndex )
            return INoteUP();
        }

        void Part::addNote( const INoteUP & note )
        {
            UNUSED_PARAMETER( note )
        }

        void Part::removeNote( int noteIndex )
        {
            UNUSED_PARAMETER( noteIndex )
        }

        int Part::getGroupCount() const
        {
            return 0;
        }

        bool Part::getIsInGroup( int noteIndex ) const
        {
            UNUSED_PARAMETER( noteIndex )
            return false;
        }

        int Part::getGroupIndex( int noteIndex ) const
        {
            UNUSED_PARAMETER( noteIndex )
            return 0;
        }

        INoteGroupUP Part::getGroup( int groupIndex ) const
        {
            UNUSED_PARAMETER( groupIndex )
            return INoteGroupUP();
        }

        void Part::addGroup( const INoteGroupUP & group )
        {
            UNUSED_PARAMETER( group )
        }

        void Part::removeGroup( int groupIndex )
        {
            UNUSED_PARAMETER( groupIndex )
        }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        Part::StaffIter Part::getCurrentStaff()
        {
            return std::begin( myStaves ) + myStaffContext;
        }

        Part::StaffIterConst Part::getCurrentStaffConst() const
        {
            return std::begin( myStaves ) + myStaffContext;
        }

        Part::MeasureIter Part::getMeasureIter( int index )
        {
            return std::begin( *getCurrentStaff() ) + index;
        }

        Part::MeasureIterConst Part::getMeasureIterConst( int index ) const
        {
            return getCurrentStaffConst()->cbegin() + index;
        }
    }
}
