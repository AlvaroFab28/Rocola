#pragma once
#include "ArtistaManejadorDatos.cpp"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class ArtistaManejadorDatosArchivo : public ArtistaManejadorDatos {
public:
	list<Artista> cargar()
	{
		//lista donde se almacenaran los artistas leidos
		list<Artista> listaArtistas;

		ifstream cin2("artistas.txt");
		string nombre, procedencia, genero;

		int nro = 1;
		Genero generoLeido = Desconocido;
		//la funcion peek() verifica que no estemos al final del archivo
		while (cin2.peek() != EOF)// corroboramos que no hayamos llegado a la ultima linea, es decir al final del archivo
		{
			//leemos todo lo que podamos donde se encuentra el cursor, (en la primera iteracion al principio) hasta donde encontremos una primera coma
			getline(cin2, nombre, ',');
			// continuacion leemos hasta encontrar otra coma, que seria el dato asociado a la procednecia
			getline(cin2, procedencia, ',');
			// finalmente leemos desde donde este el cursor, toda la linea, que seria el resto de la informacion asociada al genero
			getline(cin2, genero);

			if (genero == "Cumbia") {
				generoLeido = Cumbia;
			}
			else if (genero == "Folklore") {
				generoLeido = Folklore;
			}
			else if (genero == "Rock") {
				generoLeido = Rock;
			}
			else if (genero == "Romatica") {
				generoLeido = Romantica;
			}
			else if (genero == "Baladas") {
				generoLeido = Baladas;
			}
			else {
				generoLeido = Desconocido;
			}
			//cout << "Nro " << nro << ".-  " << nombre << " " << procedencia << " " << genero << endl;
			//nro++;

			//crear el artista
			listaArtistas.push_back(Artista(nombre, procedencia, generoLeido));
			// y guardarlo en una lista
		}
		//devolucion de la lista cargada con datos
		return listaArtistas;
	}
	void guardar(Artista artist)
	{
		bool band = false;
		for (Artista iterador : cargar())
		{
			if (iterador.getNombre() == artist.getNombre())
			{
				cout << "ERROR: Este artista ya se insertó" << endl;
				band = true;
				break; // Detiene el ciclo for si se encuentra un artista repetido
			}
		}
		if (!band)
		{
			ofstream cout2;
			cout2.open("artistas.txt", std::ios_base::app);

			std::stringstream ss;
			ss << artist.getNombre() << "," << artist.getProcedencia() << "," << artist.get_genero_preferido();

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

