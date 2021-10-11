// Exemplo de controladora de intera��o com PDCurses.

#include <string.h>
#include <stdexcept>
#include <iostream>

// Incluir cabe�alho da biblioteca PDCurses.

#include "curses.h"

#include "dominios.h"
#include "interfaces.h"
#include "controladoras.h"
#include "stubs.h"


using namespace std;

int main()
{
    IApresentacaoAutenticacao *cntr;
    IServicoAutenticacao *stub;

    CPF cpf;

    bool resultado;

    cntr = new CntrApresentacaoAutenticacao();                                      // Instanciar controladora.
    stub = new StubServicoAutenticacao();                                           // Instanciar stub.

    cntr->setCntrServicoAutenticacao(stub);                                         // Inteligar controladora e stub.

    initscr();                                                                      // Iniciar curses.

    resultado = cntr->autenticar(&cpf);                                             // Solicitar servi�o de autenticacao.

    endwin();                                                                       // Finalizar curses.

    // Apresentar resultado do processo de autentica��o.

    if(resultado)
        cout << "Sucesso na autenticacao";
    else
        cout << "Falha na autenticacao";

    return 0;
}

