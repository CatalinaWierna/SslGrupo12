#include <assert.h>
#include "tabla.h"
#include "conversion.h"

int inicio;
int final;

void generarTabla (int inicio, int final){
    int iteraciones = final-inicio+1;
    assert(inicio>0);
    printf("|   Nudos|      Km/h|");
    for (int i=0; i<iteraciones; i++){
        printf("|    %i|     %i|",inicio+i,convertir(inicio+i));
    }
}