#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include<stdexcept>

using namespace std;

//------------------------------------------------------------------------
// Declara��o de classe dom�nio e implementa��es de m�todos.

class Dominio {
    private:
        string valor;
    protected:
        virtual void validar(string) = 0;
    public:
        void setValor(string);
        string getValor() const;
};

inline void Dominio::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

inline string Dominio::getValor() const {
    return valor;
}

//------------------------------------------------------------------------
// Declara��o de classe dom�nio.

class CPF:public Dominio {
    private:
        const long unsigned int TAMANHO_MAXIMO = 10;
    protected:
        void validar(string);
};

//------------------------------------------------------------------------
// Declara��o de classe dom�nio.

class Senha:public Dominio {
    private:
        const long unsigned int TAMANHO_MAXIMO = 5;
    protected:
        void validar(string);
};

#endif // DOMINIOS_H_INCLUDED
