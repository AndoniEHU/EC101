// Curso 2023-2024

extern u16* gfx;
extern u16* gfx2;
extern u16* gfx3;
extern u16* gfxSub;

extern void memoriaReserva();

/* Para cada uno de los 256 valores que puede tomar un Píxel le da un color en la pantalla principal. El valor 0 es transparente y los valores sin definir, negros */
extern void EstablecerPaletaBillete();


extern void EstablecerPaleta();

/* Para cada uno de los 256 valores que puede tomar un Píxel le da un color en la pantalla secundaria. El valor 0 es transparente y los valores sin definir negros */
extern void EstablecerPaletaSecundaria();


/* Carga en memoria los Sprites dibujados */
extern void GuardarSpritesMemoria();

extern void mostrarMesas(int mesaXpos[8], int mesaYpos[8]);
/* Esta función dibuja un rombo en la posición de pantalla x,y. A cada rombo que queramos sacar en pantalla se le debe asignar un índice distinto que puede tomara valores entre 0 y 126 */
extern void mostrarBillete(int indice, int x, int y);

extern void mostrarBilleteSub(int indice, int x, int y);


/* Esta función borra de la pantalla el rombo con el índice que se le indique como parámetro */
extern void borrarBillete(int indice, int x, int y);

extern void mostrarMesaNormal(int indice, int x, int y, OamState *estado, bool mostrar);
extern void mostrarMesaElegida(int indice, int x, int y, OamState *estado, bool mostrar);
extern void ocultarBillete(int indice, int x, int y);
extern void mostrarBilleteCorrectoPorMesa(int indCaja, int BilletesMesa);
extern void mostrarBilleteIncorrectoPorMesa(int indCaja, int BilletesMes);
extern void mostrarMesasResuelto(int indiceCorrecto, int mesaXpos[4], int mesaYpos[4]);
extern void caerBilletes(int tick);
extern void quitarBilletes(int billetesMesa[4], int mesaXpos[4], int mesaYpos[4], int indCorrecta);
extern void borrarMesas(int mesaXpos[4], int mesaYpos[4]);
extern void quitarBilletesCorrecta(int billetesMesa[4], int mesaXpos[4], int mesaYpos[4], int indCorrecta);
extern void resetBilletes();
extern void billetesFinal(int tick, int BilletesMesa);
extern void mostrarBilletesAleatorios(int indice, int x, int y, bool mostrar);
