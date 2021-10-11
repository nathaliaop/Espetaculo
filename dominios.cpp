#include "utils.h"
#include "dominios.h"
#include <string>

void Codigo::validar(string codigo) {
    //LLDDDD
    StringUtils xx(codigo);
    if(xx.size() != 6)
        throw invalid_argument("Tamanho Invalido!");
    //LL
    StringUtils xxA(codigo.substr(0,2));
    //DDDD
    StringUtils xxB(codigo.substr(2,4));
    if(!xxA.allUpperCase())
        throw invalid_argument("Os dois primeiros caracteres precisam ser letras maiúsculas!");
    if(!xxB.AllDigits())
        throw invalid_argument("Os quatro últimos caracteres precisam ser números!");
}//Feito por -> 180042980
void Codigo::setCodigo(string codigo) {
    validar(codigo);
    this->codigo = codigo;
}//Feito por -> 180042980



void Matricula::validar(string matricula) {
    StringUtils xx(matricula);
    if(xx.size() != 5)
        throw invalid_argument("Tamanho Invalido!");
    if(!xx.AllDigits())
        throw invalid_argument("A matrícula precisa ser composta por dígitos!");
    if(xx.hasRepeatedchar())
        throw invalid_argument("Há caracteres repetidos!");
}//Feito por -> 180116207
void Matricula::setMatricula(string matricula) {
    validar(matricula);
    this->matricula = matricula;
}//Feito por -> 180116207



void Capacidade::validar(int capacidade){
    if(capacidade != 100 && capacidade != 200 && capacidade != 300 &&
       capacidade != 400 && capacidade != 500)
        throw invalid_argument("Argumento Invalido!");
}//Feito por -> 180116207
void Capacidade::setCapacidade(int capacidade){
    validar(capacidade);
    this->capacidade = capacidade;
}//Feito por -> 180116207



void Cargo::validar(string cargo){
    if(cargo !="ator" && cargo !="cenografo" && cargo !="figurinista" &&
       cargo !="maquiador" && cargo !="sonoplasta" && cargo !="iluminador")
        throw invalid_argument("Argumento Invalido!");
}//Feito por -> 180116207
void Cargo::setCargo(string cargo){
    validar(cargo);
    this->cargo = cargo;
}//Feito por -> 180116207



void Classificacao::validar(string classificacao){
    if(classificacao !="livre" && classificacao !="10" && classificacao !="12" &&
       classificacao !="14" && classificacao !="16" && classificacao !="18")
       throw invalid_argument("Argumento Invalido!");
}//Feito por -> 180116207
void Classificacao::setClassificacao(string classificacao){
    validar(classificacao);
    this->classificacao = classificacao;
}//Feito por -> 18011207



void Data::validar(string data){
    DataUtils xx(data);
    if(data.size() != 10)
        throw invalid_argument("Tamanho Invalido!");
    if(!xx.isValid() || !xx.isDataInForm())
        throw invalid_argument("Data Invalida!");
}//Feito por -> 180116207
void Data::setData(string data){
    validar(data);
    this->data = data;
}//Feito por -> 180116207



void Email::validar(string email){
    StringUtils xx (email);
    StringUtils xxA (email.substr(0, xx.sizeBeforeAt()));
    StringUtils xxB (email.substr(xx.sizeBeforeAt() + 1, xx.sizeAfterAt()));
    if(xx.sizeBeforeAt() > 64 || xx.sizeAfterAt() > 255)
        throw invalid_argument("Tamanho Invalido!");
    if (xx.beginWith(".") || xx.endsWith(".") || xx.hasSequenceComma())
        throw invalid_argument("Ponto não pode ocorrer no início, no fim ou em sequência!");
}//Feito por -> 180042980
void Email::setEmail(string email){
    validar(email);
    this->email = email;
}//Feito por -> 180042980



void Horario::validar(string horario){
    StringUtils xx(horario);
    if(xx.size() != 5)
        throw invalid_argument("Tamanho Invalido!");
    //HH
    StringUtils xxH(horario.substr(0,2));
    //MM
    StringUtils xxM(horario.substr(3,2));
    if(horario[2] != ':' || !xxH.allDigit() || !xxM.allDigit())
        throw invalid_argument("Formato Invalido!");

    if(horario[0] > '2' || (horario[0] == '2' && horario[1] > '3'))
        throw invalid_argument("Hora Invalida!");
    if(!xxM.equalsTo("00") && !xxM.equalsTo("15") && !xxM.equalsTo("30") && !xxM.equalsTo("45"))
        throw invalid_argument("Minuto Invalido!");
}//Feito por -> 180116207
void Horario::setHorario(string horario){
    validar(horario);
    this->horario=horario;
}//Feito por -> 180116207



