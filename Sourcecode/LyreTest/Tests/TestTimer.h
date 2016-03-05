#pragma once
#include <chrono>

namespace LyreTest
{
    using Clock = std::chrono::high_resolution_clock;
    using Ms = std::chrono::milliseconds;
    using Ns = std::chrono::nanoseconds;
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
        double getMilliseconds()
        {
            auto end = Clock::now();
            if( !myIsRunning )
            {
                end = myStop;
            }
            auto ns = static_cast<double>( std::chrono::duration_cast<Ns>( end - myStart ).count() );
            auto ms = ns / 1000000.0;
            return ms;
        }
		void report( const std::string& message )
		{
			stop();
			std::cout << message << " " << getMilliseconds() << " ms" << std::endl;
		}
        
    private:
        TimePoint myStart;
        TimePoint myStop;
        bool myIsRunning;
    };
}
