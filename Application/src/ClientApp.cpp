#include <Bacon.h>

class ExampleLayer : public Bacon::Layer
{
public:
	ExampleLayer()
		: Layer("Example Layer") {}

	void OnUpdate() override 
	{
	}

	void OnEvent(Bacon::Event& event) override 
	{
		BN_CLIENT_TRACE("{0}", event);

		if (event.GetEventType() == Bacon::EventType::KeyPressed)
		{
			Bacon::KeyPressedEvent& e = (Bacon::KeyPressedEvent&)event;
			if (e.GetKeyCode() == BN_KEY_TAB)
				BN_CLIENT_TRACE("Tab key is pressed (event)!");
			BN_CLIENT_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Client : public Bacon::Application
{
public:
	Client()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Bacon::ImGuiLayer());
	}

	~Client()
	{

	}
};

Bacon::Application* Bacon::CreateApplication()
{
	return new Client();
}