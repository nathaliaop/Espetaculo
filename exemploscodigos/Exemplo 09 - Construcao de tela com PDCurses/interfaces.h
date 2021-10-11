#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

// Incluir cabe�alhos.

#include "dominios.h"
#include <stdexcept>

using namespace std;

// Declara��es adiantadas.

class ILNAutenticacao;
class ILNGerente;

// Declara��o de interface da camada de apresenta��o.

class IUAutenticacao {
public:
    virtual bool autenticar() = 0;                                  // M�todo por meio do qual � solicitado servi�o.
    virtual void setCntrLNAutenticacao(ILNAutenticacao *) = 0;      // M�todo para ligar (link) controladora na camada de servi�o.
    virtual ~IUAutenticacao(){}                                     // M�todo destrutor virtual.
};

// Declara��o de interface da camada de servi�o.

class ILNAutenticacao {
public:
    virtual bool autenticar(const Matricula&, const Senha&) = 0;    // M�todo por meio do qual � solicitado servi�o.
    virtual ~ILNAutenticacao(){}                                    // M�todo destrutor virtual.
};

#endif // INTERFACES_H_INCLUDED
