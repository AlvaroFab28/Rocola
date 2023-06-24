#pragma once
#include "DataManager.cpp"
#include <vector>
#include <string>

class RocolaManager {
private:
	//Métodos de las opciones del menú principal encapsulados y disponibles solo para los metodos de esta clase
	static void mostrarCanciones(list<Cancion> lista) {
		cout << "\nNro.  Titulo                                    Duracion     Artista            Procedencia    Genero       Puntuacion\n" << endl;
		int i = 1;
		for (auto it = lista.begin(); it != lista.end(); it++) {
			//Si los numeros son menores a 10 entoces se recorrera un espacio
			if (i < 10) {
				cout << i << setw(5) << left << ".";
			}
			else {
				cout << i << setw(4) << left << ".";
			}
			cout << setw(44) << left << it->getTitulo();
			cout << it->getTiempo().minutos;
			cout << ":";
			if (it->getTiempo().segundos < 10) cout << "0" << setw(8) << left << it->getTiempo().segundos;
			else cout << setw(9) << left << it->getTiempo().segundos;
			cout << setw(21) << left << it->getArtista().getNombre();
			cout << setw(13) << left << it->getArtista().getProcedencia();
			cout << setw(16) << left << it->getArtista().get_genero_preferido();
			it->imprimirPuntuacion(); cout << endl;
			i++;
		}
	}

	static void mostrarPlayList(list<PlayList> lista) {
		int i = 1;
		for (auto it = lista.begin(); it != lista.end(); it++) {
			if (i < 10) {
				cout << "     " << i << ".   " << it->getNombreLista() << endl;
			}
			else {
				cout << "     " << i << ".  " << it->getNombreLista() << endl;
			}
			i++;
		}
	}

	static void mostrarArtistas(list<Artista> lista) {
		int i = 1;
		cout << "Nro.  Nombre              Procedencia         Genero\n\n";
		for (auto it = lista.begin(); it != lista.end(); it++) {
			if (i < 10) {
				cout << i << setw(5) << left << ".";
			}
			else {
				cout << i << setw(4) << left << ".";
			}
			cout << setw(20) << left << it->getNombre();
			cout << setw(20) << left << it->getProcedencia();
			cout << it->get_genero_preferido() << endl;
			i++;
		}
	}

	static void cargarPlaylist(list<PlayList>& ListaDePlaylist, DataManager*& AdmSingleton) {
		int opcion;
		do {
			system("cls");

			cout << "Seleccione una fuente para cargar una Playlist a la rockola\n" << endl;
			cout << "     1.-  Playlist Estaticas" << endl;
			cout << "     2.-  PlayList Archivo CSV\n" << endl;
			cout << "  <- 3.-  Volver  " << endl;

			cout << "\nopcion (1-3): ";
			cin >> opcion;

			if (cin.fail()) { // si la entrada falla (es decir, no es un número)
				cin.clear(); // se limpia la señal de error
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // se descarta la entrada incorrecta
				cout << "Debe ingresar un numero, no caracteres!" << endl;
				cin.get();
				continue; // vuelve al inicio del bucle para solicitar una entrada válida
			}

			if (opcion >= 1 && opcion <= 2) {
				list<PlayList> temp = AdmSingleton->DameListaPlaylist(opcion);
				int num;

				system("cls");
				cout << "Seleccione una PlayList para Agregar a la Rockola: \n" << endl;
				mostrarPlayList(temp);
				cout << endl << "  <- " << temp.size() + 1 << ".  Volver" << endl;
				cout << "\nseleccion (1-" << temp.size() + 1 << "): ";

				do {
					cin >> num;

					if (cin.fail()) { // si la entrada falla (es decir, no es un número)
						cin.clear(); // se limpia la señal de error
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // se descarta la entrada incorrecta
						cout << "Debe ingresar un numero, no caracteres!" << endl;
						continue; // vuelve al inicio del bucle para solicitar una entrada válida
					}
					if (num > 0 && num <= temp.size()) {
						auto it = temp.begin();
						advance(it, num - 1);
						bool band = false;

						for (PlayList iterador : ListaDePlaylist) {
							if (iterador.getNombreLista() == it->getNombreLista()) {
								cout << "ERROR: Esta playlist ya se inserto" << endl;
								band = true;
								break; //Detiene el ciclo for si se encuentra un titulo de cancion repetido
							}
						}
						if (band == false) {
							ListaDePlaylist.push_back(*it);
							cout << "Se inserto a: " << ListaDePlaylist.back().getNombreLista() << endl;
						}
					}
					else {
						if (num == temp.size() + 1) break;
						cout << "Fuera del rango, inserte un numero valido...!\n";
						num = 0;
					}
				} while (true);
			}
			else {
				if (opcion == 3) break;
				cout << "Fuera del rango, inserte un numero valido...\n";
				cin.ignore(); cin.get();
			}
		} while (true);
	}

