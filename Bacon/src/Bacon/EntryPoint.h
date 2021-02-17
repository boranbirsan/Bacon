#pragma once

#ifdef BN_PLATFORM_WINDOWS

extern Bacon::Application* Bacon::CreateApplication();

int main(int argc, char** argv)
{
	Bacon::Log::Init();
	BN_CORE_INFO("Initialized Core Log!");
	BN_CLIENT_INFO("Initialized Client Log!");

	auto client = Bacon::CreateApplication();
	client->Run();
	delete client;
}
#endif
