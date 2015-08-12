#include <iostream>
#include <string>
#include <memory>
#pragma once
#include <vector>

namespace music
{
    class Piece;
    using PiecePtr = std::shared_ptr<Piece>;
    using PieceUPtr = std::unique_ptr<Piece>;
    using PieceSet = std::vector<PiecePtr>;
    using PieceSetIter = PieceSet::iterator;
    using PieceSetIterConst = PieceSet::const_iterator;
    inline PiecePtr makePiece() { return std::make_shared<Piece>(); }
    
    class Movement;
    using MovementPtr = std::shared_ptr<Movement>;
    using MovementSet = std::vector<MovementPtr>;
    using MovementSetIter = MovementSet::iterator;
    using MovementSetIterConst = MovementSet::const_iterator;
    
    class Piece
    {
    public:
        inline ~Piece() = default;
        std::string getTitle() const;
        void setTitle( const std::string& value );
        std::string getComposer() const;
        void setComposer( const std::string& value );
        std::string getCompletionDate() const;
        void setCompletionDate( const std::string& value );
        std::string getCopyrightDate() const;
        void setCopyrightDate( const std::string& value );
        std::string getCopyrightString() const;
        void setCopyrightString( const std::string& value );
        std::string getLyricist() const;
        void setLyricist( const std::string& value );
        
        const MovementSet& getMovementSet() const;
        void addMovement( const MovementPtr& value );
        void removeMovement( const MovementSetIterConst& value );
        
        PiecePtr clone() const;
        
    private:
        std::string myTitle;
        std::string myComposer;
        std::string myCompletionDate;
        std::string myCopyrightDate;
        std::string myCopyrightString;
        std::string myLyricist;
        MovementSet myMovementSet;
    };
}

/*
 A Piece can have one or many Movements.
 A Piece has a Title.
 A Piece has a Composer.
 A Piece has a CompletionDate.
 A Piece has a CopyrightDate.
 A Piece has a CopyrightString.
 A Piece has a Lyricist.
 // later... if needed A Piece has zero or many Name Value string pairs for OtherCredits.
 A Piece will return an IMovementIterator.
 */