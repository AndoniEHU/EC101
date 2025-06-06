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
int ronda = 1;
bool poderModificarDinero = true;
static int seg = 45;
static int seg5 = 0;

void mostrarInicio(){
    int i;
    cargarFondoInicio();
    iprintf("\x1b[%d;%dH %s", 4, 0,"Bienvenido a atrapa un millon!");
    iprintf("\x1b[%d;%dH %s", 6, 10,"CONTROLES");
    iprintf("\x1b[%d;%dH%s", 8, 0,"- Pulsa en la caja para elegir");
    iprintf("\x1b[%d;%dH%s", 10, 0,"- R para poner dinero en caja");
    iprintf("\x1b[%d;%dH%s", 12, 0,"- L para quitar el dinero");
    iprintf("\x1b[%d;%dH%s", 14, 0,"- START para confirmar respuesta");
    iprintf("\x1b[%d;%dH%s", 16, 0,"- B para deseleccionar la caja");
    iprintf("\x1b[%d;%dH%s", 18, 3,"Pulsa SELECT para comenzar!");

    while(TeclaPulsada()!=SELECT){
        mostrarBilletesAleatorios(64,0+i,-15,true);
        mostrarBilletesAleatorios(65,190-i,-15,true);
        mostrarBilletesAleatorios(66,0+i,140,true);
        mostrarBilletesAleatorios(67,190-i,140,true);
        i++;
        if (i==190){
            i=0;
        }
    }
    mostrarBilletesAleatorios(64,0+i,-15,false);
    mostrarBilletesAleatorios(65,190-i,-15,false);
    mostrarBilletesAleatorios(66,0+i,140,false);
    mostrarBilletesAleatorios(67,190-i,140,false);
    ESTADO=PREGUNTA;
}


int seleccionCaja(int px,int py){
    if (ESTADO!=FINAL || ESTADO!=INICIO) {
        if ((px >= 30 && px <= 120) && (py >= 30 && py <= 80)) return 0;
        if ((px >= 136 && px <= 224) && (py >= 30 && py <= 80)) return 1;
        if ((px >= 30 && px <= 120) && (py >= 116 && py <= 164)) return 2;
        if ((px >= 136 && px <= 224) && (py >= 116 && py <= 164)) return 3;
    }
    return -1;
}
void mostrarTiempo(){
    if (seg>=10){
        printf("0:%d        ",seg);
    } else {
        printf("0:0%d        ",seg);
    }
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
    //mostrar mesas e interrupcion si se pulsa B para poder seleccionar otra caja
    if (ESTADO == SELCAJA) {
        if (TeclaPulsada() == B) {
            ESTADO = RESOLVIENDO;
            mostrarMesas(mesaXpos,mesaYpos);
        }
        //Si se pulsa L y se queda dinero en la caja: se le quita el dinero a la caja y se pasa al dinero global
        if (TeclaPulsada() == L && estaCajaVacia(&DineroCajas[indCaja]) && poderModificarDinero==true) {
            restarDineroCaja(&DineroCajas[indCaja],&Dinero);
            ocultarBillete(5+BilletesMesa[indCaja]+indCaja*10,mesaXpos[indCaja]+BilletesMesa[indCaja]*2,mesaYpos[indCaja]+BilletesMesa[indCaja]*2);
            BilletesMesa[indCaja] = BilletesMesa[indCaja] - 1;
            poderModificarDinero=false;
            mostrarRestaDinero(indCaja);
        }
        //Si se pulsa R y se queda dinero globar: se le quita el dinero global y se pasa al dinero de la caja
        if (TeclaPulsada() == R && estaDineroTotalVacio(&Dinero) && poderModificarDinero==true) {
            sumarDineroCaja(&DineroCajas[indCaja],&Dinero);
            BilletesMesa[indCaja] = BilletesMesa[indCaja] + 1;
            poderModificarDinero=false;
            mostrarSumaDinero(indCaja);
            //si la mesa se elige es incorrecta/correcta se pasa un id distintivo de rotacion para los billetes
            if (indCaja==preguntas[ronda-1].indCorrecta){
                mostrarBilleteCorrectoPorMesa(indCaja,BilletesMesa[indCaja]);
            } else {
                mostrarBilleteIncorrectoPorMesa(indCaja,BilletesMesa[indCaja]);
            }
        }
    }
    //confirmar respuesta
    if ((TeclaPulsada()==START) && (ESTADO!=FINAL && ESTADO!=INICIO)){
        ESTADO=RESUELTO;
        seg=0;
    }
    //seleccionar caja con la pantalla tactil
    if (ESTADO==RESOLVIENDO) {
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
    touchRead(&PANT_DAT);

    //mostrar pantalla final
    if (ESTADO==FINAL){
        mostrarFinal(tick%11);
    }
    //se usa el tick%2 para que no se sumen billetes sin querer
    if(ESTADO==SELCAJA && tick%2==0){
        poderModificarDinero=true;
    }

    //mostrar tiempo,dinero y ronda y reiniciar ticks cada segundo
    if ((ESTADO != FINAL && seg>=0) && ESTADO!=INICIO) {
        consoleClear();
        mostrarTiempo();
        if (tick==8 && seg>0){
            seg--;
            tick=0;
        }
        printf("\x1b[%d;%dH %d$",0,12,Dinero);
        printf("\x1b[%d;%dH %d / 10",0,24,ronda);

        printEstadoCajas();
        //seg variable que controla el tiempo total al responder
        if (seg==0){
            ESTADO=RESUELTO;
        }

        //comprueba la respuesta y inicia tiempo para cambio de estado (cuando pasen 5 segundos)
        if (ESTADO == RESUELTO) {
            mostrarMesasResuelto(preguntas[ronda-1].indCorrecta,mesaXpos,mesaYpos);
            Dinero = DineroCajas[preguntas[ronda-1].indCorrecta];
            if (tick==12 && seg5<5){
                seg5++;
                tick=0;
            }
            //animacion perder dinero de mesa incorrecta
            if (seg5==3){
                caerBilletes(tick);
                if (tick==8){
                    quitarBilletes(BilletesMesa,mesaXpos,mesaYpos,preguntas[ronda-1].indCorrecta);
                }
            }
            //cambiar al estado final si el dinero se acaba o llega a la ronda final
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
	irqSet(IRQ_TIMER0,RutAtencionTempo);
}

