#pragma once

#ifdef LUST_WIN32
#	ifdef LUST_BUILD_DLL
#		define LUST_API __declspec(dllexport)
#	elif defined(LUST_CONSUME_DLL)
#		define LUST_API __declspec(dllimport)
#	else
#		define LUST_API
#	endif
#else
#	define LUST_API
#endif
