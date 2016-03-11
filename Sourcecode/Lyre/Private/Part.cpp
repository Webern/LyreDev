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
            , myLayerContext( 0 )
            , myStaves()
        {
            // unusable object - do not expose to clients
        }

        Part::Part(
                int numStaves,
                const IInstrumentUP& instrument )
            : myNumStaves( numStaves )
            , myInstrument( instrument->clone() )
            , myStaves( static_cast<std::size_t>( numStaves ) )
            , myStaffContext( 0 )
            , myLayerContext( 0 )
        {
            if ( numStaves < 1 )
            {
                THROW( "invalid number of staves - must be at least 1" )
            }
        }
        
        Part::Part( const Part& other )
            : myNumStaves( other.myNumStaves )
            , myInstrument( other.myInstrument->clone() )
            , myStaffContext( other.myStaffContext )
            , myLayerContext( other.myLayerContext )
            , myStaves( static_cast<size_t>( other.myNumStaves ) )
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
            , myLayerContext( std::move( other.myLayerContext ) )
            , myStaves( std::move( other.myStaves ) )
        {

        }

        Part& Part::operator=( const Part& other )
        {
            myNumStaves = other.myNumStaves;
            myInstrument = other.myInstrument->clone();
            myStaffContext = other.myStaffContext;
            myLayerContext = other.myLayerContext;
            myStaves = Staves{ static_cast<std::size_t>( myNumStaves ) };
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
            IPartUP newPartUP{ part };

            // re-initialize the guts of "this"
            this->myNumStaves = 1;
            this->myInstrument = IInstrumentUP{ new Instrument{ InstrumentName{ "default", "default" }, IRangeUP{ new Range{} } } };
            this->myStaffContext = 0;
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

        IMeasureUP Part::getMeasure( int index ) const
        {
            return MEASUREC( index )->clone();
        }

        void Part::addMeasure( IMeasureUP&& measure )
        {
            UNUSED_PARAMETER( measure )
        }

        void Part::replaceMeasure( IMeasureUP&& measure, int index )
        {
            UNUSED_PARAMETER( measure )
            UNUSED_PARAMETER( index )
        }

        void Part::insertMeasureAfter( IMeasureUP&& measure, int index )
        {
            UNUSED_PARAMETER( measure )
            UNUSED_PARAMETER( index )
        }

        void Part::insertMeasureBefore( IMeasureUP&& measure, int index )
        {
            UNUSED_PARAMETER( measure )
            UNUSED_PARAMETER( index )
        }

        void Part::removeMeasure( int index )
        {
            UNUSED_PARAMETER( index )
        }

        void Part::clearMeasure( int index )
        {
            UNUSED_PARAMETER( index )
        }

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
