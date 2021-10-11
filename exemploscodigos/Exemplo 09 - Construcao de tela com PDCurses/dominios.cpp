#include "dominios.h"

//-------------------------------------------------------------------------------
// Implementa��es de m�todos da classe Matricula.

void Matricula::validar(int valor) {
    if (valor == MATRICULA_INVALIDA)
        throw invalid_argument("Argumento invalido.");
}

void Matricula::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}

//-------------------------------------------------------------------------------
// Implementa��es de m�todos da classe Senha.

void Senha::validar(int valor) {
    if(valor == SENHA_INVALIDA)
        throw invalid_argument("Erro parametro.");
}

void Senha::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}
