#pragma once
#include <iostream>
using namespace std;

enum Genero { Desconocido, Rock, HipHop, Pop, Baladas, Latin_Music, Cumbia, Romantica, Chicha, Folklore };
class Artista {
private:
	string nombre;
	string procedencia;
	Genero genero;

public:
	Artista() {
		nombre = "Desconocido";
		procedencia = "Desconocido";
		genero = Desconocido;
	};
	Artista(string _nombre, string _procedencia, Genero _genero) {
		nombre = _nombre;
		procedencia = _procedencia;
		genero = _genero;
	}
	void verInfo()
	{
		cout << "Nombre: " << nombre << endl;
		cout << "Procedencia: " << procedencia << endl;
		cout << "Genero: " << genero << endl;
	}
	string getNombre() { return nombre; }
	string getProcedencia() { return procedencia; }
	Genero getGeneroEnum() { return genero; }
	string get_genero_preferido() const {
		switch (genero) {
		case Rock:
			return "Rock";
		case HipHop:
			return "HipHop";
		case Pop:
			return "Pop";
		case Baladas:
			return "Baladas";
		case Latin_Music:
			return "Latin Music";
		case Cumbia:
			return "Cumbia";
		case Romantica:
			return "Romantica";
		case Chicha:
			return "Chicha";
		case Folklore:
			return "Folklore";
		default:
			return "Desconocido";
		}
	}
};