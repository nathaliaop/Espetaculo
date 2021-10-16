#ifndef SESSOES_H_INCLUDED
#define SESSOES_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

#include "dominios.h"
#include "entidades.h"

#include "pecas.h"

using namespace std;

vector<Sessao> sessaoVector = {};
map<string, vector<string>> pecaSessaoAssociation = {};

void listarSessao() {
    cout << "====================================" << endl;
    bool found = false;
    for(int i = 0; (unsigned)i < sessaoVector.size(); i++) {
        cout << "O código da sessão é : ";
        cout << sessaoVector[i].getCodigo().getValor() << endl;
        cout << "O nome da sessão é : ";
        cout << sessaoVector[i].getData().getValor() << endl;
        cout << "O tipo da sessão é : ";
        cout << sessaoVector[i].getHorario().getValor() << endl;
        cout << "====================================" << endl;
        found = true;
    }
    if(!found) cout << "Nenhuma sessão cadastrada" << endl;
}

void criarSessao(string inputMatricula) {
    Sessao sessao;
    
    Codigo codigo;
    Data data;
    Horario horario;

    bool found = false;
    char inputCodigoSessao[80], inputData[80], inputHorario[80];
    char inputCodigoPeca[80];
    cin.ignore();

    cout << "Insira o código da peça que será apresentada na sessão" << endl;
    cout << "====================================" << endl;
    cout << "Codigo: ";
    cin.getline(inputCodigoPeca,sizeof(inputCodigoPeca));
    try {
        codigo.setValor(string(inputCodigoPeca));
    }
    catch(invalid_argument &exp) {
        cout << "Codigo precisa ter o formato LLDDDD (L são letras maisculas e D são dígitos)" << endl;
        return;
    }

    // Verifica se a peça não atingiu o limite de sessões
    if(pecaSessaoAssociation[inputCodigoPeca].size() == 5) {
        cout << "Essa peça já foi cadastrada em 5 sessões" << endl;
        return;
    }

    //Verifica se a peça existe
    bool allowAccess = false;

    for (auto peca : pecaVector) {
        if(peca.getCodigo().getValor() == inputCodigoPeca) allowAccess = true;
    }

    if(!allowAccess) {
        cout << "Peça não existe" << endl;
        return;
    }




    cout << "Insira o código da sessao" << endl;
    cout << "====================================" << endl;
    cout << "Codigo: ";
    cin.getline(inputCodigoSessao,sizeof(inputCodigoSessao));
    try {
        codigo.setValor(string(inputCodigoSessao));
    }
    catch(invalid_argument &exp) {
        cout << "Codigo precisa ter o formato LLDDDD (L são letras maisculas e D são dígitos)" << endl;
        return;
    }

    // Verifica se o código já foi cadastrado
    sessao.setCodigo(codigo);

    for(int i = 0; (unsigned)i < sessaoVector.size(); i++){
        if(sessaoVector[i].getCodigo().getValor() == sessao.getCodigo().getValor()) {
            found = true;
            cout << "Código já cadastrado" << endl;
            return;
        }
    }

    cout << "Data: ";
    cin.getline(inputData,sizeof(inputData));
    try {
        data.setValor(string(inputData));
    }
    catch(invalid_argument &exp){
        cout << "Data deve ter o formato 25/12/2000 e ser válida" << endl;
        return;
    }
    cout << "Horario: ";
    cin.getline(inputHorario,sizeof(inputHorario));
    try{
        horario.setValor(string(inputHorario));
    }
    catch(invalid_argument &exp){
        cout << "Horário deve ter o formato 00:00 e ser válido" << endl;
        return;
    }

    sessao.setCodigo(codigo);
    sessao.setData(data);
    sessao.setHorario(horario);
    if(!found) {
        sessaoVector.push_back(sessao);
        pecaSessaoAssociation[inputCodigoPeca].push_back(inputCodigoSessao);
    }

   cout << "====================================" << endl;
}

