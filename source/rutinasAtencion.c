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
// struct mesa {
//    int idMesa;
//    int dineroActual;
//    int mesaXpos;
//    int mesaYpos;
//    _Bool esCorrecta;
// };


//struct mesa Tablero [4]
//struct mesa mesa_A = {0,0,4,16,0};
//struct mesa mesa_B = {1,0,120,16,0};
//struct mesa mesa_C = {2,0,4,112,0};
//struct mesa mesa_D = {3,0,120,112,0};

int DineroCajas[4] = {0};
int BilletesMesa[4] = {0};
int mesaXpos[] = {4,120,4,120};
int mesaYpos[] = {16,16,112,112};
int indCaja;


int seleccionCaja(int px,int py){
	if ((px >= 30 && px <= 120) && (py >= 30 && py <= 80)) return 0;
	if ((px >= 136 && px <= 224) && (py >= 30 && py <= 80)) return 1;
	if ((px >= 30 && px <= 120) && (py >= 116 && py <= 164)) return 2;
	if ((px >= 136 && px <= 224) && (py >= 116 && py <= 164)) return 3;
	return -1;

}

void printEstadoCajas(){
	printf("\n\n\n\n Dinero actual= %d", Dinero);
        printf("\n\n\n\n Dinero actual Caja A = %d", DineroCajas[0]);
        printf("\n\n\n\n Dinero actual Caja B = %d", DineroCajas[1]);
        printf("\n\n\n\n Dinero actual Caja C = %d", DineroCajas[2]);
	printf("\n\n\n\n Dinero actual Caja D = %d", DineroCajas[3]);
	printf("\n\n Mesa escogida = %d", indCaja);
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
    static int ronda = 1;
    srand(time(NULL));
    int px = rand() % 240;
    int py = rand() % 180;
    int randInd = (rand() % 127) + 5;
    consoleClear();
    touchRead(&PANT_DAT);
    tick++;

    printf("Han pasado segundos %d",seg);
    if (tick==8 && seg>0){
        seg--;
        tick=0;
    }


    //printf("Pos x: %d", PANT_DAT.px);
    //printf("Pos y: %d", PANT_DAT.py);


    // Mostrar mesas (meter en 1 funcion)
    // diruaJauzi(2);

    printf("\n\n ESTADO=%d",ESTADO);
    printf("\n\n Ronda actual = %d / 10",ronda);
    if (ESTADO != FINAL && seg>=0) {
        if (seg==0){
            ESTADO=RESUELTO;
        }

        if (ESTADO != SELCAJA) {
		switch(seleccionCaja(PANT_DAT.px,PANT_DAT.py)){
			case 0:
				indCaja = 0;
                		mostrarMesaDebug(indCaja, 4, 16);
				ESTADO = SELCAJA;
				break;
			case 1:
				// mostrarBillete(4,PANT_DAT.px-20,PANT_DAT.py-20);
				indCaja = 1;
                		mostrarMesaDebug(indCaja, 120, 16);
				ESTADO = SELCAJA;
				break;
			case 2:
				indCaja = 2;
                		mostrarMesaDebug(indCaja, 4, 112);
				ESTADO = SELCAJA;
				break;
			case 3:
				indCaja = 3;
                		mostrarMesaDebug(indCaja, 120, 112);
				ESTADO = SELCAJA;
				break;
		}
            
        }
        if (ESTADO == SELCAJA) {
	    printEstadoCajas();
            if (TeclaPulsada() == B) {
                ESTADO = RESOLVIENDO;
                mostrarMesas();
            }
            if (TeclaPulsada() == L && estaCajaVacia(&DineroCajas[indCaja])) {
                printf("\n\n -10000 EUROS EN LA OPCION %d", indCaja);
		restarDineroCaja(&DineroCajas[indCaja],&Dinero);
		BilletesMesa[indCaja] = BilletesMesa[indCaja] - 1;
            }
            if (TeclaPulsada() == R && estaDineroTotalVacio(&Dinero)) {
                printf("\n\n +10000 EUROS EN LA OPCION %d", indCaja);
		sumarDineroCaja(&DineroCajas[indCaja],&Dinero);
		BilletesMesa[indCaja] = BilletesMesa[indCaja] + 1;
            }
        }
        // Simplificar tras probar en 1 sola funcion
        if (ESTADO == RESUELTO) {
            mostrarMesasResuelto(indCaja,mesaXpos,mesaYpos);
         //   mostrarMesaIncorrecta(0, mesaXpos[0], mesaYpos[0]);
         //   mostrarMesaIncorrecta(1, mesaXpos[1], mesaYpos[1]);
         //   mostrarMesaIncorrecta(2, mesaXpos[2], mesaYpos[2]);
         //   mostrarMesaIncorrecta(3, mesaXpos[3], mesaYpos[3]);
         //   mostrarMesaCorrecta(indCaja, mesaXpos[indCaja], mesaYpos[indCaja]);
            ponerBilletes(BilletesMesa,mesaXpos,mesaYpos);
            Dinero = Dinero + DineroCajas[indCaja];
            memset(DineroCajas, 0, sizeof(DineroCajas));
            if (tick==12 && seg5<5){
                printf("Segundos animacion: %d",seg5);
                seg5++;
                tick=0;
            }
            if (seg5==3){
                // Prueba de billete cayendo
                oamRotateScale(&oamMain, 15, 1, 150 + 100 * i*2, 150 + 100 * i*2);
                oamUpdate(&oamMain);
            }

            if ((Dinero == 0 || ronda>10)) {
                borrarMesaIncorrecta(0, mesaXpos[0], mesaYpos[0]);
                borrarMesaIncorrecta(1, mesaXpos[1], mesaYpos[1]);
                borrarMesaIncorrecta(2, mesaXpos[2], mesaYpos[2]);
                borrarMesaIncorrecta(3, mesaXpos[3], mesaYpos[3]);
                borrarMesaCorrecta(indCaja, mesaXpos[indCaja], mesaYpos[indCaja]);
                visualizarFondoUno();
                ESTADO = FINAL;
                } else if (seg5==5){
                borrarBillete(15,1,1);
                    ronda=ronda+1;
                    seg=45;
                    seg5=0;
                    borrarBillete(7,mesaXpos[1],mesaYpos[1]);
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


void InicializarPreguntas(){

	
}

