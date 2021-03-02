#include <Bacon.h>

class ExampleLayer : public Bacon::Layer
{
public:
	ExampleLayer()
		: Layer("Example Layer") {}

	void OnUpdate() override 
	{
		auto [x, y] = Bacon::Input::GetMousePos();
		BN_CLIENT_TRACE("{0}, {1}", x, y);
	}

	void OnEvent(Bacon::Event& event) override 
	{
		//BN_CLIENT_TRACE("{0}: {1}", GetName(), event);
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