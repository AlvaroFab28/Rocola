#pragma once
#include "CancionManejadorDatos.cpp"//Padre
#include "ArtistaManejadorDatosArchivo.cpp"

class CancionManejadorDatosArchivo : public CancionManejadorDatos {
public:
	list<Cancion> cargar()
	{
		//lista donde se almacenaran los artistas leidos
		list<Cancion> listaCanciones;

		ArtistaManejadorDatosArchivo artMDA;
		list<Artista> lisArtistasTXT = artMDA.cargar();

		ifstream cin2("canciones.txt");
		string titulo, duracion_minutos, duracion_segundos, posicion_artista, estrellas;
		int minutos, segundos, posicion, estrella;

		int nro = 1;
		//la funcion peek() verifica que no estemos al final del archivo
		while (cin2.peek() != EOF)// corroboramos que no hayamos llegado a la ultima linea, es decir al final del archivo
		{
			//leemos todo lo que podamos donde se encuentra el cursor, (en la primera iteracion al principio) hasta donde encontremos una primera coma
			getline(cin2, titulo, ',');
			// continuacion leemos hasta encontrar otra coma, que seria el dato asociado a la procednecia
			getline(cin2, duracion_minutos, ':');
			// finalmente leemos desde donde este el cursor, toda la linea, que seria el resto de la informacion asociada al genero
			getline(cin2, duracion_segundos, ' ');
			cin2.ignore(std::numeric_limits<std::streamsize>::max(), ',');
			getline(cin2, posicion_artista, ',');
			getline(cin2, estrellas);

			//cout << "Nro " << nro << ".-  " << titulo << "   " << duracion_minutos << "   " << duracion_segundos << "    "<<posicion_artista<<"    "<<estrellas<<endl;
			//nro++;

			try {
				minutos = stoi(duracion_minutos);
			}
			catch (const std::invalid_argument&) {
				// La conversión falló, duracion_minutos no es un número válido
				// Aquí puedes manejar el caso de error de acuerdo a tus necesidades
				// Por ejemplo, puedes asignar un valor predeterminado o mostrar un mensaje de error
				minutos = 0; // Asignar un valor predeterminado de 0 en este ejemplo
				//cout << "Error: duracion_minutos no es un número válido." << endl;
			}
			segundos = stoi(duracion_segundos);
			estrella = stoi(estrellas);

			auto it = lisArtistasTXT.begin();
			posicion = stoi(posicion_artista);
			advance(it, posicion - 1);

			listaCanciones.push_back(Cancion(titulo, minutos, segundos, *it, estrella));

			// y guardarlo en una lista
		}
		// cargar datos desde un archivo de texto
			//devolucion de la lista cargada con datos
		return listaCanciones;
	}

	void guardar(Cancion _cancion)
	{
		ArtistaManejadorDatosArchivo art;
		list<Artista> listart = art.cargar();

		bool band = false;
		for (Cancion iterador : cargar()) {
			if (iterador.getTitulo() == _cancion.getTitulo())
			{
				cout << "ERROR: Esta cancion ya se insertó" << endl;
				band = true;
				break; // Detiene el ciclo for si se encuentra un artista repetido
			}
		}
		if (!band) {

			// Guardar la canción en el archivo
			ofstream cout2;
			cout2.open("canciones.txt", std::ios_base::app);

			std::stringstream ss;
			int cont = 0;
			bool band = false;

			//capturar la posicion del artista para luego grabarlo
			for (Artista iterador : listart) {
				cont++;
				if (_cancion.getArtista().getNombre() == iterador.getNombre()) {
					band = true;
					ss << _cancion.getTitulo() << "," << _cancion.getTiempo().minutos << ":" << _cancion.getTiempo().segundos << " PM," << cont << "," << _cancion.getPuntuacion();
					break;
				}
			}
			if (!band) ss << _cancion.getTitulo() << "," << _cancion.getTiempo().minutos << ":" << _cancion.getTiempo().segundos << " PM," << listart.size() + 1 << "," << _cancion.getPuntuacion();

			std::string s = ss.str();

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
	}
};