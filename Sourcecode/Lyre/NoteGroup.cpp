#include "Lyre/NoteGroup.h"
#include "Lyre/Private/throw.h"
#include "Lyre/INote.h"

// TODO remove these
#include "Lyre/INoteFactory.h"
#include "Lyre/IPitchFactory.h"
#include "Lyre/IDurationFactory.h"

namespace Lyre
{
    enum class NgType
    {
        Note = 0,
        Group = 1,
        Unk = 2
    };
    
    using MetaNoteGroup = std::pair<NgType, INoteGroupUP>;

    class NoteGroup::Impl
    {
    public:
        Impl()
        :ngType( NgType::Unk )
        ,note( nullptr )
        ,noteGroups()
        {}
        
        Impl( const INoteUP& inNote )
        :ngType( NgType::Note )
        ,note( inNote->clone() )
        ,noteGroups()
        {
            THROW_IF_NULL( note )
        }

        Impl( const Impl& other )
        :ngType( other.ngType )
        ,note( nullptr )
        ,noteGroups()
        {
            if ( other.note )
            {
                note = other.note->clone();
            }
            for ( auto i = other.noteGroups.cbegin();
                  i != other.noteGroups.cend(); ++i )
            {
                THROW_IF_NULL( i->second )
                MetaNoteGroup mng{ i->first, i->second->clone() };
                noteGroups.push_back( std::move( mng ) );
            }
        }
        
        Impl( Impl&& other )
        :ngType( std::move( other.ngType ) )
        ,note( std::move( other.note ) )
        ,noteGroups( std::move( other.noteGroups ) )
        {
            
        }
        
        Impl& operator=( const Impl& other )
        {
            ngType = other.ngType;
            note = nullptr;
            noteGroups.clear();
            if ( other.note )
            {
                note = other.note->clone();
            }
            for ( auto i = other.noteGroups.cbegin();
                 i != other.noteGroups.cend(); ++i )
            {
                THROW_IF_NULL( i->second )
                MetaNoteGroup mng{ i->first, i->second->clone() };
                noteGroups.push_back( std::move( mng ) );
            }
            return *this;
        }
        
        Impl& operator=( Impl&& other )
        {
            ngType = std::move( other.ngType );
            note =  std::move( other.note );
            noteGroups = std::move( other.noteGroups );
            return *this;
        }
        
        NgType ngType;
        INoteUP note;
        std::vector<MetaNoteGroup> noteGroups;
    };
    
    NoteGroup::~NoteGroup()
    {
        delete myImplP;
        myImplP = 0;
    }
    
    NoteGroup::NoteGroup()
    :myImplP( 0 )
    {
        myImplP = new Impl{};
        THROW_IF_NULL( myImplP );
        myImplP->ngType = NgType::Group;
        myImplP->note = nullptr;
        myImplP->noteGroups.clear();
    }
    
    NoteGroup::NoteGroup( const NoteGroup& other )
    :myImplP( 0 )
    {
        THROW_IF_NULL( other.myImplP );
        myImplP = new Impl( *other.myImplP );
    }
    
    NoteGroup::NoteGroup( NoteGroup&& other ) noexcept
    :myImplP( std::move( other.myImplP ) )
    {
        other.myImplP = 0;
    }
    
    NoteGroup& NoteGroup::operator=( const NoteGroup& other )
    {
        THROW_IF_NULL( other.myImplP );
        myImplP = new Impl( *other.myImplP );
        return *this;
    }
    
    NoteGroup& NoteGroup::operator=( NoteGroup&& other ) noexcept
    {
        myImplP = std::move( other.myImplP );
        other.myImplP = 0;
        return *this;
    }
    
	INoteGroupUP NoteGroup::clone() const
	{
		return INoteGroupUP{ new NoteGroup{ *this } };
	}
    
    NoteGroupUP NoteGroup::copy() const
	{
		return NoteGroupUP{ new NoteGroup{ *this } };
	}

	std::ostream& NoteGroup::toStream( std::ostream& os ) const
	{
        for ( int i = 0; i < getCount(); ++i )
        {
            if ( i > 0 )
            {
                os << std::endl;
            }
            os << ( *getNote( i ) );
        }
		return os;
	}

	bool NoteGroup::getIsEmpty() const
	{
		return getCount() == 0;
	}

	int NoteGroup::getCount() const
	{
        if ( myImplP->ngType == NgType::Note )
        {
            return 1;
        }
        else if ( myImplP->ngType == NgType::Unk )
        {
            return 0;
        }
        int count = 0;
        for ( auto i = myImplP->noteGroups.cbegin();
              i != myImplP->noteGroups.cend(); ++i )
        {
            count += i->second->getCount();
        }
		return count;
	}

	Rational NoteGroup::getTotalDuration() const
	{
        Rational total{ 0, 1 };
        for ( int i = 0; i < getCount(); ++i )
        {
            total += getNote( i )->getDuration()->getValue();
        }
		return total;
	}

