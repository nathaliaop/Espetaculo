#ifndef SERVICOS_H_INCLUDED
#define SERVICOS_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

#include "dominios.h"
#include "entidades.h"

using namespace std;

vector<Participante> participanteVector;
vector<Sessao> sessaoVector;
vector<Peca> pecaVector;
vector<Sala> salaVector;
map<string, vector<string>> participantePecaAssociation;
map<string, vector<string>> cadastroParticipantePeca;
map<string, vector<string>> pecaSessaoAssociation;
map<string, vector<string>> salaSessaoAssociation;

bool pecaExiste(string inputCodigoPeca) {
    //Verifica se a peça existe
    for (auto peca : pecaVector) {
        if(peca.getCodigo().getValor() == inputCodigoPeca) return true;
    }

    return false;
}

bool salaExiste(string inputCodigoSala) {
    //Verifica se a peça existe
    for (auto sala : salaVector) {
        if(sala.getCodigo().getValor() == inputCodigoSala) return true;
    }

    return false;
}

bool sessaoExiste(string inputCodigoSala) {
    //Verifica se a sessõa existe
    for (auto sessao : sessaoVector) {
        if(sessao.getCodigo().getValor() == inputCodigoSala) return true;
    }

    return false;
}

bool usuarioCadastrado(string inputCodigoPeca, string inputMatricula) {
    // Verifica se usuário já está cadastrado na peça
    for (auto participante : cadastroParticipantePeca[inputCodigoPeca]) {
        if(participante == inputMatricula) return true;
    }
    return false;
}

bool pecaLotadaParticipantes(string inputCodigoPeca) {
    if(cadastroParticipantePeca[inputCodigoPeca].size() == 10) return true;
    return false;
}

bool pecaLotadaSessoes(string inputCodigoPeca) {
    // Verifica se a peça não atingiu o limite de sessões
    if(pecaSessaoAssociation[inputCodigoPeca].size() == 5) return true;
    return false;
}

bool matriculaCadastrada(string inputMatricula) {
    // Verifica se a matrícula já foi cadastrada
    for(int i = 0; (unsigned)i < participanteVector.size(); i++){
        if(participanteVector[i].getMatricula().getValor() == inputMatricula) return true;
    }
}

bool pecaCadastrada(string inputCodigoPeca) {
    // Verifica se o código da peça já foi cadastrado
    for(int i = 0; (unsigned)i < pecaVector.size(); i++){
        if(pecaVector[i].getCodigo().getValor() == inputCodigoPeca) return true;
    }
    return false;
}

bool salaCadastrada(string inputCodigoSala) {
    // Verifica se o código da sala já foi cadastrado
    for(int i = 0; (unsigned)i < salaVector.size(); i++){
        if(salaVector[i].getCodigo().getValor() == inputCodigoSala) return true;
    }
    return false;
}

bool sessaoCadastrada(string inputCodigoSessao) {
    // Verifica se o código da sessão já foi cadastrado
    for(int i = 0; (unsigned)i < sessaoVector.size(); i++){
        if(sessaoVector[i].getCodigo().getValor() == inputCodigoSessao) return true;
    }
    return false;
}


#endif // SERVICOS_H_INCLUDED