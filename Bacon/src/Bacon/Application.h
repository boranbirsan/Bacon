#pragma once

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"

namespace Bacon
{
	class BACON_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		void OnEvent(Event& event);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	Application* CreateApplication(); 
}

