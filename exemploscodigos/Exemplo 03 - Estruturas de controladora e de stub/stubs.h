#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED

#include "Interfaces.h"

#include <stdexcept>
#include <iostream>
#include <typeinfo>

using namespace std;

// -------------------------------------------------------------------------------------------
// Declara��o de classe stub.

class StubLNAutenticacao:public ILNAutenticacao{

private:

    // Defini��es de valores a serem usados como gatilhos para notifica��es de erros.

    const static int TRIGGER_FALHA        = 67890;
    const static int TRIGGER_ERRO_SISTEMA = 78901;

public:

    // Declara��o de m�todo previsto em interface.

    bool autenticar(const Matricula&, const Senha&);
};


#endif // STUBS_H_INCLUDED
