#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.h"
#include "dominios.h"

#include <stdexcept>
#include <iostream>

using namespace std;

// ---------------------------------------------------------------------------------
// Declara��o de classe controladora e implementa��o de m�todo.

class CntrIUAutenticacao:public IUAutenticacao {
private:
    ILNAutenticacao *cntrLNAutenticacao;        // Refer�ncia para servidor.
public:
    bool autenticar(Matricula*);
    void setCntrLNAutenticacao(ILNAutenticacao*);
};

void inline CntrIUAutenticacao::setCntrLNAutenticacao(ILNAutenticacao *cntrLNAutenticacao){
        this->cntrLNAutenticacao = cntrLNAutenticacao;
}

#endif // CONTROLADORAS_H_INCLUDED
