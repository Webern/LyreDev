#include "Lyre/Private/Score.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        Score::~Score()
        {

        }


        Score::Score( const IScoreSpecUP& spec )
            : mySpec( nullptr )
        {
            THROW_IF_NULL( spec );
            mySpec = spec->clone();
        }


        Score::Score( const Score& other )
            : mySpec( nullptr )
        {
            THROW_IF_NULL( other.mySpec );
            mySpec = other.mySpec->clone();
        }


        Score::Score( Score&& other )
            : mySpec( std::move( other.mySpec ) )
        {

        }


        Score& Score::operator=( const Score& other )
        {
            THROW_IF_NULL( other.mySpec );
            mySpec = other.mySpec->clone();
            return *this;
        }


        Score& Score::operator=( Score&& other )
        {
            mySpec = std::move( other.mySpec );
            return *this;
        }


        IScoreUP Score::clone() const
        {
            return IScoreUP{ new Score{ *this } };
        }


        std::ostream& Score::toStream( std::ostream& os ) const
        {
            mySpec->toStream( os );
            for ( auto it = myMovements.cbegin(); it != myMovements.cend(); ++it )
            {
                os << std::endl;
                ( *it )->toStream( os );
            }
            return os;
        }


        IScoreSpecUP Score::getSpec() const
        {
            return mySpec->clone();
        }


        void Score::setSpec( const IScoreSpecUP spec )
        {
            THROW_IF_NULL( spec );
            mySpec = spec->clone();
        }


        int Score::getMovementCount() const
        {
            return static_cast<int>( myMovements.size() );
        }


        void Score::addMovement( IMovementUP&& movement )
        {
            THROW_IF_NULL( movement );
            myMovements.push_back( std::move( movement ) );
        }


        void Score::addMovement( const IMovementUP& movement )
        {
            THROW_IF_NULL( movement );
            myMovements.push_back( std::move( movement->clone() ) );
        }


        IMovementH Score::getMovement( int movementIndex )
        {
            THROW_IF_BAD_VALUE( movementIndex, 0, getMovementCount()-1 );
            return IMovementH( *( myMovements.begin() + movementIndex ) );
        }


        IMovementHC Score::getMovement( int movementIndex ) const
        {
            return getMovementConst( movementIndex );
        }


        IMovementHC Score::getMovementConst( int movementIndex ) const
        {
            THROW_IF_BAD_VALUE( movementIndex, 0, getMovementCount()-1 );
            return IMovementHC( *( myMovements.cbegin() + movementIndex ) );
        }
    }
}
