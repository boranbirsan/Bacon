#pragma once

#ifdef BN_PLATFORM_WINDOWS
	#ifdef BN_BUILD_DLL
		#define BACON_API __declspec(dllexport)
	#else
		#define BACON_API __declspec(dllimport)
	#endif
#else
	#error Bacon engine only supports Windows!
#endif

#define BIT(x) (1 << x)
