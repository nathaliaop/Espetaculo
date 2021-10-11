#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"

//--------------------------------------------------------------------------------------------
// Declara��es de classes controladoras de servi�o.

class CntrServicoAutenticacao:public IServicoAutenticacao{
    public:
        virtual bool autenticar(CPF, Senha);
};

//--------------------------------------------------------------------------------------------

class CntrServicoPessoal:public IServicoPessoal{
};

//--------------------------------------------------------------------------------------------

class CntrServicoProdutosFinanceiros:public IServicoProdutosFinanceiros{
};

#endif // CONTROLADORASSERVICO_H_INCLUDED
