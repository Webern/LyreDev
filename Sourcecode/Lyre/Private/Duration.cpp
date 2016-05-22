#include "Lyre/Private/Duration.h"
#include "Lyre/Private/TupletDef.h"
#include "Lyre/Private/throw.h"
#include "Lyre/DurationConstants.h"
#include <sstream>

namespace Lyre
{
    namespace Private
    {
        std::map<Rational, IDurationUP> Duration::ourDurLut;
        
        Duration::~Duration() {};
        
        Duration::Duration()
        :myDurDotFactory( createDurDotFactory( DurDotFactoryType::Standard ) )
        ,myDurDot( myDurDotFactory->createDurDot() )
        ,myTuplets()
        {
            
        }
                           
        Duration::Duration( const String& durName )
        :myDurDotFactory( createDurDotFactory( DurDotFactoryType::Standard ) )
        ,myDurDot( myDurDotFactory->createDurDot( durName ) )
        ,myTuplets()
        {

        }
        
        Duration::Duration(
            const String& durName,
            const int dotCount )
        :myDurDotFactory( createDurDotFactory( DurDotFactoryType::Standard ) )
        ,myDurDot( myDurDotFactory->createDurDot( durName, dotCount ) )
        ,myTuplets()
        {

        }
        
        Duration::Duration(
            const VecITupletDefSPC& tuplets,
            const String& durName,
            const int dotCount )
        :myDurDotFactory( createDurDotFactory( DurDotFactoryType::Standard ) )
        ,myDurDot( myDurDotFactory->createDurDot( durName, dotCount ) )
        ,myTuplets( tuplets )
        {

        }
        
        Duration::Duration(
            const ITupletDefUP& tupletDef,
            const String& durName,
            const int dotCount )
        :myDurDotFactory( createDurDotFactory( DurDotFactoryType::Standard ) )
        ,myDurDot( myDurDotFactory->createDurDot( durName, dotCount ) )
        ,myTuplets()
        {
            myTuplets.push_back( tupletDef->clone() );
        }
        
        IDurationUP Duration::findDuration(
            Rational rational,
            bool doThrowOnBadInput )
        {
            if ( ourDurLut.size() == 0 )
            {
                initializeLut();
            }
            IDurationUP value;
            for ( auto i = ourDurLut.cbegin();
                  i != ourDurLut.cend(); ++i )
            {
                if ( i->first <= rational )
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
                if ( doThrowOnBadInput )
                {
                    THROW( "duration lookup failed" )
                }
                else
                {
                    return IDurationUP{ new Duration{ STR_QUARTER } };
                }
            }
            if ( value->getValue() == rational )
            {
                return std::move( value );
            }
            if ( doThrowOnBadInput )
            {
                THROW( "duration lookup failed" )
            }
            return value;
        }
        
        IDurationUP Duration::clone() const
        {
            Duration* d = new Duration{};
            d->myDurDot = this->myDurDot->clone();
            for ( auto t : myTuplets )
            {
                d->myTuplets.push_back( t->clone() );
            }
            return IDurationUP{ d };
        }
        
        IDurBaseUP Duration::getDurBase() const
        {
            return myDurDot->getDurBase();
        }
        
        Rational Duration::getDurBaseValue() const
        {
            return myDurDot->getDurBaseValue();
        }
        
        String Duration::getDurBaseName() const
        {
            return myDurDot->getDurBaseName();
        }
        
        int Duration::getDotCount() const
        {
            return myDurDot->getDotCount();
        }
        
        Rational Duration::getDottedBaseValue() const
        {
            return myDurDot->getValue();
        }
        
        String Duration::getDottedBaseName() const
        {
            return myDurDot->toString();
        }
        
        bool Duration::getIsTuplet() const
        {
            auto one = Rational{ 1, 1 };
            for ( auto t : myTuplets )
            {
                auto reducedTupletValue = t->getMultiplier();
                reducedTupletValue.reduce();
                
                if ( reducedTupletValue != one )
                {
                    return true;
                }
            }
            return false;
        }
        
        bool Duration::getIsNestedTuplet() const
        {
            return getTupletNestingCount() > 1;
        }
        
        int Duration::getTupletNestingCount() const
        {
            auto one = Rational{ 1, 1};
            int nestingCount = 0;
            for ( auto t : myTuplets )
            {
                auto reducedTupletValue = t->getMultiplier();
                reducedTupletValue.reduce();
                
                if ( reducedTupletValue != one )
                {
                    ++nestingCount;
                }
            }
            return nestingCount;
        }
        
        VecITupletDefSPCIterC Duration::getTupletsBegin() const
        {
            return myTuplets.cbegin();
        }
        
        VecITupletDefSPCIterC Duration::getTupletsEnd() const
        {
            return myTuplets.cend();
        }
        
