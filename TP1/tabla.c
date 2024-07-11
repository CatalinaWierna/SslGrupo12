#include <assert.h>
#include<math.h>
#include <stdlib.h>
#include <stdio.h>
#include "tabla.h"
#include "conversion.h"

float inicio;
float final;
float incremento;
void generarTabla (char* ini, char* fin){
    inicio = atof (ini);
    final = atof(fin);
    int iteraciones = final-inicio+1;
    assert(inicio>0);
    printf("|   Nudos|      Km/h| \n");
    for (int i=0; i<iteraciones; i++){
        printf("|    %.3f|     %.3f| \n",inicio+i,convertir(inicio+i));
    }
}

void generarTablaConIncremento (char* ini, char* fin, char* salto){
    inicio = atof (ini);
    final = atof(fin);
    incremento = atof(salto);
    assert(inicio>0);
    printf("|   Nudos|      Km/h| \n");
    while(inicio<final){
        printf("|    %.3f|     %.3f| \n",inicio,convertir(inicio));
        inicio=inicio+incremento;
    }
}