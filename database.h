#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

#include <fstream>
#include <vector>
#include <iostream> // teste

#include "entidades.h"

using namespace std;

class Database {
    //private:

    public:
        void limparArquivo(string path);
        void armazenarArquivo(Participante participante);
        vector<Participante, vector<Peca, vector<Sessao, vector<Sala>>>> carregarArquivo();
};

inline void Database::limparArquivo(string path) {
    ofstream File(path);
    File << "";
    File.close();
}

inline void armazenarArquivo(Participante participante) {
    ofstream File("database.txt", ios::app); // append mode
    File << participante.getMatricula().getValor() << ';' 
        << participante.getNome().getValor() << ';'
        << participante.getSobrenome().getValor() << ';'
        << participante.getEmail().getValor() << ';'
        << participante.getTelefone().getValor() << ';'
        << participante.getSenha().getValor() << ';'
        << participante.getCargo().getValor() << ';'
        << '\n';

    // File << n; // numero de pecas
    
    File.close();
}

// vector<Participante, vector<Peca, vector<Sessao, vector<Sala>>>> ans;

inline vector<Participante, vector<Peca, vector<Sessao, vector<Sala>>>> carregarArquivo() {
    ifstream ReadFile("database.txt");
    string participanteTxt;

    while (getline(ReadFile, participanteTxt)) {
        cout << participanteTxt << endl;
    }
    
    vector<Participante, vector<Peca, vector<Sessao, vector<Sala>>>> v;
    return v;
}

#endif // DATABASE_H_INCLUDED