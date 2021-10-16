#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

#include "dominios.h"
#include "entidades.h"

#include "participantes.h"

using namespace std;

int main() {

    int option;

    do {
        cout << "1 - Acessar sistema" << endl;
        cout << "2 - Realizar cadastro" << endl;
        cout << "3 - Listar peças" << endl;
        cout << "4 - Listar sessões" << endl;
        cout << "5 - Listar salas" << endl;
        cout << "6 - Sair do sistema" << endl;
        cout << "7 - Listar participantes" << endl;
        cout << "Selecione a opção >> ";

        cin >> option;

        switch(option) {
            case 1: autenticarParticipante();
                    break;
            case 2: criarParticipante();
                    break;
            case 3: listarPeca();
                    break;
            case 4: listarSessao();
                    break;
            case 5: listarSala();
                    break;
            case 7: listarParticipante();
                    break;
        }
    } while(option != 6);
}
