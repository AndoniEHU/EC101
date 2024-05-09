
#include <nds.h> 		
#include <stdio.h>		
#include <stdlib.h>		
#include <unistd.h>		

/* Si queremos visualizar distintos fondos, aquí se debe incluir el fichero de cabecera (fichero .h) de cada fondo. Estos ficheros de cabecera se generan automáticamente durante la compilación */

#include "fondos.h"
#include "graficos.h"
#include "fondoFinal.h"
#include "fondoMain.h"
#include "fondoInicio.h"

/* Se elige el canal de DMA que se utilizará para copiar las imágenes en memoria */
static const int DMA_CHANNEL = 3;

void cargarFondoInicio(){
    dmaCopyHalfWords(DMA_CHANNEL,
                     fondoInicioBitmap, /* Variable que se genera automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     fondoInicioBitmapLen);
}

void cargarFondoMain(){
    dmaCopyHalfWords(DMA_CHANNEL,
                     fondoMainBitmap, /* Variable que se genera automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     fondoMainBitmapLen);
}

void visualizarFin(){
    dmaCopyHalfWords(DMA_CHANNEL,
                     fondoFinalBitmap, /* Variable que se genera automáticamente */
                     (uint16 *)BG_BMP_RAM(0), /* Dirección del fondo principal */
                     fondoFinalBitmapLen);
}