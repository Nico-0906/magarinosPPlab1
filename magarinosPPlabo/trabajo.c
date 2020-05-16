#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "moto.h"
#include "servicio.h"
#include "trabajo.h"
#include "herramientas.h"


int altaTrabajos(){

}

void inicializarTrabajos(eTrabajo trabajos[] ,int tamtra){
     for(int i = 0 ; i < tamtra ; i++){
        trabajos[i].isEmpty = 1;
     }
}