	static void eliminarPlaylist(list<PlayList>& ListaDePlaylist) {
		do {
			system("cls");
			cout << "Seleccione que Playlist quiere eliminar\n" << endl;
			mostrarPlayList(ListaDePlaylist);
			cout << endl << "  <- " << ListaDePlaylist.size() + 1 << ".   Volver Atras" << endl;
			int opcion;
			cout << "\nSeleccion: ";

			cin >> opcion;
			if (cin.fail()) { // si la entrada falla (es decir, no es un número)
				cin.clear(); // se limpia la señal de error
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // se descarta la entrada incorrecta
				cout << "Debe ingresar un numero, no caracteres!" << endl;
				cin.get();
				continue; // vuelve al inicio del bucle para solicitar una entrada válida
			}
			if (opcion > 0 && opcion <= ListaDePlaylist.size()) {
				list<PlayList>::iterator it = ListaDePlaylist.begin();
				advance(it, opcion - 1);
				ListaDePlaylist.erase(it);
				cout << "eliminacion exitosa" << endl;
			}
			else {
				if (opcion == ListaDePlaylist.size() + 1) break;
				cout << "Seleccion Fuera del rango" << endl;
			}
			cin.ignore(); cin.get();
		} while (true);
	}
	static void trabajarPlaylist(list<PlayList>& ListaDePlaylist, DataManager*& AdmSingleton) {
		int opc;
		do {
			system("cls");
			cout << "\tTRABAJAR EN UNA PLAYLIST" << endl;
			cout << "\nSeleccione la PlayList sobre la que quiere trabajar\n\n";
			mostrarPlayList(ListaDePlaylist);
			cout << endl << "  <- " << ListaDePlaylist.size() + 1 << ".   Volver" << endl;
			cout << "\nOpcion: ";

			cin >> opc;

			if (cin.fail()) { // si la entrada falla (es decir, no es un número)
				cin.clear(); // se limpia la señal de error
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // se descarta la entrada incorrecta
				cout << "Debe ingresar un numero, no caracteres!" << endl;
				cin.get(); // espera a que el usuario presione Enter para continuar
				continue; // vuelve al inicio del bucle para solicitar una entrada válida
			}

			if (opc > 0 && opc <= ListaDePlaylist.size()) {
				int opc2;

				Cancion cancionEncontrada;
				PlayList* currentList = nullptr;

				auto it = ListaDePlaylist.begin();
				advance(it, opc - 1);
				currentList = &*it;
				enum opcion { Default, Agregar, Eliminar, Ver, Buscar, Importar, Clonar, Cancion_Corta, Cancion_Larga, Top_10, Top_n, Artista_Json, Salir };
				do {
					system("cls");
					cout << "\t" << currentList->getNombreLista() << endl;
					cout << "\nDESCRIPCION: " << endl << currentList->getDescripcion() << endl;

					cout << "\nSeleccione la operacion a realizar: \n\n";
					cout << "      1.-  Agregar Cancion\n";
					cout << "      2.-  Eliminar Cancion\n";
					cout << "      3.-  Ver la PlayList\n";
					cout << "      4.-  Buscar cancion\n";
					cout << "      5.-  Importar una PlayList\n";
					cout << "      6.-  Clonar una PlayList\n";
					cout << "      7.-  Cancion mas Corta\n";
					cout << "      8.-  Cancion mas Larga\n";
					cout << "      9.-  Top 10 canciones\n";
					cout << "      10.- Top N canciones\n";
					cout << "      11.- Ver Artistas Archivo Json\n\n";
					cout << "   <- 12.- Volver\n\n";
					cout << "Opcion (1-12): ";
					cin >> opc2;
					if (cin.fail()) { // si la entrada falla (es decir, no es un número)
						cin.clear(); // se limpia la señal de error
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // se descarta la entrada incorrecta
						cout << "Debe ingresar un numero, no caracteres!." << endl;
						cin.get(); // espera a que el usuario presione Enter para continuar
						continue; // vuelve al inicio del bucle para solicitar una entrada válida
					}
					switch (opc2) {
						//Agregar Cancion
					case Agregar:
						do {
							int i;
							system("cls");
							cout << "Seleccione una fuente de origen de las canciones: \n" << endl;
							cout << "     1. Canciones Estaticas" << endl;
							cout << "     2. Canciones TXT\n" << endl;
							cout << "  <- 3. Volver\n" << endl;
							cout << "opcion (1-3): ";
							cin >> i;
							if (cin.fail()) { // si la entrada falla (es decir, no es un número)
								cin.clear(); // se limpia la señal de error
								cin.ignore(numeric_limits<streamsize>::max(), '\n'); // se descarta la entrada incorrecta
								cout << "Debe ingresar un numero, no caracteres!." << endl;
								cin.get(); // espera a que el usuario presione Enter para continuar
								continue; // vuelve al inicio del bucle para solicitar una entrada válida
							}
							if (i > 0 && i < 3) {
								list<Cancion> listaCanciones = AdmSingleton->DameListaCancion(i);
								system("cls");
								cout << "Mostrando todas las canciones de esta fuente... " << endl;
								mostrarCanciones(listaCanciones);
								cout << "\n" << listaCanciones.size() + 1 << ".<- Volver\n" << endl;
								cout << "opcion: ";
								do {
									int n;
									cin >> n;
									if (cin.fail()) { // si la entrada falla (es decir, no es un número)
										cin.clear(); // se limpia la señal de error
										cin.ignore(numeric_limits<streamsize>::max(), '\n'); // se descarta la entrada incorrecta
										cout << "Debe ingresar un numero, no caracteres!." << endl;
										cin.get(); // espera a que el usuario presione Enter para continuar
										continue; // vuelve al inicio del bucle para solicitar una entrada válida
									}
									if (n > 0 && n <= listaCanciones.size()) {
										auto it = listaCanciones.begin();
										advance(it, n - 1);
										currentList->agregarCancion(*it);
									}
									else {
										if (n == listaCanciones.size() + 1) break;
										cout << "Fuera del rango, inserte un numero valido... " << endl;
									}
								} while (true);
							}
							else {
								if (i == 3) break;
								cout << "Fuera del rango, inserte un numero valido... " << endl;
								cin.ignore(); cin.get();
							}
						} while (true);
						break;

						//Eliminar Cancion
					case Eliminar:
						if (currentList->getListaCanciones().empty() == true) cout << "La playlist actual no tiene canciones";
						else {
							system("cls");
							int n;
							currentList->verLista();
							cout << "\nQue numero de cancion desea Eliminar?\n";
							cin >> n;
							currentList->eliminarCancion(n - 1);
						}cin.ignore(); cin.get(); break;

						//Ver la PlayList
					case Ver:
						if (currentList->getListaCanciones().empty() == true) cout << "La playlist actual no tiene canciones";
						else {
							cout << "Mostrando las canciones de: " << currentList->getNombreLista() << endl;
							currentList->verLista();
						} cin.ignore(); cin.get(); break;

						//Buscar Cancion
					case Buscar:
						cin.ignore();
						if (currentList->getListaCanciones().empty() == true) cout << "La playlist actual no tiene canciones";
						else {
							string buscador;
							system("cls");
							cout << "Escriba el nombre de la cancion a buscar: ";
							getline(cin, buscador);
							cancionEncontrada = currentList->buscarCancion(buscador);
							if (cancionEncontrada.getTitulo() != "") {
								system("cls");
								cout << "La cancion se encontro, es la siguiente: \n" << endl;
								cancionEncontrada.verInfo();
							}
							else cout << "La cancion a buscar no existe en la PlayList" << endl;
						}
						cin.get(); break;

						//Importar PlayList
					case Importar: {
						system("cls"); int i = 0;
						string listaActual = currentList->getNombreLista();
						vector<PlayList*> listasImportables;
						for (auto it = ListaDePlaylist.begin(); it != ListaDePlaylist.end(); it++) {
							listasImportables.push_back(&*it);
						}

						// elimina de la lista de importación la lista actual
						for (i = 0; i < listasImportables.size(); i++) {
							if (listaActual == listasImportables[i]->getNombreLista()) {
								listasImportables.erase(listasImportables.begin() + i);
								break;
							}
						}
						// muestra las opciones de importación
						cout << "Seleccione la lista de la que desea importar las canciones:" << endl;
						for (i = 0; i < listasImportables.size(); i++) {
							cout << "\n" << "[" << i + 1 << "] " << listasImportables[i]->getNombreLista();
							if (listasImportables[i]->getListaCanciones().empty())cout << "\nEsta Playlist aun no tiene canciones" << endl;
							else listasImportables[i]->verLista();
						}
						cout << "\n[" << i + 1 << "] Volver" << endl;
						// pide al usuario que seleccione la lista a la que se importarán las canciones
						int selec;
						cout << "opcion: ";
						do {
							cin >> selec;
							if (cin.fail()) { // si la entrada falla (es decir, no es un número)
								cin.clear(); // se limpia la señal de error
								cin.ignore(numeric_limits<streamsize>::max(), '\n'); // se descarta la entrada incorrecta
								cout << "Debe ingresar un numero, no caracteres!." << endl;
								continue; // vuelve al inicio del bucle para solicitar una entrada válida
							}
							if (selec == listasImportables.size() + 1) break;
							// valida la selección y realiza la importación
							if (selec >= 1 && selec <= listasImportables.size()) {
								system("cls");
								cout << "IMPORTANDO CANCIONES...\n" << endl;
								currentList->importarLista(*listasImportables[selec - 1]);
								cin.ignore(); cin.get();
								break;
							}
							else {
								cout << "Fuera del rango, intente nuevamente..." << endl;
							}
						} while (true);
						break;
					}

								 //Clonar Playlist
					case Clonar: {
						system("cls"); int i = 0;
						string listaActual = currentList->getNombreLista();

						vector<PlayList*>listasClonables;
						for (auto it = ListaDePlaylist.begin(); it != ListaDePlaylist.end(); it++) {
							listasClonables.push_back(&*it);
						}
						// elimina de la lista de clonación la lista actual
						for (i = 0; i < listasClonables.size(); i++) {
							if (listaActual == listasClonables[i]->getNombreLista()) {
								listasClonables.erase(listasClonables.begin() + i);
								break;
							}
						}
						// muestra las opciones de clonación
						cout << "Seleccione la lista de la que desea clonar las canciones:" << endl;
						for (i = 0; i < listasClonables.size(); i++) {
							cout << "\n[" << i + 1 << "] " << listasClonables[i]->getNombreLista();
							if (listasClonables[i]->getListaCanciones().empty()) cout << "\nEsta Playlist no contiene canciones" << endl;
							else listasClonables[i]->verLista();
						}
						cout << "\n[" << i + 1 << "] Volver atras" << endl;
						// pide al usuario que seleccione la lista de la que se clonarán las canciones
						int selec;
						cout << "opcion: ";
						cin >> selec;
						if (selec == 3)break;
						system("cls");
						// valida la selección y realiza la clonación
						if (selec >= 1 && selec <= listasClonables.size()) {
							cout << "CLONANDO CANCIONES...\n" << endl;
							currentList->clonarLista(*listasClonables[selec - 1]);
						}
						else {
							cout << "No selecciono correctamente" << endl;
						}
						cin.ignore();
						cin.get();
						break;
					}
					case Cancion_Corta:
						cout << "\nLa cancion mas corta es: \n" << endl;
						currentList->getCancionMasCorta().verInfo(); cin.ignore(); cin.get(); break;

					case Cancion_Larga:
						cout << "\nLa cancion mas larga es: \n" << endl;
						currentList->getCancionMasLarga().verInfo(); cin.ignore(); cin.get(); break;

					case Top_10: mostrarCanciones(currentList->getTopCanciones()); cin.ignore(); cin.get(); break;

					case Top_n: {
						short n;
						cout << "Ingrese el numero de Top que desea ver: "; cin >> n;
						if (n == 1) cout << "\nLa mejor cancion es: \n";
						else cout << "\nLas mejores " << n << " canciones son: \n";
						mostrarCanciones(currentList->getTopCanciones(n)); cin.ignore(); cin.get(); break;
					}
					case Artista_Json:
						cout << "\nMostrando los Artistas leidos de un Archivo Json...\n" << endl;
						mostrarArtistas(AdmSingleton->DameListaArtista(3));
						cin.ignore(); cin.get(); break;

					case Salir: break;

					default: cout << "No selecciono una opcion correctamente" << endl;  cin.ignore(); cin.get(); break;
					}
				} while (opc2 != 12);
			}
			else {
				if (opc == ListaDePlaylist.size() + 1) break;
				cout << "Fuera del rango, inserte un numero valido...\n";
				cin.ignore(); cin.get();
			}
		} while (true);
	}

