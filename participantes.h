#ifndef PARTICIPANTES_H_INCLUDED
#define PARTICIPANTES_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

#include "dominios.h"
#include "entidades.h"
#include "utils.h"

#include "pecas.h"
#include "salas.h"
#include "sessoes.h"

using namespace std;

vector<Participante> participanteVector;

void cadastrarParticipantePeca(string inputMatricula) {
    cout << "Em qual peça você gostaria de se cadastrar" << endl;
    cout << "====================================" << endl;
    cout << "Código: ";
    char inputCodigoPeca[80];
    cin.ignore();
    cin.getline(inputCodigoPeca,sizeof(inputCodigoPeca));

    //Verifica se a peça existe
    bool allowAccess = false;

    for (auto peca : pecaVector) {
        if(peca.getCodigo().getValor() == inputCodigoPeca) allowAccess = true;
    }

    if(!allowAccess) {
        cout << "Peça não existe" << endl;
        return;
    }

    // Verifica se usuário já está cadastrado na peça
    for (auto participante : cadastroParticipantePeca[inputCodigoPeca]) {
        if(participante == inputMatricula) {
            cout << "Você já está cadastrado nessa peça" << endl;
            return;
        }
    }

    if(cadastroParticipantePeca[inputCodigoPeca].size() == 10) {
        cout << "Está peça já está lotada" << endl;
        return;
    }

    cadastroParticipantePeca[inputCodigoPeca].push_back(inputMatricula);
    cout << "Cadastro realizado com sucesso" << endl;
}

void criarParticipante() {
    Participante participante;
    
    Matricula matricula;
    Nome nome;
    Nome sobrenome;
    Email email;
    Telefone telefone;
    Senha senha;
    Cargo cargo;

    bool found = false;
    char inputMatricula[80], inputNome[80], inputSobrenome[80], inputEmail[80], inputTelefone[80], inputSenha[80], inputCargo[80];
    cin.ignore();

    cout << "Insira seus dados" << endl;
    cout << "====================================" << endl;
    cout << "Matrícula: ";
    cin.getline(inputMatricula,sizeof(inputMatricula));
    try {
        matricula.setValor(string(inputMatricula));
    }
    catch(invalid_argument &exp) {
        cout << "Matricula precisa ter 5 dígitos distintos" << endl;
        return;
    }

    // Verifica se a matrícula já foi cadastrada
    participante.setMatricula(matricula);

    for(int i = 0; (unsigned)i < participanteVector.size(); i++){
        if(participanteVector[i].getMatricula().getValor() == participante.getMatricula().getValor()) {
            found = true;
            cout << "Matrícula já cadastrada" << endl;
            return;
        }
    }

    cout << "Nome: ";
    cin.getline(inputNome,sizeof(inputNome));
    try {
        nome.setValor(string(inputNome));
    }
    catch(invalid_argument &exp){
        cout << "Cada palavra do nome deve começar com letra maiúscula e ter entre 5 e 20 caracteres" << endl;
        return;
    }
    cout << "Sobrenome: ";
    cin.getline(inputSobrenome,sizeof(inputSobrenome));
    try{
        sobrenome.setValor(string(inputSobrenome));
    }
    catch(invalid_argument &exp){
        cout << "Cada palavra do sobrenome deve começar com letra maiúscula e ter entre 5 e 20 caracteres" << endl;
        return;
    }
    cout << "Email: ";
    cin.getline(inputEmail,sizeof(inputEmail));
    try{
        email.setValor(string(inputEmail));
    }
    catch(invalid_argument &exp){
        cout << "Email precisa conter @" << endl;
        return;
    }
    cout << "Telefone: ";
    cin.getline(inputTelefone,sizeof(inputTelefone));
    try{
        telefone.setValor(string(inputTelefone));
    }
    catch(invalid_argument &exp){
        cout << "O DDD precisa ser válido e o telefone deve estar no formato (99)-999999999" << endl;
        return;
    }
    cout << "Senha: ";
    cin.getline(inputSenha,sizeof(inputSenha));
    try{
        senha.setValor(string(inputSenha));
    }
    catch(invalid_argument &exp){
        cout << "Senha precisa conter 8 caracteres distintos tendo pelo menos uma letra, um número e um caractere especial" << endl;
        return;
    }
    cout << "Cargo: ";
    cin.getline(inputCargo,sizeof(inputCargo));
    try{
        cargo.setValor(string(inputCargo));
    }
    catch(invalid_argument &exp){
        cout << "Escolha um cargo válido como ator, figurinista ou iluminador" << endl;
        return;
    }

    participante.setNome(nome);
    participante.setSobrenome(sobrenome);
    participante.setEmail(email);
    participante.setTelefone(telefone);
    participante.setSenha(senha);
    participante.setCargo(cargo);
    if(!found) {participanteVector.push_back(participante);
    }
   cout << "====================================" << endl;
}