void procurarSessao(string inputMatricula) {
    cout << "Qual sessão você gostaria de visualizar" << endl;
    cout << "====================================" << endl;
    cout << "Código: ";
    char inputCodigo[80];
    cin.ignore();
    cin.getline(inputCodigo,sizeof(inputCodigo));

    //Verifica se a sessão existe
    bool allowAccess = false;

    for (auto sessao : sessaoVector) {
        if(sessao.getCodigo().getValor() == inputCodigo) allowAccess = true;
    }

    if(!allowAccess) {
        cout << "Sessão não existe" << endl;
        return;
    }

    string data, horario;
    for(int i = 0; (unsigned)i < sessaoVector.size(); i++) {
    if(sessaoVector[i].getCodigo().getValor() == inputCodigo) {
            data = sessaoVector[i].getData().getValor();
            horario = sessaoVector[i].getHorario().getValor();
            break;
        }
    }
    cout << "====================================" << endl;
    cout << "Data: " << data << endl;
    cout << "Horario: " << horario << endl;
    cout << "====================================" << endl;
}

void editarSessao(string inputMatricula) {
    Data data;
    Horario horario;

    cout << "Qual peça você gostaria de editar" << endl;
    cout << "====================================" << endl;
    cout << "Código: ";
    char inputCodigo[80],inputData[80], inputHorario[80];
    cin.ignore();
    cin.getline(inputCodigo,sizeof(inputCodigo));

    //Verifica se a sessão existe
    bool allowAccess = false;

    for (auto sessao : sessaoVector) {
        if(sessao.getCodigo().getValor() == inputCodigo) allowAccess = true;
    }

    if(!allowAccess) {
        cout << "Sessão não existe" << endl;
        return;
    }

    cout << "Insira os dados da peça atualizados" << endl;
    cout << "====================================" << endl;
    cout << "Data: ";
    cin.getline(inputData,sizeof(inputData));
    try {
        data.setValor(string(inputData));
    }
    catch(invalid_argument &exp){
        cout << "Data deve ter o formato 25/12/2000 e ser válida" << endl;
        return;
    }
    cout << "Horario: ";
    cin.getline(inputHorario,sizeof(inputHorario));
    try{
        horario.setValor(string(inputHorario));
    }
    catch(invalid_argument &exp){
        cout << "Horário deve ter o formato 00:00 e ser válido" << endl;
        return;
    }

    bool found = false;

    for(int i = 0; (unsigned)i < sessaoVector.size(); i++){
        if(sessaoVector[i].getCodigo().getValor() == inputCodigo) {
            found = true;
            sessaoVector[i].setData(data);
            sessaoVector[i].setHorario(horario);
            cout << "Informações atualizadas com sucesso" << endl;
            break;
        }
    }

   cout << "====================================" << endl;
}

void excluirSessao(string inputMatricula) {
    cout << "Qual sessão você gostaria de excluir" << endl;
    cout << "====================================" << endl;
    cout << "Codigo: ";

    char inputCodigoSessao[80];
    cin.ignore();
    cin.getline(inputCodigoSessao,sizeof(inputCodigoSessao));

    //Verifica se a sessão existe
    bool allowAccess = false;

    for (auto sessao : sessaoVector) {
        if(sessao.getCodigo().getValor() == inputCodigoSessao) allowAccess = true;
    }

    if(!allowAccess) {
        cout << "Sessão não existe" << endl;
        return;
    }
    
    bool found = false;

    for(int i = 0; (unsigned)i < sessaoVector.size(); i++){
        if(sessaoVector[i].getCodigo().getValor() == inputCodigoSessao) {
            found = true;
            sessaoVector.erase(sessaoVector.begin() + i);
            cout << "Sessão excluída com sucesso" << endl;
            break;
        }
    }

    // Apaga peça de pecaSessaoAssociation
    for(auto peca : pecaSessaoAssociation){
        for(int i = 0; i < peca.second.size(); i++) {
            if(peca.second[i] == inputCodigoSessao)
            pecaSessaoAssociation[peca.first].erase(pecaSessaoAssociation[peca.first].begin() + i);
            break;
        }
    }

    if(!found) cout << "Peça não cadastrada" << endl;
}

#endif // SESSOES_H_INCLUDED