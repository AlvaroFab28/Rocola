#pragma once

#include "PlayListManejadorDatosArchivo.cpp"
#include "PlayListManejadorDatosEstaticos.cpp"

#include "CancionManejadorDatosArchivo.cpp"
#include "CancionManejadorDatosEstaticos.cpp"

#include "ArtistaManejadorDatosArchivo.cpp"
#include "ArtistaManejadorDatosEstaticos.cpp"
#include "ArtistaManejadorDatosArchivoJson.cpp"

class DataManager {
private:
	static DataManager* instancia;

	DataManager() {

	}

public:

	list<PlayList> DameListaPlaylist(int n) {
		if (n == 1) {
			PlayListManejadorDatosEstaticos playListDataManager;
			return playListDataManager.cargar();
		}
		else {
			PlayListManejadorDatosArchivo playListDataManager;
			return playListDataManager.cargar();
		/*	 Manejar otros casos o retornar una lista vacía si es necesario*/
		}
	}

	list<Cancion> DameListaCancion(int n) {
		if (n == 1) {
			CancionManejadorDatosEstaticos CancionDataManager;
			return CancionDataManager.cargar();
		}
		else {
			CancionManejadorDatosArchivo CancionDataManager;
			return CancionDataManager.cargar();
			// Manejar otros casos o retornar una lista vacía si es necesario
		}
	}
	list<Artista> DameListaArtista(int n) {
		if (n == 1) {
			ArtistaManejadorDatosEstaticos ArtistaDataManager;
			return ArtistaDataManager.cargar();
		}
		else if(n == 2){
			ArtistaManejadorDatosArchivo ArtistaDataManager;
			return ArtistaDataManager.cargar();
		}
		else {
			ArtistaManejadorDatosArchivoJson ArtistaDataManager;
			return ArtistaDataManager.cargar();
		}
	}


	static DataManager* getInstancia() {
		if (instancia == nullptr) {
			instancia = new DataManager();
		}
		return instancia;
	}
};

