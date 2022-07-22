#ifndef SOLUCION_MULTICONJUNTO_HPP
#define SOLUCION_MULTICONJUNTO_HPP
#include "Diccionario.cpp"

template<class T>

class Multiconjunto {
public:
    Multiconjunto();
    void agregar(T x);
    int ocurrencias(T x) const;
    bool operator<=(Multiconjunto<T> otro);

private:
    Diccionario<T, int> _mult;
};


#endif
