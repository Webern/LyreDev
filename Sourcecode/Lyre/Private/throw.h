#pragma once
#include <string>

#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)

#define THROW(message)                     \
throw std::runtime_error (                 \
  std::string( "error in " )               \
+ std::string( __FILENAME__ )              \
+ std::string(" (line ")                   \
+ std::string( std::to_string(__LINE__ ))  \
+ std::string(") ")                        \
+ std::string( __FUNCTION__ )              \
+ std::string(": ")                        \
+ std::string( message ) );

