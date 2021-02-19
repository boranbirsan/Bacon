#include "bnpch.h"
#include "Application.h"

namespace Bacon
{
	
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));
	}

	Application::~Application()
	{

	}

	void Application::OnEvent(Event& event) 
	{
		BN_CORE_TRACE("{0}", event);
	}

	void Application::Run()
	{

		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}

}