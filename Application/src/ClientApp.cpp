#include <Bacon.h>

class Client : public Bacon::Application
{
public:
	Client()
	{

	}

	~Client()
	{

	}
};

Bacon::Application* Bacon::CreateApplication()
{
	return new Client();
}