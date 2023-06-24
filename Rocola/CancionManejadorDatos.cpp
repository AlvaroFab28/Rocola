#pragma once
#include "Cancion.cpp"
#include <list>
using namespace std;

class CancionManejadorDatos {
public:
	virtual list <Cancion> cargar() = 0;
	virtual void guardar(Cancion _cancion) = 0;
};