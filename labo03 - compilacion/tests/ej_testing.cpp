#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
    EXPECT_EQ(15+7, 22);
}

// Ejercicio 5
TEST(Aritmetica, potencia) {
    EXPECT_EQ(pow(10,2), 100);
}

// Ejercicio 6

TEST(Aritmetica, potencia_general){
    for(int i = -5; i <= 5; i++){
        if(i != 0){
            EXPECT_EQ(pow(i,2), i*i);
        }
    }
}

// Ejercicio 7

TEST(Diccionario, obtener){
    map<int, int> mapa;
    mapa.insert(make_pair(3,4));
    EXPECT_EQ(mapa[3],4);
}

// Ejercicio 8

TEST(Diccionario, definir){
    map<int, int> mapa;
    EXPECT_EQ(mapa.count(3),0);
    mapa.insert(make_pair(3,4));
    EXPECT_EQ(mapa.count(3),1);
}

// Ejercicio 9

TEST(Truco, Inicio){
    Truco j1; Truco j2;
    EXPECT_EQ(j1.puntaje_j1(), 0);
    EXPECT_EQ(j2.puntaje_j2(), 0);
}

// Ejercicio 10

TEST(Truco, buenas){
    Truco j1;
    EXPECT_FALSE(j1.buenas(1));
    for(int i = 1; i <= 15; i++){
        j1.sumar_punto(1);
    }
    EXPECT_FALSE(j1.buenas(1));
    j1.sumar_punto(1);
    EXPECT_TRUE(j1.buenas(1));
    j1.sumar_punto(2);
    EXPECT_TRUE(j1.buenas(1));
}
