#include "controladoras.h"
#include "telas.h"

// Defini��es de m�todos da classe CntrIUAutenticacao.

bool CntrIUAutenticacao::autenticar() {

    bool resultado;

    Matricula matricula;
    Senha senha;

    // Apresentar tela de autentica��o.

    while(true) {

        try {
            TelaAutenticacao telaAutenticacao;
            telaAutenticacao.apresentar(&matricula, &senha);
            break;
        }
        catch (const invalid_argument &exp) {
            TelaMensagem telaMensagem;
            telaMensagem.apresentar("Dado em formato incorreto.");
        }
    }

    // Solicitar autentica��o.

    resultado = cntrLNAutenticacao->autenticar(matricula, senha);

    return resultado;
}
