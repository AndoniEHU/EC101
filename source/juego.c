/*---------------------------------------------------------------------------------
Este código se ha desarrollado basándose en el código de dovoto "Simple sprite demo" 
y en otro ejemplo de Jaeden Ameronen
---------------------------------------------------------------------------------*/


#include <nds.h> 		// Librería de la nds
#include <stdio.h>		// Librería de entrada/salida estándar de C
#include <stdlib.h>		// Librería estándar de C para reserva de memoria y conversiones numéricas
#include <unistd.h>		// Librería para asegurar la compatibilidad entre sistemas operativos

// Librerías desarrolladas por nosotros para el proyecto

#include "sprites.h"
#include "definiciones.h"
#include "perifericos.h"
#include "rutinasAtencion.h"
#include "fondos.h"
#include "preguntas.h"

int tiempo;
void juego()
{
	ConfigurarTemporizador(0x100,0xC1);
	ConfigurarTeclado(0x4005);
	EstablecerVectorInt();
	HabilitarIntTeclado();
	HabilitarIntTempo();
    aleatorizarPreguntas();
    ESTADO=PREGUNTA;

	while(1)
	{
        if (ESTADO == PREGUNTA) {
            cargarFondoMain();
            mostrarMesas(mesaXpos,mesaYpos);
            ESTADO=RESOLVIENDO;
        }
	}
}



