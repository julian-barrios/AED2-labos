#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>


// Ejercicio 1 y 8

template<class Contenedor>
typename Contenedor::value_type minimo (const Contenedor &c){
    typename Contenedor::const_iterator min = c.begin();
    for(typename Contenedor::const_iterator it = c.begin(); it != c.end(); ++it){
        if(*it < *min){
            min = it;
        }
    }
    return *min;
}

// Ejercicio 2

template<class Contenedor>
typename Contenedor::value_type promedio (const Contenedor &c){
    auto suma = 0.0;
    auto total = 0.0;
    for(typename Contenedor::const_iterator it = c.begin(); it != c.end(); ++it){
        suma = suma + *it;
        total++;
    }
    return suma/total;
}

// Ejercicio 3

template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    auto min = desde;
    for(auto it = desde; it != hasta; it++){
        if (*min > *it){
            min = it;
        }
    }
    return *min;
}

// Ejercicio 4

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta){
    auto suma = 0.0;
    auto total = 0.0;
    for(auto it = desde; it != hasta; it++){
        suma = suma + *it;
        total++;
    }
    return suma/total;
}

// Ejercicio 5

template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem){
    for(typename Contenedor::const_iterator it = c.begin(); it != c.end(); ++it){
        if(*it == elem){
            it = c.erase(it);
            --it;
        }
    }
}

// Ejercicio 6

template<class Contenedor>
bool ordenado(Contenedor &c){
    bool ord = true;
    auto it = c.begin();
    for(auto it1 = c.begin(); it1 != c.end(); ++it1){
        if(*it1 != *it){
            ord = ord && *it < *it1;
            ++it;
        }
    }
    return ord;
}

// Ejercicio 7

template<class Contenedor>
std::pair<Contenedor, Contenedor> split(const Contenedor & c, const typename Contenedor::value_type& elem){
    std::pair<Contenedor,Contenedor> result;
    auto it1 = result.first.begin();
    auto it2 = result.second.begin();
    for(auto it = c.begin(); it != c.end(); ++it){
            if (*it < elem){
                it1 =  result.first.insert(it1,*it);
                ++it1;
            } else {
                it2 = result.second.insert(it2,*it);
                ++it2;
            }
    }
    return result;
}

template <class Contenedor>
void merge(const Contenedor& c1, const Contenedor & c2, Contenedor & res){
    auto it1 = c1.begin();
    auto it2 = c2.begin();
    auto it_res = res.begin();
    while(it1 != c1.end() || it2 != c2.end()){
        if(it2 == c2.end() || (it1 != c1.end() && *it1 < *it2)){
            it_res = res.insert(it_res, *it1);
            ++it1;
        } else {
            it_res = res.insert(it_res, *it2);
            it2++;
        }
        ++it_res;
    }
}


#endif
