#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Bacon
{
	class BACON_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnUpdate() {};
		virtual void OnEvent(Event& event) {};

		inline const std::string GetName() { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}