	static void dibujarGuitarra() {
		cout << " _____  _                                  _   _     _    _     \n"
			"(  _  )(_ )                               ( ) ( ) _ (_ ) (_ )    \n"
			"| (_) | | |  _   _    _ _  _ __    _      | | | |(_) | |  | |    __    ___     _ _\n"
			"|  _  | | | ( ) ( ) /'_` )( '__) /'_`\\    | | | || | | |  | |  /'__`\\/'_` `\\/'_` )\n"
			"| | | | | | | \\_/ |( (_| || |   ( (_) )   | \\_/ || | | |  | | (  ___/| ( ) |( (_| |\n"
			"(_) (_)(___)`\\___/'`\\__,_)(_)   `\\___/'   `\\___/'(_)(___)(___)`\\____)(_) (_)`\\__,_)\n\n\n"
			"                                                  -=++.\n"
			"                                                .+*#*#= \n"
			"                                               .+-+*+*= \n"
			"                                              .*=+#-+=. \n"
			"                                             .+=**-+-  \n"
			"                                             +=*+=*:   \n"
			"                                            :=+**+:.   \n"
			"                                           -+*+-:      \n"
			"                                          :+++=        \n"
			"                                         :++*+         \n"
			"                                        :+**+.         \n"
			"                                       .+**+.          \n"
			"                                      .+++*:           \n"
			"                                     .++**:            \n"
			"                                    .++**-             \n"
			"                                   .+++*=              \n"
			"                                   =++*=               \n"
			"                                  =++*+                \n"
			"                          .:::.  =++++.                \n"
			"                        :========+****                 \n"
			"                       -======++++**#=                 \n"
			"                      -======++++**+=++.               \n"
			"                     .=======++*+*+====#.              \n"
			"                     :====++++*+*+=====+#=             \n"
			"                    .====+*##%#**=======##             \n"
			"                   :====++##%%%%*+=====+##.            \n"
			"                .-======++##%%%#+======*#*             \n"
			"              :==========++##*+======*##:             \n"
			"            .==============++++=====+##*:              \n"
			"           :======================+*##-               \n"
			"          .======+===============+##*.                \n"
			"          -======***=============+##-                 \n"
			"          ========++=+===========*##:                 \n"
			"          ============++++=======+##:                 \n"
			"          :=============#**+=====*##.                 \n"
			"           -=============+*+=====*##                  \n"
			"            -====================##*                  \n"
			"             :==================+##:                  \n"
			"               :===============+##=                   \n"
			"                 :-===========*##-                    \n"
			"                   .:-=====+*#*-.                     \n"
			"                         ....                          \n"
			"\n";
	}
public:

	//Metodo publico "iniciar" que se ejecutara en el main del Archivo "Principal"
	static void iniciar() {

		// Dos únicas variables 
		// AdmSingleton instacia unica que se encargara de obtener datos
		DataManager* AdmSingleton = DataManager::getInstancia();

		// y ListaDePlaylist que contendra los Playlist de la Rockola
		list<PlayList> ListaDePlaylist;

		int opcion;
		do {
			system("cls");
			cout << "----------------ROCKOLA USFX------------------\n";
			cout << "|                                            |\n";
			cout << "| Operacion a realizar en la Rockola:        |\n";
			cout << "|                                            |\n";
			cout << "|     1.-  Cargar una Playlist               |\n";
			cout << "|     2.-  Eliminar una Playlist             |\n";
			cout << "|     3.-  Mostrar Todas las Playlist        |\n";
			cout << "|     4.-  Trabajar en una Playlist          |\n";
			cout << "|     5.-  Guardar                           |\n";
			cout << "|                                            |\n";
			cout << "|  <- 6.-  Cerrar Programa                   |\n";
			cout << "|____________________________________________|\n";

			cout << "\nopcion (1-6): "; cin >> opcion;

			if (cin.fail()) { // si la entrada falla (es decir, no es un número)
				cin.clear(); // se limpia la señal de error
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // se descarta la entrada incorrecta
				cout << "Debe ingresar un numero, no caracteres!" << endl;
				cin.get(); // espera a que el usuario presione Enter para continuar
				continue; // vuelve al inicio del bucle para solicitar una entrada válida
			}
			cin.ignore();
			if (opcion > 0 && opcion < 6) {
				switch (opcion) {

					//Cargar Playlist
				case 1:
					cargarPlaylist(ListaDePlaylist, AdmSingleton);
					break;

				case 2:
					if (ListaDePlaylist.empty()) { cout << "Error la rocola esta vacia" << endl; cin.get(); }
					else eliminarPlaylist(ListaDePlaylist);
					break;

					//Mostrar Playlist
				case 3:
					if (ListaDePlaylist.empty()) cout << "Error la rocola esta vacia" << endl;
					else {
						cout << "\nMostrando todas las playlist cargadas a la rockola: \n" << endl;
						mostrarPlayList(ListaDePlaylist);
						cout << "\nPresione ENTER para cerrar...";

					}cin.get();
					break;

					//Trabajar en una PlayList
				case 4:
					if (ListaDePlaylist.empty()) { cout << "Error la rocola esta vacia" << endl; cin.get(); }
					else trabajarPlaylist(ListaDePlaylist, AdmSingleton);
					break;
				case 5: {
					if (ListaDePlaylist.empty()) { cout << "Error la rocola esta vacia" << endl; cin.get(); }
					else {
						system("cls");
						int opcion, con = 1;
						cout << "Seleccione la playlist que desea guardar: \n" << endl;
						for (auto it = ListaDePlaylist.begin(); it != ListaDePlaylist.end(); it++) {

							cout << "     " << con << ". " << it->getNombreLista() << endl;
							if (it->getListaCanciones().empty()) cout << "        Esta playlist no contiene canciones\n" << endl;
							else cout << "        Todo ok\n" << endl;
							con++;
						}
						cout << "<-   " << ListaDePlaylist.size() + 1 << ". Volver" << endl;
						cout << "\nopcion: ";
						cin >> opcion;
						if (opcion == ListaDePlaylist.size() + 1) break;
						auto it = ListaDePlaylist.begin();
						advance(it, opcion - 1);
						PlayListManejadorDatosArchivo probador;
						probador.guardar(*it);
					}
				}break;
				}
			}
			else {
				if (opcion == 6) break;
				cout << "Fuera del rango, seleccione un numero valido..." << endl; cin.get();
			}
		} while (true);
		system("cls"); dibujarGuitarra(); system("pause");
	}
};