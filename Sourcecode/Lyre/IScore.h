//PUBLIC
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IScoreSpec.h"
#include "Lyre/IMovement.h"
#include "Lyre/Handle.h"

namespace Lyre
{
    FORWARD_DECLARE(IScore)
    using IScoreH = Handle<IScoreUP>;
    using IScoreHC = HandleConst<IScoreUP>;
    
    class PUBLIC IScore : public IStreamable
    {
    public:
        virtual ~IScore() {};
        virtual IScoreUP clone() const = 0;
        virtual std::ostream& toStream( std::ostream& os ) const = 0;
        
        virtual IScoreSpecUP getSpec() const = 0;
        virtual void setSpec( const IScoreSpecUP spec ) = 0;

        virtual int getMovementCount() const = 0;
        virtual void addMovement( IMovementUP&& movement ) = 0;
        virtual void addMovement( const IMovementUP& movement ) = 0;
        virtual IMovementH getMovement( int movementIndex ) = 0;
        virtual IMovementHC getMovement( int movementIndex ) const = 0;
        virtual IMovementHC getMovementConst( int movementIndex ) const = 0;
    };
}
