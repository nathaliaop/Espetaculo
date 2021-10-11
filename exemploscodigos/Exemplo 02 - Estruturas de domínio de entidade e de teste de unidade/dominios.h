#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;

/* -----------------------------------------------------------------------
// Estrutura de código para declaração de classe domínio.
// Substituir Dominio por nome da classe.
// Substituir Tipo.

class Dominio {
    private:
        Tipo valor;                      // Atributo para armazenar valor.
        void validar(Tipo);              // Método para validar valor.
    public:
        void setValor(Tipo);             // Método para atribuir valor.
        Tipo getValor() const;           // Método para recuperar valor.
};

inline Tipo Dominio::getValor() const{
    return valor;
}

----------------------------------------------------------------------- */

// -----------------------------------------------------------------------
// Exemplo de declaração de classe domínio e implementação de método.

class Codigo {
private:
        static const int LIMITE = 25;       // Declaração para evitar números mágicos.
        int valor;
        void validar(int);
public:
        void setValor(int);
        int getValor() const;
};

inline int Codigo::getValor() const{
    return valor;
}

// -----------------------------------------------------------------------
// Exemplo de declaração de classe domínio e implementação de método.

class Prioridade {
    private:
        static const int INVALIDO = 0;      // Declaração para evitar números mágicos.
        int valor;
        void validar(int);
    public:
        void setValor(int);
        int getValor() const;
};

inline int Prioridade::getValor() const{
    return valor;
}

#endif // DOMINIOS_H_INCLUDED
