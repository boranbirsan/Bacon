#pragma once

#include "Event.h"

namespace Bacon
{
	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Window Resize Event: (" << m_Width << ", " << m_Height << ")";
			return ss.str();
		}

		unsigned int GetWidth() { return m_Width; }
		unsigned int GetHeight() { return m_Height; }

		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	private:
		unsigned int m_Width, m_Height;
	};

	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Window Close Event";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	private:
	};

	class WindowMinimizeEvent : public Event
	{
	public:
		WindowMinimizeEvent() = default;

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Window Minimize Event";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	private:
	};
}