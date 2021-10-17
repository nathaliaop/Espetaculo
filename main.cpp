#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

#include "dominios.h"
#include "entidades.h"

#include "participantes.h"
#include "database.h" // teste
#include <vector> // teste

using namespace std;

int main() {

    int option;
        Database database;
        vector<Participante, vector<Peca, vector<Sessao, vector<Sala>>>> dados = database.carregarArquivo();

        

        return 0;

    do {
        cout << "1 - Acessar sistema" << endl;
        cout << "2 - Realizar cadastro" << endl;
        cout << "3 - Listar peças" << endl;
        cout << "4 - Listar sessões" << endl;
        cout << "5 - Listar salas" << endl;
        cout << "6 - Sair do sistema" << endl;
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
        }
    } while(option != 6);
}