void Nome::validar(string nome){
    StringUtils xx(nome);
    if (xx.size() < 5 || xx.size() > 20)
        throw invalid_argument("Tamanho Invalido!");
    if(!xx.allAlphaSpaceComma() || xx.hasNoLetterb4comma())
        throw invalid_argument("Formato Invalido!");
    if(xx.hasSequencespace())
        throw invalid_argument("Não pode haver sequeência de espaços em branco!");
    if(!xx.isFirstUpperAfterSpace() || !xx.isFirstUpper())
        throw invalid_argument("A primeira letra de cada termo precisa ser maiúscula!");
}//Feito por -> 180042980
void Nome::setNome(string nome){
    validar(nome);
    this->nome = nome;
}//Feito por -> 180042980



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



void Telefone::validar(string telefone){
    StringUtils xx (telefone);
    if(xx.size() != 14)
        throw invalid_argument("Tamanho Invalido!");
    if (telefone[0] != '(' || telefone[3] != ')' || telefone[4] != '-')
      throw invalid_argument("Formato Invalido!");

    StringUtils xxDDD (telefone.substr(1,2));
    StringUtils xxTEL (telefone.substr(5,9));
    if(!xxTEL.allDigit())
       throw invalid_argument("Telefone Invalido!");
    if(xxTEL.equalsTo("000000000"))
       throw invalid_argument("Telefone Invalido!");

    if(!xxDDD.equalsTo("11") && !xxDDD.equalsTo("22") && !xxDDD.equalsTo("24") && !xxDDD.equalsTo("27") && !xxDDD.equalsTo("28") &&
       !xxDDD.equalsTo("32") && !xxDDD.equalsTo("33") && !xxDDD.equalsTo("34") && !xxDDD.equalsTo("35") && !xxDDD.equalsTo("37") && !xxDDD.equalsTo("38") &&
       !xxDDD.equalsTo("41") && !xxDDD.equalsTo("42") && !xxDDD.equalsTo("43") && !xxDDD.equalsTo("44") && !xxDDD.equalsTo("45") && !xxDDD.equalsTo("46") && !xxDDD.equalsTo("47") && !xxDDD.equalsTo("48") && !xxDDD.equalsTo("49") &&
       !xxDDD.equalsTo("51") && !xxDDD.equalsTo("53") && !xxDDD.equalsTo("54") && !xxDDD.equalsTo("55") &&
       !xxDDD.equalsTo("61") && !xxDDD.equalsTo("62") && !xxDDD.equalsTo("63") && !xxDDD.equalsTo("64") && !xxDDD.equalsTo("65") && !xxDDD.equalsTo("66") && !xxDDD.equalsTo("67") && !xxDDD.equalsTo("68") && !xxDDD.equalsTo("69") &&
       !xxDDD.equalsTo("71") && !xxDDD.equalsTo("73") && !xxDDD.equalsTo("74") && !xxDDD.equalsTo("75") && !xxDDD.equalsTo("77") && !xxDDD.equalsTo("79") &&
       !xxDDD.equalsTo("81") && !xxDDD.equalsTo("82") && !xxDDD.equalsTo("83") && !xxDDD.equalsTo("84") && !xxDDD.equalsTo("85") && !xxDDD.equalsTo("86") && !xxDDD.equalsTo("87") && !xxDDD.equalsTo("88") && !xxDDD.equalsTo("89") &&
       !xxDDD.equalsTo("91") && !xxDDD.equalsTo("92") && !xxDDD.equalsTo("93") && !xxDDD.equalsTo("94") && !xxDDD.equalsTo("95") && !xxDDD.equalsTo("96") && !xxDDD.equalsTo("97") && !xxDDD.equalsTo("98") && !xxDDD.equalsTo("99"))
        throw invalid_argument("DDD Invalido!");
}//Feito por -> 180116207
void Telefone::setTelefone(string telefone){
    validar(telefone);
    this->telefone = telefone;
}//Feito por -> 180116207



void Tipo::validar(string tipo){
    if(tipo != "auto" && tipo != "comédia" && tipo != "drama" && tipo != "farsa" &&
       tipo != "melodrama" && tipo != "monólogo" && tipo != "musical" && tipo != "ópera" &&
       tipo != "revista" )
        throw invalid_argument("Argumento Invalido!");
}//Feito por -> 180116207
void Tipo::setTipo(string tipo){
    validar(tipo);
    this->tipo = tipo;
}//Feito por -> 180116207
