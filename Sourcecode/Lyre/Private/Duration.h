//PRIVATE
#pragma once
#include "Lyre/Lyre.h"
#include "Lyre/IDuration.h"
#include "Lyre/ITupletDef.h"
#include "Lyre/IDurDotFactory.h"
#include <map>

namespace Lyre
{
    FORWARD_DECLARE(IDurDot)
    
    namespace Private
    {
        class EXPORT_FOR_TESTS Duration : public IDuration
        {
        public:
            virtual ~Duration();
            
            Duration();

            Duration( const String& durName );

            Duration(
                const String& durName,
                const int dotCount );

            Duration(
                const VecITupletDefSPC& tuplets,
                const String& durName,
                const int dotCount );
            
            static IDurationUP findDuration(
                Rational rational,
                bool doThrowOnBadInput );
            
            IDurationUP clone() const;
            Rational getDurBaseValue() const;
            String getDurBaseName() const;
            int getDotCount() const;
            Rational getDottedBaseValue() const;
            String getDottedBaseName() const;
            
            bool getIsTuplet() const;
            bool getIsNestedTuplet() const;
            int getTupletNestingCount() const;
            VecITupletDefSPCIterC getTupletsBegin() const;
            VecITupletDefSPCIterC getTupletsEnd() const;
            
            Rational getValue() const;

            virtual std::ostream& toStream( std::ostream& os ) const;
            virtual String toString() const;
            
            
            
        private:
            IDurDotFactoryUP myDurDotFactory;
            IDurDotUP myDurDot;
            VecITupletDefSPC myTuplets;
            
            static std::map<Rational, IDurationUP> ourDurLut;
            static void initializeLut();
            
            static void addTuplet(
                const char* durName,
                int dots,
                int tupNum,
                int inTheSpaceOf );
            
            static void addTupletGroup(
               const char* durName,
               int tupNum,
               int inTheSpaceOf );
            
            static void addTupletGroups( const char* durName );
            
            static void addAllTuplets();
            
            static void addDurDots( const char* durName );
            static void addAllDurDots();
        };
    }
}
