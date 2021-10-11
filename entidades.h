#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"

#include <string>

using namespace std;

class Participante {
    private:
        Matricula matricula;
        Nome nome;
        Nome sobrenome;
        Email email;
        Telefone telefone;
        Senha senha;
        Cargo cargo;
    public:
        void setMatricula(const Matricula&);
        Matricula getMatricula() const;
        void setNome(const Nome&);
        Nome getNome() const;
        void setSobrenome(const Nome&);
        Nome getSobrenome() const;
        void setEmail(const Email&);
        Email getEmail() const;
        void setTelefone(const Telefone&);
        Telefone getTelefone() const;
        void setSenha(const Senha&);
        Senha getSenha() const;
        void setCargo(const Cargo&);
        Cargo getCargo() const;
}; //Feito por -> 180042980

void Participante::setMatricula(const Matricula &matricula){
    this->matricula = matricula;
}

Matricula Participante::getMatricula() const {
    return matricula;
}


class Peca {
    private:
        Codigo codigo;
        Nome nome;
        Tipo tipo;
        Classificacao classificacao;
    public:
        void setCodigo(const Codigo&);
        Codigo getCodigo() const;
        void setNome(const Nome&);
        Nome getNome() const;
        void setTipo(const Tipo&);
        Tipo getTipo() const;
        void setClassificacao(const Classificacao&);
        Classificacao getClassificacao() const;
}; //Feito por -> 180042980

class Sessao {
    private:
        Codigo codigo;
        Data data;
        Horario horario;
    public:
        void setCodigo(const Codigo&);
        Codigo getCodigo() const;
        void setData(const Data&);
        Data getData() const;
        void setHorario(const Horario&);
        Horario getHorario() const;
}; //Feito por -> 180042980

class Sala {
    private:
        Codigo codigo;
        Nome nome;
        Capacidade capacidade;
    public:
        void setCodigo(const Codigo&);
        Codigo getCodigo() const;
        void setNome(const Nome&);
        Nome getNome() const;
        void setCapacidade(const Capacidade&);
        Capacidade getCapacidade() const;
}; //Feito por -> 180042980

#endif // ENTIDADES_H_INCLUDED
