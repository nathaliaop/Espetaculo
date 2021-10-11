#include "entidades.h"

//Participante
//Feito por -> 180042980

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
//Pe�a - codigo, nome, tipo, classificacao
//Feito por -> 180042980
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

//Sess�o - codigo, data, horario
//Feito por -> 180042980
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

//Sala - codigo, nome, capacidade
//Feito por -> 180042980
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
