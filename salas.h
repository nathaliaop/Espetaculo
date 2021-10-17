#ifndef SALAS_H_INCLUDED
#define SALAS_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

#include "dominios.h"
#include "entidades.h"

#include "sessoes.h"

using namespace std;


void listarSala() {
    cout << "====================================" << endl;
    bool found = false;
    for(int i = 0; (unsigned)i < salaVector.size(); i++) {
        cout << "O código da sala é : ";
        cout << salaVector[i].getCodigo().getValor() << endl;
        cout << "O nome da sala é : ";
        cout << salaVector[i].getNome().getValor() << endl;
        cout << "A capacidade da sala é : ";
        cout << salaVector[i].getCapacidade().getValor() << endl;
        cout << "====================================" << endl;
        found = true;
    }
    if(!found) cout << "Nenhuma sala cadastrada" << endl;
}

void criarSala() {
    Sala sala;
    
    Codigo codigo;
    Nome nome;
    Capacidade capacidade;

    bool found = false;
    char inputCodigoSala[80], inputNome[80], inputCapacidade[80];
    char inputCodigoSessao[80];
    cin.ignore();

    cout << "Insira o código da sala" << endl;
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
    sala.setCodigo(codigo);

    for(int i = 0; (unsigned)i < salaVector.size(); i++){
        if(salaVector[i].getCodigo().getValor() == sala.getCodigo().getValor()) {
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
    cout << "Capacidade: ";
    cin.getline(inputCapacidade,sizeof(inputCapacidade));
    try{
        capacidade.setValor(string(inputCapacidade));
    }
    catch(invalid_argument &exp){
        cout << "Insira uma capacidade válida como 100, 200 ou 300" << endl;
        return;
    }

    sala.setCodigo(codigo);
    sala.setNome(nome);
    sala.setCapacidade(capacidade);
    if(!found) {
        salaVector.push_back(sala);
    }

   cout << "====================================" << endl;
}

void procurarSala() {
    cout << "Qual sala você gostaria de visualizar" << endl;
    cout << "====================================" << endl;
    cout << "Código: ";
    char inputCodigo[80];
    cin.ignore();
    cin.getline(inputCodigo,sizeof(inputCodigo));

    //Verifica se a sessão existe
    bool allowAccess = false;

    for (auto sala : salaVector) {
        if(sala.getCodigo().getValor() == inputCodigo) allowAccess = true;
    }

    if(!allowAccess) {
        cout << "Sala não existe" << endl;
        return;
    }

    string nome, capacidade;
    for(int i = 0; (unsigned)i < salaVector.size(); i++) {
        if(salaVector[i].getCodigo().getValor() == inputCodigo) {
            nome = salaVector[i].getNome().getValor();
            capacidade = salaVector[i].getCapacidade().getValor();
            break;
        }
    }
    cout << "====================================" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Capacidade: " << capacidade << endl;
    cout << "====================================" << endl;
}

void editarSala() {
    Nome nome;
    Capacidade capacidade;

    cout << "Qual sala você gostaria de editar" << endl;
    cout << "====================================" << endl;
    cout << "Código: ";
    char inputCodigo[80],inputNome[80], inputCapacidade[80];
    cin.ignore();
    cin.getline(inputCodigo,sizeof(inputCodigo));

    //Verifica se a sala existe
    bool allowAccess = false;

    for (auto sala : salaVector) {
        if(sala.getCodigo().getValor() == inputCodigo) allowAccess = true;
    }

    if(!allowAccess) {
        cout << "Sala não existe" << endl;
        return;
    }

    cout << "Insira os dados da sala atualizados" << endl;
    cout << "====================================" << endl;
    cout << "Nome: ";
    cin.getline(inputNome,sizeof(inputNome));
    try {
        nome.setValor(string(inputNome));
    }
    catch(invalid_argument &exp){
        cout << "Cada palavra do nome deve começar com letra maiúscula e ter entre 5 e 20 caracteres" << endl;
        return;
    }
    cout << "Capacidade: ";
    cin.getline(inputCapacidade,sizeof(inputCapacidade));
    try{
        capacidade.setValor(string(inputCapacidade));
    }
    catch(invalid_argument &exp){
        cout << "Insira uma capacidade válida como 100, 200 ou 300" << endl;
        return;
    }

    bool found = false;

    for(int i = 0; (unsigned)i < salaVector.size(); i++){
        if(salaVector[i].getCodigo().getValor() == inputCodigo) {
            found = true;
            salaVector[i].setNome(nome);
            salaVector[i].setCapacidade(capacidade);
            cout << "Informações atualizadas com sucesso" << endl;
            break;
        }
    }

   cout << "====================================" << endl;
}

void excluirSala(string inputCodigoSala) {

    //Verifica se a sessão existe
    bool allowAccess = false;

    for (auto sala : salaVector) {
        if(sala.getCodigo().getValor() == inputCodigoSala) allowAccess = true;
    }

    if(!allowAccess) {
        cout << "Sala não existe" << endl;
        return;
    }
    
    bool found = false;

    for(int i = 0; (unsigned)i < salaVector.size(); i++){
        if(salaVector[i].getCodigo().getValor() == inputCodigoSala) {
            found = true;
            salaVector.erase(salaVector.begin() + i);
            cout << "Sala excluída com sucesso" << endl;
            break;
        }
    }

    // Apaga sessoes de salaSessaoAssociation
    for(auto x : salaSessaoAssociation){
        for(int i = 0; i < x.second.size(); i++) {
            if(x.first == inputCodigoSala) {
                excluirSessao(salaSessaoAssociation[x.first][i]);
                salaSessaoAssociation[x.first].erase(salaSessaoAssociation[x.first].begin() + i);
            }
            break;
        }
    }

    if(!found) cout << "Peça não cadastrada" << endl;
}

#endif // SALAS_H_INCLUDED