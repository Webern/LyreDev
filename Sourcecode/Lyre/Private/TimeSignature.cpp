#include "Lyre/Private/TimeSignature.h"
#include "Lyre/IBeatPatternFactory.h"
#include "Lyre/IDurationFactory.h"
#include "Lyre/IDuration.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    TimeSignature::~TimeSignature() {}
    
    TimeSignature::TimeSignature()
    :myTop( 4 )
    ,myBottom( 4 )
    ,myBeatPattern( nullptr )
    {
        setTop( DEFAULT_TOP );
        setBottom( DEFAULT_BOTTOM );
        guessBeatPattern();
    }
    
    TimeSignature::TimeSignature( int top, int bottom )
    :myTop( 4 )
    ,myBottom( 4 )
    ,myBeatPattern( nullptr )
    {
        setTop( top );
        setBottom( bottom );
        guessBeatPattern();
    }
    
    TimeSignature::TimeSignature( const IBeatPatternUP& beatPattern,
                                  int top,
                                  int bottom )
    :myTop( 4 )
    ,myBottom( 4 )
    {
        setTop( top );
        setBottom( bottom );
        setBeatPattern( beatPattern );
    }
    
    TimeSignature::TimeSignature( const TimeSignature& other )
    :myTop( 4 )
    ,myBottom( 4 )
    ,myBeatPattern( nullptr )
    {
        setTop( other.myTop );
        setBottom( other.myBottom );
        setBeatPattern( other.myBeatPattern );
    }
    
    TimeSignature::TimeSignature( TimeSignature&& other )
    :myTop( std::move( other.myTop ) )
    ,myBottom( std::move( other.myBottom ) )
    ,myBeatPattern( std::move( other.myBeatPattern ) )
    {
        
    }
    
    TimeSignature& TimeSignature::operator=( const TimeSignature& other )
    {
        setTop( other.myTop );
        setBottom( other.myBottom );
        setBeatPattern( other.myBeatPattern );
        return *this;
    }
    
    TimeSignature& TimeSignature::operator=( TimeSignature&& other )
    {
        myTop = std::move( other.myTop );
        myBottom = std::move( other.myBottom );
        myBeatPattern = std::move( other.myBeatPattern );
        return *this;
    }
    
    ITimeSignatureUP TimeSignature::clone() const
    {
        return ITimeSignatureUP{ new TimeSignature{ *this } };
    }
    
    std::ostream& TimeSignature::toStream( std::ostream& os ) const
    {
        os << "TimeSignature[" << myTop << "/" << myBottom << " (";
        os << *myBeatPattern << ")]";
        return os;
    }
    
    IBeatPatternUP TimeSignature::getBeatPattern() const
    {
        return myBeatPattern->clone();
    }
    
    int TimeSignature::getTop() const
    {
        return myTop;
    }
    
    int TimeSignature::getBottom() const
    {
        return myBottom;
    }
    
    Rational TimeSignature::getTotalDuration()
    {
        Rational beat = Rational{ 4, 1 } / Rational{ myBottom, 1 };
        auto value = beat * Rational{ myTop, 1 };
        value.reduce();
        return value;
    }
    
    void TimeSignature::setTop( int top )
    {
        if ( top < 1 )
        {
            myTop = 4;
            THROW( "invalid argument, top must be >= 1" )
        }
        myTop = top;
    }
    
    void TimeSignature::setBottom( int bottom )
    {
        if ( bottom != 1 &&
             bottom != 2 &&
             bottom != 4 &&
             bottom != 8 &&
             bottom != 16 &&
             bottom != 32 &&
             bottom != 64 &&
             bottom != 128 &&
             bottom != 256 )
        {
            myBottom = 4;
            std::stringstream ss;
            ss << "invalid argument, bottom must be in (";
            ss << "1, 2, 4, 8, 16, 32, 64, 128, 256)";
            THROW( ss.str() )
        }
        myBottom = bottom;
    }
    
    void TimeSignature::guessBeatPattern()
    {
        auto bpFactory = createBeatPatternFactory();
        auto durFactory = createDurationFactory( DurationFactoryType::Standard );
        Rational remaining = getTotalDuration();
        auto currDur = durFactory->createDuration( "Quarter" );
        VecIDurationUP durs;
        while ( remaining >= currDur->getValue() )
        {
            durs.push_back( currDur->clone() );
            remaining -= currDur->getValue();
        }
        remaining.reduce();
        currDur = durFactory->createDuration( "Eighth" );
        while ( remaining >= currDur->getValue() )
        {
            durs.push_back( currDur->clone() );
            remaining -= currDur->getValue();
        }
        remaining.reduce();
        currDur = durFactory->createDuration( "16th" );
        while ( remaining >= currDur->getValue() )
        {
            durs.push_back( currDur->clone() );
            remaining -= currDur->getValue();
        }
        remaining.reduce();
        currDur = durFactory->createDuration( "32nd" );
        while ( remaining >= currDur->getValue() )
        {
            durs.push_back( currDur->clone() );
            remaining -= currDur->getValue();
        }
        remaining.reduce();
        currDur = durFactory->createDuration( "64th" );
        while ( remaining >= currDur->getValue() )
        {
            durs.push_back( currDur->clone() );
            remaining -= currDur->getValue();
        }
        remaining.reduce();
        currDur = durFactory->createDuration( "128th" );
        while ( remaining >= currDur->getValue() )
        {
            durs.push_back( currDur->clone() );
            remaining -= currDur->getValue();
        }
        remaining.reduce();
        currDur = durFactory->createDuration( "256th" );
        while ( remaining >= currDur->getValue() )
        {
            durs.push_back( currDur->clone() );
            remaining -= currDur->getValue();
        }
        if ( remaining != Rational{ 0, 1 } )
        {
            THROW( "the algorithm failed" )
        }
        auto beatPattern = bpFactory->create( durs );
        setBeatPattern( beatPattern );
    }
    
    void TimeSignature::setBeatPattern( const IBeatPatternUP& beatPattern )
    {
        if ( beatPattern->getTotalDuration() != this->getTotalDuration() )
        {
            THROW( "beat pattern duration does not fit time signature" )
        }
        myBeatPattern = beatPattern->clone();
    }
    
    Rational TimeSignature::getTotalFromDurVec( const VecIDurationUP& durs ) const
    {
        Rational total{ 0, 1 };
        for ( auto i = durs.cbegin(); i != durs.cend(); ++i )
        {
            total += (*i)->getValue();
        }
        return total;
    }
    
}
