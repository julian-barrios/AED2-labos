#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1

// En el ejercicio 1 y 2 están mal los test

vector<int> quitar_repetidos(vector<int> s) {
    vector<int> sin_repetidos;
    for (int i = 0; i < s.size(); i++){
        for(int j = 0 ; j < s.size(); j++){
            if(s[i] != s[j]){
                sin_repetidos.push_back(s[i]);
            }
        }
    }
    return sin_repetidos;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    return vector<int>();
}

// Ejercicio 3

bool pertenece(vector<int> a, int x){
    int i = 0;
    while(i < a.size() && a[i] != x){
        i++;
    }
    return i < a.size();
}


bool mismos_elementos(vector<int> a, vector<int> b) {
    bool res = true;
    for(int x: a){
        res = res && pertenece(b,x);
    }
    return res;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    set<int> conj_a;
    set<int> conj_b;
    bool res = true;
    for(int i = 0; i < a.size(); i++){
        conj_a.insert(a[i]);
    }
    for(int i = 0; i < b.size(); i++){
        conj_b.insert(b[i]);
    }
    for(int x: a){
        res = res && conj_b.count(x) == 1;
    }
    return res;
}

// Ejercicio 5

int cant_apariciones(vector <int> s, int x){
    int apariciones = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == x){
            apariciones++;
        }
    }
    return apariciones;
}

map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> res;
    for(int i = 0; i < s.size(); i++){
        res[s[i]] = cant_apariciones(s,s[i]);
    }
    return res;
}


// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {\
    vector <int> res;
    for(int i = 0; i < s.size(); i++){
        if(cant_apariciones(s,s[i]) == 1){
            res.push_back(s[i]);
        }
    }
    return res;
}

// Ejercicio 7


set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for(int x: a){
        if(a.count(x) == b.count(x)){
            res.insert(x);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res;
    for(int i = 0; i < s.size(); i++){
        set<int> unidad_i;
        for(int j = 0; j < s.size(); j++){
            if(s[i] % 10 == s[j] % 10){
                unidad_i.insert(s[j]);
            }
        }
        res[s[i] % 10] = unidad_i;
    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res;
    for(int i = 0; i < str.size(); i++){
        int j;
        for(j = 0; j < tr.size() && tr[j].first != str[i]; j++){
        }
        if(j < tr.size()){
            res.push_back(tr[j].second);
        } else {
            res.push_back(str[i]);
        }
    }
    return res;
}

set<LU> interseccionLibretas(set<LU> a, set<LU> b) {
    set<LU> res;
    for(LU x: a){
        if(a.count(x) == b.count(x)){
            res.insert(x);
        }
    }
    return res;
}


// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    bool res = true;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < s.size(); j++){
            if(i != j){
                res = res && (s[i].libretas() == s[j].libretas() || interseccionLibretas(s[i].libretas(), s[j].libretas()).size() == 0);
            }
        }
    }
    return res;
}





// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s){
    map<set<LU>, Mail> res;
    for(int i = 0; i < s.size(); i++){
        if(s[i].adjunto()){
            res[s[i].libretas()] = s[i];
        }
    }
    return res;
}
