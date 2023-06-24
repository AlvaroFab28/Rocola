#pragma once
#include <iostream>
#include <iomanip>
#include "Artista.cpp"
using namespace std;

struct Tiempo
{
	int minutos;
	int segundos;
};

class Cancion {
private:
	string titulo;
	Tiempo duracion;
	Artista artista;
	short puntuacion; // 1...5

public:
	Cancion()
	{
		titulo = "";
		duracion.minutos = 0;
		duracion.segundos = 0;
	}
	Cancion(string tit,int min,int seg) {
		titulo = tit;
		duracion.minutos = min;
		duracion.segundos = seg;
	}
	Cancion(string tit,int min,Artista art,int _puntuacion)
	{
		titulo = tit;
		duracion.minutos = min;
		duracion.segundos = 0;
		artista = art;
		puntuacion = _puntuacion;
	}
	Cancion(string tit, Tiempo t)
	{
		titulo = tit;
		duracion = t;
	}
	Cancion(string tit, Tiempo t, Artista art)
	{
		titulo = tit;
		duracion = t;
		artista = art;
	}
	Cancion(string tit, int min, int seg, Artista art, short _puntuacion) {
		titulo = tit;
		duracion.minutos = min;
		duracion.segundos = seg;
		artista = art;
		puntuacion = _puntuacion;
	}
	void verInfo()
	{
		cout << "Titulo              Tiempo      Artista            Procedencia       Genero       Puntuacion" << endl;
		cout << setw(20) << left << titulo << duracion.minutos << ":"; if (duracion.segundos < 10)cout << "0" << setw(9) << left << duracion.segundos;
		else cout << setw(10) << left << duracion.segundos; cout << setw(19) << left << artista.getNombre();
		cout << setw(18) << left << artista.getProcedencia() << setw(13) << left << artista.get_genero_preferido(); imprimirPuntuacion(); cout << endl;
	}
	string getTitulo(){return titulo;}
	Tiempo getTiempo(){return duracion;}
	Artista getArtista() {return artista;}
	short getPuntuacion() { return puntuacion; }
	void setPuntuacion(short puntos){puntuacion = puntos;}


	/*La funci�n miembro operator> de la clase Cancion siempre recibe una nueva canci�n por par�metro(b) para compararla con la canci�n actual(a).
	La puntuaci�n es un atributo de la canci�n actual(a), por lo que no es necesario que se pase como par�metro a la funci�n.
	La funci�n miembro operator> compara la puntuaci�n de la canci�n actual(a) con la puntuaci�n de la canci�n que se est� comparando(b).
	Si la puntuaci�n de la canci�n actual es mayor que la puntuaci�n de la canci�n que se est� comparando, entonces la funci�n devuelve true.De lo contrario, devuelve false.*/

	bool operator>(const Cancion& b) const {
		return puntuacion > b.puntuacion;
	}

	int operator==(Cancion b)
	{
		return titulo == b.titulo;
	}
	void imprimirPuntuacion() {
		for (int i = 0; i < puntuacion; i++) {
			cout << "*";
		}
	}
};