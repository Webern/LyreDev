#include "Lyre/Private/Duration.h"
#include "Lyre/Private/DurDot.h"
#include "Lyre/IDurDotFactory.h"
#include "Lyre/IDurDot.h"
#include "Lyre/Private/throw.h"
#include <sstream>

namespace Lyre
{
    namespace Private
    {
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
        
        Rational Duration::getDottedValue() const
        {
            return myDurDot->getValue();
        }
        
        String Duration::getDottedName() const
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
        
        int Duration::getTupletNestingCount() const
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
