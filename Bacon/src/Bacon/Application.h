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
		void OnEvent(Event& event);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* CreateApplication(); 
}

