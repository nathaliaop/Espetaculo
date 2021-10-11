#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"
#include <string>

using namespace std;

//-----------------------------------------------------------------------------------
// Declara��o de classe entidade e implementa��es de m�todos.

class Gerente {
private:
    Matricula matricula;
public:
    void setMatricula(const Matricula &);
    Matricula getMatricula() const;
};

inline void Gerente::setMatricula(const Matricula &matricula){
        this->matricula = matricula;
}

inline Matricula Gerente::getMatricula() const {
        return matricula;
}

#endif // ENTIDADES_H_INCLUDED
