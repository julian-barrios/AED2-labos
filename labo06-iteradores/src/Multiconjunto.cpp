#include "Multiconjunto.hpp"

template<class T>
Multiconjunto<T>::Multiconjunto(): _mult() {}


template<class T>
void Multiconjunto<T>::agregar(T x) {
    _mult.definir(x, ocurrencias(x) + 1);
}

template<class T>
int Multiconjunto<T>::ocurrencias(T x) const {
    return _mult.obtener(x);
}

template<class  T>
bool Multiconjunto<T>::operator<=(Multiconjunto<T> otro) {
    bool incluido = true;
    std::vector<T> cl = _mult.claves();
    for(T elem: cl){
        incluido = incluido && ocurrencias(elem) <= otro.ocurrencias(elem);
    }
    return incluido;
}