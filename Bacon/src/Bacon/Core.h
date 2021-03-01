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

#define BN_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)