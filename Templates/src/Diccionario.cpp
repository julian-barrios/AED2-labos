#include <cassert>
#include "Diccionario.hpp"


template<class Clave, class Valor>

Diccionario<Clave, Valor>::Diccionario(): _asociaciones() {}


template<class Clave, class Valor>
Diccionario<Clave, Valor>::Asociacion::Asociacion(Clave k, Valor v) : clave(k), valor(v) {
}

template<class Clave, class Valor>
void Diccionario<Clave, Valor>::definir(Clave k, Valor v) {
	for (unsigned int i = 0; i < _asociaciones.size(); i++) {
		if (_asociaciones[i].clave == k) {
			_asociaciones[i].valor = v;
			return;
		}
	}
	_asociaciones.push_back(Asociacion(k, v));
}

template<class Clave, class Valor>
bool Diccionario<Clave, Valor>::def(Clave k) const {
	for (unsigned int i = 0; i < _asociaciones.size(); i++) {
		if (_asociaciones[i].clave == k) {
			return true;
		}
	}
	return false;
}

template<class Clave, class Valor>
Valor Diccionario<Clave, Valor>::obtener(Clave k) const {
	for (unsigned int i = 0; i < _asociaciones.size(); i++) {
		if (_asociaciones[i].clave == k) {
			return _asociaciones[i].valor;
		}
	}
//	assert(false);
}

template <class Clave>
int minimo(std::vector<Clave> v){
    int min = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] < v[min]){
            min = i;
        }
    }
    return min;
}

template <class Clave>
std::vector<Clave> swap(std::vector<Clave> v, int a, int b){
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;
    return v;
}


template<class Clave, class  Valor>
std::vector<Clave> Diccionario<Clave, Valor>::claves() {
    std::vector<Clave> desordenado;
    std::vector<Clave> ordenado;
    for(int i = 0; i < _asociaciones.size(); i++){
        desordenado.push_back(_asociaciones[i].clave);
    }
    int tamano = desordenado.size();
    for(int i = 0; i < tamano; i++){
        int min = minimo(desordenado);
        ordenado.push_back(desordenado[min]);
        desordenado = swap(desordenado, min, desordenado.size()-1);
        desordenado.pop_back();
    }
    return ordenado;
}