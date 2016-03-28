//PUBLIC
#include "LyreTest/Tests/TestMovement.h"
#include "LyreTest/Tests/TestScore.h"

using namespace Lyre;
using namespace std;

TEST( ctorZeroCount, Score )
{
    ScoreFactories f;
    auto spec = f.scoreSpecFactory->create();
    spec->setTitle( "Once Upon a Time" );
    spec->setComposer( "Bones & Bishop" );
    auto score = f.scoreFactory->create( spec );
    CHECK_EQUAL( 0, score->getMovementCount() )
}
T_END

TEST( addMovementget1Count, Score )
{
    ScoreFactories f;
    auto spec = f.scoreSpecFactory->create();
    spec->setTitle( "Once Upon a Time" );
    spec->setComposer( "Bones & Bishop" );
    auto score = f.scoreFactory->create( spec );
    score->addMovement( f.createMovement( 1, "Fake Title" ) );
    CHECK_EQUAL( 1, score->getMovementCount() )
}
T_END

TEST( getMovement0, Score )
{
    ScoreFactories f;
    auto spec = f.scoreSpecFactory->create();
    spec->setTitle( "Once Upon a Time" );
    spec->setComposer( "Bones & Bishop" );
    auto score = f.scoreFactory->create( spec );
    score->addMovement( f.createMovement( 1, "Fake Title" ) );
    auto movement = score->getMovement( 0 );
    CHECK_EQUAL( 3, movement->getPartCount() )
}
T_END

TEST( getMovementThrowNegative, Score )
{
    ScoreFactories f;
    auto spec = f.scoreSpecFactory->create();
    spec->setTitle( "Once Upon a Time" );
    spec->setComposer( "Bones & Bishop" );
    auto score = f.scoreFactory->create( spec );
    score->addMovement( f.createMovement( 1, "Fake Title" ) );
    score->addMovement( f.createMovement( 2, "Fake Too" ) );
    bool isExceptionThrown = false;
    try
    {
        auto movement = score->getMovement( -1 );
        CHECK_EQUAL( 3, movement->getPartCount() )
    }
    catch ( const std::exception& e )
    {
        UNUSED_PARAMETER( e );
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown );
}
T_END

TEST( getMovementThrowBadIndex, Score )
{
    ScoreFactories f;
    auto spec = f.scoreSpecFactory->create();
    spec->setTitle( "Once Upon a Time" );
    spec->setComposer( "Bones & Bishop" );
    auto score = f.scoreFactory->create( spec );
    score->addMovement( f.createMovement( 1, "Fake Title" ) );
    score->addMovement( f.createMovement( 2, "Fake Too" ) );
    bool isExceptionThrown = false;
    try
    {
        auto movement = score->getMovement( 2 );
        CHECK_EQUAL( 3, movement->getPartCount() )
    }
    catch ( const std::exception& e )
    {
        UNUSED_PARAMETER( e );
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown );
}
T_END

TEST( ctorThrowNull, Score )
{
    ScoreFactories f;
    IScoreSpecUP spec;
    bool isExceptionThrown = false;
    try
    {
        auto score = f.scoreFactory->create( spec );
    }
    catch ( const std::exception& e )
    {
        UNUSED_PARAMETER( e );
        isExceptionThrown = true;
    }
    CHECK( isExceptionThrown );
}
T_END

TEST( assignmentAndClone, Score )
{
    ScoreFactories f;
    auto spec = f.scoreSpecFactory->create();
    spec->setTitle( "Once Upon a Time" );
    spec->setComposer( "Bones & Bishop" );
    auto score = f.scoreFactory->create( spec );
    auto cloned = score->clone();
    CHECK( cloned != nullptr );
    CHECK( cloned.get() != score.get() )
}
T_END

TEST( move, Score )
{
    ScoreFactories f;
    auto spec = f.scoreSpecFactory->create();
    spec->setTitle( "Once Upon a Time" );
    spec->setComposer( "Bones & Bishop" );
    auto score = f.scoreFactory->create( spec );
    IScoreUP moved{ std::move( score ) };
    CHECK( moved != nullptr )
}
T_END

TEST( toStream, Score )
{
    ScoreFactories f;
    auto spec = f.scoreSpecFactory->create();
    spec->setTitle( "Once Upon a Time" );
    spec->setComposer( "Bones & Bishop" );
    auto score = f.scoreFactory->create( spec );
    score->addMovement( f.createMovement( 1, "Fake Title" ) );
    score->addMovement( f.createMovement( 2, "Fake Too" ) );
    std::string actual = score->toString();
    std::stringstream exp;
    //score->toStream( std::cout );
}
T_END