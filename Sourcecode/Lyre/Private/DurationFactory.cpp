#include "Lyre/Private/DurationFactory.h"
#include "Lyre/Private/Duration.h"
#include "Lyre/Private/DurDot.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/ITupletDefFactory.h"
#include "Lyre/IDurDotFactory.h"
#include "Lyre/IDurDot.h"
#include "Lyre/Private/throw.h"
#include <sstream>

namespace Lyre
{
    namespace Private
    {
        DurationFactory::~DurationFactory() {}
        
        DurationFactory::DurationFactory()
        :myLut()
        {
            createLut();
        }
        
        DurationFactory::DurationFactory( const DurationFactory& other )
        :myLut()
        {
            copyLut( other.myLut );
        }
        
        DurationFactory::DurationFactory( DurationFactory&& other )
        :myLut( std::move( other.myLut ) )
        {
            
        }
        
        DurationFactory& DurationFactory::operator=( const DurationFactory& other )
        {
            copyLut( other.myLut );
            return *this;
        }
        
        DurationFactory& DurationFactory::operator=( DurationFactory&& other )
        {
            myLut = std::move( other.myLut );
            return *this;
        }
        
        IDurationUP DurationFactory::createDuration(
            const String& durName ) const
        {
            return IDurationUP{ new Duration { durName } };
        }
        
        IDurationUP DurationFactory::createDuration(
            const String& durName,
            const int dotCount ) const
        {
            return IDurationUP{ new Duration { durName, dotCount } };
        }
        
        IDurationUP DurationFactory::createDuration(
            const VecITupletDefSPC& tuplets,
            const String& durName,
            const int dotCount ) const
        {
            return IDurationUP{ new Duration { tuplets, durName, dotCount } };
        }
        
        IDurationUP DurationFactory::createDuration(
            const Rational& rational,
            bool doThrowOnBadInput ) const
        {
            return find( rational, doThrowOnBadInput );
        }
        
        void DurationFactory::createLut()
        {
            myLut.clear();
            
            auto tupFactory = createTupletDefFactory( TupletDefFactoryType::Standard );
            auto durDotFactory = createDurDotFactory( DurDotFactoryType::Standard );
            
            IDurationUP currDur;
            IDurDotUP currDurDot;
            ITupletDefUP currTup;
            VecITupletDefSPC tuplets;

            #define ADD_DUR_LUT_TUP( dots, durBaseName, count, inTheSpaceOf ) \
            currDurDot = durDotFactory->createDurDot( durBaseName, dots ); \
            currTup = tupFactory->createTupletDef( count, inTheSpaceOf, *currDurDot ); \
            tuplets.clear(); \
            tuplets = { currTup->clone() }; \
            currDur = this->createDuration( tuplets , durBaseName, dots ); \
            myLut[ currDur->getValue() ] = currDur->clone();

            #define ADD_DUR_LUT_TUPS( theName ) \
            ADD_DUR_LUT_TUP( 3, theName, 3, 2 ) \
            ADD_DUR_LUT_TUP( 3, theName, 5, 4 ) \
            ADD_DUR_LUT_TUP( 3, theName, 7, 4 ) \
            ADD_DUR_LUT_TUP( 2, theName, 3, 2 ) \
            ADD_DUR_LUT_TUP( 2, theName, 5, 4 ) \
            ADD_DUR_LUT_TUP( 2, theName, 7, 4 ) \
            ADD_DUR_LUT_TUP( 1, theName, 3, 2 ) \
            ADD_DUR_LUT_TUP( 1, theName, 5, 4 ) \
            ADD_DUR_LUT_TUP( 1, theName, 7, 4 ) \
            ADD_DUR_LUT_TUP( 0, theName, 3, 2 ) \
            ADD_DUR_LUT_TUP( 0, theName, 5, 4 ) \
            ADD_DUR_LUT_TUP( 0, theName, 7, 4 )
            
            #define ADD_DUR_LUT( name ) \
            currDur = createDuration( name); \
            myLut[ currDur->getValue() ] = currDur->clone(); \
            \
            currDur = createDuration( name, 1 ); \
            myLut[ currDur->getValue() ] = currDur->clone(); \
            \
            currDur = createDuration( name, 2 ); \
            myLut[ currDur->getValue() ] = currDur->clone(); \
            \
            currDur = createDuration( name, 3 ); \
            myLut[ currDur->getValue() ] = currDur->clone(); \
            
            
            ADD_DUR_LUT_TUPS( "256th" )
            ADD_DUR_LUT_TUPS( "128th" )
            ADD_DUR_LUT_TUPS( "64th" )
            ADD_DUR_LUT_TUPS( "32nd" )
            ADD_DUR_LUT_TUPS( "16th" )
            ADD_DUR_LUT_TUPS( "Eighth" )
            ADD_DUR_LUT_TUPS( "Quarter" )
            ADD_DUR_LUT_TUPS( "Half" )
            ADD_DUR_LUT_TUPS( "Whole" )
            ADD_DUR_LUT_TUPS( "Breve" )
            ADD_DUR_LUT_TUPS( "Longa" )
            
            ADD_DUR_LUT( "256th" )
            ADD_DUR_LUT( "128th" )
            ADD_DUR_LUT( "64th" )
            ADD_DUR_LUT( "32nd" )
            ADD_DUR_LUT( "16th" )
            ADD_DUR_LUT( "Eighth" )
            ADD_DUR_LUT( "Quarter" )
            ADD_DUR_LUT( "Half" )
            ADD_DUR_LUT( "Whole" )
            ADD_DUR_LUT( "Breve" )
            ADD_DUR_LUT( "Longa" )
            
            #if 1==0
            for ( auto i = myLut.cbegin(); i != myLut.cend(); ++i )
            {
                std::cout << i->first << " ";
                std::cout << (*i->second) << std::endl;
            }
            #endif
        }
        
        void DurationFactory::copyLut( const std::map<Rational,IDurationUP>& other )
        {
            myLut.clear();
            for ( auto i = other.cbegin(); i != other.cend(); ++i )
            {
                myLut[ i->first ] = i->second->clone();
            }
        }
        
        IDurationUP DurationFactory::find( const Rational& r, bool doThrow ) const
        {
            IDurationUP value;
            for ( auto i = myLut.cbegin(); i != myLut.cend(); ++i )
            {
                if ( i->first <= r )
                {
                    value = i->second->clone();
                }
                else
                {
                    break;
                }
            }
            if ( value == nullptr )
            {
                if ( doThrow )
                {
                    THROW( "duration lookup failed" )
                }
                else
                {
                    return createDuration( "Quarter" );
                }
            }
            if ( value->getValue() == r )
            {
                return std::move( value );
            }
            if ( doThrow )
            {
                THROW( "duration lookup failed" )
            }
            return value;
        }
    }
}
