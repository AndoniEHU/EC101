// Curso 2023-2024


extern void memoriaReserva();

extern void EstablecerPaleta();

/* Carga en memoria los Sprites dibujados */
extern void GuardarSpritesMemoria();

extern void mostrarMesas(int mesaXpos[8], int mesaYpos[8]);

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
