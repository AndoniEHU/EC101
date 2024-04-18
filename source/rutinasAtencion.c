/*-------------------------------------
rutinasAtencion.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"
#include "time.h"
#include "unistd.h"




int ESTADO; // Para controlar el estado del autómata en que esté
int seg3;   // Para ver si pasan tres segundos
int i;
int Dinero = 100000;
int DineroMesa[4] = {0};
int mesaXpos[] = {4,120,4,12};
int mesaYpos[] = {16,112,16,112};
int indCaja;

void RutAtencionTeclado ()
{
if (ESTADO == CERRADA)
{	
	if (TeclaPulsada()==A)
	{
		ESTADO=ABIERTA;
		visualizarFondoDos();
        soundEnable();
	}
}
}

void RutAtencionTempo() {
    static int tick = 0;
    static int seg = 0;
    srand(time(NULL));
    int px = rand() % 240;
    int py = rand() % 180;
    int randInd = (rand() % 127) + 5;
    consoleClear();
    touchRead(&PANT_DAT);
    printf("Pos x: %d", PANT_DAT.px);
    printf("Pos y: %d", PANT_DAT.py);

    // Mostrar mesas (meter en 1 funcion todo dentro de sprites.c)
    tick++;
    // diruaJauzi(2);

    if (ESTADO == ABIERTA) {
        mostrarMesas();
    }
    if (ESTADO != FINAL) {
        if (ESTADO != SELCAJA) {
            if ((PANT_DAT.px >= 30 && PANT_DAT.px <= 120) && (PANT_DAT.py >= 30 && PANT_DAT.py <= 80)) {
                indCaja = 0;
                mostrarMesaDebug(indCaja, 4, 16);
                ESTADO = SELCAJA;
            }

            if ((PANT_DAT.px >= 136 && PANT_DAT.px <= 224) && (PANT_DAT.py >= 30 && PANT_DAT.py <= 80)) {
                // mostrarBillete(4,PANT_DAT.px-20,PANT_DAT.py-20);
                indCaja = 1;
                mostrarMesaDebug(indCaja, 120, 16);
                ESTADO = SELCAJA;
            }


            if ((PANT_DAT.px >= 30 && PANT_DAT.px <= 120) && (PANT_DAT.py >= 116 && PANT_DAT.py <= 164)) {
                indCaja = 2;
                mostrarMesaDebug(indCaja, 4, 112);
                ESTADO = SELCAJA;
            }

            if ((PANT_DAT.px >= 136 && PANT_DAT.px <= 224) && (PANT_DAT.py >= 116 && PANT_DAT.py <= 164)) {
                indCaja = 3;
                mostrarMesaDebug(indCaja, 120, 112);
                ESTADO = SELCAJA;
            }
        }
        if (ESTADO == SELCAJA) {
            printf("\n\n\n\n Dinero actual= %d", Dinero);
            printf("\n\n\n\n Dinero actual Caja A = %d", DineroMesa[0]);
            printf("\n\n\n\n Dinero actual Caja B = %d", DineroMesa[1]);
            printf("\n\n\n\n Dinero actual Caja C = %d", DineroMesa[2]);
            printf("\n\n\n\n Dinero actual Caja D = %d", DineroMesa[3]);
            printf("\n\n Mesa escogida = %d", indCaja);
            if (TeclaPulsada() == B) {
                ESTADO = ABIERTA;
            }
            if (TeclaPulsada() == L) {
                printf("\n\n -10000 EUROS EN LA OPCION %d", indCaja);
                if ((Dinero >= 0 && Dinero < 100000) && (DineroMesa[indCaja] > 0 && DineroMesa[indCaja] <= 100000)) {
                    Dinero = Dinero + 10000;
                    DineroMesa[indCaja] = DineroMesa[indCaja] - 10000;
                }
            }
            if (TeclaPulsada() == R) {
                printf("\n\n +10000 EUROS EN LA OPCION %d", indCaja);
                if ((Dinero > 0 && Dinero <= 100000) && (DineroMesa[indCaja] >= 0 && DineroMesa[indCaja] < 100000)) {
                    Dinero = Dinero - 10000;
                    DineroMesa[indCaja] = DineroMesa[indCaja] + 10000;
                }
            }
        }
        // Simplificar tras probar en 1 sola funcion
        if (TeclaPulsada() == SELECT && ESTADO == SELCAJA) {
            mostrarMesaIncorrecta(0, mesaXpos[0], mesaYpos[0]);
            mostrarMesaIncorrecta(1, mesaXpos[1], mesaYpos[1]);
            mostrarMesaIncorrecta(2, mesaXpos[2], mesaYpos[2]);
            mostrarMesaIncorrecta(3, mesaXpos[3], mesaYpos[3]);
            mostrarMesaCorrecta(indCaja, mesaXpos[indCaja], mesaYpos[indCaja]);
            Dinero = Dinero + DineroMesa[indCaja];
            memset(DineroMesa, 0, sizeof(DineroMesa));
            if (Dinero == 0 && TeclaPulsada() == SELECT) {
                borrarMesaIncorrecta(0, mesaXpos[0], mesaYpos[0]);
                borrarMesaIncorrecta(1, mesaXpos[1], mesaYpos[1]);
                borrarMesaIncorrecta(2, mesaXpos[2], mesaYpos[2]);
                borrarMesaIncorrecta(3, mesaXpos[3], mesaYpos[3]);
                borrarMesaCorrecta(indCaja, mesaXpos[indCaja], mesaYpos[indCaja]);
                visualizarFondoUno();
                ESTADO = FINAL;
            } else {
                ESTADO = ABIERTA;
            }
        }
    }
}





void EstablecerVectorInt()
{
// A COMPLETAR
	irqSet(0x4001,RutAtencionTeclado);
	irqSet(0x8,RutAtencionTempo);
	
}

