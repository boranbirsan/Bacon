workspace "Bacon"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Bacon"
	location "Bacon"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
			"BN_PLATFORM_WINDOWS",
			"BN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Application")
		}

	filter "configurations:Debug"
		defines "BN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BN_DIST"
		optimize "On"

project "Application"
	location "Application"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

		files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Bacon/vendor/spdlog/include",
		"Bacon/src"
	}

	links
	{
		"Bacon"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
			"BN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BN_DIST"
		optimize "On"
	