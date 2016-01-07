#include "Lyre/INoteFactory.h"
#include "Lyre/Private/NoteFactory.h"
#include "Lyre/Private/throw.h"
#include <sstream>

namespace Lyre
{
    INoteFactoryUP createNoteFactory( const NoteFactoryType t )
    {
        INoteFactoryUP returnValue;
        switch ( t )
        {
            case NoteFactoryType::Standard:
                returnValue = INoteFactoryUP{ new Private::NoteFactory{} };
                break;
                
            default:
                THROW( "unknown NoteFactoryType" );
                break;
        }
        return returnValue;
    }
}