        Rational Duration::getValue() const
        {
            if ( ! getIsTuplet() )
            {
                return myDurDot->getValue();
            }
            
            auto one = Rational{ 1, 1 };
            auto value = myDurDot->getValue();
            
            for ( auto t : myTuplets )
            {
                auto reducedTupletValue = t->getMultiplier();
                reducedTupletValue.reduce();
                
                if ( reducedTupletValue != one )
                {
                    value *= t->getMultiplier();
                }
                
            }
            
            return value;
        }
        
        std::ostream& Duration::toStream( std::ostream& os ) const
        {
            os << (*myDurDot);
            if ( ! getIsTuplet() )
            {
                return os;
            }
            int parenthesisCount = 0;
            auto one = Rational{ 1, 1 };
            for ( auto it = this->getTupletsBegin();
                  it != this->getTupletsEnd(); ++it )
            {
                auto reducedTupletValue = (*it)->getMultiplier();
                reducedTupletValue.reduce();
                if( ! ( reducedTupletValue == one ) )
                {
                    if ( parenthesisCount == 0 )
                    {
                        os << "^";
                    }
                    else // ( parenthesisCount > 0 )
                    {
                        os << " ";
                    }
                    ++parenthesisCount;
                    os << "( " << (*(*it));
                }
            }
            for ( int i = 0; i < parenthesisCount; ++i )
            {
                os << " )";
            }
            return os;
        }
        
        String Duration::toString() const
        {
            std::stringstream ss;
            toStream( ss );
            return ss.str();
        }
        
        void Duration::initializeLut()
        {
            addAllTuplets();
            addAllDurDots();
        }
        
        void Duration::addTuplet(
            const char* durName,
            int dots,
            int tupNum,
            int inTheSpaceOf )
        {
            IDurDotUP durDot;
            IDurDotUP tupDurDot;
            ITupletDefUP tupDef;
            VecITupletDefSPC tups;
            IDurationUP currDur;
            
            durDot = IDurDotUP{ new DurDot{ durName, dots } };
            tupDurDot = IDurDotUP{ new DurDot{ durName, 0 } };
            tupDef = ITupletDefUP{ new TupletDef{ tupNum, inTheSpaceOf, *tupDurDot } };
            tups.clear();
            tups.push_back( tupDef->clone() );
            currDur = IDurationUP{ new Duration( tups, durName, dots ) };
            ourDurLut[currDur->getValue()] = std::move( currDur );
        }
        
        void Duration::addTupletGroup(
         const char* durName,
         int tupNum,
         int inTheSpaceOf )
        {
            addTuplet( durName, 3, tupNum, inTheSpaceOf );
            addTuplet( durName, 2, tupNum, inTheSpaceOf );
            addTuplet( durName, 1, tupNum, inTheSpaceOf );
            addTuplet( durName, 0, tupNum, inTheSpaceOf );
        }
        
        void Duration::addTupletGroups( const char* durName )
        {
            addTupletGroup( durName, 9, 8 );
            addTupletGroup( durName, 7, 4 );
            addTupletGroup( durName, 5, 4 );
            addTupletGroup( durName, 3, 2 );
        }
        
        void Duration::addAllTuplets()
        {
            addTupletGroups( STR_256TH.c_str() );
            addTupletGroups( STR_128TH.c_str() );
            addTupletGroups( STR_64TH.c_str() );
            addTupletGroups( STR_32ND.c_str() );
            addTupletGroups( STR_16TH.c_str() );
            addTupletGroups( STR_EIGHTH.c_str() );
            addTupletGroups( STR_QUARTER.c_str() );
            addTupletGroups( STR_HALF.c_str() );
            addTupletGroups( STR_WHOLE.c_str() );
            addTupletGroups( STR_BREVE.c_str() );
            addTupletGroups( STR_LONGA.c_str() );
        }
        
        void Duration::addDurDots( const char* durName )
        {
            IDurationUP currDur;
            currDur = IDurationUP{ new Duration( durName, 3 ) };
            ourDurLut[currDur->getValue()] = std::move( currDur );
            
            currDur = IDurationUP{ new Duration( durName, 2 ) };
            ourDurLut[currDur->getValue()] = std::move( currDur );
            
            
            currDur = IDurationUP{ new Duration( durName, 1 ) };
            ourDurLut[currDur->getValue()] = std::move( currDur );
            
            
            currDur = IDurationUP{ new Duration( durName, 0 ) };
            ourDurLut[currDur->getValue()] = std::move( currDur );
        }
        
        void Duration::addAllDurDots()
        {
            addDurDots( STR_256TH.c_str() );
            addDurDots( STR_128TH.c_str() );
            addDurDots( STR_64TH.c_str() );
            addDurDots( STR_32ND.c_str() );
            addDurDots( STR_16TH.c_str() );
            addDurDots( STR_EIGHTH.c_str() );
            addDurDots( STR_QUARTER.c_str() );
            addDurDots( STR_HALF.c_str() );
            addDurDots( STR_WHOLE.c_str() );
            addDurDots( STR_BREVE.c_str() );
            addDurDots( STR_LONGA.c_str() );
        }
    }
}
