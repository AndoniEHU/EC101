/*---------------------------------------------------------------------------------
preguntas.h
---------------------------------------------------------------------------------*/

#ifndef PREGUNTA_H
#define PREGUNTA_H
struct pregunta {
	char pregunta [75];
	char respuestas [4][25];
	int indCorrecta;
};
#endif

extern struct pregunta preguntas[10];

extern void inicializarPreguntas();

//extern void aleatorizarPreguntas();