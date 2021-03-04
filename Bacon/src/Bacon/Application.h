#pragma once

#include "Core.h"
#include "Window.h"
#include "LayerStack.h"

#include "Events/ApplicationEvent.h"

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

		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		void OnEvent(Event& event);
		bool OnWindowClose(WindowCloseEvent& event);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
		
		static Application* s_Instance;
	};

	Application* CreateApplication(); 
}

