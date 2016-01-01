#pragma once
#include <string>

#ifndef __FILENAME__

    #ifdef WIN32

        #define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

    #else

        #define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

    #endif

#endif

#define THROW(message)                                  \
throw std::runtime_error (                              \
  std::string( "error in " )                            \
+ std::string( __FILENAME__ )                           \
+ std::string(" (line ")                                \
+ std::string( std::to_string(__LINE__ ) )              \
+ std::string(") ")                                     \
+ std::string( __FUNCTION__ )                           \
+ std::string(": ")                                     \
+ std::string( message ) );

