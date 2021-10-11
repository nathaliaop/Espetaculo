#include <string.h>
#include <stdexcept>
#include <iostream>

#include "curses.h"
#include "dominios.h"
#include "interfaces.h"
#include "controladorasapresentacao.h"
#include "stubs.h"

using namespace std;

int main()
{
    // Instanciar controladoras de apresenta��o.

    CntrApresentacaoControle *cntrApresentacaoControle;
    IApresentacaoAutenticacao *cntrApresentacaoAutenticacao;
    IApresentacaoPessoal *cntrApresentacaoPessoal;
    IApresentacaoProdutosFinanceiros *cntrApresentacaoProdutosFinanceiros;

    cntrApresentacaoControle = new CntrApresentacaoControle();
    cntrApresentacaoAutenticacao = new CntrApresentacaoAutenticacao();
    cntrApresentacaoPessoal = new CntrApresentacaoPessoal();
    cntrApresentacaoProdutosFinanceiros = new CntrApresentacaoProdutosFinanceiros();

    // Instanciar stubs de servi�o.

    IServicoAutenticacao *stubServicoAutenticacao;
    IServicoPessoal *stubServicoPessoal;
    IServicoProdutosFinanceiros *stubServicoProdutosFinanceiros;

    stubServicoAutenticacao = new StubServicoAutenticacao();
    stubServicoPessoal = new StubServicoPessoal();
    stubServicoProdutosFinanceiros = new StubServicoProdutosFinanceiros();

    // Interligar controladoras e stubs.

    cntrApresentacaoControle->setCntrApresentacaoAutenticacao(cntrApresentacaoAutenticacao);
    cntrApresentacaoControle->setCntrApresentacaoPessoal(cntrApresentacaoPessoal);
    cntrApresentacaoControle->setCntrApresentacaoProdutosFinanceiros(cntrApresentacaoProdutosFinanceiros);

    cntrApresentacaoAutenticacao->setCntrServicoAutenticacao(stubServicoAutenticacao);

    cntrApresentacaoPessoal->setCntrServicoPessoal(stubServicoPessoal);
    cntrApresentacaoPessoal->setCntrServicoProdutosFinanceiros(stubServicoProdutosFinanceiros);

    cntrApresentacaoProdutosFinanceiros->setCntrServicoProdutosFinanceiros(stubServicoProdutosFinanceiros);

    initscr();                                                                      // Iniciar curses.
    cntrApresentacaoControle->executar();                                           // Solicitar servi�o apresentacao.
    endwin();                                                                       // Finalizar curses.

    return 0;
}

