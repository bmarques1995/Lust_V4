// Lust.h: arquivo de inclusão para arquivos de inclusão padrão do sistema,
// ou arquivos de inclusão específicos a um projeto.

#pragma once

#include "LustDLLMacro.hpp"

namespace Lust
{
	class LUST_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
}

// TODO: Referencie os cabeçalhos adicionais de que seu programa precisa aqui.
