#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include "dominios.h"
#include <string.h>
#include <stdlib.h>
#include "curses.h"

class TelaAutenticacao {
public:
    void apresentar(Matricula *, Senha*);       // M�todo por meio do qual � solicitada a apresenta��o da tela.
};

class TelaMensagem {
public:
    void apresentar(string);                    // M�todo por meio do qual � solicitada a apresenta��o da tela.
};


#endif // COMANDOS_H_INCLUDED

