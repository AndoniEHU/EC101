/*-------------------------------------
rutinasAtencion.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"
#include "preguntas.h"

int ESTADO;
int Dinero = 100000;


int DineroCajas[4] = {0};
int BilletesMesa[4] = {0};
int mesaXpos[8] = {4,120,4,120,4,120,4,120};
int mesaYpos[8] = {16,16,112,112,40,40,116,116};
int indCaja;
int ronda = 11;
static int seg = 45;
static int seg5 = 0;


int seleccionCaja(int px,int py){
    if (ESTADO!=FINAL) {
        if ((px >= 30 && px <= 120) && (py >= 30 && py <= 80)) return 0;
        if ((px >= 136 && px <= 224) && (py >= 30 && py <= 80)) return 1;
        if ((px >= 30 && px <= 120) && (py >= 116 && py <= 164)) return 2;
        if ((px >= 136 && px <= 224) && (py >= 116 && py <= 164)) return 3;
    }
    return -1;
}

void printEstadoCajas(){
    printf("\n %s", preguntas[ronda-1].pregunta);
    iprintf("\x1b[%d;%dH %s", 8, 5,preguntas[ronda-1].respuestas[0]);
    iprintf("\x1b[%d;%dH %s", 8, 19,preguntas[ronda-1].respuestas[1]);
    iprintf("\x1b[%d;%dH %s", 18, 5,preguntas[ronda-1].respuestas[2]);
    iprintf("\x1b[%d;%dH %s", 18, 19,preguntas[ronda-1].respuestas[3]);
    iprintf("\x1b[%d;%dH %d$", 13, 5,DineroCajas[0]);
    iprintf("\x1b[%d;%dH %d$", 13, 19,DineroCajas[1]);
    iprintf("\x1b[%d;%dH %d$", 23, 5,DineroCajas[2]);
	iprintf("\x1b[%d;%dH %d$", 23, 19,DineroCajas[3]);
}

bool estaCajaVacia(int *dineroCaja){

	return *dineroCaja > 0;

}

bool estaDineroTotalVacio(int *dineroTotal){

    return *dineroTotal > 0;

}

void mostrarSumaDinero(int indCaja){
    switch (indCaja) {
        case 0:
            iprintf("\x1b[32m\x1b[%d;%dH +%d$\x1b[39m", 13, 5,DineroCajas[0]);
            break;
        case 1:
            iprintf("\x1b[32m\x1b[%d;%dH +%d$\x1b[39m", 13, 19,DineroCajas[1]);
            break;
        case 2:
            iprintf("\x1b[32m\x1b[%d;%dH +%d$\x1b[39m", 23, 5,DineroCajas[2]);
            break;
        case 3:
            iprintf("\x1b[32m\x1b[%d;%dH +%d$\x1b[39m", 23, 19,DineroCajas[3]);
            break;
    }
}
void mostrarRestaDinero(int indCaja){
    switch (indCaja) {
        case 0:
            iprintf("\x1b[31m\x1b[%d;%dH -%d$\x1b[39m", 13, 5,DineroCajas[0]);
            break;
        case 1:
            iprintf("\x1b[31m\x1b[%d;%dH -%d$\x1b[39m", 13, 19,DineroCajas[1]);
            break;
        case 2:
            iprintf("\x1b[31m\x1b[%d;%dH -%d$\x1b[39m", 23, 5,DineroCajas[2]);
            break;
        case 3:
            iprintf("\x1b[31m\x1b[%d;%dH -%d$\x1b[39m", 23, 19,DineroCajas[3]);
            break;
    }
};
void restarDineroCaja(int *dineroCaja, int *dineroTotal){
	*dineroTotal = *dineroTotal + 10000;
       	*dineroCaja = *dineroCaja - 10000;
}

void sumarDineroCaja(int *dineroCaja, int *dineroTotal){
	*dineroTotal = *dineroTotal - 10000;
       	*dineroCaja = *dineroCaja + 10000;
}

void mostrarCreditos(){
    printf("\x1b[%d;%dH %s",9,11,"Autores:");
    printf("\x1b[%d;%dH %s",11,6,"Mikel Berasategui");
    printf("\x1b[%d;%dH %s",12+1,6,"Andoni de la Iglesia");
    printf("\x1b[%d;%dH %s",15,6,"Mikel Bilbao");
    printf("\x1b[%d;%dH%s",18,4,"Proyecto EC101 2023/2024");
}
void mostrarFinal(int tick){
    borrarMesas(mesaXpos,mesaYpos);
    quitarBilletes(BilletesMesa,mesaXpos,mesaYpos,preguntas[ronda-1].indCorrecta);
    visualizarFin();
    ESTADO = FINAL;
    consoleClear();
    if (Dinero>0){
        printf("\x1b[%d;%dHFelicades, has ganado %d$!",6,1,Dinero);
        billetesFinal(tick, BilletesMesa[indCaja]);
    } else {
        printf("\x1b[%d;%dH %s",6,2,"Has perdido todo el dinero!");
    }
    mostrarCreditos();
}

void RutAtencionTeclado ()
{
    touchRead(&PANT_DAT);

    if (ESTADO == SELCAJA) {
        if (TeclaPulsada() == B) {
            ESTADO = RESOLVIENDO;
            mostrarMesas(mesaXpos,mesaYpos);
        }
        if (TeclaPulsada() == L && estaCajaVacia(&DineroCajas[indCaja])) {
            restarDineroCaja(&DineroCajas[indCaja],&Dinero);
            ocultarBillete(5+BilletesMesa[indCaja]+indCaja*10,mesaXpos[indCaja]+BilletesMesa[indCaja]*2,mesaYpos[indCaja]+BilletesMesa[indCaja]*2);
            BilletesMesa[indCaja] = BilletesMesa[indCaja] - 1;
            mostrarRestaDinero(indCaja);
        }
        if (TeclaPulsada() == R && estaDineroTotalVacio(&Dinero)) {
            sumarDineroCaja(&DineroCajas[indCaja],&Dinero);
            BilletesMesa[indCaja] = BilletesMesa[indCaja] + 1;
            mostrarSumaDinero(indCaja);
            if (indCaja==preguntas[ronda-1].indCorrecta){
                mostrarBilleteCorrectoPorMesa(indCaja,BilletesMesa[indCaja]);
            } else {
                mostrarBilleteIncorrectoPorMesa(indCaja,BilletesMesa[indCaja]);
            }
        }
    }

    if ((TeclaPulsada() == START) && ESTADO!=FINAL){
        ESTADO=RESUELTO;
        seg=0;
    }

    if (ESTADO != SELCAJA && ESTADO != RESUELTO) {
        switch(seleccionCaja(PANT_DAT.px,PANT_DAT.py)){
            case -1:
                break;
            case 0:
                indCaja = 0;
                mostrarMesaElegida(indCaja, 4, 16, &oamMain, true);
                mostrarMesaElegida(indCaja+4, 4, 40, &oamSub, true);
                ESTADO = SELCAJA;
                break;
            case 1:
                indCaja = 1;
                mostrarMesaElegida(indCaja, 120, 16, &oamMain, true);
                mostrarMesaElegida(indCaja+4, 120, 40, &oamSub, true);
                ESTADO = SELCAJA;
                break;
            case 2:
                indCaja = 2;
                mostrarMesaElegida(indCaja, 4, 112, &oamMain, true);
                mostrarMesaElegida(indCaja+4, 4, 116, &oamSub, true);
                ESTADO = SELCAJA;
                break;
            case 3:
                indCaja = 3;
                mostrarMesaElegida(indCaja, 120, 112, &oamMain, true);
                mostrarMesaElegida(indCaja+4, 120, 116, &oamSub, true);
                ESTADO = SELCAJA;
                break;
        }

    }
}

void RutAtencionTempo() {
    static int tick = 0;
    tick++;

    if (ESTADO==FINAL){
        mostrarFinal(tick%11);
    }

    if (ESTADO != FINAL && seg>=0) {
        consoleClear();
        printf("0:%d        ",seg);
        if (tick==8 && seg>0){
            seg--;
            tick=0;
        }
        printf("\x1b[%d;%dH %d$",0,12,Dinero);
        printf("\x1b[%d;%dH %d / 10",0,24,ronda);

        printEstadoCajas();

        if (seg==0){
            ESTADO=RESUELTO;
        }


        if (ESTADO == RESUELTO) {
            mostrarMesasResuelto(preguntas[ronda-1].indCorrecta,mesaXpos,mesaYpos);
            Dinero = DineroCajas[preguntas[ronda-1].indCorrecta];
            if (tick==12 && seg5<5){
                seg5++;
                tick=0;
            }

            if (seg5==3){
                caerBilletes(tick);
                if (tick==8){
                    quitarBilletes(BilletesMesa,mesaXpos,mesaYpos,preguntas[ronda-1].indCorrecta);
                }
            }

            if ((Dinero == 0 || ronda>=10) && (seg5==5)) {
                ESTADO=FINAL;
                quitarBilletesCorrecta(BilletesMesa,mesaXpos,mesaYpos,preguntas[ronda-1].indCorrecta);
                } else if (seg5==5){
                    quitarBilletesCorrecta(BilletesMesa,mesaXpos,mesaYpos,preguntas[ronda-1].indCorrecta);
                    resetBilletes(BilletesMesa);
                    memset(DineroCajas, 0, sizeof(DineroCajas));
                    memset(BilletesMesa,0, sizeof(BilletesMesa));
                    ronda=ronda+1;
                    seg=45;
                    seg5=0;
                    ESTADO=RESOLVIENDO;
                    mostrarMesas(mesaXpos,mesaYpos);
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