void visualizarDadosPessoais(string inputMatricula) {
    string nome, sobrenome, email, telefone, senha, cargo;
    for(int i = 0; (unsigned)i < participanteVector.size(); i++){
       if(participanteVector[i].getMatricula().getValor() == inputMatricula) {
            nome = participanteVector[i].getNome().getValor();
            sobrenome = participanteVector[i].getSobrenome().getValor();
            email = participanteVector[i].getEmail().getValor();
            telefone = participanteVector[i].getTelefone().getValor();
            senha = participanteVector[i].getSenha().getValor();
            cargo = participanteVector[i].getCargo().getValor();
            break;
        }
    }
    cout << "====================================" << endl;
    cout << "Matrícula: " << inputMatricula << endl;
    cout << "Nome: " << nome << endl;
    cout << "Sobrenome: " << sobrenome << endl;
    cout << "Email: " << email << endl;
    cout << "Telefone: " << telefone << endl;
    cout << "Senha: " << senha << endl;
    cout << "Cargo: " << cargo << endl;
    cout << "====================================" << endl;
}

string participanteToString(string matricula) {
    string nome, sobrenome, email, telefone, senha, cargo;
    for(int i = 0; (unsigned)i < participanteVector.size(); i++){
       if(participanteVector[i].getMatricula().getValor() == matricula) {
            nome = participanteVector[i].getNome().getValor();
            sobrenome = participanteVector[i].getSobrenome().getValor();
            email = participanteVector[i].getEmail().getValor();
            telefone = participanteVector[i].getTelefone().getValor();
            senha = participanteVector[i].getSenha().getValor();
            cargo = participanteVector[i].getCargo().getValor();
            break;
        }
    }

    return matricula + ";" + nome + ";" + sobrenome + ";" + email + ";" + telefone + ";" + senha + ";" + cargo;
}

Participante stringToParticipante(string linha) {
    vector<string> parametros = split(linha, ';');

    Participante participante;
    
    Matricula matricula; matricula.setValor(parametros[0]);
    Nome nome; nome.setValor(parametros[1]);
    Nome sobrenome; sobrenome.setValor(parametros[2]);
    Email email; email.setValor(parametros[3]);
    Telefone telefone; telefone.setValor(parametros[4]);
    Senha senha; senha.setValor(parametros[5]);
    Cargo cargo; cargo.setValor(parametros[6]);

    participante.setMatricula(matricula);
    participante.setNome(nome);
    participante.setSobrenome(sobrenome);
    participante.setEmail(email);
    participante.setTelefone(telefone);
    participante.setSenha(senha);
    participante.setCargo(cargo);

    return participante;
}

void editarDadosPessoais(string inputMatricula) {
    Matricula matricula;
    Nome nome;
    Nome sobrenome;
    Email email;
    Telefone telefone;
    Senha senha;
    Cargo cargo;

    matricula.setValor(string(inputMatricula));

    char inputNome[80], inputSobrenome[80], inputEmail[80], inputTelefone[80], inputSenha[80], inputCargo[80];
    cin.ignore();
    cout << "Insira seus dados atualizados" << endl;
    cout << "====================================" << endl;
    cout << "Nome: ";
    cin.getline(inputNome,sizeof(inputNome));
    try{
        nome.setValor(string(inputNome));
    }
    catch(invalid_argument &exp){
        cout << "Cada palavra do nome deve começar com letra maiúscula e ter entre 5 e 20 caracteres" << endl;
        return;
    }
    cout << "Sobrenome: ";
    cin.getline(inputSobrenome,sizeof(inputSobrenome));
    try{
        sobrenome.setValor(string(inputSobrenome));
    }
    catch(invalid_argument &exp){
        cout << "Cada palavra do sobrenome deve começar com letra maiúscula e ter entre 5 e 20 caracteres" << endl;
        return;
    }
    cout << "Email: ";
    cin.getline(inputEmail,sizeof(inputEmail));
    try{
        email.setValor(string(inputEmail));
    }
    catch(invalid_argument &exp){
        cout << "Email precisa conter @" << endl;
        return;
    }
    cout << "Telefone: ";
    cin.getline(inputTelefone,sizeof(inputTelefone));
    try{
        telefone.setValor(string(inputTelefone));
    }
    catch(invalid_argument &exp){
        cout << "O DDD precisa ser válido e o telefone deve estar no formato (99)-999999999" << endl;
        return;
    }
    cout << "Senha: ";
    cin.getline(inputSenha,sizeof(inputSenha));
    try{
        senha.setValor(string(inputSenha));
    }
    catch(invalid_argument &exp){
        cout << "Senha precisa conter 8 caracteres distintos tendo pelo menos uma letra, um número e um caractere especial" << endl;
        return;
    }
    cout << "Cargo: ";
    cin.getline(inputCargo,sizeof(inputCargo));
    try{
        cargo.setValor(string(inputCargo));
    }
    catch(invalid_argument &exp){
        cout << "Escolha um cargo válido como ator, figurinista ou iluminador" << endl;
        return;
    }

    bool found = false;

    for(int i = 0; (unsigned)i < participanteVector.size(); i++){
        if(participanteVector[i].getMatricula().getValor() == inputMatricula) {
            found = true;
            participanteVector[i].setNome(nome);
            participanteVector[i].setSobrenome(sobrenome);
            participanteVector[i].setEmail(email);
            participanteVector[i].setTelefone(telefone);
            participanteVector[i].setSenha(senha);
            participanteVector[i].setCargo(cargo);
            cout << "Informações atualizadas com sucesso" << endl;
            break;
        }
    }
   cout << "====================================" << endl;
}

