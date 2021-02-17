#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Bacon
{
	class BACON_API Log
	{
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// CORE Log ------------------------
#define BN_CORE_ERROR(...)		::Bacon::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BN_CORE_WARN(...)		::Bacon::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BN_CORE_INFO(...)		::Bacon::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BN_CORE_TRACE(...)		::Bacon::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BN_CORE_CRITICAL(...)	::Bacon::Log::GetCoreLogger()->critical(__VA_ARGS__)

// CLIENT Log ----------------------
#define BN_CLIENT_ERROR(...)	::Bacon::Log::GetClientLogger()->error(__VA_ARGS__)
#define BN_CLIENT_WARN(...)		::Bacon::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BN_CLIENT_INFO(...)		::Bacon::Log::GetClientLogger()->info(__VA_ARGS__)
#define BN_CLIENT_TRACE(...)	::Bacon::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BN_CLIENT_CRITICAL(...)	::Bacon::Log::GetClientLogger()->critical(__VA_ARGS__)