#ifndef MAPA_H
#define MAPA_H

#include "Tipos.h"
#include <tuple>
#include "string_map.h"

class Mapa {
public:
    Mapa(Nat alto, Nat ancho, map<Color, Coordenada> rs);
    
    ~Mapa();

    void agregarElevacion(const Coordenada &c);

    void agregarRampa(const Coordenada &c);

    bool esPiso(const Coordenada &c) const;
    
    bool esRampa(const Coordenada &c) const;

    bool enRango(const Coordenada &c) const;

    bool esElevacion(const Coordenada &c) const;

    string_map<Coordenada> obtenerReceptaculos() const;

    Coordenada obtenerPosReceptaculos(const Color &col);

    Nat ancho() const;

    Nat alto() const;

    Color colorPorPosicion(Coordenada c) const;
private:
    vector<vector<pair<TipoCasillero, Color>>> _casilleros;
    string_map<Coordenada> _receptaculos;
    Nat _alto;
    Nat _ancho;
};

#endif
