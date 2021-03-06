#ifndef PECAS_H_INCLUDED
#define PECAS_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

#include "dominios.h"
#include "entidades.h"

#include "sessoes.h"

using namespace std;

map<string, vector<string>> participantePecaAssociation;
map<string, vector<string>> cadastroParticipantePeca;

void listarPeca() {
    cout << "====================================" << endl;
    bool found = false;
    for(int i = 0; (unsigned)i < pecaVector.size(); i++) {
        cout << "O código da peça é : ";
        cout << pecaVector[i].getCodigo().getValor() << endl;
        cout << "O nome da peça é : ";
        cout << pecaVector[i].getNome().getValor() << endl;
        cout << "O tipo da peça é : ";
        cout << pecaVector[i].getTipo().getValor() << endl;
        cout << "A classificação da peça é : ";
        cout << pecaVector[i].getClassificacao().getValor() << endl;
        cout << "====================================" << endl;
        found = true;
    }
    if(!found) cout << "Nenhuma peça cadastrada" << endl;
}

void criarPeca(string inputMatricula) {
    Peca peca;
    
    Codigo codigo;
    Nome nome;
    Tipo tipo;
    Classificacao classificacao;

    bool found = false;
    char inputCodigo[80], inputNome[80], inputTipo[80], inputClassificacao[80];
    cin.ignore();

    cout << "Insira seus dados" << endl;
    cout << "====================================" << endl;
    cout << "Codigo: ";
    cin.getline(inputCodigo,sizeof(inputCodigo));
    try {
        codigo.setValor(string(inputCodigo));
    }
    catch(invalid_argument &exp) {
        cout << "Codigo precisa ter o formato LLDDDD (L são letras maisculas e D são dígitos)" << endl;
        return;
    }

    // Verifica se o código já foi cadastrado
    peca.setCodigo(codigo);

    for(int i = 0; (unsigned)i < pecaVector.size(); i++){
        if(pecaVector[i].getCodigo().getValor() == peca.getCodigo().getValor()) {
            found = true;
            cout << "Código já cadastrado" << endl;
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
    cout << "Tipo: ";
    cin.getline(inputTipo,sizeof(inputTipo));
    try{
        tipo.setValor(string(inputTipo));
    }
    catch(invalid_argument &exp){
        cout << "Insira uma classificacao válida, como auto, drama, farsa" << endl;
        return;
    }
    cout << "Classificacao: ";
    cin.getline(inputClassificacao,sizeof(inputClassificacao));
    try{
        classificacao.setValor(string(inputClassificacao));
    }
    catch(invalid_argument &exp){
        cout << "Insira uma classificacao válida, como livre, 10 ou 12" << endl;
        return;
    }

    peca.setCodigo(codigo);
    peca.setNome(nome);
    peca.setTipo(tipo);
    peca.setClassificacao(classificacao);
    if(!found) {
        pecaVector.push_back(peca);
        participantePecaAssociation[inputMatricula].push_back(inputCodigo);
    }

   cout << "====================================" << endl;
}

void procurarPeca() {
    cout << "Qual peça você gostaria de visualizar" << endl;
    cout << "====================================" << endl;
    cout << "Código: ";
    char inputCodigo[80];
    cin.ignore();
    cin.getline(inputCodigo,sizeof(inputCodigo));

    //Verifica se a peça existe
    bool allowAccess = false;

    for (auto peca : pecaVector) {
        if(peca.getCodigo().getValor() == inputCodigo) allowAccess = true;
    }

    if(!allowAccess) {
        cout << "Peça não existe" << endl;
        return;
    }

    string nome, tipo, classificacao;
    for(int i = 0; (unsigned)i < pecaVector.size(); i++) {
    if(pecaVector[i].getCodigo().getValor() == inputCodigo) {
            nome = pecaVector[i].getNome().getValor();
            tipo = pecaVector[i].getTipo().getValor();
            classificacao = pecaVector[i].getClassificacao().getValor();
            break;
        }
    }
    cout << "====================================" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Classificação: " << classificacao << endl;
    cout << "====================================" << endl;
}

string pecaToString(string codigo) {
    for (auto peca : pecaVector) {
        if(peca.getCodigo().getValor() == codigo) {
            return codigo + ";" + peca.getNome().getValor() + ";" + peca.getTipo().getValor() + ";" + peca.getClassificacao().getValor();
        }
    }

    return "";
}

Peca stringToPeca(string linha) {
    vector<string> parametros = split(linha, ';');

    Peca peca;
    
    Codigo codigo; codigo.setValor(parametros[0]);
    Nome nome; nome.setValor(parametros[1]);
    Tipo tipo; tipo.setValor(parametros[2]);
    Classificacao classificacao; classificacao.setValor(parametros[3]);

    peca.setCodigo(codigo);
    peca.setNome(nome);
    peca.setTipo(tipo);
    peca.setClassificacao(classificacao);

    return peca;
}

void editarPeca() {
    Nome nome;
    Tipo tipo;
    Classificacao classificacao;

    cout << "Qual peça você gostaria de editar" << endl;
    cout << "====================================" << endl;
    cout << "Código: ";
    char inputCodigo[80],inputNome[80], inputTipo[80], inputClassificacao[80];
    cin.ignore();
    cin.getline(inputCodigo,sizeof(inputCodigo));

    //Verifica se a peça existe
    bool allowAccess = false;

    for (auto peca : pecaVector) {
        if(peca.getCodigo().getValor() == inputCodigo) allowAccess = true;
    }

    if(!allowAccess) {
        cout << "Peça não existe" << endl;
        return;
    }

    cout << "Insira os dados da peça atualizados" << endl;
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
    cout << "Tipo: ";
    cin.getline(inputTipo,sizeof(inputTipo));
    try{
        tipo.setValor(string(inputTipo));
    }
    catch(invalid_argument &exp){
        cout << "Insira um tipo válido, como livre, 10 ou 12" << endl;
        return;
    }
    cout << "Classificacao: ";
    cin.getline(inputClassificacao,sizeof(inputClassificacao));
    try{
        classificacao.setValor(string(inputClassificacao));
    }
    catch(invalid_argument &exp){
        cout << "Insira uma classificacao válida, como auto, drama, farsa" << endl;
        return;
    }


    bool found = false;

    for(int i = 0; (unsigned)i < pecaVector.size(); i++){
        if(pecaVector[i].getCodigo().getValor() == inputCodigo) {
            found = true;
            pecaVector[i].setNome(nome);
            pecaVector[i].setTipo(tipo);
            pecaVector[i].setClassificacao(classificacao);
            cout << "Informações atualizadas com sucesso" << endl;
            break;
        }
    }

   cout << "====================================" << endl;
}

void excluirPeca(string inputCodigoPeca) {

    //Verifica se a peça existe
    bool allowAccess = false;

    for (auto peca : pecaVector) {
        if(peca.getCodigo().getValor() == inputCodigoPeca) allowAccess = true;
    }

    if(!allowAccess) {
        cout << "Peça não existe" << endl;
        return;
    }
    
    bool found = false;

    for(int i = 0; (unsigned)i < pecaVector.size(); i++){
        if(pecaVector[i].getCodigo().getValor() == inputCodigoPeca) {
            found = true;
            pecaVector.erase(pecaVector.begin() + i);
            cout << "Peca excluída com sucesso" << endl;
            break;
        }
    }

    //Apaga cadastros na peça
    cadastroParticipantePeca[inputCodigoPeca] = {};

    // Apaga sessoes de pecaSessaoAssociation
    for(auto x : pecaSessaoAssociation){
        for(int i = 0; i < x.second.size(); i++) {
            if(x.first == inputCodigoPeca) {
                excluirSessao(pecaSessaoAssociation[x.first][i]);
                pecaSessaoAssociation[x.first].erase(pecaSessaoAssociation[x.first].begin() + i);
            }
            break;
        }
    }

    // Apaga peças de participantePecaAssociation
    for(auto x : participantePecaAssociation){
        for(int i = 0; i < x.second.size(); i++) {
            if(x.second[i] == inputCodigoPeca) {
                participantePecaAssociation[x.first].erase(participantePecaAssociation[x.first].begin() + i);
            }
            break;
        }
    }
    if(!found) cout << "Peça não cadastrada" << endl;
}

#endif // PECAS_H_INCLUDED