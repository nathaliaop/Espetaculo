#include "dominios.h"

// --------------------------------------------------------------------------
// Implementa��es de m�todos de classe dom�nio.

void Codigo::validar(int codigo){
    if (codigo > LIMITE)
        throw invalid_argument("Argumento invalido.");
}

void Codigo::setValor(int valor){
    validar(valor);
    this->valor = valor;
}

// --------------------------------------------------------------------------
// Implementa��es de m�todos de classe dom�nio.

void Prioridade::validar(int valor){
    if (valor == INVALIDO)
        throw invalid_argument("Argumento invalido.");
}

void Prioridade::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}
