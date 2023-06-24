#pragma once
#include "CancionManejadorDatos.cpp"
#include "ArtistaManejadorDatosEstaticos.cpp"
#include <map>

class CancionManejadorDatosEstaticos : public CancionManejadorDatos {
public:
	list <Cancion> cargar() {
		
		//Obtenemos la lista de Artistas Estaticos para Asignar sus artistas a las canciones Estaticas
		ArtistaManejadorDatosEstaticos ArtistaDatos;
		list<Artista> listaArtistas = ArtistaDatos.cargar();

		//La lista de canciones que contendran a nuestras canciones agregadas manualmente
		list<Cancion> listaCanciones;

		// Mapa para buscar rápidamente el artista por nombre
		map<string, Artista*> mapaArtistas; 

		// Asocia los artistas de la lista al mapa
		for (Artista& artista : listaArtistas) {
			mapaArtistas[artista.getNombre()] = new Artista(artista.getNombre(), artista.getProcedencia(), artista.getGeneroEnum());
		}

		//Creamos manualmente la lista de Canciones 
		listaCanciones.push_back(Cancion("Quiero Amarte", 3, 05, *mapaArtistas["Cliver"], 5));
		listaCanciones.push_back(Cancion("De ti aprendi", 3, 10, *mapaArtistas["Cliver"], 3));
		listaCanciones.push_back(Cancion("Me bebi tu recuerdo", 3, 19, *mapaArtistas["Wilson"], 2));
		listaCanciones.push_back(Cancion("Cosas del Amor", 3, 21, *mapaArtistas["Histeria"], 4));
		listaCanciones.push_back(Cancion("Tu traicion", 3, 12, *mapaArtistas["Bryndis"], 3));
		listaCanciones.push_back(Cancion("Te he prometido", 3, 11, *mapaArtistas["Bryndis"], 4));
		listaCanciones.push_back(Cancion("Crei que me amabas", 3, 36, *mapaArtistas["Bryndis"], 3));
		listaCanciones.push_back(Cancion("La gata bajo la lluvia", 3, 27, *mapaArtistas["Bryndis"], 5));
		listaCanciones.push_back(Cancion("Hasta el final", 3, 0, *mapaArtistas["Cliver"], 1));
		listaCanciones.push_back(Cancion("Mi verdadero Amor", 3, 06, *mapaArtistas["Bryndis"], 2));
		listaCanciones.push_back(Cancion("Traigan Cerveza", 3, 15, *mapaArtistas["Histeria"], 1));
		listaCanciones.push_back(Cancion("Me gusta Todo de ti", 3, 30, *mapaArtistas["Noche de Brujas"], 4));
		listaCanciones.push_back(Cancion("Ya no vuelvas", 3, 31, *mapaArtistas["Luck Ra"], 3));
		listaCanciones.push_back(Cancion("Mejores Amigos", 3, 32, *mapaArtistas["BM Phontana"], 3));
		listaCanciones.push_back(Cancion("No se va", 3, 33, *mapaArtistas["Grupo Frontera"], 2));
		listaCanciones.push_back(Cancion("Provenza", 3, 34, *mapaArtistas["Karol G"], 1));
		listaCanciones.push_back(Cancion("Todo se paga", 3, 21, *mapaArtistas["Cliver"], 5));
		listaCanciones.push_back(Cancion("Que viva el amor", 3, 22, *mapaArtistas["Cliver"], 5));
		listaCanciones.push_back(Cancion("Dimelo", 3, 22, *mapaArtistas["Aguilas"], 4));
		listaCanciones.push_back(Cancion("Cenizas de Amor", 3, 10, *mapaArtistas["Cliver"], 5));
		listaCanciones.push_back(Cancion("Solo amigos", 3, 10, *mapaArtistas["Cliver"], 3));
		listaCanciones.push_back(Cancion("La inocente", 3, 35, *mapaArtistas["Mora Feid"], 5));
		listaCanciones.push_back(Cancion("Doy la vida por un beso", 3, 39, *mapaArtistas["Bryndis"], 3));
		listaCanciones.push_back(Cancion("Querreque", 3, 40, *mapaArtistas["Bryndis"], 2));
		listaCanciones.push_back(Cancion("La chica del este", 3, 5, *mapaArtistas["Bryndis"], 4));
		listaCanciones.push_back(Cancion("Cuando vuelvas tu", 3, 3, *mapaArtistas["Bryndis"], 4));
		listaCanciones.push_back(Cancion("Perdiste corazon", 3, 2, *mapaArtistas["Bryndis"], 5));
		listaCanciones.push_back(Cancion("Pagando mi Pasado", 3, 45, *mapaArtistas["Bryndis"], 2));
		listaCanciones.push_back(Cancion("Te esperare", 3, 25, *mapaArtistas["Bryndis"], 5));
		listaCanciones.push_back(Cancion("La ultima cancion", 3, 28, *mapaArtistas["Bryndis"], 1));

		// Libera la memoria de los artistas creados en el mapa
		for (auto& pair : mapaArtistas) {
			delete pair.second;
		}
		return listaCanciones;
	}

	void guardar(Cancion _cancion) {

	}
};