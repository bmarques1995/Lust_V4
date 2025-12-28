#include "Application.hpp"

class SandCoffin : public Lust::Application
{
public:
	SandCoffin() : Lust::Application() {}
	~SandCoffin() {}
};

Lust::Application* CreateApplication()
{
	return new SandCoffin();
}

int main(int argc, char* argv[]) {
	Lust::Application* app = CreateApplication();
	app->Run();
	delete app;
	return 0;
}

