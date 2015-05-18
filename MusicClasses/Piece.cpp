#include "Piece.h"
#include "Movement.h"

namespace music
{
    /* -------------------------------------------------- */
    std::string Piece::getTitle() const
    {
        return myTitle;
    }
    void Piece::setTitle( const std::string& value )
    {
        myTitle = value;
    }
    /* -------------------------------------------------- */
    std::string Piece::getComposer() const
    {
        return myComposer;
    }
    void Piece::setComposer( const std::string& value )
    {
        myComposer = value;
    }
    /* -------------------------------------------------- */
    std::string Piece::getCompletionDate() const
    {
        return myCompletionDate;
    }
    void Piece::setCompletionDate( const std::string& value )
    {
        myCompletionDate = value;
    }
    /* -------------------------------------------------- */
    std::string Piece::getCopyrightDate() const
    {
        return myCopyrightDate;
    }
    void Piece::setCopyrightDate( const std::string& value )
    {
        myCopyrightDate = value;
    }
    /* -------------------------------------------------- */
    std::string Piece::getCopyrightString() const
    {
        return myCopyrightString;
    }
    void Piece::setCopyrightString( const std::string& value )
    {
        myCopyrightString = value;
    }
    /* -------------------------------------------------- */
    std::string Piece::getLyricist() const
    {
        return myLyricist;
    }
    void Piece::setLyricist( const std::string& value )
    {
        myLyricist = value;
    }
    /* -------------------------------------------------- */
    const MovementSet& Piece::getMovementSet() const
    {
        return myMovementSet;
    }
    void Piece::addMovement( const MovementPtr& value )
    {
        if ( value )
        {
            myMovementSet.push_back( value );
        }
    }
    void Piece::removeMovement( const MovementSetIterConst& value )
    {
        if ( value != myMovementSet.end() )
        {
            myMovementSet.erase( value );
        }
    }
}