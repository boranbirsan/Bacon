#pragma once

#include "Bacon/Layer.h"

#include "Bacon/Events/ApplicationEvent.h"
#include "Bacon/Events/KeyEvent.h"
#include "Bacon/Events/MouseEvent.h"

#include "Bacon/Application.h"

namespace Bacon 
{
	class BACON_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();

		void OnUpdate();
		void OnEvent(Event& event);
	private:
		bool OnMouseButtonPresssed(ButtonPressedEvent& event);
		bool OnMouseButtonReleased(ButtonReleasedEvent& event);
		bool OnMouseMoved(MouseMovedEvent& event);
		bool OnMouseScroll(MouseScrolledEvent& event);
		bool OnKeyPressed(KeyPressedEvent& event);
		bool OnKeyReleased(KeyReleasedEvent& event);
		bool OnWindowResize(WindowResizeEvent& event);

		float m_Time = 0.0f;
	};
}

