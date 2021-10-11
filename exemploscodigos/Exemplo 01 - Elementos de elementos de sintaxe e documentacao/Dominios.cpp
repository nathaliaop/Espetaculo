#include "Dominios.h"

//---------------------------------------------------------------------
// Inicializacao de atributo estatico.

int CodigoProduto::quantidade = 0;

//---------------------------------------------------------------------
// Definicoes de constantes.

const float Conta::SALDO_INICIAL            = 0;
const float ContaEspecial::LIMITE           = -1000.0;
const float ContaCorrenteEspecial::LIMITE   = -1000.0;
const float ContaClienteEspecial::LIMITE    = -1000.0;

//-----------------------------------------------------------------------
// Implementa��es de m�todos de classe dom�nio sem lan�amento de exce��o.

// M�todos construtores.

CodigoCliente::CodigoCliente(){
    valor = DEFAULT;
}

CodigoCliente::CodigoCliente(int valor){
    if(validar(valor))
        this->valor = valor;
    else
        this->valor = DEFAULT;
}

// M�todo para valida��o sem lan�amento de exce��o.

bool CodigoCliente::validar(int valor){
    if (valor > LIMITE)
        return false;
    return true;
}

// M�todo para acesso a atributo.

bool CodigoCliente::setValor(int valor) {
    if (!validar(valor))
        return false;
    this->valor = valor;
    return true;
}

//-----------------------------------------------------------------------
// Implementa��es de m�todos de classe dom�nio com lan�amento de exce��o.

// M�todo construtor.

CodigoProduto::CodigoProduto(int valor){
    validar(valor);
    this->valor = valor;
    quantidade++;
}

// M�todo para valida��o com lan�amento de exce��o.

void CodigoProduto::validar(int valor){
    if (valor > LIMITE)
        throw invalid_argument("Argumento invalido.");
}

// M�todo para acesso a atributo.

void CodigoProduto::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}

//-----------------------------------------------------------------------

// M�todo para valida��o com lan�amento de exce��o.

void CodigoServico::validar(int valor){
    if (valor > LIMITE)
        throw invalid_argument("Argumento invalido.");
}

// M�todo para acesso a atributo.

void CodigoServico::setValor(int valor) {
    validar(valor);
    this->valor = valor;
}

//---------------------------------------------------------------------
// Implementa��es de metodos.

Conta::Conta(){
    saldo = SALDO_INICIAL;
}

bool ContaConvencional::sacar(float valor){
    if (saldo < valor)
        return false;
    saldo -= valor;
    return true;
}

bool ContaEspecial::sacar(float valor){
    if ((saldo - valor) < LIMITE)
        return false;
    saldo -= valor;
    return true;
}

//---------------------------------------------------------------------
// Implementa��es de metodos.

bool ContaCorrente::sacar(float valor){
    if (saldo < valor)
        return false;
    saldo -= valor;
    return true;
}

bool ContaCorrenteEspecial::sacar(float valor){
    if ((saldo - valor) < LIMITE)
        return false;
    saldo -= valor;
    return true;
}

//---------------------------------------------------------------------
// Implementa��es de metodos.

bool ContaCliente::sacar(float valor){
    if (saldo < valor)
        return false;
    saldo -= valor;
    return true;
}

bool ContaClienteEspecial::sacar(float valor){
    if ((saldo - valor) < LIMITE)
        return false;
    saldo -= valor;
    return true;
}

bool ControladoraTransacao::transferir(ContaCliente *origem, ContaCliente *destino, float valor){
    if (!origem->sacar(valor))
        return false;
    destino->depositar(valor);
    return true;
}
