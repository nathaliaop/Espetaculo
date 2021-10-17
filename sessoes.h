#ifndef SESSOES_H_INCLUDED
#define SESSOES_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

#include "dominios.h"
#include "entidades.h"

using namespace std;

vector<Sessao> sessaoVector;
vector<Peca> pecaVector;
vector<Sala> salaVector;
map<string, vector<string>> pecaSessaoAssociation;
map<string, vector<string>> salaSessaoAssociation;

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

void criarSessao() {
    Sessao sessao;
    
    Codigo codigo;
    Data data;
    Horario horario;

    bool found = false;
    char inputCodigoSessao[80], inputData[80], inputHorario[80];
    char inputCodigoPeca[80], inputCodigoSala[80];
    cin.ignore();

    //Verifica a relação com peça
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
    bool allowAccessPeca = false;

    for (auto peca : pecaVector) {
        if(peca.getCodigo().getValor() == inputCodigoPeca) allowAccessPeca = true;
    }

    if(!allowAccessPeca) {
        cout << "Peça não existe" << endl;
        return;
    }



  //Verifica a relação com sala
    cout << "Insira o código da sala onde a sessão será exibida" << endl;
    cout << "====================================" << endl;
    cout << "Codigo: ";
    cin.getline(inputCodigoSala,sizeof(inputCodigoSala));
    try {
        codigo.setValor(string(inputCodigoSala));
    }
    catch(invalid_argument &exp) {
        cout << "Codigo precisa ter o formato LLDDDD (L são letras maisculas e D são dígitos)" << endl;
        return;
    }

    //Verifica se a sala existe
    bool allowAccessSala = false;

    for (auto sala : salaVector) {
        if(sala.getCodigo().getValor() == inputCodigoSala) allowAccessSala = true;
    }

    if(!allowAccessSala) {
        cout << "Sala não existe" << endl;
        return;
    }


    // Cria sessão
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
        salaSessaoAssociation[inputCodigoSala].push_back(inputCodigoSessao);
    }

   cout << "====================================" << endl;
}

void procurarSessao() {
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

string sessaoToString(string codigo) {
    for (auto sessao : sessaoVector) {
        if(sessao.getCodigo().getValor() == codigo) {
            return codigo + ";" + sessao.getData().getValor() + ";" + sessao.getHorario().getValor();
        }
    }

    return "";
}

Sessao stringToSessao(string linha) {
    vector<string> parametros = split(linha, ';');

    Sessao sessao;
    
    Codigo codigo; codigo.setValor(parametros[0]);
    Data data; data.setValor(parametros[1]);
    Horario horario; horario.setValor(parametros[2]);

    sessao.setCodigo(codigo);
    sessao.setData(data);
    sessao.setHorario(horario);

    return sessao;
}

void editarSessao() {
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

void excluirSessao(string inputCodigoSessao) {

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

    // Apaga sessão de pecaSessaoAssociation
    for(auto x : pecaSessaoAssociation){
        for(int i = 0; i < x.second.size(); i++) {
            if(x.second[i] == inputCodigoSessao) {
                pecaSessaoAssociation[x.first].erase(pecaSessaoAssociation[x.first].begin() + i);
            }
            break;
        }
    }

    // Apaga sessão de salaSessaoAssociation
    for(auto x : salaSessaoAssociation){
        for(int i = 0; i < x.second.size(); i++) {
            if(x.second[i] == inputCodigoSessao) {
                salaSessaoAssociation[x.first].erase(salaSessaoAssociation[x.first].begin() + i);
            }
            break;
        }
    }

    if(!found) cout << "Peça não cadastrada" << endl;
}

#endif // SESSOES_H_INCLUDED