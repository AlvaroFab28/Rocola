#pragma once
#include "PlayListManejadorDatos.cpp"

class PlayListManejadorDatosEstaticos: public PlayListManejadorDatos {
public:
	list <PlayList> cargar() {
		list<PlayList> listaPlayList;

		listaPlayList.push_back(PlayList("PLAYLIST POR DEFECTO", "Playlist por defecto para realizar pruebas"));
		listaPlayList.push_back(PlayList("PLAYLIST FAVORITOS", "Las canciones mas apreciadas"));
		listaPlayList.push_back(PlayList("PLAYLIST LATINOS", "Un mix de latinos"));
		listaPlayList.push_back(PlayList("AT FULL VOLUMEN", "o lo que es lo mismo a todo volumen. Pon ese musicon imprescindible para darlo todo en casa, en el coche o en una reunion de amigos y a cantar."));
		listaPlayList.push_back(PlayList("SAD, SAD, SAD", "sad o melancolicas, este es el mas conciso aqui hay canciones que te emocionen, que te calen y que te hagan pensar en esos viejos tiempos."));
		listaPlayList.push_back(PlayList("LOSERS IN LOVE", "para todos aquellos perdedores enamorados, esta lista puede contar con los exitos más romanticos y bonitos o aquellos temas que te hagan pensar en esa persona especial."));
		listaPlayList.push_back(PlayList("ROLAS CHIDAS PARA DARLO TODO", "el nombre lo dice todo, no es asi? prepara una lista con los temas y los exitos que mas te saquen a la pista de baile."));
		listaPlayList.push_back(PlayList("DE TAL PALO TAL ASTILLA", "playlist llenas de exitos que te ponian tus padres."));
		listaPlayList.push_back(PlayList("CUMBIAS DE MICROBUSERO", "A esta maravillosa lista solo le falta el caracteristico claxon del micro para ser perfecta. Ideal para hacer una fiesta poderosisima llena de bailongo y risas. Dale play y relajate; cierra los ojos y te vas a sentir en un asiento con destino a Yotala, en una de esas hasta escuchas al chofer gritar: subale, hay lugares! "));
		listaPlayList.push_back(PlayList("MUSICA PARA CAMINAR COMO PETER PARKER", "Existe mejor escena en la historia del cine? NO. Todos nos acordamos de aquel sublime momento en Spider-Man 3, en el que Peter Parker camina por la calle con toda la seguridad y el estilo del mundo. Que cancion sonaba en su cabeza mientras lo hacia? Ni idea. Pero aca tu puedes probar con muuuuchas canciones para sentirte como el. Vas!"));
		listaPlayList.push_back(PlayList("CANCIONES PARA CERRAR LA CALLE", "Ideal para XV anios, bautizos, cumpleanios o la ocasion que prefieras. Pura cancion pa echar barrio en la calle, con tus sillitas de plastico, cuantas botellas quieras y taquiza pa los invitados. Claro que si, como no. Ojo: la playlist no incluye el permiso de la policia para cerrar la calle, ni coches para poner en las esquinas y evitar que la gente pase. Pero si incluye unos rolonononones que prenden hasta al mas apagado."));
		listaPlayList.push_back(PlayList("PA BAILAR CON EL FANTASMA DE TU CUARTO.", "Y por que no?, si te ve llorar en las noches, es justo que tambien lo saques a bailar."));
		listaPlayList.push_back(PlayList("MUSICA RELAJANTE PARA PERRITO", "Musica para calmar la ansiedad del perrito"));
		listaPlayList.push_back(PlayList("MUSICA PARA CONDUCIR Y NO MATARME CAMBIANDO DE CANCION", "Que detalle, se preocupan por tu bienestar, una recopilacion de buenas canciones para que nunca las cambies y sigas manejando tranquilamente"));
		listaPlayList.push_back(PlayList("PARA HACER TAREAS DE 3 MESES EN 7 HORAS", "Esta seguramente la necesitas si vas en la universidad"));
		listaPlayList.push_back(PlayList("ROLAS PA LA RAZA CHIDA", "La musica mas chingona para echar desmadre con los cuates. Puro flow y buena vibra!"));
		listaPlayList.push_back(PlayList("TRAP BOLIVIANO COCHALO", "Si eres bien cochalo y te gusta el trap, esta playlist te hara perrear bien duro. Dale con todo y que retumbe el Illimani!"));
		listaPlayList.push_back(PlayList("CARNAVALITO PARTY", "Aqui encontraras los mejores carnavalitos para bailar como diablada en pleno Carnaval de Oruro. Preparate para la fiesta mas colorida!"));
		listaPlayList.push_back(PlayList("CHICHA POWER", "La chicha mas poderosa y refrescante para poner a gozar a tus oidos. Prepara el singani y a brindar con esta seleccion musical sabrosa!"));
		return listaPlayList;
	}

	void guardar(PlayList _playlist) {

	}
};