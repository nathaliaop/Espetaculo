#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "dominios.h"
#include "entidades.h"

using namespace std;

vector<Participante> participanteVector = {};

void adicionarParticipante() {
    char inputMatricula[80], inputNome[80], inputSobrenome[80], inputEmail[80], inputTelefone[80], inputSenha[80], inputCargo[80];
    cin.ignore();
    cout << "Insira seus dados" << endl;
    cout << "====================================" << endl;
    cout << "Matrícula: ";
    cin.getline(inputMatricula,sizeof(inputMatricula));
    cout << "Nome: ";
    cin.getline(inputNome,sizeof(inputNome));
    cout << "Sobrenome: ";
    cin.getline(inputSobrenome,sizeof(inputSobrenome));
    cout << "Email: ";
    cin.getline(inputEmail,sizeof(inputEmail));
    cout << "Telefone: ";
    cin.getline(inputTelefone,sizeof(inputTelefone));
    cout << "Senha: ";
    cin.getline(inputSenha,sizeof(inputSenha));
    cout << "Cargo: ";
    cin.getline(inputCargo,sizeof(inputCargo));

    Matricula matricula;
    Nome nome;
    Nome sobrenome;
    Email email;
    Telefone telefone;
    Senha senha;
    Cargo cargo;

    try{
        matricula.setValor(string(inputMatricula));
    }
    catch(invalid_argument &exp){
        cout << "Matricula precisa ter 5 dígitos distintos" << endl;
        return;
    }

    try{
        nome.setValor(string(inputNome));
    }
    catch(invalid_argument &exp){
        cout << "Cada palavra do nome deve começar com letra maiúscula e ter entre 5 e 20 caracteres" << endl;
        return;
    }

    try{
        sobrenome.setValor(string(inputSobrenome));
    }
    catch(invalid_argument &exp){
        cout << "Cada palavra do sobrenome deve começar com letra maiúscula e ter entre 5 e 20 caracteres" << endl;
        return;
    }

    try{
        email.setValor(string(inputEmail));
    }
    catch(invalid_argument &exp){
        cout << "Email precisa conter @" << endl;
        return;
    }

    try{
        telefone.setValor(string(inputTelefone));
    }
    catch(invalid_argument &exp){
        cout << "O DDD precisa ser válido e o telefone deve estar no formato (99)-999999999" << endl;
        return;
    }

    try{
        senha.setValor(string(inputSenha));
    }
    catch(invalid_argument &exp){
        cout << "Senha precisa conter 8 caracteres distintos tendo pelo menos uma letra, um número e um caractere especial" << endl;
        return;
    }

    try{
        cargo.setValor(string(inputCargo));
    }
    catch(invalid_argument &exp){
        cout << "Escolha um cargo válido como ator, figurinista ou iluminador" << endl;
        return;
    }

    bool found = false;

    Participante participante;
    participante.setMatricula(matricula);
    participante.setNome(nome);
    participante.setSobrenome(sobrenome);
    participante.setEmail(email);
    participante.setTelefone(telefone);
    participante.setSenha(senha);
    participante.setCargo(cargo);
    for(int i = 0; (unsigned)i < participanteVector.size(); i++){
        if(participanteVector[i].getMatricula().getValor() == participante.getMatricula().getValor()) {
            found = true;
            cout << "Matrícula já cadastrada" << endl;
            break;
        }
    }
    if(!found) participanteVector.push_back(participante);
   cout << "====================================" << endl;
}

//Função para teste
void listarParticipante() {
    bool found = false;
    for(int i = 0; (unsigned)i < participanteVector.size(); i++){
        cout << participanteVector[i].getMatricula().getValor() << endl;
            found = true;
    }
    if(!found) cout << "No participants" << endl;
}

void visualizarDadosPessoais() {
    char input1[80], input2[80];
    cin.ignore();
    cout << "Insira seus dados" << endl;
    cout << "====================================" << endl;
    cout << "Matrícula: ";
    cin.getline(input1,sizeof(input1));
    cout << "Senha: ";
    cin.getline(input2,sizeof(input2));

    Matricula matricula;
    Nome nome;
}

