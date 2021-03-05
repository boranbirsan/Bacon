#pragma once

#include "Bacon/Layer.h"

#include "Bacon/Events/ApplicationEvent.h"
#include "Bacon/Events/KeyEvent.h"
#include "Bacon/Events/MouseEvent.h"

namespace Bacon 
{
	class BACON_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}

