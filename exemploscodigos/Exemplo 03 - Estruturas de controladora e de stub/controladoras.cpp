#include "controladoras.h"

// ---------------------------------------------------------------------------------
// Implementa��es de m�todos de classe controladora.

bool CntrIUAutenticacao::autenticar(Matricula *matricula) {
    Senha senha;
    int entrada;

    // Solicitar matricula e senha.

    while(true) {

        cout << endl << "Autenticacao de usuario." << endl << endl;

        try {
            cout << "Digite a matricula : ";
            cin >> entrada;
            matricula->setValor(entrada);
            cout << "Digite a senha     : ";
            cin >> entrada;
            senha.setValor(entrada);
            break;
        }
        catch (const invalid_argument &exp) {
            cout << endl << "Dado em formato incorreto." << endl;
        }
    }

    // Solicitar autentica��o.

    bool resultado = cntrLNAutenticacao->autenticar(*matricula, senha);

    // Retornar resultado da autentica��o.

    return resultado;
}
