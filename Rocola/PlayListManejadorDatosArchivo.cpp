#pragma once
#include "PlayListManejadorDatos.cpp"
#include "CancionManejadorDatosArchivo.cpp"
#include <vector>
#include <sstream>
#include <fstream>
class PlayListManejadorDatosArchivo : public PlayListManejadorDatos {
public:

	list<PlayList> cargar() {
		// Lista donde se almacenarán las PlayList leídas
		list<PlayList> listaPlayList;

		// Obtener la lista de canciones del archivo para asignar sus canciones a las PlayList del archivo
		CancionManejadorDatosArchivo canMDA;
		list<Cancion> listaCancionesTXT = canMDA.cargar();

		//lista auxiliar que guardara canciones en base a la posicion de cada linea del csv
		list<Cancion> listaCancionParaPlaylist;

		ifstream cin2("playlists.csv");
		string nombreLista, descripcion, posicion;
		int pos;
		// La función peek() verifica que no estemos al final del archivo
		while (cin2.peek() != EOF) {

			// Leer el nombre de la lista de reproducción
			getline(cin2, nombreLista, ',');

			// Leer la descripción de la lista de reproducción
			getline(cin2, descripcion, '[');

			// Leer los números "[{10},{15},{30},{11}]" hasta el último que exista y asignarlos a la variable "posicion"
			string numeros;
			getline(cin2, numeros);

			// Eliminar los corchetes iniciales y finales
			numeros = numeros.substr(0, numeros.length() - 2);

			// Tokenizar los números entre llaves separados por comas
			stringstream ss(numeros);
			string numero;
			//cout << "nombre: " << nombreLista <<" canciones: "<< numeros << endl;
			//cin.get();
			while (getline(ss, numero, ',')) {
				// Eliminar las llaves del número
				numero = numero.substr(1, numero.length() - 2);
				try {
					// Convertir el número de string a entero
					pos = stoi(numero);
				}
				catch (const std::invalid_argument&) {
					pos = 0;
				}
				if (pos != 0) {
					// Usar el entero para buscar una canción en la lista de canciones
					auto it = listaCancionesTXT.begin();
					advance(it, pos - 1);
					// Cargar la canción de esa posición en una nueva lista de canciones
					listaCancionParaPlaylist.push_back(*it);
				}
			}
			//Finalmente en la lista para playlist que va a retornar agregamos todos los datos leidos de una linea
			listaPlayList.push_back(PlayList(nombreLista, descripcion, listaCancionParaPlaylist));

			//vaciamos la lista auxiliar para que en la siguiente linea este libre de datos basura
			listaCancionParaPlaylist.clear();

		}
		return listaPlayList;
	}

	void guardar(PlayList _playlist)
	{
		CancionManejadorDatosArchivo can;
		ArtistaManejadorDatosArchivo art;
		list<Cancion> listCanTxt = can.cargar();
		int i = listCanTxt.size();
		list<Cancion> listaCancionPlaylistActual = _playlist.getListaCanciones();

		ofstream cout2;
		cout2.open("playlists.csv", std::ios_base::app);

		std::stringstream ss;

		ss << _playlist.getNombreLista() << "," << _playlist.getDescripcion() << ",\"[";

		// Agregar las canciones entre llaves
		for (auto it = listaCancionPlaylistActual.begin(); it != listaCancionPlaylistActual.end(); ++it)
		{
			int cont2 = 0;
			bool band = false;
			// verifica si esta cancion de la playlist actual ya existe en el txt entonces grabar la posicion
			for (auto it2 = listCanTxt.begin(); it2 != listCanTxt.end(); ++it2) {
				cont2++;
				if (it2->getTitulo() == it->getTitulo()) {				
					ss << "{" << cont2 << "},";
					can.guardar(*it);
					art.guardar(it->getArtista());
					band = true;
					break;
				}
			}
			// si no existe entonces agregar al final
			if (band == false) {
				i++;
				ss << "{" << i << "},";
				can.guardar(*it);
				art.guardar(it->getArtista());
			}
		}
		// Eliminar la coma extra al final
		std::string s = ss.str();
		if (!listaCancionPlaylistActual.empty())
		{
			s.pop_back();
		}

		s += "]\"";

		// Verificar si el archivo ya tiene contenido
		cout2.seekp(0, std::ios::end);
		bool fileIsEmpty = (cout2.tellp() == 0);

		// Agregar un salto de línea si el archivo no está vacío
		if (!fileIsEmpty)
		{
			cout2 << "\n";
		}

		cout2 << s;
		cout2.close(); // Cerrar el archivo después de guardar los datos
	}

};