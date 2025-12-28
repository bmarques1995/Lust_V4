#pragma once

#ifdef LUST_DEVUTILS_WIN32
#	ifdef LUST_DEVUTILS_BUILD_DLL
#		define LUST_DEVUTILS_API __declspec(dllexport)
#	elif defined(LUST_DEVUTILS_CONSUME_DLL)
#		define LUST_DEVUTILS_API __declspec(dllimport)
#	else
#		define LUST_DEVUTILS_API
#	endif
#else
#	define LUST_DEVUTILS_API
#endif