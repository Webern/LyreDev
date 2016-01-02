#include "Lyre/Private/Duration.h"
#include "Lyre/Private/DurDot.h"
#include "Lyre/IDurDotFactory.h"
#include "Lyre/IDurDot.h"
#include "Lyre/Private/throw.h"
#include "Lyre/ITupletDefFactory.h"
#include <sstream>

namespace Lyre
{
    namespace Private
    {
        Duration::~Duration() {};
        
        Duration::Duration()
        :myDurDotFactory( createDurDotFactory( DurDotFactoryType::Standard ) )
        ,myDurDot( myDurDotFactory->createDurDot() )
        ,myTuplets()
        {}
                           
        Duration::Duration( const String& durName )
        :myDurDotFactory( createDurDotFactory( DurDotFactoryType::Standard ) )
        ,myDurDot( myDurDotFactory->createDurDot( durName ) )
        ,myTuplets()
        {}
        
        Duration::Duration(
            const String& durName,
            const Integer dotCount )
        :myDurDotFactory( createDurDotFactory( DurDotFactoryType::Standard ) )
        ,myDurDot( myDurDotFactory->createDurDot( durName, dotCount ) )
        ,myTuplets()
        {}
        
        Duration::Duration(
            const ITupletDefSPCs& tuplets,
            const String& durName,
            const Integer dotCount )
        :myDurDotFactory( createDurDotFactory( DurDotFactoryType::Standard ) )
        ,myDurDot( myDurDotFactory->createDurDot( durName, dotCount ) )
        ,myTuplets( tuplets )
        {}
        
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
        
        Rational Duration::getDurBaseValue() const
        {
            return myDurDot->getDurBaseValue();
        }
        
        String Duration::getDurBaseName() const
        {
            return myDurDot->getDurBaseName();
        }
        
        Integer Duration::getDotCount() const
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
            auto one = Rational{ 1, 1};
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
        
        ITupletDefSPCsIter Duration::getTupletsBegin() const
        {
            return myTuplets.cbegin();
        }
        
        ITupletDefSPCsIter Duration::getTupletsEnd() const
        {
            return myTuplets.cend();
        }
        
        Rational Duration::getValue() const
        {
            return Rational{ 1, 1 };
        }
        
        std::ostream& Duration::toStream( std::ostream& os ) const
        {
            return os << "not implemented";
        }
        
        String Duration::toString() const
        {
            std::stringstream ss;
            toStream( ss );
            return ss.str();
        }
    }
}
