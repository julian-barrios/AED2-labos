#include "SistemaDeMensajes.h"

SistemaDeMensajes::SistemaDeMensajes(): _conns()   {}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr;
}

void SistemaDeMensajes::registrarJugador(int id, string ip) {
    if(registrado(id)){
        desregistrarJugador(id);
    }
    _conns[id] = new  ConexionJugador(ip);
    _conns[id]->ip() = ip;
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje) {
    _conns[id]->enviarMensaje(mensaje);
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip();
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    delete _conns[id];
    _conns[id] = nullptr;
}


Proxy* SistemaDeMensajes::obtenerProxy(int id){
    
}

SistemaDeMensajes::~SistemaDeMensajes()   {
    for(ConexionJugador* rj: _conns){
        delete rj;
    }
}