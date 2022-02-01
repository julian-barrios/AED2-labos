#ifndef SIMULACION_H
#define SIMULACION_H

#include "Mapa.h"
#include "Objetivo.h"

class Simulacion {
public:
    Simulacion(const Mapa &m, Coordenada posInicial, map<Color,Coordenada> objetos);

    void moverAgente(Direccion d);

    void agregarObjetivo(const Objetivo& o);

    const Mapa& obtenerMapa() const;

    const Coordenada& posicionActual() const;

    Nat nroMovimientos() const;

    const list<Objetivo>& obtenerObjetivosDisponibles() const;

    Nat nroObjetivosCompletados() const;

    const vector<vector<Color>>& obtenerColoresObjetos() const;

    Coordenada posConDesplazamiento(Coordenada c, Direccion d) const;

    bool puedeMover(Coordenada posActual, Direccion d) const;

    bool hayObjeto(Coordenada pos) const;

private:
    Mapa mapa_;
    list<Objetivo> objetivosDisponibles_;
    Coordenada posicionActual_;
    string_map<string_map <list<Objetivo>::iterator>> objetivosTrie_;
    Nat cantMovimientos_;
    Nat objetivosCompletados_;
    vector<vector<Color>> objetoEnPosicion_; // si no hay objeto en una coordenada el valor es " "
};

#endif // SIMULACION_H
