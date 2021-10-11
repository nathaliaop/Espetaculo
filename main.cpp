#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "dominios.h"
#include "entidades.h"

using namespace std;

const int maxParticipante = 10;

vector<Participante> participanteVector = {};
string participanteSenha[maxParticipante] = {};

void adicionarParticipante() {
    char input1[80], input2[80];
    cin.ignore();
    cout << "Insira seus dados" << endl;
    cout << "====================================" << endl;
    cout << "Matrícula: ";
    cin.getline(input1,sizeof(input1));
    cout << "Senha: ";
    cin.getline(input2,sizeof(input2));

    Matricula matricula;
    Senha senha;

    try{
        matricula.setMatricula(string(input1));
    }
    catch(invalid_argument &exp){
        cout << "Matricula precisa ter 5 dígitos distintos" << endl;                                                                               // Leitura de caracter digitado.
        return;
    }
    try{
        senha.setSenha(string(input2));
    }
    catch(invalid_argument &exp){
        cout << "Senha precisa conter 8 caracteres distintos tendo pelo menos uma letra, um número e um caractere especial" << endl;                                                                               // Leitura de caracter digitado.
        return;
    }

    bool found = false;


    Participante participante;
    participante.setMatricula(matricula);
    for(int i = 0; (unsigned)i < participanteVector.size(); i++){
        if(participanteVector[i].getMatricula().getMatricula() == participante.getMatricula().getMatricula()) {
            found = true;
            cout << "Matrícula já cadastrada" << endl;
        }
    }
    if(!found) participanteVector.push_back(participante);
   cout << "====================================" << endl;
}

void listarParticipante() {
    cout << "oi";
    bool found = false;
    for(int i = 0; (unsigned)i < participanteVector.size(); i++){
        cout << participanteVector[i].getMatricula().getMatricula() << endl;
            found = true;
    }
    if(!found) cout << "No participants" << endl;
}


void participanteAutenticado(){
    cout << "oi" << endl;
}

void autenticarParticipante() {
    participanteAutenticado();
}

void listaPeca() {
        cout << "oi" << endl;
}

void listarSessao() {
        cout << "oi" << endl;
}

void listarSala() {
    cout << "oi" << endl;
}

int main() {
// --------------------------------------------------------------------------
//Testes de dominios
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
            case 2: adicionarParticipante();
                    break;
            case 3: listaPeca();
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
