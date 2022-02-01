#include "aed2_mapa.h"

map<Color,Coordenada> rs;

aed2_Mapa::aed2_Mapa() : _mapa(0,0,rs), _receptaculos() {
}

aed2_Mapa::aed2_Mapa(Mapa m) : _mapa(m),_receptaculos() {
    string_map<Coordenada> rsAux = m.obtenerReceptaculos();
    set<Color> clavesRs = rsAux.claves();
    auto it = clavesRs.begin();
    while(it != clavesRs.end()){
        _receptaculos.insert(make_pair(*it, rsAux.at(*it)));
        ++it;
    }
}

aed2_Mapa::aed2_Mapa(Nat ancho, Nat alto, set<Coordenada> elevaciones, map<Color, Coordenada> receptaculos):
        _mapa(Mapa(alto,ancho,receptaculos)),_receptaculos(receptaculos){
    for(Coordenada i: elevaciones) {
        _mapa.agregarElevacion(i);
    }
}

void aed2_Mapa::agregarRampa(Coordenada c) {
    _mapa.agregarRampa(c);
}

Nat aed2_Mapa::ancho() const {
    return _mapa.ancho();
}

Nat aed2_Mapa::alto() const {
    return _mapa.alto();
}

TipoCasillero aed2_Mapa::tipoCasillero(Coordenada c) const {
    if(_mapa.esElevacion(c)) {
        return ELEVACION;
    }
    else if(_mapa.esRampa(c)) {
        return RAMPA;
    }
    else if(_mapa.esPiso(c)) {
        return PISO;
    }
}

const map<Color, Coordenada>& aed2_Mapa::receptaculos() const {
    return _receptaculos;
}

Coordenada aed2_Mapa::receptaculo(Color c) {
    return _mapa.obtenerPosReceptaculos(c);
}

Mapa aed2_Mapa::mapa() const {
    return _mapa;
}