#include "Lyre/Private/Movement.h"
#include "Lyre/Private/throw.h"

namespace Lyre
{
    namespace Private
    {
        Movement::~Movement()
        {
            
        }
        
        Movement::Movement()
        {
            
        }

        Movement::Movement(
            const IMovementSpecUP& spec,
            const VecIPartSpecUP& partSpecs,
            const IMasterTrackSPC& masterTrack,
            const IPartFactoryUP& partFactory  )
        : mySpec( nullptr )
        , myMasterTrack( masterTrack )
        , myParts()
        , myPartFactory( nullptr )
        {
            THROW_IF_NULL( spec )
            mySpec = spec->clone();
            THROW_IF_NULL( masterTrack )
            THROW_IF_NULL( partFactory )
            myPartFactory = partFactory->clone();
            THROW_IF_BAD_VALUE( partSpecs.size(), 1, INT_MAX )
            initializeParts( partSpecs, partFactory );
        }

        Movement::Movement( const Movement& other )
        : mySpec( other.mySpec->clone() )
        , myMasterTrack( other.myMasterTrack )
        , myParts()
        , myPartFactory( other.myPartFactory->clone() )
        {
            copyParts( other.myParts );
        }

        Movement::Movement( Movement&& other ) noexcept
        : mySpec( std::move( other.mySpec ) )
        , myMasterTrack( std::move( other.myMasterTrack ) )
        , myParts( std::move ( other.myParts ) )
        , myPartFactory( std::move( other.myPartFactory ) )
        {
            
        }

        Movement& Movement::operator=( const Movement& other )
        {
            THROW_IF_NULL( other.mySpec );
            mySpec = other.mySpec->clone();
            THROW_IF_NULL( other.myMasterTrack );
            myMasterTrack = other.myMasterTrack;
            myPartFactory = other.myPartFactory->clone();
            copyParts( other.myParts );
            return *this;
        }

        Movement& Movement::operator=( Movement&& other ) noexcept
        {
            mySpec = std::move( other.mySpec );
            myMasterTrack = std::move( other.myMasterTrack );
            myParts = std::move( other.myParts );
            myPartFactory = std::move( other.myPartFactory );
            return *this;
        }

        
        IMovementUP Movement::clone() const
        {
            return IMovementUP{ new Movement{ *this } };
        }
        
        
        IMovementUP Movement::move() noexcept
        {
            try
            {
                return IMovementUP{ new Movement{ std::move(*this ) } };
            }
            catch( ... )
            {
                return IMovementUP{};
            }
        }
        

        std::ostream& Movement::toStream( std::ostream& os ) const
        {
            os  << "Movement '" << mySpec->getDisplayTitle() << "'" << std::endl;
            os << "{";
            for ( auto it = myParts.cbegin();
                  it != myParts.cend(); ++it )
            {
                os << std::endl;
                std::istringstream iss( (*it)->toString() );
                std::string line;
                while( std::getline( iss, line ) )
                {
                    os << "    " << line;
                    os << std::endl;
                }
            }
            os << "}" << std::endl;
            return os;
        }

        
        const IMovementSpecUPC Movement::getSpec() const
        {
            return mySpec->clone();
        }
        
        
		int Movement::getPartCount() const
		{
			return static_cast<int>( myParts.size() );
		}


		IPartH Movement::getPart( int partIndex )
		{
            THROW_IF_BAD_VALUE( partIndex, 0, getPartCount() )
            auto it = ( myParts.begin() + partIndex );
			return IPartH( *it );
		}


		const IPartHC Movement::getPart( int partIndex ) const
		{
			return getPartConst( partIndex );
		}


		const IPartHC Movement::getPartConst( int partIndex ) const
		{
			THROW_IF_BAD_VALUE( partIndex, 0, getPartCount() )
            auto it = ( myParts.cbegin() + partIndex );
			return IPartHC( *it );
		}
        
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PRIVATE FUNCTIONS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        void Movement::initializeParts(
            const VecIPartSpecUP& partSpecs,
            const IPartFactoryUP& partFactory )
        {
            
            for ( auto it = partSpecs.cbegin(); it != partSpecs.cend(); ++it )
            {
                THROW_IF_NULL( *it )
                myParts.push_back( partFactory->create( *it, myMasterTrack ) );
            }
        }
        
        void Movement::copyParts( const VecIPartUP& other )
        {
            myParts.clear();
            for ( auto it = other.cbegin();
                  it != other.cend(); ++it )
            {
                THROW_IF_NULL( *it );
                myParts.push_back( (*it)->clone() );
            }
        }
        
    }
}
