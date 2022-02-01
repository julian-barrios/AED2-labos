#include "Mapa.h"

Mapa::Mapa(Nat alto, Nat ancho, map<Color, Coordenada> rs): _ancho(ancho), _alto(alto) {
    vector<pair<TipoCasillero, Color>> v;
    for(Nat i = 0; i < alto; i++){
        for(Nat j = 0; j < ancho; j++){
            v.emplace_back(PISO, " ");
        }
        _casilleros.push_back(v);
    }
    auto it = rs.begin();
    Coordenada posAux;
    Color colorAux;
    while(it != rs.end()){
        _receptaculos.insert(make_pair(it->first, it->second));
        posAux = it->second;
        colorAux = it->first;
        _casilleros[posAux.first][posAux.second].second = colorAux;
        ++it;
    }
}

Mapa::~Mapa() {
}

void Mapa::agregarElevacion(const Coordenada &c) {
    _casilleros[c.first][c.second].first = ELEVACION;
}

void Mapa::agregarRampa(const Coordenada &c) {
    _casilleros[c.first][c.second].first = RAMPA;
}

bool Mapa::esPiso(const Coordenada &c) const {
    return _casilleros[c.first][c.second].first == PISO;
}

bool Mapa::esRampa(const Coordenada &c) const {
    return _casilleros[c.first][c.second].first == RAMPA;
}

bool Mapa::esElevacion(const Coordenada &c) const {
    return _casilleros[c.first][c.second].first == ELEVACION;
}

string_map<Coordenada> Mapa::obtenerReceptaculos() const {
    return _receptaculos;
}

Coordenada Mapa::obtenerPosReceptaculos(const Color &col) {
    return _receptaculos.at(col);
}

Nat Mapa::ancho() const {
    return _alto;
}

Nat Mapa::alto() const {
    return _ancho;
}

Color Mapa::colorPorPosicion(Coordenada c) const {
    return _casilleros[c.first][c.second].second;
}

bool Mapa::enRango(const Coordenada &c) const {
    return  0 <= c.first && c.first < _ancho && 
            0 <= c.second && c.second < _alto;
}
