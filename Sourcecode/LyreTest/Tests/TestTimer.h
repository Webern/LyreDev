#pragma once
#include <chrono>

namespace LyreTest
{
    using Clock = std::chrono::high_resolution_clock;
    using Ms = std::chrono::milliseconds;
    using TimePoint = std::chrono::high_resolution_clock::time_point;
    
    class TestTimer
    {
    public:
        TestTimer()
        :myStart( Clock::now() )
        ,myStop( Clock::now() )
        ,myIsRunning( true )
        {}
        
        void start() { myStart = Clock::now(); myIsRunning = true; }
        void stop() { myStop = Clock::now(); myIsRunning = false; }
        int getMilliseconds()
        {
            auto end = Clock::now();
            if( !myIsRunning )
            {
                end = myStop;
            }
            return static_cast<int>( std::chrono::duration_cast<Ms>( end - myStart ).count() );
        }
        
    private:
        TimePoint myStart;
        TimePoint myStop;
        bool myIsRunning;
    };
}
