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
#include "preguntas.h"





int ESTADO; // Para controlar el estado del autómata en que esté
int seg3;   // Para ver si pasan tres segundos
int i;
int Dinero = 100000;


int DineroCajas[4] = {0};
int BilletesMesa[4] = {0};
int mesaXpos[] = {4,120,4,120};
int mesaYpos[] = {16,16,112,112};
int indCaja;
int ronda = 1;


int seleccionCaja(int px,int py){
	if ((px >= 30 && px <= 120) && (py >= 30 && py <= 80)) return 0;
	if ((px >= 136 && px <= 224) && (py >= 30 && py <= 80)) return 1;
	if ((px >= 30 && px <= 120) && (py >= 116 && py <= 164)) return 2;
	if ((px >= 136 && px <= 224) && (py >= 116 && py <= 164)) return 3;
	return -1;

}

void printEstadoCajas(){
    printf("\n %s", preguntas[ronda-1].pregunta);
    // Texto 24 alto 32 ancho contando desde 0
    iprintf("\x1b[%d;%dH %s", 8, 5,preguntas[ronda-1].respuestas[0]);
    iprintf("\x1b[%d;%dH %s", 8, 19,preguntas[ronda-1].respuestas[1]);
    iprintf("\x1b[%d;%dH %s", 18, 5,preguntas[ronda-1].respuestas[2]);
    iprintf("\x1b[%d;%dH %s", 18, 19,preguntas[ronda-1].respuestas[3]);
    //printf("\n\n\n\n  %s = %d$", preguntas[ronda-1].respuestas[0],DineroCajas[0]);
    //printf("\n\n\n\n  %s = %d$", preguntas[ronda-1].respuestas[1],DineroCajas[1]);
    //printf("\n\n\n\n  %s = %d$", preguntas[ronda-1].respuestas[2],DineroCajas[2]);
	//printf("\n\n\n\n  %s = %d$", preguntas[ronda-1].respuestas[3],DineroCajas[3]);
}

bool estaCajaVacia(int *dineroCaja){

	return *dineroCaja > 0;

}
void restarDineroCaja(int *dineroCaja, int *dineroTotal){
	*dineroTotal = *dineroTotal + 10000;
       	*dineroCaja = *dineroCaja - 10000;
}

bool estaDineroTotalVacio(int *dineroTotal){

	return *dineroTotal > 0;

}
void sumarDineroCaja(int *dineroCaja, int *dineroTotal){
	*dineroTotal = *dineroTotal - 10000;
       	*dineroCaja = *dineroCaja + 10000;
}



void RutAtencionTeclado ()
{

}

