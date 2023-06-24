#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <algorithm>
#include <list>
#include "Cancion.cpp"
using namespace std;

class PlayList {
private:
	string nombreLista;
	string descripcion;
	list<Cancion> listaCanciones;
public:
	PlayList(string _nombreLista, string _descripcion) {    //Constructor de PlayList
		nombreLista = _nombreLista;
		descripcion = _descripcion;
		listaCanciones = list<Cancion>(); // inicializa la lista con su constructor predeterminado
	}
	PlayList(string _nombreLista, string _descripcion,list<Cancion> lista) {    //Constructor de PlayList
		nombreLista = _nombreLista;
		descripcion = _descripcion;
		listaCanciones = lista;
	}
	void agregarCancion(Cancion c)          //Agrega Canciones
	{
		bool band = false;
		for (Cancion cancionLista : listaCanciones) {               //validar canciones repetidas                                                            
			if (c.getTitulo() == cancionLista.getTitulo()) {       //si la cancion ya existe, no incorporarla
				cout << "ERROR: Esta cancion esta repetida y no se puede introducir" << endl;
				band = true;
				break; //Detiene el ciclo si se encuentra un titulo de cancion repetido
			}
		}
		if (band == false) {
			listaCanciones.push_back(c);
			cout << "Se agrego la cancion '" << listaCanciones.back().getTitulo() << "' " << endl;
		}
	}
	void eliminarCancion(int nroCancion)				//quite una cacnion en funcion a la posicion de la cancion
	{																//listaCanciones.erase
		if (nroCancion < 0 || nroCancion >= listaCanciones.size())
		{
			cout << "El numero de cancion ingresado no es valido." << endl;
			return;
		}
		char opcion;
		cout << "Seguro que desea eliminar la cancion? Presione 's' para confirmar o cualquier otra tecla para cancelar: ";
		cin >> opcion;
		if (opcion == 's')
		{
			list<Cancion>::iterator it = listaCanciones.begin();
			advance(it, nroCancion);
			listaCanciones.erase(it);
			cout << "La cancion se elimino con exito" << endl;
		}
		else
		{
			cout << "La eliminacion de la cancion ha sido cancelada." << endl;
		}
	}
	//mostrar las canciones
//Nro cancion  /   Titulo   / duracion (mm:ss)
//1         Te voy a Extraniar   03:40
//2         It´s my Life         04:30
//3         Bla Bla Bla          07:20
	void verLista()
	{
		{
			cout << "\nNro.   Titulo                     Duracion   Artista         Puntuacion\n" << endl;
			int i = 1;
			for (list<Cancion>::iterator it = listaCanciones.begin(); it != listaCanciones.end(); it++) {
				if (i < 10) {
					cout << i << setw(6) << left << ".";
				}
				else {
					cout << i << setw(5) << left << ".";
				}
				cout << setw(23) << left << it->getTitulo();
				cout << setw(5) << right << it->getTiempo().minutos;
				cout << ":"; if (it->getTiempo().segundos < 10) cout << "0" << setw(8) << left << it->getTiempo().segundos;
				else cout << setw(9) << left << it->getTiempo().segundos;
				cout << setw(16) << left << it->getArtista().getNombre(); it->imprimirPuntuacion(); cout << endl;
				i++;
			}
		}
	}

