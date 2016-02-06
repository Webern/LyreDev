//PUBLIC
#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace Lyre
{
    using Integer = int;
    using Integers = std::vector<Integer>;
    using Float = long double;
    using Floats = std::vector<Float>;
    using String = std::string;
    using Strings = std::vector<String>;
}

#ifdef EXPORT_LYRE_API_SYMBOLS
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
		#define PUBLIC __declspec(dllexport)
		#define EXPORT_FOR_TESTS __declspec(dllexport)
		#pragma warning(disable:4251)
	#else
        #define PUBLIC
        #define EXPORT_FOR_TESTS
    #endif
#else
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        #define PUBLIC __declspec(dllexport)
        #define EXPORT_FOR_TESTS __declspec(dllexport)
		#pragma warning(disable:4251)
    #else
        #define PUBLIC
        #define EXPORT_FOR_TESTS
    #endif
#endif
