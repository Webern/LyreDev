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

#if 1==0
namespace jrd {
    namespace time {
        class Timer {
            typedef std::chrono::high_resolution_clock high_resolution_clock;
            typedef std::chrono::milliseconds milliseconds;
        public:
            explicit Timer(bool run = false)
            {
                if (run)
                    Reset();
            }
            void Reset()
            {
                _start = high_resolution_clock::now();
            }
            milliseconds Elapsed() const
            {
                return std::chrono::duration_cast<milliseconds>(high_resolution_clock::now() - _start);
            }
            template <typename T, typename Traits>
            friend std::basic_ostream<T, Traits>& operator<<(std::basic_ostream<T, Traits>& out, const Timer& timer)
            {
                return out << timer.Elapsed().count();
            }
        private:
            high_resolution_clock::time_point _start;
        };
    }
}
#endif