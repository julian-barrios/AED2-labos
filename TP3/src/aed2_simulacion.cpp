#include "aed2_simulacion.h"

aed2_Simulacion::aed2_Simulacion(const aed2_Mapa &mapa, const map<Color, Coordenada> &objetos, Coordenada inicio):
        _sim(mapa.mapa(),inicio, objetos), _objetos(objetos) {
}

void aed2_Simulacion::mover(Direccion d) {
    Coordenada posActualAgente = _sim.posicionActual();
    _sim.moverAgente(d);
    Coordenada pos_sig = _sim.posConDesplazamiento(_sim.posicionActual(), d);
    if(_sim.obtenerMapa().enRango(pos_sig)) {
        if ((posActualAgente != _sim.posicionActual()) && _sim.hayObjeto(pos_sig)) {
            Color colorObjeto = _sim.obtenerColoresObjetos()[pos_sig.first][pos_sig.second];
            _objetos[colorObjeto] = pos_sig;
        }
    }
}

void aed2_Simulacion::agregarObjetivo(Objetivo o) {
    _sim.agregarObjetivo(o);
}

const aed2_Mapa aed2_Simulacion::mapa() const {
    return aed2_Mapa(_sim.obtenerMapa());
}

const map<Color, Coordenada> &aed2_Simulacion::posObjetos() const {
    return _objetos;
}

Coordenada aed2_Simulacion::posAgente() const {
    return _sim.posicionActual();
}

const list<Objetivo> &aed2_Simulacion::objetivosDisponibles() const {
    return _sim.obtenerObjetivosDisponibles();
}

Nat aed2_Simulacion::movimientos() const {
    return _sim.nroMovimientos();
}

Nat aed2_Simulacion::objetivosResueltos() const {
    return _sim.nroObjetivosCompletados();
}