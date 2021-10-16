#ifndef PECAS_H_INCLUDED
#define PECAS_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

#include "dominios.h"
#include "entidades.h"

using namespace std;

vector<Peca> pecaVector = {};
map<string, vector<string>> participantePecaAssociation = {};

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
        found = true;
    }
    if(!found) cout << "Nenhuma peça cadastrada" << endl;
    cout << "====================================" << endl;
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

void procurarPeca(string inputMatricula) {
    cout << "Qual peça você gostaria de visualizar" << endl;
    cout << "====================================" << endl;
    cout << "Código: ";
    char inputCodigo[80];
    cin.ignore();
    cin.getline(inputCodigo,sizeof(inputCodigo));

    //Verifica se o usuário tem permissão para acessar a peça
    bool allowAccess = false;

    for (string pecaCodigo : participantePecaAssociation[inputMatricula]) {
        if(pecaCodigo == inputCodigo) allowAccess = true;
    }

    if(!allowAccess) {
        cout << "Peça não existe ou você não tem autorização para ver essa peça" << endl;
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

void editarPeca(string inputMatricula) {
    Nome nome;
    Tipo tipo;
    Classificacao classificacao;

    cout << "Qual peça você gostaria de editar" << endl;
    cout << "====================================" << endl;
    cout << "Código: ";
    char inputCodigo[80],inputNome[80], inputTipo[80], inputClassificacao[80];
    cin.ignore();
    cin.getline(inputCodigo,sizeof(inputCodigo));

    //Verifica se o usuário tem permissão para acessar a peça
    bool allowAccess = false;

    for (string pecaCodigo : participantePecaAssociation[inputMatricula]) {
        if(pecaCodigo == inputCodigo) allowAccess = true;
    }

    if(!allowAccess) {
        cout << "Peça não existe ou você não tem autorização para ver essa peça" << endl;
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

void excluirPeca(string inputMatricula) {
    cout << "Qual peça você gostaria de excluir" << endl;
    cout << "====================================" << endl;
    cout << "Codigo: ";

    char inputCodigo[80];
    cin.ignore();
    cin.getline(inputCodigo,sizeof(inputCodigo));

    //Verifica se o usuário tem permissão para acessar a peça
    bool allowAccess = false;

    for (string pecaCodigo : participantePecaAssociation[inputMatricula]) {
        if(pecaCodigo == inputCodigo) allowAccess = true;
    }

    if(!allowAccess) {
        cout << "Você não tem autorização para ver essa peça" << endl;
        return;
    }
    
    bool found = false;

    for(int i = 0; (unsigned)i < pecaVector.size(); i++){
        if(pecaVector[i].getCodigo().getValor() == inputCodigo) {
            found = true;
            pecaVector.erase(pecaVector.begin() + i);
            cout << "Peca excluída com sucesso" << endl;
            break;
        }
    }

    // Apaga peça de participantePecaAssociation
    for(int i = 0; (unsigned)i < participantePecaAssociation[inputMatricula].size(); i++){
        if(participantePecaAssociation[inputMatricula][i] == inputCodigo) {
            found = true;
            participantePecaAssociation[inputMatricula].erase(participantePecaAssociation[inputMatricula].begin() + i);
            break;
        }
    }

    if(!found) cout << "Peça não cadastrada" << endl;
}

#endif // PECAS_H_INCLUDED