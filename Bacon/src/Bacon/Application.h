#pragma once

#include "Core.h"
#include "Window.h"

namespace Bacon
{
	class BACON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication(); 
}

