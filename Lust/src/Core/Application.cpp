// Lust.cpp: define o ponto de entrada para o aplicativo.
//

#include "Application.hpp"
#include <iostream>

#ifdef LUST_DEBUG_MODE
#include "Console.hpp"
#endif

Lust::Application::Application()
{
#ifdef LUST_DEBUG_MODE
	Console::Init();
#endif
}

Lust::Application::~Application()
{
#ifdef LUST_DEBUG_MODE
	Console::End();
#endif
}

void Lust::Application::Run()
{
	std::cout << "Hello World!\n";
	std::cout << "Here will come the loop!\n";
#ifdef LUST_DEBUG_MODE
	Console::CoreDebug("Debug level");
	Console::CoreLog("Info level");
	Console::CoreWarn("Warn level");
	Console::CoreError("Error level");
	Console::CoreCritical("Critical level");
#endif
}
