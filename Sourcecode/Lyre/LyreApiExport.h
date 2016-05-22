// PUBLIC
#pragma once

// Sorry for the global pragma disable.

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
