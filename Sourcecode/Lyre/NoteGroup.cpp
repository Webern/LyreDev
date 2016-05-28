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

/*******************************************************************************
Impl
*******************************************************************************/
    
    class NoteGroup::Impl
    {
    public:
        
		NgType ngType;
		INoteUP note;
		std::vector<MetaNoteGroup> noteGroups;
		mutable Rational durCache;
		mutable bool isDurCacheDirty;
		mutable int countCache;
		mutable bool isCountCacheDirty;

        Impl()
        :ngType( NgType::Unk )
        ,note( nullptr )
        ,noteGroups()
		,durCache( 0, 0 )
		,isDurCacheDirty( true )
		,countCache( 0 )
		,isCountCacheDirty( true )
        {}
        
        
        Impl( const INoteUP& inNote )
        :ngType( NgType::Note )
        ,note( inNote->clone() )
        ,noteGroups()
		,durCache( inNote->getDuration()->getValue() )
		,isDurCacheDirty( true )
		,countCache( 0 )
		,isCountCacheDirty( true )
        {
            THROW_IF_NULL( note )
        }

        
        Impl( const Impl& other )
        :ngType( other.ngType )
        ,note( nullptr )
        ,noteGroups()
		,durCache( other.durCache )
		,isDurCacheDirty( other.isDurCacheDirty )
		,countCache( other.countCache )
		,isCountCacheDirty( other.isCountCacheDirty )
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
		,durCache( std::move( other.durCache ) )
		,isDurCacheDirty( std::move( other.isDurCacheDirty ) )
		,countCache( std::move( other.countCache ) )
		,isCountCacheDirty( std::move( other.isCountCacheDirty ) )
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
			durCache = other.durCache;
			isDurCacheDirty = other.isDurCacheDirty;
			countCache = other.countCache;
			isCountCacheDirty =other.isCountCacheDirty;
            return *this;
        }
        
        
        Impl& operator=( Impl&& other )
        {
            ngType = std::move( other.ngType );
            note =  std::move( other.note );
            noteGroups = std::move( other.noteGroups );
			durCache = std::move( other.durCache );
			isDurCacheDirty = std::move( other.isDurCacheDirty );
			countCache = std::move( other.countCache );
			isCountCacheDirty = std::move( other.isCountCacheDirty );
            return *this;
        }
        
        
        std::ostream& toStreamImpl( std::ostream& os )
        {
            for ( auto i = noteGroups.cbegin();
                 i != noteGroups.cend(); ++i )
            {
                if ( i->first == NgType::Note )
                {
                    i->second->getNote( 0 )->toStream( os );
                    os << std::endl;
                }
                else
                {
                    i->second->toStream( os );
                }
            }
            return os;
        }
        
        
        void clear()
        {
            noteGroups.clear();
            countCache = 0;
            isCountCacheDirty = false;
            durCache = Rational{ 0, 1 };
            isDurCacheDirty = false;
        }
        
        
        bool getIsEmpty() const
        {
            return this->getCount() == 0;
        }
        
        
        Rational getTotalDuration() const
        {
            if ( ! isDurCacheDirty )
            {
                return durCache;
            }
            Rational total{ 0, 1 };
            for ( auto i = noteGroups.cbegin();
                 i != noteGroups.cend(); ++i )
            {
                if ( i->first == NgType::Note )
                {
                    total += i->second->getNote( 0 )->getDuration()->getValue();
                }
                else
                {
                    total += i->second->getTotalDuration();
                }
            }
            durCache = total;
            isDurCacheDirty = false;
            return total;
        }
        
        
        int getCount() const
        {
            if ( ngType == NgType::Note )
            {
                return 1;
            }
            else if ( ngType == NgType::Unk )
            {
                return 0;
            }
            else if ( !isCountCacheDirty )
            {
                return countCache;
            }
            int count = 0;
            for ( auto i = noteGroups.cbegin();
                 i != noteGroups.cend(); ++i )
            {
                count += i->second->getCount();
            }
            countCache = count;
            isCountCacheDirty = false;
            return count;
        }
        
        
        void removeNote( int noteIndex )
        {
            int myCount = getCount();
            if ( noteIndex < 0 || noteIndex > myCount - 1 )
            {
                THROW( "index out of range" )
            }
            if ( ngType == NgType::Note )
            {
                THROW( "bad internal state" )
            }
            isDurCacheDirty = true;
            isCountCacheDirty = true;
            int counter = 0;
            for ( auto i = noteGroups.begin();
                 i != noteGroups.end(); ++i )
            {
                if ( counter == noteIndex )
                {
                    if ( i->first == NgType::Note )
                    {
                        noteGroups.erase( i );
                        return;
                    }
                    else
                    {
                        i->second->removeNote( 0 );
                        if ( i->second->getCount() == 0 )
                        {
                            noteGroups.erase( i );
                        }
                        return;
                    }
                }
                else if ( counter > noteIndex )
                {
                    THROW( "bad internal state" )
                }
                int currentItemGetCount = i->second->getCount();
                int targetItemIndexInChild = noteIndex - counter;
                int lastIndexInRange = counter + currentItemGetCount - 1;
                if ( noteIndex <= lastIndexInRange ) // note is in current
                {
                    i->second->removeNote( targetItemIndexInChild );
                    return;
                }
                counter += currentItemGetCount;
            }
        }
        
        
        int getGroupCount() const
        {
            int groupCount = 0;
            for ( auto i = noteGroups.begin();
                 i != noteGroups.end(); ++i )
            {
                if ( i->first == NgType::Group )
                {
                    ++groupCount;
                }
            }
            return groupCount;
        }
        
        
        bool getIsInGroup( int noteIndex ) const
        {
            if ( noteIndex < 0 || noteIndex > getCount() - 1 )
            {
                THROW( "index out of range" )
            }
            return ! ( getGroupIndex( noteIndex ) == -1 );
        }
        
        
        int getGroupIndex( int noteIndex ) const
        {
            if ( noteIndex < 0 || noteIndex > getCount() - 1 )
            {
                THROW( "index out of range" )
            }
            int counter = 0;
            int rangeStop = 0;
            int groupIndex = -1;
            for ( auto i = noteGroups.begin();
                 i != noteGroups.end(); ++i )
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
                rangeStop = counter + span - 1;
                if ( noteIndex >= counter && noteIndex <= rangeStop )
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
                counter += span;
            }
            return -1;
        }
        
        
        INoteGroupUP getGroup( int groupIndex ) const
        {
            if ( groupIndex < 0 )
            {
                THROW( "index out of range" )
            }
            int groupCounter = -1;
            for ( auto i = noteGroups.begin();
                 i != noteGroups.end(); ++i )
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
        
        
        void addGroup( const INoteGroupUP& group )
        {
            THROW_IF_NULL( group )
            if ( ngType == NgType::Note )
            {
                THROW( "bad internal state" )
            }
            isDurCacheDirty = true;
            isCountCacheDirty = true;
            MetaNoteGroup mng{ NgType::Group, group->clone() };
            noteGroups.push_back( std::move( mng ) );
        }
        
        
        void removeGroup( int groupIndex )
        {
            if ( groupIndex < 0 )
            {
                THROW( "index out of range" )
            }
            isDurCacheDirty = true;
            isCountCacheDirty = true;
            int groupCounter = -1;
            for ( auto i = noteGroups.begin();
                 i != noteGroups.end(); ++i )
            {
                if ( i->first == NgType::Group )
                {
                    ++groupCounter;
                    if ( groupCounter == groupIndex )
                    {
                        noteGroups.erase( i );
                        return;
                    }
                }
            }
            THROW( "index out of range" )
        }
        
        
        INoteUP getNote( int noteIndex ) const
        {
            if ( noteIndex < 0 || noteIndex > getCount() - 1 )
            {
                THROW( "index out of range" )
            }
            if ( ngType == NgType::Note )
            {
                if ( noteIndex != 0 )
                {
                    THROW( "index out of range" )
                }
                THROW_IF_NULL( note )
                return note->clone();
            }
            int counter = 0;
            for ( auto i = noteGroups.begin();
                 i != noteGroups.end(); ++i )
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
                    int rangeEnd = counter + currItemGetCount;
                    if ( noteIndex <= rangeEnd )
                    {
                        return i->second->getNote( noteIndex - counter );
                    }
                    counter += currItemGetCount;
                }
            }
            THROW( "should not reach here" )
        }
        
        
        void addNote( const INoteUP& note )
        {
            THROW_IF_NULL( note )
            if ( ngType == NgType::Note )
            {
                THROW( "cannot add to a leaf node" )
            }
            isDurCacheDirty = true;
            isCountCacheDirty = true;
            NoteGroup* newP = new NoteGroup{};
            newP->myImplP->ngType = NgType::Note;
            newP->myImplP->note = note->clone();
            INoteGroupUP newItem{ newP };
            MetaNoteGroup mng{ NgType::Note, std::move( newItem ) };
            noteGroups.push_back( std::move( mng ) );
        }
    };
    