void excluirParticipante(string inputMatricula) {
    for(int i = 0; (unsigned)i < participanteVector.size(); i++){
        if(participanteVector[i].getMatricula().getValor() == inputMatricula) {
            participanteVector.erase(participanteVector.begin() + i);
            cout << "Cadastro excluído com sucesso" << endl;
            break;
        }
    }

    // Apaga cadastro do participante de cadastroParticipantePeca
    for(auto x : cadastroParticipantePeca){
        for(int i = 0; i < x.second.size(); i++) {
            if(x.second[i] == inputMatricula) {
                cadastroParticipantePeca[x.first].erase(cadastroParticipantePeca[x.first].begin() + i);
            }
            break;
        }
    }

    // Apaga peças de participantePecaAssociation
    for(auto x : participantePecaAssociation){
        for(int i = 0; i < x.second.size(); i++) {
            if(x.first == inputMatricula) {
                excluirPeca(participantePecaAssociation[x.first][i]);
                participantePecaAssociation[x.first].erase(participantePecaAssociation[x.first].begin() + i);
            }
            break;
        }
    }

}

void participanteAutenticado(string inputMatricula){
    int option;
    do {
        cout << "Sua matrícula é: " << inputMatricula << endl;
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
        cout << "16 - Listar peças" << endl;
        cout << "17 - Listar sessões" << endl;
        cout << "18 - Listar salas" << endl;
        cout << "19 - Cadastrar-se como participante da peça" << endl;
        cout << "20 - Retorna à tela inicial" << endl;
        cout << "Selecione a opção >> ";

        cin >> option;

        switch(option) {
            case 1: visualizarDadosPessoais(inputMatricula);
                    break;
            case 2: editarDadosPessoais(inputMatricula);
                    break;
            case 3: excluirParticipante(inputMatricula);
                    break;
            case 4: criarPeca(inputMatricula);
                    break;
            case 5: procurarPeca();
                    break;
            case 6: editarPeca();
                    break;
            case 7: cout << "Qual peça você gostaria de excluir" << endl;
                    cout << "====================================" << endl;
                    cout << "Codigo: ";
                    char inputCodigoPeca[80];
                    cin.ignore();
                    cin.getline(inputCodigoPeca,sizeof(inputCodigoPeca));
                    excluirPeca(inputCodigoPeca);
                    break;
            case 8: criarSessao();
                    break;
            case 9: procurarSessao();
                    break;
            case 10: editarSessao();
                    break;
            case 11:cout << "Qual sessão você gostaria de excluir" << endl;
                    cout << "====================================" << endl;
                    cout << "Codigo: ";
                    char inputCodigoSessao[80];
                    cin.ignore();
                    cin.getline(inputCodigoSessao,sizeof(inputCodigoSessao)); 
                    excluirSessao(inputCodigoSessao);
                    break;
            case 12: criarSala();
                    break;
            case 13: procurarSala();
                    break;
            case 14: editarSala();
                    break;
            case 15:cout << "Qual sala você gostaria de excluir" << endl;
                    cout << "====================================" << endl;
                    cout << "Codigo: ";
                    char inputCodigoSala[80];
                    cin.ignore();
                    cin.getline(inputCodigoSala,sizeof(inputCodigoSala)); 
                    excluirSala(inputCodigoSala);
                    break;
            case 16: listarPeca();
                    break;
            case 17: listarSessao();
                    break;
            case 18: listarSala();
                    break;
            case 19: cadastrarParticipantePeca(inputMatricula);
                    break;
        }
    } while(option != 20 && option != 3);
}

void autenticarParticipante() {
    Matricula matricula;
    Senha senha;
    char inputMatricula[80], inputSenha[80];
    cin.ignore();
    cout << "Insira seus dados" << endl;
    cout << "====================================" << endl;
    cout << "Matrícula: ";
    cin.getline(inputMatricula,sizeof(inputMatricula));
    try{
        matricula.setValor(string(inputMatricula));
    }
    catch(invalid_argument &exp){
        cout << "Matricula precisa ter 5 dígitos distintos" << endl;
        return;
    }
    cout << "Senha: ";
    cin.getline(inputSenha,sizeof(inputSenha));
    try{
        senha.setValor(string(inputSenha));
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
    if(foundSenha) participanteAutenticado(inputMatricula);
    else if(foundMatricula) {
        cout << "Senha incorreta!" << endl;
        return;
    }
    else {
        cout << "Participante não cadastrado!" << endl;
        return;
    }
    cout << "====================================" << endl;
}

#endif // PARTICIPANTES_H_INCLUDED