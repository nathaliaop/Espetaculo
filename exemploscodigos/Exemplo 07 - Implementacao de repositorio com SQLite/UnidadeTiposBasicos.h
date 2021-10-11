//---------------------------------------------------------------------------

#ifndef UnidadeTiposBasicosH
#define UnidadeTiposBasicosH
//---------------------------------------------------------------------------

#include <string>
#include <stdexcept>

using namespace std;

//---------------------------------------------------------------------------
// Declara��o da classe TipoBasico.

class TipoBasico {
       virtual void validar(string) = 0;
protected:
       string valor;
public:
       TipoBasico(){}
       void setValor(const string&);
       string getValor() const;
};

//---------------------------------------------------------------------------
// Declara��o da classe Matricula.

class Matricula:public TipoBasico {
private:
        void validar(string);
public:
        Matricula(){}
        Matricula(string);
};

//---------------------------------------------------------------------------
// Declara��o da classe Senha.

class Senha:public TipoBasico {
private:
        void validar(string);
public:
        Senha () {}
        Senha(string);
};

//---------------------------------------------------------------------------
// Declara��o da classe Nome.

class Nome:public TipoBasico {
private:
        void validar(string);
public:
        Nome() {}
        Nome(string);
};

//---------------------------------------------------------------------------
// Declara��o da classe Telefone.

class Telefone:public TipoBasico {
private:
        void validar(string);
public:
        Telefone() {}
        Telefone(string);
};

//---------------------------------------------------------------------------
//Classe Declara��o da classe CodigoDisciplina.

class CodigoDisciplina:public TipoBasico {
private:
        void validar(string);
public:
        CodigoDisciplina () {}
        CodigoDisciplina(string);
};

//---------------------------------------------------------------------------
// Implementa��es de m�todos.

inline void TipoBasico::setValor(const string& valor) {
        validar(valor);
        this->valor = valor;
}

inline string TipoBasico::getValor() const {
       return valor;
}

#endif
