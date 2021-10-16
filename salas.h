#ifndef SALAS_H_INCLUDED
#define SALAS_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

#include "dominios.h"
#include "entidades.h"

using namespace std;

vector<Sala> salaVector = {};

void listarSala() {
    cout << "oi" << endl;
}

void criarSala(string inputMatricula) {
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

void procurarSala(string inputMatricula) {
    cout << "oi" << endl;
}

void editarSala(string inputMatricula) {
    cout << "oi" << endl;
}

void excluirSala(string inputMatricula) {
    cout << "oi" << endl;
}

#endif // SALAS_H_INCLUDED