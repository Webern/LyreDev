#include "Step.h"

namespace music
{
    Step::Step()
    :myValue( 0 )
    {}
    
    Step::Step( const StepName value )
    :myValue( 0 )
    {
        setValue( value );
    }
    
    Step::Step( const Int value )
    :myValue( value )
    {}
    
    void Step::setValue( const Int value )
    {
        myValue.setValue( value );
    }
    
    void Step::setValue( const StepName value )
    {
        switch ( value )
        {
            case StepName::C:
                myValue.setValue( 0 );
                break;
            case StepName::D:
                myValue.setValue( 1 );
                break;
            case StepName::E:
                myValue.setValue( 2 );
                break;
            case StepName::F:
                myValue.setValue( 3 );
                break;
            case StepName::G:
                myValue.setValue( 4 );
                break;
            case StepName::A:
                myValue.setValue( 5 );
                break;
            case StepName::B:
                myValue.setValue( 6 );
                break;
            default:
                myValue.setValue( 0 );
                break;
        }
    }
    
    Step::operator Int() const
    {
        return myValue.getValue();
    }
    
    Int Step::getValue() const
    {
        return myValue.getValue();
    }
    
    StepName Step::getStepName() const
    {
        StepName output{ StepName::C };
        switch ( myValue.getValue() )
        {
            case 0:
                output = StepName::C;
                break;
            case 1:
                output = StepName::D;
                break;
            case 2:
                output = StepName::E;
                break;
            case 3:
                output = StepName::F;
                break;
            case 4:
                output = StepName::G;
                break;
            case 5:
                output = StepName::A;
                break;
            case 6:
                output = StepName::B;
                break;
            default:
                break;
        }
        return output;
    }
    
    Step& Step::operator++()
    {
        ++myValue;
        return *this;
    }
    Step& Step::operator++(int)
    {
        myValue++;
        return *this;
    }
    Step& Step::operator--()
    {
        --myValue;
        return *this;
    }
    Step& Step::operator--(int)
    {
        myValue--;
        return *this;
    }
    Step& Step::add( const Int value )
    {
        myValue.add( value );
        return *this;
    }
    Step& Step::subtract( const Int value )
    {
        myValue.subtract( value );
        return *this;
    }
    bool operator==( const Step& r, const Step& l )
    {
        return r.getValue() == l.getValue();
    }
    bool operator!=( const Step& r, const Step& l )
    {
        return ! ( r == l );
    }
    bool operator< ( const Step& r, const Step& l )
    {
        return r.getValue() < l.getValue();
    }
    bool operator> ( const Step& r, const Step& l )
    {
        return l < r;
    }
    bool operator<=( const Step& r, const Step& l )
    {
        return ( r < l ) || ( r == l );
    }
    bool operator>=( const Step& r, const Step& l )
    {
        return ( r > l ) || ( r == l );
    }
}