	INoteUP NoteGroup::getNote( int noteIndex ) const
	{
        if ( noteIndex < 0 || noteIndex > getCount() - 1 )
        {
            THROW( "index out of range" )
        }
        if ( myImplP->ngType == NgType::Note )
        {
            if ( noteIndex != 0 )
            {
                THROW( "index out of range" )
            }
            THROW_IF_NULL( myImplP->note )
            return myImplP->note->clone();
        }
        int counter = 0;
        for ( auto i = myImplP->noteGroups.begin();
             i != myImplP->noteGroups.end(); ++i )
        {
            if ( counter == noteIndex )
            {
                return i->second->getNote( 0 );
            }
            int currItemGetCount = i->second->getCount();
            if( currItemGetCount == 1 )
            {
                ++counter;
            }
            else
            {
                int rangeEnd = noteIndex + currItemGetCount;
                if ( noteIndex <= rangeEnd )
                {
                    return i->second->getNote( noteIndex - counter );
                }
                counter += currItemGetCount;
            }
        }
        THROW( "should not reach here" )
		return INoteUP{};
	}

	void NoteGroup::add( const INoteUP& note )
	{
        THROW_IF_NULL( note )
        if ( myImplP->ngType == NgType::Note )
        {
            THROW( "cannot add to a leaf node" )
        }
        NoteGroup* newP = new NoteGroup{};
        newP->myImplP->ngType = NgType::Note;
        newP->myImplP->note = note->clone();
        INoteGroupUP newItem{ newP };
        MetaNoteGroup mng{ NgType::Note, std::move( newItem ) };
        myImplP->noteGroups.push_back( std::move( mng ) );
	}

	void NoteGroup::remove( int noteIndex )
	{
        if ( noteIndex < 0 || noteIndex > getCount() - 1 )
        {
            THROW( "index out of range" )
        }
        if ( myImplP->ngType == NgType::Note )
        {
            THROW( "bad internal state" )
        }
        int counter = 0;
        bool isInGroup = getIsInGroup( noteIndex );
        for ( auto i = myImplP->noteGroups.begin();
              i != myImplP->noteGroups.end(); ++i )
        {
            int currItemGetCount = i->second->getCount();
            
            if ( counter == noteIndex )
            {
                if ( ! isInGroup || currItemGetCount == 1 )
                {
                    myImplP->noteGroups.erase( i );
                    return;
                }
                else
                {
                    i->second->remove( 0 );
                    return;
                }
                THROW( "bad internal state" )
            }
            int rangeEnd = counter + currItemGetCount;
            if ( noteIndex <= rangeEnd )
            {
                i->second->remove( noteIndex - counter );
                return;
            }
            counter += currItemGetCount;
        }
	}

	int NoteGroup::getGroupCount() const
	{
        int groupCount = 0;
        for ( auto i = myImplP->noteGroups.begin();
              i != myImplP->noteGroups.end(); ++i )
        {
            if ( i->first == NgType::Group )
            {
                ++groupCount;
            }
        }
		return groupCount;
	}

	bool NoteGroup::getIsInGroup( int noteIndex ) const
	{
        if ( noteIndex < 0 || noteIndex > getCount() - 1 )
        {
            THROW( "index out of range" )
        }
		return ! ( getGroupIndex( noteIndex ) == -1 );
	}

	int NoteGroup::getGroupIndex( int noteIndex ) const
	{
        int rangeStart = 0;
        int rangeStop = 0;
        int groupIndex = 0;
        for ( auto i = myImplP->noteGroups.begin();
              i != myImplP->noteGroups.end(); ++i )
        {
            int span = 0;
            if ( i->first == NgType::Note )
            {
                span = 1;
            }
            else
            {
                ++groupIndex;
                span = i->second->getCount();
            }
            rangeStop = rangeStart + span;
            if ( noteIndex >= rangeStart && noteIndex <= rangeStop )
            {
                if ( i->first == NgType::Group )
                {
                    return groupIndex;
                }
                else
                {
                    return -1;
                }
            }
        }
		return -1;
	}

	INoteGroupUP NoteGroup::getGroup( int groupIndex ) const
	{
        if ( groupIndex < 0 )
        {
            THROW( "index out of range" )
        }
        int groupCounter = 0;
        for ( auto i = myImplP->noteGroups.begin();
              i != myImplP->noteGroups.end(); ++i )
        {
            if ( i->first == NgType::Group )
            {
                ++groupCounter;
                if ( groupCounter == groupIndex )
                {
                    return i->second->clone();
                }
            }
        }
        THROW( "index out of range" )
	}

	void NoteGroup::addGroup( const INoteGroupUP& group )
	{
        THROW_IF_NULL( group )
        if ( myImplP->ngType == NgType::Note )
        {
            THROW( "bad internal state" )
        }
        MetaNoteGroup mng{ NgType::Group, group->clone() };
        myImplP->noteGroups.push_back( std::move( mng ) );
	}

	void NoteGroup::removeGroup( int groupIndex )
	{
        if ( groupIndex < 0 )
        {
            THROW( "index out of range" )
        }
        int groupCounter = 0;
        for ( auto i = myImplP->noteGroups.begin();
              i != myImplP->noteGroups.end(); ++i )
        {
            if ( i->first == NgType::Group )
            {
                ++groupCounter;
                if ( groupCounter == groupIndex )
                {
                    myImplP->noteGroups.erase( i );
                    return;
                }
            }
        }
		THROW( "index out of range" )
	}

}

