// Exemplo de uso de resposit�rio constru�do com SQLite.

#include <cstdlib>
#include <iostream>

#include "UnidadeControladoras.h"

/* --------------------------------------------------------------

Exemplos de usu�rios e senhas cadastradas em teste.db.

Matr�cula : 12345
Senha     : 54321

Matr�cula : 13579
Senha     : 12345

-------------------------------------------------------------- */

using namespace std;

int main(int argc, char *argv[])
{
    // Instanciar e executar autentica��o.

    CntrAutenticacao cntrA;
    cntrA.executar();

    // Instanciar e executar navega��o.

    CntrNavegacao cntrB;
    cntrB.executar();

    system("PAUSE");

    return EXIT_SUCCESS;
}
