#include <Bacon.h>

class ExampleLayer : public Bacon::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override {}

	void OnEvent(Bacon::Event& event) override 
	{
		BN_CLIENT_TRACE("{0}", event);
	}
};

class Client : public Bacon::Application
{
public:
	Client()
	{
		PushLayer(new ExampleLayer());
	}

	~Client()
	{

	}
};

Bacon::Application* Bacon::CreateApplication()
{
	return new Client();
}