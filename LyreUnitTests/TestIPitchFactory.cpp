//PUBLIC
#include "LyreUnitTests/cpulTestHarness.h"
#include "Lyre/Pitch.h"
#include "Lyre/IPitchFactory.h"
#include <sstream>
#include <iostream>

using namespace lyre;
using namespace lyre::impl;
using namespace std;

class TestMockPitchFactory : public IPitchFactory
{
    public:
    virtual IPitchFactoryUP clone() const
    {
        return std::unique_ptr<TestMockPitchFactory>{ new TestMockPitchFactory( *this ) };
    }
    virtual IPitchUP createPitch() const
    {
        return PitchUP{ new Pitch{ myPitch } };
    }
    virtual void setPitch( const Integer pitchValue )
    {
        auto octaves = pitchValue / 12;
        octaves -= 1;
        auto p = pitchValue - ( (octaves+1) * 12 );
        switch ( p )
        {
            case 0:
                myPitch.setStepValue( 0 );
                myPitch.setAlterValue( 0 );
                myPitch.setOctaveValue( octaves );
                break;
            case 1:
                myPitch.setStepValue( 0 );
                myPitch.setAlterValue( 1 );
                myPitch.setOctaveValue( octaves );
                break;
            case 2:
                myPitch.setStepValue( 1 );
                myPitch.setAlterValue( 0 );
                myPitch.setOctaveValue( octaves );
                break;
            case 3:
                myPitch.setStepValue( 2 );
                myPitch.setAlterValue( -1 );
                myPitch.setOctaveValue( octaves );
                break;
            case 4:
                myPitch.setStepValue( 2 );
                myPitch.setAlterValue( 0 );
                myPitch.setOctaveValue( octaves );
                break;
            case 5:
                myPitch.setStepValue( 3 );
                myPitch.setAlterValue( 0 );
                myPitch.setOctaveValue( octaves );
                break;
            case 6:
                myPitch.setStepValue( 3 );
                myPitch.setAlterValue( 1 );
                myPitch.setOctaveValue( octaves );
                break;
            case 7:
                myPitch.setStepValue( 4 );
                myPitch.setAlterValue( 0 );
                myPitch.setOctaveValue( octaves );
                break;
            case 8:
                myPitch.setStepValue( 5 );
                myPitch.setAlterValue( -1 );
                myPitch.setOctaveValue( octaves );
                break;
            case 9:
                myPitch.setStepValue( 5 );
                myPitch.setAlterValue( 0 );
                myPitch.setOctaveValue( octaves );
                break;
            case 10:
                myPitch.setStepValue( 6 );
                myPitch.setAlterValue( -1 );
                myPitch.setOctaveValue( octaves );
                break;
            case 11:
                myPitch.setStepValue( 6 );
                myPitch.setAlterValue( 0 );
                myPitch.setOctaveValue( octaves );
                break;
            default:
                throw std::runtime_error( "boom" );
                break;
        }
    }
    virtual void setPitch( const IPitchUP& pitch )
    {
        if ( pitch )
        {
            setPitch( pitch->getValue() );
        }
    }
    
    virtual void next() { add( 1 ); }
    virtual void previous() { add( -1 ); }
    virtual void add( const Integer value ) { setPitch( createPitch()->getValue() + value ); }
private:
    Pitch myPitch;
};

TEST( compiles, IPitchFactory )
{
    TestMockPitchFactory f;
    f.setPitch( 0 );
    for ( int i = 0; i < 100; ++i )
    {
        auto p = f.createPitch();
        CHECK_EQUAL( i, p->getValue() )
        f.next();
    }
    
}