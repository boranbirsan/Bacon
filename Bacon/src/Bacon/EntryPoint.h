#pragma once

#ifdef BN_PLATFORM_WINDOWS

extern Bacon::Application* Bacon::CreateApplication();

int main(int argc, char** argv)
{
	printf("Initialize Bacon Engine!\n");
	auto client = Bacon::CreateApplication();
	client->Run();
	delete client;
}
#endif
