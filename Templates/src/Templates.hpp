#ifndef SOLUCION_TEMPLATES_HPP
#define SOLUCION_TEMPLATES_HPP

template <class T>

T cuadrado(T x) {
    return x * x;
}

template<class Contenedor, class Elem>

bool contiene(Contenedor s, Elem e){
    int i;
    for(i = 0; i < s.size() && s[i] != e; i++){
    }
    return i < s.size();
}

template<class Contenedor>

bool esPrefijo(Contenedor a, Contenedor b){
    bool prefijo = a.size() < b.size();
    for(int i = 0; i < a.size() && prefijo; i++){
        prefijo = a[i] == b[i];
    }
    return prefijo;
}

template<class Contenedor, class Elem>

Elem maximo(Contenedor c){
    Elem maximo = c[0];
    for(int i = 0; i < c.size(); i++){
        if (c[i] > maximo){
            maximo = c[i];
        }
    }
    return maximo;
}



#endif
