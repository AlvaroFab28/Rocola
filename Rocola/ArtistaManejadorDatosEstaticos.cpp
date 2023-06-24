#pragma once
#include "ArtistaManejadorDatos.cpp"

class ArtistaManejadorDatosEstaticos: public ArtistaManejadorDatos {
public:
	list <Artista> cargar() {
		list<Artista> listaArtistas;

		listaArtistas.push_back(Artista("Cliver", "Peru", Chicha));
		listaArtistas.push_back(Artista("Wilson", "Bolivia", Cumbia));
		listaArtistas.push_back(Artista("Histeria", "Bolivia", Cumbia));
		listaArtistas.push_back(Artista("Bryndis", "Mexico", Romantica));
		listaArtistas.push_back(Artista("Noche de Brujas", "Chile", Pop));
		listaArtistas.push_back(Artista("Luck Ra", "Argentina", HipHop));
		listaArtistas.push_back(Artista("BM Phontana", "Argentina", Cumbia));
		listaArtistas.push_back(Artista("Grupo Frontera", "Mexico", Latin_Music));
		listaArtistas.push_back(Artista("Karol G", "Colombia", HipHop));
		listaArtistas.push_back(Artista("Aguilas", "Peru", Cumbia));
		listaArtistas.push_back(Artista("Mora Feid", "Bolivia", Latin_Music));

		return listaArtistas;
	}
	void guardar(Artista art) {

	}
};