/*******************************************************************************
NoteGroup
*******************************************************************************/
 
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
        other.myImplP = new Impl();
        return *this;
    }
    
    
	INoteGroupUP NoteGroup::clone() const
	{
		return INoteGroupUP{ new NoteGroup{ *this } };
	}
    
    
    INoteGroupUP NoteGroup::move()
    {
        NoteGroup *noteGroupP = new NoteGroup{};
        noteGroupP->myImplP = std::move( this->myImplP );
        myImplP = 0;
        return INoteGroupUP{ noteGroupP };
    }
    
    
    NoteGroupUP NoteGroup::copyNoteGroup() const
	{
		return NoteGroupUP{ new NoteGroup{ *this } };
	}

    
	std::ostream& NoteGroup::toStream( std::ostream& os ) const
	{
		return myImplP->toStreamImpl( os );
	}

    
    void NoteGroup::clear()
	{
		myImplP->clear();
	}
    
    
	bool NoteGroup::getIsEmpty() const
	{
		return getCount() == 0;
	}

    
	int NoteGroup::getCount() const
	{
        return myImplP->getCount();
	}
    

	Rational NoteGroup::getTotalDuration() const
	{
		return myImplP->getTotalDuration();
	}
    

	INoteUP NoteGroup::getNote( int noteIndex ) const
	{
        return myImplP->getNote( noteIndex );
	}
    

	void NoteGroup::addNote( const INoteUP& note )
	{
        myImplP->addNote( note );
	}
    

	void NoteGroup::removeNote( int noteIndex )
	{
        myImplP->removeNote( noteIndex );
	}
    
    
	int NoteGroup::getGroupCount() const
	{
        return myImplP->getGroupCount();
	}

    
	bool NoteGroup::getIsInGroup( int noteIndex ) const
	{
        return myImplP->getIsInGroup( noteIndex );
	}

    
	int NoteGroup::getGroupIndex( int noteIndex ) const
	{
        return myImplP->getGroupIndex( noteIndex );
	}

    
	INoteGroupUP NoteGroup::getGroup( int groupIndex ) const
	{
        return myImplP->getGroup( groupIndex );
	}
    

	void NoteGroup::addGroup( const INoteGroupUP& group )
	{
        myImplP->addGroup( group );
	}
    

	void NoteGroup::removeGroup( int groupIndex )
	{
        myImplP->removeGroup( groupIndex );
	}
    
}

