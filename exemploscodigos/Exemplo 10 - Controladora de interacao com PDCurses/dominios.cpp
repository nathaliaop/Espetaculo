#include "dominios.h"

//---------------------------------------------------------------------------
// Implementa��es de m�todos.

void CPF::validar(string valor){
    if(valor.length() > TAMANHO_MAXIMO)
        throw invalid_argument("Valor invalido");
}

void Senha::validar(string valor){
    if(valor.length() > TAMANHO_MAXIMO)
        throw invalid_argument("Valor invalido");
}
