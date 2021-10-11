#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <list>

using namespace std;

//----------------------------------------------------------------------------------------
// Declara��o de classe container.
//
// Declara��o adota padr�o de projeto Singleton.

class ContainerUsuario{
    private:
        list<Usuario> container;                        // Lista de usu�rios.
        static ContainerUsuario *instancia;             // Ponteiro para inst�ncia da classe.
        ContainerUsuario(){};                           // Construtor.
    public:
        static  ContainerUsuario* getInstancia();       // M�todo para instanciar classe.
        bool incluir(Usuario);                          // M�todos respons�veis por prestar servi�os.
        bool remover(CPF);
        bool pesquisar(Usuario*);
        bool atualizar(Usuario);
};

#endif // CONTROLADORAS_H_INCLUDED
