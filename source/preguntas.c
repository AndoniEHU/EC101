/*-------------------------------------
preguntas.c
-------------------------------------*/
#include <stdlib.h>
#include "preguntas.h"
#include <string.h>

struct pregunta preguntas[10];


void inicializarPreguntas(){

	strcpy(preguntas[0].pregunta,"Cuando llego el hombre \n a la luna?");
	strcpy(preguntas[0].respuestas[0], "1965");
	strcpy(preguntas[0].respuestas[1], " 1969");
	strcpy(preguntas[0].respuestas[2], "1972");
	strcpy(preguntas[0].respuestas[3], " 1976");
	preguntas[0].indCorrecta = 1;

	strcpy(preguntas[1].pregunta, "¿Cual es la pelicula mas \n taquillera de la historia?");
	strcpy(preguntas[1].respuestas[0], "Avengers  \n      Endgame");
	strcpy(preguntas[1].respuestas[1], "Titanic");
	strcpy(preguntas[1].respuestas[2], "Avatar");
	strcpy(preguntas[1].respuestas[3], "Barbie");
	preguntas[1].indCorrecta = 0;

	strcpy(preguntas[2].pregunta, "Que registro no forma parte de un controlador de perifericos?");
	strcpy(preguntas[2].respuestas[0], "Estado");
	strcpy(preguntas[2].respuestas[1], "Espera");
	strcpy(preguntas[2].respuestas[2], "Datos");
	strcpy(preguntas[2].respuestas[3], "Control");
	preguntas[2].indCorrecta = 1;
    // volver a ver para cambiar centro
	strcpy(preguntas[3].pregunta, "Cuantos dientes tiene \n una persona adulta?");
	strcpy(preguntas[3].respuestas[0], "  26");
	strcpy(preguntas[3].respuestas[1], "  28");
	strcpy(preguntas[3].respuestas[2], "  30");
	strcpy(preguntas[3].respuestas[3], "  32");
	preguntas[3].indCorrecta = 3;

	strcpy(preguntas[4].pregunta, "Cual es el primer numero primo?");
	strcpy(preguntas[4].respuestas[0], "  0");
	strcpy(preguntas[4].respuestas[1], "  1");
	strcpy(preguntas[4].respuestas[2], "  2");
	strcpy(preguntas[4].respuestas[3], "  3");
	preguntas[4].indCorrecta = 3;

	strcpy(preguntas[5].pregunta, "Como se escribe 'ventana' \n en euskera?");
	strcpy(preguntas[5].respuestas[0], "Leihoa");
	strcpy(preguntas[5].respuestas[1], "Leioa");
	strcpy(preguntas[5].respuestas[2], "Lehioa");
	strcpy(preguntas[5].respuestas[3], "Leioha");
	preguntas[5].indCorrecta = 0;

	strcpy(preguntas[6].pregunta, "Cual de las siguientes esta mal escrita?");
	strcpy(preguntas[6].respuestas[0], "Yendo");
	strcpy(preguntas[6].respuestas[1], "Agujero");
	strcpy(preguntas[6].respuestas[2], " Uve");
	strcpy(preguntas[6].respuestas[3], "Cojer");
	preguntas[6].indCorrecta = 3;

	strcpy(preguntas[7].pregunta, "\n Cuanto es 64*64?");
	strcpy(preguntas[7].respuestas[0], " 4096");
	strcpy(preguntas[7].respuestas[1], " 4098");
	strcpy(preguntas[7].respuestas[2], " 2096");
	strcpy(preguntas[7].respuestas[3], " 2098");
	preguntas[7].indCorrecta = 0;

	strcpy(preguntas[8].pregunta, "Cual es la capital de etiopia?");
	strcpy(preguntas[8].respuestas[0], "Adis \n     Abeba");
	strcpy(preguntas[8].respuestas[1], "Asmara");
	strcpy(preguntas[8].respuestas[2], "Kinsasa");
	strcpy(preguntas[8].respuestas[3], "Yibuti");
	preguntas[8].indCorrecta = 0;

	strcpy(preguntas[9].pregunta, "Que nota se repite al principio de la cancion 'runaway' \n de Kanye West?");
	strcpy(preguntas[9].respuestas[0], " Do");
	strcpy(preguntas[9].respuestas[1], "  Re");
	strcpy(preguntas[9].respuestas[2], " Mi");
	strcpy(preguntas[9].respuestas[3], "  Fa");
	preguntas[9].indCorrecta = 2;


}

/*void aleatorizarPreguntas(){

	int i;
	int randInd1;
	int randInd2;
	struct pregunta aux;
	for (i=0;i<sizeof(preguntas);i++){
		randInd1 = (rand() % sizeof(preguntas)-1);
		randInd2 = (rand() % sizeof(preguntas)-1);
		aux = preguntas[randInd1];
		preguntas[randInd1] = preguntas[randInd2];
		preguntas[randInd2] = aux;
	}

}*/