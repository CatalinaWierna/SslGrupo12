#include "tabla.h"

int main (int argc, char** argv){
    if(argc<=3){
    generarTabla (argv[1], argv[2]);
    }
    else {
    generarTablaConIncremento (argv[1], argv[2], argv[3]);
    }
}
