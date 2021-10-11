#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

//--------------------------------------------------------------------------------------------
// Declara��es de interfaces.

// Declara��es adiantadas (forward declarations).

class IServicoAutenticacao;
class IServicoPessoal;
class IServicoProdutosFinanceiros;

//--------------------------------------------------------------------------------------------

class IApresentacaoAutenticacao {
    public:
        virtual bool autenticar(CPF*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){}
};

class IApresentacaoPessoal{
    public:
        virtual void executar(CPF) = 0;
        virtual void cadastrar() = 0;
        virtual void setCntrServicoPessoal(IServicoPessoal*) = 0;
        virtual void setCntrServicoProdutosFinanceiros(IServicoProdutosFinanceiros*) = 0;
        virtual ~IApresentacaoPessoal(){}
};

class IApresentacaoProdutosFinanceiros{
    public:
        virtual void executar() = 0;
        virtual void executar(CPF) = 0;
        virtual void setCntrServicoProdutosFinanceiros(IServicoProdutosFinanceiros*) = 0;
        virtual ~IApresentacaoProdutosFinanceiros(){}
};

//--------------------------------------------------------------------------------------------

class IServicoAutenticacao {
    public:
        virtual bool autenticar(CPF, Senha) = 0;
        virtual ~IServicoAutenticacao(){}
};

class IServicoPessoal{
public:
        virtual bool cadastrarUsuario(Usuario) = 0;
        virtual ~IServicoPessoal(){}
};

class IServicoProdutosFinanceiros{
public:
        virtual bool cadastrarConta(Conta) = 0;
        virtual bool consultarConta(Conta*) = 0;
        virtual bool cadastrarProdutoInvestimento(Produto) = 0;
        virtual bool descadastrarProdutoInvestimento(Codigo) = 0;
        virtual bool realizarAplicacao(Aplicacao) = 0;
        virtual bool recuperarAplicacao(Aplicacao*) = 0;
        virtual ~IServicoProdutosFinanceiros(){}
};

#endif // INTERFACES_H_INCLUDED