void RutAtencionTempo() {
    static int tick = 0;
    static int seg = 45;
    static int seg5 = 0;
    srand(time(NULL));
    int px = rand() % 240;
    int py = rand() % 180;
    int randInd = (rand() % 127) + 5;
    consoleClear();
    touchRead(&PANT_DAT);
    tick++;


    if (TeclaPulsada()==SELECT){
        oamRotateScale(&oamMain,6,1,150,150);
        oamUpdate(&oamMain);
        oamRotateScale(&oamMain,16,1,150,150);
        oamUpdate(&oamMain);
        oamRotateScale(&oamMain,26,1,150,150);
        oamUpdate(&oamMain);
        oamRotateScale(&oamMain,36,1,150,150);
        oamUpdate(&oamMain);
    }



    printf("0:%d        ",seg);
    if (tick==8 && seg>0){
        seg--;
        tick=0;
    }
    printf("\x1b[%d;%dH %d$",0,12,Dinero);
    printf("\x1b[%d;%dH %d / 10",0,24,ronda);


    if (ESTADO != FINAL && seg>=0) {
        if (seg==0){
            ESTADO=RESUELTO;
        }

	if(ESTADO==SELCAJA || ESTADO==RESOLVIENDO && seg==0){
		printEstadoCajas();
	}

        if (ESTADO != SELCAJA && ESTADO != RESUELTO) {
		switch(seleccionCaja(PANT_DAT.px,PANT_DAT.py)){
			case 0:
				indCaja = 0;
                		mostrarMesaDebug(indCaja, 4, 16);
                        mostrarMesaDebugSub(indCaja+4, 4, 40);
				ESTADO = SELCAJA;
				break;
			case 1:
				// mostrarBillete(4,PANT_DAT.px-20,PANT_DAT.py-20);
				indCaja = 1;
                		mostrarMesaDebug(indCaja, 120, 16);
                        mostrarMesaDebugSub(indCaja+4, 120, 40);
				ESTADO = SELCAJA;
				break;
			case 2:
				indCaja = 2;
                		mostrarMesaDebug(indCaja, 4, 112);
                        mostrarMesaDebugSub(indCaja+4, 4, 116);
				ESTADO = SELCAJA;
				break;
			case 3:
				indCaja = 3;
                		mostrarMesaDebug(indCaja, 120, 112);
                        mostrarMesaDebugSub(indCaja+4, 120, 116);
				ESTADO = SELCAJA;
				break;
		}
            
        }
        if (ESTADO == SELCAJA) {
            if (TeclaPulsada() == B) {
                ESTADO = RESOLVIENDO;
                mostrarMesas();
            }
            if (TeclaPulsada() == L && estaCajaVacia(&DineroCajas[indCaja])) {
                //printf("\n\n -10000 EUROS EN LA OPCION %d", indCaja);
		        restarDineroCaja(&DineroCajas[indCaja],&Dinero);
                ocultarBillete(5+BilletesMesa[indCaja]+indCaja*10,mesaXpos[indCaja]+BilletesMesa[indCaja]*2,mesaYpos[indCaja]+BilletesMesa[indCaja]*2);
		        BilletesMesa[indCaja] = BilletesMesa[indCaja] - 1;
            }
            if (TeclaPulsada() == R && estaDineroTotalVacio(&Dinero)) {
                //printf("\n\n +10000 EUROS EN LA OPCION %d", indCaja);
		        sumarDineroCaja(&DineroCajas[indCaja],&Dinero);
		        BilletesMesa[indCaja] = BilletesMesa[indCaja] + 1;
                if (indCaja==preguntas[ronda-1].indCorrecta){
                    mostrarBilleteCorrecto(5+BilletesMesa[indCaja]+indCaja*10,mesaXpos[indCaja]+BilletesMesa[indCaja]*2,mesaYpos[indCaja]+BilletesMesa[indCaja]*2);
                } else {
                    mostrarBilleteIncorrecto(5+BilletesMesa[indCaja]+indCaja*10,mesaXpos[indCaja]+BilletesMesa[indCaja]*2,mesaYpos[indCaja]+BilletesMesa[indCaja]*2);
                }
            }

            if (TeclaPulsada() == START){
                ESTADO=RESUELTO;
                seg=0;
            }
        }
        // Simplificar tras probar en 1 sola funcion
        if (ESTADO == RESUELTO) {
            mostrarMesasResuelto(preguntas[ronda-1].indCorrecta,mesaXpos,mesaYpos);
            Dinero = Dinero + DineroCajas[preguntas[ronda-1].indCorrecta];
            memset(DineroCajas, 0, sizeof(DineroCajas));
            if (tick==12 && seg5<5){
                seg5++;
                tick=0;
            }
            if (seg5==3){
                // Prueba de billete cayendo
                caerBilletes(tick);
                if (tick==11){
                    quitarBilletes(BilletesMesa,mesaXpos,mesaYpos,preguntas[ronda-1].indCorrecta);
                }
            }


            if ((Dinero == 0 || ronda>10)) {
                borrarMesaIncorrecta(0, mesaXpos[0], mesaYpos[0]);
                borrarMesaIncorrecta(1, mesaXpos[1], mesaYpos[1]);
                borrarMesaIncorrecta(2, mesaXpos[2], mesaYpos[2]);
                borrarMesaIncorrecta(3, mesaXpos[3], mesaYpos[3]);
                borrarMesaCorrecta(indCaja, mesaXpos[indCaja], mesaYpos[indCaja]);
                visualizarFondoUno();
                ESTADO = FINAL;
                consoleClear();
                } else if (seg5==5){
                    quitarBilletesCorrecta(BilletesMesa,mesaXpos,mesaYpos,preguntas[ronda-1].indCorrecta);
                    resetBilletes(BilletesMesa);
                    memset(BilletesMesa,0, sizeof(BilletesMesa));
                    ronda=ronda+1;
                    seg=45;
                    seg5=0;
                    ESTADO=RESOLVIENDO;
                    mostrarMesas();
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

