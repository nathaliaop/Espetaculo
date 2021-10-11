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

void Participante::setNome(const Nome &nome){
    this->nome = nome;
}

Nome Participante::getNome() const {
    return nome;
}

void Participante::setSobrenome(const Nome &sobrenome){
    this->sobrenome = sobrenome;
}

Nome Participante::getSobrenome()const {
    return sobrenome;
}

void Participante::setEmail(const Email &email){
    this->email = email;
}

Email Participante::getEmail() const {
    return email;
}

void Participante::setTelefone(const Telefone &telefone){
    this->telefone = telefone;
}

Telefone Participante::getTelefone() const {
    return telefone;
}

void Participante::setSenha(const Senha &senha){
    this->senha = senha;
}

Senha Participante::getSenha() const {
    return senha;
}

void Participante::setCargo(const Cargo &cargo){
    this->cargo = cargo;
}

Cargo Participante::getCargo() const {
    return cargo;
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

void Peca::setCodigo(const Codigo &codigo){
    this->codigo = codigo;
}

Codigo Peca::getCodigo() const {
    return codigo;
}

void Peca::setNome(const Nome &nome){
    this->nome = nome;
}

Nome Peca::getNome() const {
    return nome;
}

void Peca::setTipo(const Tipo &tipo){
    this->tipo = tipo;
}

Tipo Peca::getTipo() const {
    return tipo;
}

void Peca::setClassificacao(const Classificacao &classificacao){
    this->classificacao = classificacao;
}

Classificacao Peca::getClassificacao() const {
    return classificacao;
}

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

void Sessao::setCodigo(const Codigo &codigo){
    this->codigo = codigo;
}

Codigo Sessao::getCodigo() const {
    return codigo;
}

void Sessao::setData(const Data &data){
    this->data = data;
}

Data Sessao::getData() const {
    return data;
}

void Sessao::setHorario(const Horario &horario){
    this->horario = horario;
}

Horario Sessao::getHorario() const {
    return horario;
}

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

void Sala::setCodigo(const Codigo &codigo){
    this->codigo = codigo;
}

Codigo Sala::getCodigo() const {
    return codigo;
}

void Sala::setNome(const Nome &nome){
    this->nome = nome;
}

Nome Sala::getNome() const {
    return nome;
}

void Sala::setCapacidade(const Capacidade &capacidade){
    this->capacidade = capacidade;
}

Capacidade Sala::getCapacidade() const {
    return capacidade;
}


#endif // ENTIDADES_H_INCLUDED
