// Exemplos de estruturas de classe controladora e stub.

// Incluir cabe�alhos.

#include <stdexcept>
#include <iostream>
#include <string>

#include "dominios.h"
#include "interfaces.h"
#include "controladoras.h"
#include "stubs.h"

using namespace std;

int main()
{
    // ---------------------------------------------------------------------------------
    // Instanciar classe controladora e classe stub.

    IUAutenticacao  *cntrIUAutenticacao = new CntrIUAutenticacao();
    ILNAutenticacao *stubLNAutenticacao = new StubLNAutenticacao();

    // Ligar inst�ncia de controladora a inst�ncia de stub.

    cntrIUAutenticacao->setCntrLNAutenticacao(stubLNAutenticacao);

    bool resultado;

    Matricula matricula;

    while(true){

        // Simular apresenta��o de tela inicial do sistema.

        cout << endl << "Tela inicial de sistema." << endl;

        try{

            // Soliciatar servi�o de autentica��o.

            resultado = cntrIUAutenticacao->autenticar(&matricula);
        }
        catch(const runtime_error &exp){
                 cout << "Erro de sistema." << endl;
                 break;
        }

        // Criticar resultado da autentica��o.

        if(resultado) {
            cout << endl << "Sucesso autenticacao." << endl;
            cout << endl << "Matricula = " << matricula.getValor() << endl;
            break;
        }
        else {
            cout << endl << "Erro autenticacao." << endl;
            break;
        }
    }

    // Destruir inst�ncia de controladora e inst�ncia de stub.

    delete cntrIUAutenticacao;
    delete stubLNAutenticacao;

    return 0;
}
