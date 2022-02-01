#include "Simulacion.h"

Simulacion::Simulacion(const Mapa &m, const Coordenada posInicial, map<Color,Coordenada> objetos): mapa_(m), posicionActual_(posInicial), objetivosCompletados_(0), cantMovimientos_(0), objetivosTrie_(), objetivosDisponibles_(), objetoEnPosicion_() {
    auto it = objetos.begin();
    Coordenada posAux;
    vector<vector<Color>> nuevoObjetosEnPosicion(m.ancho(), vector<Color>(m.alto(), " "));
    while(it != objetos.end()){
        posAux = it->second;//  = el significado
        nuevoObjetosEnPosicion[posAux.first][posAux.second] = it->first; // = la clave
        it++;
    }
    objetoEnPosicion_ = nuevoObjetosEnPosicion;
}

void Simulacion::moverAgente(Direccion d) {
    Coordenada pos_actual = posicionActual_;
    Coordenada pos_sig = posConDesplazamiento(posicionActual_, d);
    Coordenada pos_sig_sig = posConDesplazamiento(pos_sig, d);
    if(puedeMover(pos_actual, d) && (!hayObjeto(pos_sig) || (puedeMover(pos_sig, d) && !hayObjeto(pos_sig_sig)))){
        if(hayObjeto(pos_sig)) {
            string color_obj_pos_sig = objetoEnPosicion_[pos_sig.first][pos_sig.second];
            if(objetivosTrie_.count(color_obj_pos_sig) != 0) {
                auto casilleros_dests = objetivosTrie_.at(color_obj_pos_sig);
                string color_cas_dest = mapa_.colorPorPosicion(pos_sig_sig);
                if (casilleros_dests.count(color_cas_dest)) {
                    objetivosCompletados_++;
                    auto itLista = casilleros_dests.at(color_cas_dest);
                    objetivosDisponibles_.erase(itLista);
                    if (casilleros_dests.size() > 1) {
                        casilleros_dests.erase(color_cas_dest);
                    } else {
                        objetivosTrie_.erase(color_obj_pos_sig);
                    }
                }
            }
            objetoEnPosicion_[pos_sig.first][pos_sig.second] = " ";
            objetoEnPosicion_[pos_sig_sig.first][pos_sig_sig.second] = color_obj_pos_sig;
        }
        posicionActual_ = pos_sig;
    }
    if(mapa_.enRango(pos_sig)){
        cantMovimientos_++;
    }
}

void Simulacion::agregarObjetivo(const Objetivo &o) {
    if(objetoEnPosicion_[mapa_.obtenerPosReceptaculos(o.receptaculo()).first][mapa_.obtenerPosReceptaculos(o.receptaculo()).second] == o.objeto()){
        objetivosCompletados_++;
    } else {
         // primero creo un iterador en la lista de objetivos para insertar
        const list<Objetivo>::iterator i = objetivosDisponibles_.begin();
        bool objetoEstaEnObjetivosTrie = objetivosTrie_.count(o.objeto()) != 0;
        if(!objetoEstaEnObjetivosTrie) {
            auto itLista = objetivosDisponibles_.insert(i, o);
            string_map<list<Objetivo>::iterator> trieReceptaculos;
            trieReceptaculos.insert(make_pair(o.receptaculo(), itLista));
            objetivosTrie_.insert(make_pair(o.objeto(), trieReceptaculos));
        } else {
            bool existeReceptaculo = objetivosTrie_.at(o.objeto()).count(o.receptaculo()) != 0;
            if(!existeReceptaculo) {
                auto itLista = objetivosDisponibles_.insert(i, o);
                objetivosTrie_.at(o.objeto()).insert(make_pair(o.receptaculo(), itLista));
            }
        }
    }
}

const Mapa& Simulacion::obtenerMapa() const {
    return mapa_;
}

const Coordenada& Simulacion::posicionActual() const {
    return posicionActual_;
}

Nat Simulacion::nroMovimientos() const {
    return cantMovimientos_;
}

const list<Objetivo>& Simulacion::obtenerObjetivosDisponibles() const {
    return objetivosDisponibles_;
}

Nat Simulacion::nroObjetivosCompletados() const {
    return objetivosCompletados_;
}

const vector<vector<Color>>& Simulacion::obtenerColoresObjetos() const {
    return objetoEnPosicion_;
}

Coordenada Simulacion::posConDesplazamiento(Coordenada c, Direccion d) const {
    Coordenada res = c;
    if(d == ARRIBA){
        res.second = res.second + 1;
    }
    if(d == ABAJO){
        res.second = res.second - 1;
    }
    if(d == IZQUIERDA){
        res.first = res.first - 1;
    }
    if(d == DERECHA){
        res.first = res.first + 1;
    }
    return res;
}

bool Simulacion::puedeMover(Coordenada posActual, Direccion d) const {
    return mapa_.enRango(posConDesplazamiento(posActual, d)) && (!mapa_.esElevacion(posConDesplazamiento(posActual, d)) || mapa_.esRampa(posActual));
}

bool Simulacion::hayObjeto(Coordenada pos) const {
    return objetoEnPosicion_[pos.first][pos.second] != " ";
}
