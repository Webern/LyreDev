// PRIVATE
#include "Lyre/Lyre.h"
#include "Lyre/IDurBase.h"
#include "Lyre/Rational.h"
#include "Mx/Elements.h"

namespace Lyre
{
    namespace Lmx
    {
        mx::t::NoteTypeValue convertDur( const Rational& durBaseValue );
        mx::t::NoteTypeValue convertDur( const IDurBaseUP& durBaseValue );
        IDurBaseUP convertDur( const mx::t::NoteTypeValue& mxDurVal );
    }
}
