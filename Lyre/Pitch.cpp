#include "Pitch.h"
#include "PitchName.h"
#include "Mod.h"

namespace lyre
{
    class Pitch::PitchImpl
    {
    public:
        ~PitchImpl(){}
        
        PitchImpl()
        :myPitchName{ 0 }
        ,myOctave{ 0 }
        {}
        
        PitchImpl( const Integer step, const Integer alter, const Integer octave )
        :myPitchName{ step, alter }
        ,myOctave{ alter }
        {}
        
        PitchName myPitchName;
        Integer myOctave;
    };
    
    Pitch::~Pitch(){}
    
    Pitch::Pitch()
    :myImpl{ new PitchImpl{} }
    {}
    
    Pitch::Pitch( const Integer step, const Integer alter, const Integer octave )
    :myImpl( new PitchImpl{ step, alter, octave } )
    {}
    
    Pitch::Pitch( const String& str )
    :myImpl{ new PitchImpl{} }
    {
        parse( str );
    }
    
    Pitch::Pitch( const Pitch& other )
    :myImpl( new PitchImpl{ *other.myImpl } )
    {}
    
    Pitch::Pitch( Pitch&& other ) noexcept
    :myImpl( std::move( other.myImpl ) )
    {}
    
    Pitch& Pitch::operator=( const Pitch& other )
    {
        auto temp = other;
        Pitch::swap( temp, *this );
        return *this;
    }
    
    Pitch& Pitch::operator=( Pitch&& other ) noexcept
    {
        Pitch::swap( other, *this );
        return *this;
    }
    
    
    IPitchUPtr Pitch::clone() const
    {
        IPitchUPtr value{ new Pitch{ *this } };
        return value;
    }
    
    Integer Pitch::getValue() const
    {
        throw std::runtime_error( "not implemented" );
    }
    
    bool Pitch::parse( const String& str )
    {
        throw std::runtime_error( "not implemented" );
    }
    
    std::ostream& Pitch::toStream( std::ostream& os ) const
    {
        os << myImpl->myPitchName;
        return os << std::to_string( myImpl->myOctave );
    }
    
    Integer Pitch::getStepValue() const
    {
        return myImpl->myPitchName.getStepValue();
    }
    
    void Pitch::setStepValue( const Integer val )
    {
        myImpl->myPitchName.setStepValue( val );
    }
    
    void Pitch::incrementStep()
    {
        myImpl->myPitchName.incrementStep();
    }
    
    void Pitch::decrementStep()
    {
        myImpl->myPitchName.decrementStep();
    }
    
    Integer Pitch::getAlterValue() const
    {
        return myImpl->myPitchName.getAlterValue();
    }
    
    void Pitch::setAlterValue( const Integer val )
    {
        myImpl->myPitchName.setAlterValue( val );
    }
    
    void Pitch::incrementAlter()
    {
        myImpl->myPitchName.incrementAlter();
    }
    
    void Pitch::decrementAlter()
    {
        myImpl->myPitchName.decrementAlter();
    }
    
    void Pitch::swap( Pitch& left, Pitch& right ) noexcept
    {
        std::swap( left.myImpl, right.myImpl );
    }
    
    Integer Pitch::getOctaveValue() const
    {
        return myImpl->myOctave;
    }
    
    void Pitch::setOctaveValue( const Integer val )
    {
        myImpl->myOctave = val;
    }
    
    void Pitch::incrementOctave()
    {
        myImpl->myOctave += 1;
    }
    
    void Pitch::decrementOctave()
    {
        myImpl->myOctave -= 1;
    }
}