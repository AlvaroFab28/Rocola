#include <fstream>
#include <iostream>
#include <list>
#include <nlohmann/json.hpp>
#include "ArtistaManejadorDatos.cpp"
using json = nlohmann::json;

class ArtistaManejadorDatosArchivoJson : public ArtistaManejadorDatos {
public:
    std::list<Artista> cargar() {
        std::list<Artista> listaArtistas;

        std::ifstream archivo("artistas.json");
        if (!archivo.is_open()) {
            // Manejo de error en caso de que no se pueda abrir el archivo
            return listaArtistas;
        }

        json datosJson;
        try {
            archivo >> datosJson;
        }
        catch (const json::exception& e) {
            // Manejo de error en caso de que haya un problema al analizar el JSON
            std::cerr << "Error al analizar el archivo JSON: " << e.what() << std::endl;
            return listaArtistas;
        }

        for (const auto& elemento : datosJson) {
            string nombre = elemento["nombre"].get<string>();
            string procedencia = elemento["procedencia"].get<string>();
            string genero = elemento["genero"].get<string>();

            Genero generoLeido = Desconocido;
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
            else if (genero == "Romantica") {
                generoLeido = Romantica;
            }
            else if (genero == "Chicha") {
                generoLeido = Chicha;
            }
            else if (genero == "Pop") {
                generoLeido = Pop;
            }
            else if (genero == "Baladas") {
                generoLeido = Baladas;
            }

            listaArtistas.push_back(Artista(nombre, procedencia, generoLeido));
        }

        return listaArtistas;
    }
    void guardar(Artista artist) {

    }
};