	Cancion buscarCancion(string titulo) {
		transform(titulo.begin(), titulo.end(), titulo.begin(), ::tolower); // Convertir a minúsculas
		//titulo.begin()primer caracter titulo.end()ultimo caracter <=rango string titulo.begin() desde el inicio ::tolower (minusculas)
		for (auto& cancion : listaCanciones) {
			string tituloCancion = cancion.getTitulo();
			transform(tituloCancion.begin(), tituloCancion.end(), tituloCancion.begin(), ::tolower); // Convertir a minúsculas
			if (tituloCancion == titulo) {
				return cancion;
			}
		}
		return Cancion();
	}
	void limpiarLista()
	{
		listaCanciones.clear();
		//limpiar la lista
		//eliminar todos sus elementos
	}
	void importarLista(PlayList lista)
	{
		for (auto it = lista.listaCanciones.begin(); it != lista.listaCanciones.end(); it++) {
			agregarCancion(*it);
		}
		//debe copiar los valores de la playlist parametro de la funcion lista
		// a la lista actual, utilizando las funciones definidas dentro de la clase
		//  agregarCancion()
	}
	void clonarLista(PlayList lista)
	{
		limpiarLista(); // Elimina las canciones de la lista actual
		for (auto it = lista.listaCanciones.begin(); it != lista.listaCanciones.end(); it++) {
			agregarCancion(*it); // Agrega las canciones de la lista parametro a la lista actual
		}
		//debe copiar los valores de la playlist parametro de la funcion lista
		// a la lista actual, utilizando las funciones definidas dentro de la clase
		//  limpiarLista()
		//y luego agregarCancion() mientras recorre el vector
	}
	bool existeNroCancion(int pos)
	{
		bool existe = true; \
		auto it = listaCanciones.begin();
		if (pos < 1 || pos > listaCanciones.size()) {
			// Si la posición está fuera de los límites del vector, la canción no existe
			return existe = false;
		}
		else {
			// La posición es válida, se busca la canción en la lista
			return existe = true;
		}
		//implementar la logica para ver si dicho indice existe en la lista de canciones
	}

	Cancion getCancionMasCorta() {
		Cancion cancionMasCorta("", { 100000, 0 }); // inicializar con duración alta para asegurarse de encontrar una canción más corta
		for (Cancion cancion : listaCanciones) {
			if (cancion.getTiempo().minutos < cancionMasCorta.getTiempo().minutos ||
				(cancion.getTiempo().minutos == cancionMasCorta.getTiempo().minutos && cancion.getTiempo().segundos < cancionMasCorta.getTiempo().segundos)) {
				cancionMasCorta = cancion;
			}
		}
		return cancionMasCorta;
	}

	Cancion getCancionMasLarga() {
		Cancion cancionMasLarga; // inicializar con duración alta para asegurarse de encontrar una canción más corta
		for (Cancion cancion : listaCanciones) {
			if (cancion.getTiempo().minutos > cancionMasLarga.getTiempo().minutos ||
				(cancion.getTiempo().minutos == cancionMasLarga.getTiempo().minutos && cancion.getTiempo().segundos > cancionMasLarga.getTiempo().segundos)) {
				cancionMasLarga = cancion;
			}
		}
		return cancionMasLarga;
	}
	/*Se llama a la función sort() pasando la lista de canciones como argumento.
	El algoritmo de ordenamiento sort() divide la lista en subgrupos y realiza comparaciones utilizando la función lambda.
	Dentro de la función lambda, se invoca el operador sobrecargado > de la clase Cancion para comparar las puntuaciones de las canciones a y b.
	El operador sobrecargado > realiza la comparación de las puntuaciones de las canciones según la implementación definida en la clase Cancion.
	La función lambda devuelve true o false según el resultado de la comparación.
	El algoritmo de ordenamiento sort() utiliza los resultados devueltos por la función lambda para ordenar las canciones en la lista.
	El proceso se repite para todas las comparaciones necesarias hasta que la lista esté completamente ordenada.*/
	list<Cancion> getTopCanciones()
	{
		// Crear una copia de la lista de canciones
		list<Cancion> topCanciones = listaCanciones;

		// Ordenar la lista en orden descendente por puntuación
		topCanciones.sort([](const Cancion& a, const Cancion& b) { return a > b; });

		// Si hay más de 10 canciones, eliminar las restantes
		if (topCanciones.size() > 10) {
			topCanciones.resize(10);
		}
		// Devolver la lista de las 10 canciones con mayor puntuación
		return topCanciones;
	}

	list<Cancion> getTopCanciones(int nro)
	{
		// Crear una copia de la lista de canciones
		list<Cancion> topCanciones = listaCanciones;

		// Ordenar la lista en orden descendente por puntuación
		topCanciones.sort([](const Cancion& a, const Cancion& b) { return a > b; }); //funcion lambda

		// Si hay más de n canciones, eliminar las restantes
		if (topCanciones.size() > nro) {
			topCanciones.resize(nro);
		}

		// Devolver la lista de las n canciones con mayor puntuación
		return topCanciones;
	}

	string getNombreLista() { return nombreLista; }
	string getDescripcion() { return descripcion; }
	list<Cancion> getListaCanciones() { return listaCanciones; }
};
