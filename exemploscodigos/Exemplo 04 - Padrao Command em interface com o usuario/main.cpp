// Exemplo de uso do padr�o de projeto Command na constru��o de interface com o usu�rio.

// Incluir cabe�alhos.

#include <stdexcept>
#include <iostream>
#include <string>

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "controladoras.h"
#include "stubs.h"

using namespace std;

int main()
{
    // -------------------------------------------------------------------------------------------
    // Declarar ponteiros e instanciar controladoras.

    IAAutenticacao  *cntrIAAutenticacao;
    IAGerente       *cntrIAGerente;

    cntrIAAutenticacao = new CntrIAAutenticacao();
    cntrIAGerente = new CntrIAGerente();

    // -------------------------------------------------------------------------------------------
    // Declarar ponteiros e instanciar stubs.

    ISAutenticacao *stubISAutenticacao;
    ISGerente      *stubISGerente;

    stubISAutenticacao = new StubISAutenticacao();
    stubISGerente = new StubISGerente();

    // -------------------------------------------------------------------------------------------
    // Estabelecer relacionamentos entre inst�ncias de controladoras e inst�ncias de stubs.

    cntrIAAutenticacao->setCntrISAutenticacao(stubISAutenticacao);
    cntrIAGerente->setCntrISGerente(stubISGerente);

    bool resultado;

    Matricula matricula;

    while(true){

        // Simular apresenta��o da tela inicial do sistema.

        cout << endl << "Tela inicial de sistema." << endl;

        try{

            // Solicitar servi�o de autentica��o.

            resultado = cntrIAAutenticacao->autenticar(&matricula);

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
        catch(const runtime_error &exp){
                 cout << "Erro de sistema." << endl;
        }
    }

    try{

        // Solicitar servi�o da controladora de apresenta��o.

        cntrIAGerente->executar(matricula);
    }
    catch(const runtime_error &exp){
        cout << "Erro de sistema." << endl;
    }

    // Destruir inst�ncias criadas.

    delete cntrIAAutenticacao;
    delete cntrIAGerente;
    delete stubISAutenticacao;
    delete stubISGerente;

    return 0;
}
