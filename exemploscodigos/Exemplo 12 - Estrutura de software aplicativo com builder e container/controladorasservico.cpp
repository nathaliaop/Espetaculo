#include "controladorasservico.h"

//--------------------------------------------------------------------------------------------
// Implementa��es de m�todos de classes controladoras da camada de servi�o.

bool CntrServicoAutenticacao::autenticar(CPF cpf, Senha senha){

    // ---------------------------------------------------------------------------------------
    // Instanciar container de usu�rios.
    // ---------------------------------------------------------------------------------------

    // ---------------------------------------------------------------------------------------
    // Recuperar e comparar senha de usu�rio.
    // ---------------------------------------------------------------------------------------

    // ---------------------------------------------------------------------------------------
    // Retornar resultado.
    // ---------------------------------------------------------------------------------------

    return true;
}

//--------------------------------------------------------------------------------------------

bool CntrServicoPessoal::cadastrarUsuario(Usuario usuario){

    // Instancia container de usu�rios.

    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    // Solicitar cadastramento de usu�rio e retornar resultado da solicita��o de servi�o.

    return container->incluir(usuario);
}

//--------------------------------------------------------------------------------------------



