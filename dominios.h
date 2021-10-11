#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

#include "utils.h"

using namespace std;

class Capacidade {
    private:
        int capacidade;
        void validar(int);
    public:
        void setCapacidade(int capacidade);
        int getCapacidade();
};//Feito por -> 180116207
inline int Capacidade::getCapacidade() {
    return capacidade;
}//Feito por -> 180116207


class Cargo{
    private:
        string cargo;
        void validar(string);
    public:
        void setCargo(string cargo);
        string getCargo();
};//Feito por -> 180116207
inline string Cargo::getCargo(){
    return cargo;
}//Feito por -> 180116207


class Classificacao{
    private:
        string classificacao;
		void validar(string);
    public:
        void setClassificacao(string classificacao);
        string getClassificacao();
};//Feito por -> 180116207
inline string Classificacao::getClassificacao(){
    return classificacao;
}//Feito por -> 180116207


class Codigo {
    private:
        string codigo;
        void validar(string);
    public:
        void setCodigo(string codigo);
        string getCodigo();
};//Feito por -> 180116207
inline string Codigo::getCodigo() {
    return codigo;
}//Feito por -> 180116207


class Data{
    private:
        string data;
        void validar(string);
    public:
        void setData(string data);
        string getData();
};//Feito por -> 180116207
inline string Data::getData(){
    return data;
}//Feito por -> 180116207


class Email {
private:
    string email;
    void validar(string);
public:
    void setEmail(string email);
    string getEmail();
};//Feito por -> 180116207
inline string Email::getEmail(){
    return email;
}//Feito por -> 180116207

class Horario{
    private:
        string horario;
        void validar(string);
    public:
        void setHorario(string horario);
        string getHorario();
};//Feito por -> 180116207
inline string Horario::getHorario(){
    return horario;
}//Feito por -> 180116207


class Nome {
private:
    string nome;
    void validar(string);
public:
    void setNome(string nome);
    string getNome();
};//Feito por -> 180116207
inline string Nome::getNome(){
    return nome;
}//Feito por -> 180116207

class Matricula {
private:
    string matricula;
    void validar(string);
public:
    void setMatricula(string matricula);
    string getMatricula();
};//Feito por -> 180116207
inline string Matricula::getMatricula(){
    return matricula;
}//Feito por -> 180116207
void Matricula::validar(string matricula) {
    StringUtils xx(matricula);
    if(xx.size() != 5)
        throw invalid_argument("Tamanho Invalido!");
    if(!xx.AllDigits())
        throw invalid_argument("A matrícula precisa ser composta por dígitos!");
    if(xx.hasRepeatedchar())
        throw invalid_argument("Há caracteres repetidos!");
}
inline void Matricula::setMatricula(string matricula){
        validar(matricula);
    this -> matricula = matricula;
}//Feito por -> 180116207


class Senha {
    private:
        string senha;
        void validar(string);
    public:
        void setSenha(string senha);
        string getSenha();
};//Feito por -> 180116207
inline string Senha::getSenha() {
    return senha;
}
void Senha::validar(string senha){
    StringUtils xx(senha);
    if (xx.size() != 8)
        throw invalid_argument("Tamanho Invalido!");
    if(!xx.allAlphaDigitSpecial())
        throw invalid_argument("Formato Invalido!");
    if(!xx.hasAlpha() || !xx.hasDigit() || !xx.hasSpecial())
        throw invalid_argument("A senha precisa conter letra, número e caractere especial!");
    if(xx.hasRepeatedchar())
        throw invalid_argument("Não pode haver caractere repetido!");
}//Feito por -> 180042980
void Senha::setSenha(string senha){
    validar(senha);
    this->senha = senha;
}//Feito por -> 180042980


class Telefone {
    private:
        string telefone;
        void validar(string);
    public:
        void setTelefone(string telefone);
        string getTelefone();
};//Feito por -> 180116207
inline string Telefone::getTelefone() {
    return telefone;
}//Feito por -> 180116207


class Tipo {
    private:
        string tipo;
		void validar(string);
    public:
        void setTipo(string tipo);
        string getTipo();
};//Feito por -> 180116207
inline string Tipo::getTipo() {
    return tipo;
}//Feito por -> 180116207


#endif // DOMINIOS_H_INCLUDED
