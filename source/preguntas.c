/*-------------------------------------
preguntas.c
-------------------------------------*/
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "preguntas.h"


struct pregunta preguntas[50];


void inicializarPreguntas(){

strcpy(preguntas[0].pregunta, "En que ano llego\n el hombre a la luna?");
strcpy(preguntas[0].respuestas[0], "1965");
strcpy(preguntas[0].respuestas[1], " 1969");
strcpy(preguntas[0].respuestas[2], "1972");
strcpy(preguntas[0].respuestas[3], " 1976");
preguntas[0].indCorrecta = 1;



strcpy(preguntas[1].pregunta, "Cuanto es 64*64?");
strcpy(preguntas[1].respuestas[0], "4096");
strcpy(preguntas[1].respuestas[1], " 4098");
strcpy(preguntas[1].respuestas[2], "2096");
strcpy(preguntas[1].respuestas[3], " 2098");
preguntas[1].indCorrecta = 0;


strcpy(preguntas[2].pregunta, "Cuantos anos tiene un lustro");
strcpy(preguntas[2].respuestas[0], "5");
strcpy(preguntas[2].respuestas[1], "50");
strcpy(preguntas[2].respuestas[2], "15");
strcpy(preguntas[2].respuestas[3], "10");
preguntas[2].indCorrecta = 0;


strcpy(preguntas[3].pregunta, "Cuantos dientes tiene\n una persona adulta?");
strcpy(preguntas[3].respuestas[0], "26");
strcpy(preguntas[3].respuestas[1], "28");
strcpy(preguntas[3].respuestas[2], "30");
strcpy(preguntas[3].respuestas[3], "32");
preguntas[3].indCorrecta = 3;

strcpy(preguntas[4].pregunta, "Cual es el primer\n numero primo?");
strcpy(preguntas[4].respuestas[0], "0");
strcpy(preguntas[4].respuestas[1], "1");
strcpy(preguntas[4].respuestas[2], "2");
strcpy(preguntas[4].respuestas[3], "3");
preguntas[4].indCorrecta = 2;

strcpy(preguntas[5].pregunta, "Como se escribe\n 'ventana' en euskera?");
strcpy(preguntas[5].respuestas[0], "Leihoa");
strcpy(preguntas[5].respuestas[1], "Leioa");
strcpy(preguntas[5].respuestas[2], "Lehioa");
strcpy(preguntas[5].respuestas[3], "Leioha");
preguntas[5].indCorrecta = 0;

strcpy(preguntas[6].pregunta, "Cual de las siguientes\n esta mal escrita?");
strcpy(preguntas[6].respuestas[0], "Yendo");
strcpy(preguntas[6].respuestas[1], "Agujero");
strcpy(preguntas[6].respuestas[2], "Uve");
strcpy(preguntas[6].respuestas[3], "Cojer");
preguntas[6].indCorrecta = 3;

strcpy(preguntas[7].pregunta, "Que es 'dogon'?");
strcpy(preguntas[7].respuestas[0], "Arma");
strcpy(preguntas[7].respuestas[1], "Animal");
strcpy(preguntas[7].respuestas[2], "Tribu");
strcpy(preguntas[7].respuestas[3], "Pokemon");
preguntas[7].indCorrecta = 2;

strcpy(preguntas[8].pregunta, "Cual es la capital de etiopia?");
strcpy(preguntas[8].respuestas[0], "Asmara");
strcpy(preguntas[8].respuestas[1], "Adis\nAbeba");
strcpy(preguntas[8].respuestas[2], "Yibuti");
strcpy(preguntas[8].respuestas[3], "Yemen");
preguntas[8].indCorrecta = 1;

strcpy(preguntas[9].pregunta, "Cual es el pokemon legendario?");
strcpy(preguntas[9].respuestas[0], "Natu");
strcpy(preguntas[9].respuestas[1], "Dratini");
strcpy(preguntas[9].respuestas[2], "Arceus");
strcpy(preguntas[9].respuestas[3], "Pikachu");
preguntas[9].indCorrecta=2;

strcpy(preguntas[10].pregunta, "Que oceano es el mas pequeno?");
strcpy(preguntas[10].respuestas[0], "Artico");
strcpy(preguntas[10].respuestas[1], "Indico");
strcpy(preguntas[10].respuestas[2], "Pacifico");
strcpy(preguntas[10].respuestas[3], "Ninguno");
preguntas[10].indCorrecta = 0;

strcpy(preguntas[11].pregunta, "En que equipo jugo\n Cristiano Ronaldo?");
strcpy(preguntas[11].respuestas[0], "Arsenal");
strcpy(preguntas[11].respuestas[1], "Juventus");
strcpy(preguntas[11].respuestas[2], "Chelsea");
strcpy(preguntas[11].respuestas[3], "Levante");
preguntas[11].indCorrecta = 1;

strcpy(preguntas[12].pregunta, "En que ano se hizo la\n constitucion actual espanola?");
strcpy(preguntas[12].respuestas[0], "1962");
strcpy(preguntas[12].respuestas[1], "1968");
strcpy(preguntas[12].respuestas[2], "1972");
strcpy(preguntas[12].respuestas[3], "1978");
preguntas[12].indCorrecta = 3;

strcpy(preguntas[13].pregunta, "De donde es originario\n Usain Bolt?");
strcpy(preguntas[13].respuestas[0], "Guinea");
strcpy(preguntas[13].respuestas[1], "Ecuador");
strcpy(preguntas[13].respuestas[2], "Jamaica");
strcpy(preguntas[13].respuestas[3], "Etiopia");
preguntas[13].indCorrecta = 2;

strcpy(preguntas[14].pregunta, "Cual de las siguientes banderas\n NO tiene el color naranja?");
strcpy(preguntas[14].respuestas[0], "Irlanda");
strcpy(preguntas[14].respuestas[1], "Bulgaria");
strcpy(preguntas[14].respuestas[2], "Armenia");
strcpy(preguntas[14].respuestas[3], "Butan");
preguntas[14].indCorrecta = 1;

strcpy(preguntas[15].pregunta, "A que conjugacion pertenece\n el verbo traer?");
strcpy(preguntas[15].respuestas[0], "Primera");
strcpy(preguntas[15].respuestas[1], "Segunda");
strcpy(preguntas[15].respuestas[2], "Tercera");
strcpy(preguntas[15].respuestas[3], "Cuarta");
preguntas[15].indCorrecta = 1;

strcpy(preguntas[16].pregunta, "Cual es el primer apellido\n del Cid Campeador?");
strcpy(preguntas[16].respuestas[0], "Diaz");
strcpy(preguntas[16].respuestas[1], "Garcia");
strcpy(preguntas[16].respuestas[2], "Espana");
strcpy(preguntas[16].respuestas[3], "Perez");
preguntas[16].indCorrecta = 0;

strcpy(preguntas[17].pregunta, "Como se traduce el numero\n 123 en binario?");
strcpy(preguntas[17].respuestas[0], "1111001");
strcpy(preguntas[17].respuestas[1], "1111000");
strcpy(preguntas[17].respuestas[2], "1111011");
strcpy(preguntas[17].respuestas[3], "0011011");
preguntas[17].indCorrecta = 2;

strcpy(preguntas[18].pregunta, "Que palabra deberia llevar\n dieresis?");
strcpy(preguntas[18].respuestas[0], "Aguero");
strcpy(preguntas[18].respuestas[1], "Ayuno");
strcpy(preguntas[18].respuestas[2], "Atun");
strcpy(preguntas[18].respuestas[3], "Ambiguo");
preguntas[18].indCorrecta = 3;


strcpy(preguntas[19].pregunta, "De que deporte es campeon\n mundial Magnus Carlsen?");
strcpy(preguntas[19].respuestas[0], "Ajedrez");
strcpy(preguntas[19].respuestas[1], "Poker");
strcpy(preguntas[19].respuestas[2], "Futbol");
strcpy(preguntas[19].respuestas[3], "Boxeo");
preguntas[19].indCorrecta = 0;


strcpy(preguntas[20].pregunta, "Que letra es la mas usada\n en el lenguaje castellano?");
strcpy(preguntas[20].respuestas[0], "a");
strcpy(preguntas[20].respuestas[1], "r");
strcpy(preguntas[20].respuestas[2], "e");
strcpy(preguntas[20].respuestas[3], "s");
preguntas[20].indCorrecta = 2;


strcpy(preguntas[21].pregunta, "Cual de las siguientes\n palabras deberia llevar tilde?");
strcpy(preguntas[21].respuestas[0], "Guion");
strcpy(preguntas[21].respuestas[1], "Amplio");
strcpy(preguntas[21].respuestas[2], "Examen");
strcpy(preguntas[21].respuestas[3], "Buho");
preguntas[21].indCorrecta = 3;


strcpy(preguntas[22].pregunta, "Que nota musical esta mas\n centrada (en la mitad) \n en el pentagrama?");
strcpy(preguntas[22].respuestas[0], "Fa");
strcpy(preguntas[22].respuestas[1], "Sol");
strcpy(preguntas[22].respuestas[2], "La");
strcpy(preguntas[22].respuestas[3], "Si");
preguntas[22].indCorrecta = 3;


strcpy(preguntas[23].pregunta, "Cuantos dias puede estar\n una persona sin beber?");
strcpy(preguntas[23].respuestas[0], "5");
strcpy(preguntas[23].respuestas[1], "7");
strcpy(preguntas[23].respuestas[2], "10");
strcpy(preguntas[23].respuestas[3], "12");
preguntas[23].indCorrecta = 0;


strcpy(preguntas[24].pregunta, "Cuantos anos vivio matusalen?");
strcpy(preguntas[24].respuestas[0], "357");
strcpy(preguntas[24].respuestas[1], "564");
strcpy(preguntas[24].respuestas[2], "749");
strcpy(preguntas[24].respuestas[3], "969");
preguntas[24].indCorrecta = 3;


strcpy(preguntas[25].pregunta, "Que video es el mas\n reproducido en youtube?");
strcpy(preguntas[25].respuestas[0], "Baby\n      Shark");
strcpy(preguntas[25].respuestas[1], "Runaway");
strcpy(preguntas[25].respuestas[2], "Dura");
strcpy(preguntas[25].respuestas[3], "Me");
preguntas[25].indCorrecta = 0;


strcpy(preguntas[26].pregunta, "Quien canta la sesion\n de bizarrap mas escuchada?");
strcpy(preguntas[26].respuestas[0], "Peso\n     pluma");
strcpy(preguntas[26].respuestas[1], "Shakira");
strcpy(preguntas[26].respuestas[2], "Quevedo");
strcpy(preguntas[26].respuestas[3], "Duki");
preguntas[26].indCorrecta = 1;


strcpy(preguntas[27].pregunta, "Cual es un elemento no metalico \n de la tabla periodica?");
strcpy(preguntas[27].respuestas[0], "Fosforo");
strcpy(preguntas[27].respuestas[1], "Francio");
strcpy(preguntas[27].respuestas[2], "Magnesio");
strcpy(preguntas[27].respuestas[3], "Mercurio");
preguntas[27].indCorrecta = 0;


strcpy(preguntas[28].pregunta, "Que dia de la semana ocurrio\n el atentado a las torres gemelas?");
strcpy(preguntas[28].respuestas[0], "Martes");
strcpy(preguntas[28].respuestas[1], "Jueves");
strcpy(preguntas[28].respuestas[2], "Sabado");
strcpy(preguntas[28].respuestas[3], "Domingo");
preguntas[28].indCorrecta = 0;


strcpy(preguntas[29].pregunta, "Que forma trigonometrica bordea\n a la senal de stop?");
strcpy(preguntas[29].respuestas[0], "Octogono");
strcpy(preguntas[29].respuestas[1], "Circulo");
strcpy(preguntas[29].respuestas[2], "Hexagono");
strcpy(preguntas[29].respuestas[3], "Cuadrado");
preguntas[29].indCorrecta = 0;


strcpy(preguntas[30].pregunta, "Que comunidad tiene mayor\n tasa de criminalidad?");
strcpy(preguntas[30].respuestas[0], "Pais\n     Vasco");
strcpy(preguntas[30].respuestas[1], "Madrid");
strcpy(preguntas[30].respuestas[2], "Islas\n    Baleares");
strcpy(preguntas[30].respuestas[3], "Catalunya");
preguntas[30].indCorrecta = 2;


strcpy(preguntas[31].pregunta, "Alrededor de cuantas palabras\n diferentes contiene El Quijote?");
strcpy(preguntas[31].respuestas[0], "11000");
strcpy(preguntas[31].respuestas[1], "17000");
strcpy(preguntas[31].respuestas[2], "19000");
strcpy(preguntas[31].respuestas[3], "23000");
preguntas[31].indCorrecta = 3;


strcpy(preguntas[32].pregunta, "Cuantas estrellas tiene\n la bandera de Estados Unidos?");
strcpy(preguntas[32].respuestas[0], "30");
strcpy(preguntas[32].respuestas[1], "40");
strcpy(preguntas[32].respuestas[2], "50");
strcpy(preguntas[32].respuestas[3], "60");
preguntas[32].indCorrecta = 2;



strcpy(preguntas[33].pregunta, "Como se llamaba el primer\n perro que fue al espacio?");
strcpy(preguntas[33].respuestas[0], "Toby");
strcpy(preguntas[33].respuestas[1], "Laika");
strcpy(preguntas[33].respuestas[2], "Wetch");
strcpy(preguntas[33].respuestas[3], "Ted");
preguntas[33].indCorrecta = 1;


strcpy(preguntas[34].pregunta, "Cual de estos libros \n es de George Orwell?");
strcpy(preguntas[34].respuestas[0], "1984");
strcpy(preguntas[34].respuestas[1], "Dune");
strcpy(preguntas[34].respuestas[2], "You");
strcpy(preguntas[34].respuestas[3], "Nada");
preguntas[34].indCorrecta = 2;


strcpy(preguntas[35].pregunta, "Con que dorsal se\n retiro Kobe Bryant?");
strcpy(preguntas[35].respuestas[0], "8");
strcpy(preguntas[35].respuestas[1], "10");
strcpy(preguntas[35].respuestas[2], "18");
strcpy(preguntas[35].respuestas[3], "24");
preguntas[35].indCorrecta = 3;


strcpy(preguntas[36].pregunta, "Cuantas preguntas tiene un\n examen teorico de conducir \n tipo B?");
strcpy(preguntas[36].respuestas[0], "25");
strcpy(preguntas[36].respuestas[1], "30");
strcpy(preguntas[36].respuestas[2], "35");
strcpy(preguntas[36].respuestas[3], "40");
preguntas[36].indCorrecta = 1;


strcpy(preguntas[37].pregunta, "Cuantas Champions tiene el Barca?");
strcpy(preguntas[37].respuestas[0], "5");
strcpy(preguntas[37].respuestas[1], "6");
strcpy(preguntas[37].respuestas[2], "4");
strcpy(preguntas[37].respuestas[3], "7");
preguntas[37].indCorrecta = 0;


strcpy(preguntas[38].pregunta, "Cuantos segundos suman dos dias?");
strcpy(preguntas[38].respuestas[0], "170200");
strcpy(preguntas[38].respuestas[1], "172800");
strcpy(preguntas[38].respuestas[2], "176400");
strcpy(preguntas[38].respuestas[3], "178600");
preguntas[38].indCorrecta = 1;


strcpy(preguntas[39].pregunta, "De que pais es capital Riga?");
strcpy(preguntas[39].respuestas[0], "Estonia");
strcpy(preguntas[39].respuestas[1], "Letonia");
strcpy(preguntas[39].respuestas[2], "Suecia");
strcpy(preguntas[39].respuestas[3], "Suiza");
preguntas[39].indCorrecta = 1;

strcpy(preguntas[40].pregunta, "Que videjuego es de 'Rockstar'");
strcpy(preguntas[40].respuestas[0], "Elden\n      Ring");
strcpy(preguntas[40].respuestas[1], "GTA-V");
strcpy(preguntas[40].respuestas[2], "Wii\n     Sports");
strcpy(preguntas[40].respuestas[3], "Pong");
preguntas[40].indCorrecta = 3;


strcpy(preguntas[41].pregunta, "De que grupo era\n el guitarrista Brian May?");
strcpy(preguntas[41].respuestas[0], "Beatles");
strcpy(preguntas[41].respuestas[1], "Queen");
strcpy(preguntas[41].respuestas[2], "ACDC");
strcpy(preguntas[41].respuestas[3], "U2");
preguntas[41].indCorrecta = 1;

strcpy(preguntas[42].pregunta, "Cuantos bytes son 1 TeraByte?");
strcpy(preguntas[42].respuestas[0], "6000000");
strcpy(preguntas[42].respuestas[1], "8000000");
strcpy(preguntas[42].respuestas[2], "600000");
strcpy(preguntas[42].respuestas[3], "800000");
preguntas[42].indCorrecta = 1;

strcpy(preguntas[43].pregunta, "Con que edad murio\n Michael Jackson?");
strcpy(preguntas[43].respuestas[0], "39");
strcpy(preguntas[43].respuestas[1], "43");
strcpy(preguntas[43].respuestas[2], "47");
strcpy(preguntas[43].respuestas[3], "50");
preguntas[43].indCorrecta = 3;

strcpy(preguntas[44].pregunta, "En que mes esta el sol\n mas cerca de la Tierra?");
strcpy(preguntas[44].respuestas[0], "Enero");
strcpy(preguntas[44].respuestas[1], "Mayo");
strcpy(preguntas[44].respuestas[2], "Julio");
strcpy(preguntas[44].respuestas[3], "Agosto");
preguntas[44].indCorrecta = 0;

strcpy(preguntas[45].pregunta, "Donde se celebraron los\n juegos olimpicos en 2012");
strcpy(preguntas[45].respuestas[0], "Rio");
strcpy(preguntas[45].respuestas[1], "Londres");
strcpy(preguntas[45].respuestas[2], "Madrid");
strcpy(preguntas[45].respuestas[3], "Praga");
preguntas[45].indCorrecta = 1;

strcpy(preguntas[46].pregunta, "Cual es el elemento mas comun \n en la atmosfera?");
strcpy(preguntas[46].respuestas[0], "O");
strcpy(preguntas[46].respuestas[1], "He");
strcpy(preguntas[46].respuestas[2], "N");
strcpy(preguntas[46].respuestas[3], "H");
preguntas[46].indCorrecta = 2;

strcpy(preguntas[47].pregunta, "Cuando finalizo la\n Segunda Guerra Mundial?");
strcpy(preguntas[47].respuestas[0], "1944");
strcpy(preguntas[47].respuestas[1], "1945");
strcpy(preguntas[47].respuestas[2], "1943");
strcpy(preguntas[47].respuestas[3], "1946");
preguntas[47].indCorrecta = 1;

strcpy(preguntas[48].pregunta, "Como se llama la mascota\n de la Real Sociedad?");
strcpy(preguntas[48].respuestas[0], "Txurdin");
strcpy(preguntas[48].respuestas[1], "Txuri");
strcpy(preguntas[48].respuestas[2], "Urdin");
strcpy(preguntas[48].respuestas[3], "Mascota");
preguntas[48].indCorrecta = 0;

strcpy(preguntas[49].pregunta, "Como se llama la mejor amiga\n de Harry Potter en la saga?");
strcpy(preguntas[49].respuestas[0], "Cynthia");
strcpy(preguntas[49].respuestas[1], "Mikaela");
strcpy(preguntas[49].respuestas[2], "Jasmina");
strcpy(preguntas[49].respuestas[3], "Hermion");
preguntas[49].indCorrecta = 3;

	


}

void aleatorizarPreguntas(){
	int i;
	int randInd1;
	struct pregunta aux;
    srand(time(NULL));
    for (i=0;i<50;i++){
        randInd1 = (rand() % 10);
        aux = preguntas[i];
		preguntas[i] = preguntas[randInd1];
		preguntas[randInd1] = aux;
	}
}