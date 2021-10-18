#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include <fstream>
#include <vector>
#include <iostream> // teste

#include "entidades.h"

using namespace std;

class Database {
    public:
        void limparArquivo(string path);
        void armazenarBancoDeDados();
        void carregarBancoDeDados();
        vector<Participante, vector<Peca, vector<Sessao, vector<Sala>>>> carregarArquivo();
};

inline void Database::limparArquivo(string path) {
    ofstream File(path);
    File << "";
    File.close();
}

inline void Database::armazenarBancoDeDados() {
    // participantes
    ofstream FileParticipante("database_participante.txt"); // FileParticipante("database.txt", ios::app) append mode

    // participantes
    for (Participante participante : participanteVector) {
        string matricula = participante.getMatricula().getValor();

        FileParticipante << participanteToString(matricula) << '\n';
        
        // pecas
        FileParticipante << participantePecaAssociation[matricula].size() << '\n';
        for (string codigoPeca : participantePecaAssociation[matricula]) {
            FileParticipante << pecaToString(codigoPeca) << '\n';
            /* se pá não precisa disso
            // sessoes
            FileParticipante << pecaSessaoAssociation[codigoPeca].size() << '\n';
            for (string codigoSessao : pecaSessaoAssociation[codigoPeca]) {
                FileParticipante << sessaoToString(codigoSessao) << '\n';
            }
            */
        }
    }

    FileParticipante.close();

    // pecas
    ofstream FilePeca("database_peca.txt");

    for (Peca peca : pecaVector) {
        string codigoPeca = peca.getCodigo().getValor();
        FilePeca << pecaToString(peca.getCodigo().getValor()) << '\n';

        FilePeca << pecaSessaoAssociation[codigoPeca].size() << '\n';
        for (string codigoSessao : pecaSessaoAssociation[codigoPeca]) {
            FilePeca << sessaoToString(codigoSessao) << '\n';
        }
    }

    FilePeca.close();

    // salas
    ofstream FileSala("database_sala.txt");

    for (Sala sala : salaVector) {
        string codigoSala = sala.getCodigo().getValor();

        FileSala << salaToString(codigoSala) << '\n';

        FileSala << salaSessaoAssociation[codigoSala].size() << '\n';
        for (string codigoSessao : salaSessaoAssociation[codigoSala]) {
            FileSala << sessaoToString(codigoSessao) << '\n';
        }
    }

    FileSala.close();

    // sessoes
    ofstream FileSessao("database_sessao.txt");

    for (Sessao sessao : sessaoVector) {
        FileSessao << sessaoToString(sessao.getCodigo().getValor()) << '\n';
    }

    FileSessao.close();

    // cadastroParticipantePeca
    // participantes cadastrados na peça com a key codigoPeca
    ofstream FileParticipantePeca("database_participantePeca.txt");

    for (Peca peca : pecaVector) {
        string codigoPeca = peca.getCodigo().getValor();

        FileParticipantePeca << codigoPeca << '\n';

        FileParticipantePeca << cadastroParticipantePeca[codigoPeca].size() << '\n';
        for (string matriculaParticipante : cadastroParticipantePeca[codigoPeca]) {
            FileParticipantePeca << matriculaParticipante << '\n';
        }
    }

    FileParticipantePeca.close();
}

inline void Database::carregarBancoDeDados() {
    // participantes
    ifstream ReadFileParticipante("database_participante.txt");

    string linhaParticipante;
    while (getline(ReadFileParticipante, linhaParticipante)) {
        Participante participante = stringToParticipante(linhaParticipante);
        participanteVector.push_back(participante);

        string linhaQntPecas;
        getline(ReadFileParticipante, linhaQntPecas);

        int qntPecas = stoi(linhaQntPecas);
        for (int i = 0; i < qntPecas; i++) {
            string linhaPeca;
            getline(ReadFileParticipante, linhaPeca);

            Peca peca = stringToPeca(linhaPeca);

            // cria a relação
            participantePecaAssociation[participante.getMatricula().getValor()].push_back(peca.getCodigo().getValor());
        }
    }
    
    ReadFileParticipante.close();

    // pecas
    ifstream ReadFilePeca("database_peca.txt");

    string linhaPeca;
    while (getline(ReadFilePeca, linhaPeca)) {
        Peca peca = stringToPeca(linhaPeca);
        pecaVector.push_back(peca);

        string linhaQntSessoes;
        getline(ReadFilePeca, linhaQntSessoes);

        int qntSessoes = stoi(linhaQntSessoes);
        for (int i = 0; i < qntSessoes; i++) {
            string linhaSessao;
            getline(ReadFilePeca, linhaSessao);
            
            Sessao sessao = stringToSessao(linhaSessao);

            // cria a relação
            pecaSessaoAssociation[peca.getCodigo().getValor()].push_back(sessao.getCodigo().getValor());
        }
    }

    ReadFilePeca.close();

    // salas
    ifstream ReadFileSala("database_sala.txt");

    string linhaSala;
    while (getline(ReadFileSala, linhaSala)) {
        Sala sala = stringToSala(linhaSala);
        salaVector.push_back(sala);

        string linhaQntSessoes;
        getline(ReadFileSala, linhaQntSessoes);

        int qntSessoes = stoi(linhaQntSessoes);
        for (int i = 0; i < qntSessoes; i++) {
            string linhaSessao;
            getline(ReadFileSala, linhaSessao);
            
            Sessao sessao = stringToSessao(linhaSessao);

            // cria a relação
            salaSessaoAssociation[sala.getCodigo().getValor()].push_back(sessao.getCodigo().getValor());
        }
    }

    ReadFileSala.close();

    // sessoes
    ifstream ReadFileSessao("database_sessao.txt");

    string linhaSessao;
    while (getline(ReadFileSessao, linhaSessao)) {
        Sessao sessao = stringToSessao(linhaSessao);

        sessaoVector.push_back(sessao);
    }

    ReadFileSessao.close();

    // cadastroParticipantePeca
    ifstream ReadFileParticipantePeca("database_participantePeca.txt");

    string linhaParticipantePeca;
    while (getline(ReadFileParticipantePeca, linhaParticipantePeca)) {
        Peca peca = stringToPeca(linhaParticipantePeca);

        string linhaQntParticipantes;
        getline(ReadFileParticipantePeca, linhaQntParticipantes);

        int qntParticipantes = stoi(linhaQntParticipantes);
        for (int i = 0; i < qntParticipantes; i++) {
            string linhaParticipante;
            getline(ReadFileParticipantePeca, linhaParticipante);
            
            Participante participante = stringToParticipante(linhaParticipante);

            cadastroParticipantePeca[peca.getCodigo().getValor()].push_back(participante.getMatricula().getValor());
        }
    }

    ReadFileParticipantePeca.close();
}

#endif // DATABASE_H_INCLUDED