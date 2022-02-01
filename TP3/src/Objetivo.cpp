#include "Objetivo.h"

Objetivo::Objetivo(): _objetivo(){
}

Objetivo::Objetivo(const Color& objeto, const Color& receptaculo){
    _objetivo.first = objeto;
    _objetivo.second = receptaculo;
}


const Color& Objetivo::objeto() const{
    return _objetivo.first;
}

const Color& Objetivo::receptaculo() const{
    return _objetivo.second;
}