void editarDadosPessoais() {
    cout << "oi" << endl;
}

void excluirParticipante() {
    cout << "oi" << endl;
}

void criarPeca() {
    cout << "oi" << endl;
}

void procurarPeca() {
    cout << "oi" << endl;
}

void editarPeca() {
    cout << "oi" << endl;
}

void excluirPeca() {
    cout << "oi" << endl;
}

void criarSessao() {
    cout << "oi" << endl;
}

void procurarSessao() {
    cout << "oi" << endl;
}

void editarSessao() {
    cout << "oi" << endl;
}

void excluirSessao() {
    cout << "oi" << endl;
}

void criarSala() {
    cout << "oi" << endl;
}

void procurarSala() {
    cout << "oi" << endl;
}

void editarSala() {
    cout << "oi" << endl;
}

void excluirSala() {
    cout << "oi" << endl;
}


void participanteAutenticado(string input1){
    int option;

    do {
        cout << "Sua matrícula é: " << input1 << endl;
        cout << "1 - Visualizar dados pessoais" << endl;
        cout << "2 - Editar dados pessoais" << endl;
        cout << "3 - Excluir cadastro no sistema" << endl;
        cout << "4 - Criar peça" << endl;
        cout << "5 - Procurar peça" << endl;
        cout << "6 - Editar peça" << endl;
        cout << "7 - Excluir peça" << endl;
        cout << "8 - Criar sessão" << endl;
        cout << "9 - Procurar sessão" << endl;
        cout << "10 - Editar sessão" << endl;
        cout << "11 - Excluir sessão" << endl;
        cout << "12 - Criar sala" << endl;
        cout << "13 - Procurar sala" << endl;
        cout << "14 - Editar sala" << endl;
        cout << "15 - Excluir sala" << endl;
        cout << "16 - Retorna à tela inicial" << endl;
        cout << "Selecione a opção >> ";

        cin >> option;

        switch(option) {
            case 1: visualizarDadosPessoais();
                    break;
            case 2: editarDadosPessoais();
                    break;
            case 3: excluirParticipante();
                    break;
            case 4: criarPeca();
                    break;
            case 5: procurarPeca();
                    break;
            case 6: editarPeca();
                    break;
            case 7: excluirPeca();
                    break;
            case 8: criarSessao();
                    break;
            case 9: procurarSessao();
                    break;
            case 10: editarSessao();
                    break;
            case 11: excluirSessao();
                    break;
            case 12: criarSala();
                    break;
            case 13: procurarSala();
                    break;
            case 14: editarSala();
                    break;
            case 15: excluirSala();
                    break;
        }
    } while(option != 16);
}

void autenticarParticipante() {
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
        matricula.setValor(string(input1));
    }
    catch(invalid_argument &exp){
        cout << "Matricula precisa ter 5 dígitos distintos" << endl;
        return;
    }
    try{
        senha.setValor(string(input2));
    }
    catch(invalid_argument &exp){
        cout << "Senha precisa conter 8 caracteres distintos tendo pelo menos uma letra, um número e um caractere especial" << endl;
        return;
    }

    Participante participante;
    participante.setMatricula(matricula);
    participante.setSenha(senha);

    bool foundMatricula = false;
    bool foundSenha = false;

    for(int i = 0; (unsigned)i < participanteVector.size(); i++){
       if(participanteVector[i].getMatricula().getValor() == participante.getMatricula().getValor()) {
           foundMatricula = true;
            if(participanteVector[i].getSenha().getValor() == participante.getSenha().getValor()) {
                foundSenha = true;
            }
        }
    }
    if(foundSenha) participanteAutenticado(input1);
    else if(foundMatricula) {
        cout << "Senha incorreta!" << endl;
        return;
    }
    else {
        cout << "Participante não cadastrado!" << endl;
        return;
    }
}

void listarPeca() {
    cout << "oi" << endl;
}

void listarSessao() {
    cout << "oi" << endl;
}

void listarSala() {
    cout << "oi" << endl;
}

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
            case 2: adicionarParticipante();
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
