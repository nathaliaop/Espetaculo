#include "dominios.h"

// ----------------------------------------------------------------------
// Implementa��es de m�todos de classe dom�nio.

void Matricula::validar(int valor) {
    if(valor == MATRICULA_INVALIDA)
        throw invalid_argument("Erro parametro.");
}

void Matricula::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}

// ----------------------------------------------------------------------
// Implementa��es de m�todos de classe dom�nio.

void Senha::validar(int valor) {
    if(valor == SENHA_INVALIDA)
        throw invalid_argument("Erro parametro.");
}

void Senha::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}
