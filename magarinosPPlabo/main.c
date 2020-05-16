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

#define TAMMOT 10
#define TAMTIP 4
#define TAMCOL 5
#define TAMSER 5
#define TAMTRA 5


int main()
{
    char salir = 'n';
    int autoIdMoto = 0;
    eMoto motos[TAMMOT];
    eTipo tipos[TAMTIP] = {{1000, "Enduro"}, {1001, "Chopera"}, {1002, "Scooter"}, {1003, "Ciclomotor"}};
    eColor colores[TAMCOL] = {{10000, "Gris"}, {10001, "Negro"}, {10002, "Blanco"}, {10003, "Azul"}, {10004, "Rojo"}};
    eServicio servicios[TAMSER] = {{20000, "Limpieza", 250.00}, {20001, "Ajuste", 300.00}, {20002, "Balanceo", 17.00}, {20003, "Cadena", 190.50}};
    eTrabajo trabajos[TAMTRA];

    inicializarMoto(motos, TAMMOT);
    //inicializarTipo(tipos, TAMTIP);
    //inicializarColores(colores, TAMCOL);
    //inicializarServicios(servicios, TAMSER);
    inicializarTrabajos(trabajos, TAMTRA);

    do{
        switch(menuOpciones()){
            case 'a':
                altaMoto(autoIdMoto, motos, TAMMOT, tipos, TAMTIP, colores, TAMCOL);
                break;
            case 'b':
                break;
            case 'c':
                bajaMoto(motos, TAMMOT, tipos, TAMTIP, colores, TAMCOL);
                break;
            case 'd':
                listarMotos(motos, TAMMOT, tipos, TAMTIP, colores, TAMCOL);
                break;
            case 'e':
                mostrarTipos(tipos, TAMTIP);
                break;
            case 'f':
                mostrarColores(colores, TAMCOL);
                break;
            case 'g':
                mostrarServicios(servicios,  TAMSER);
                break;
            case 'h':
                altaTrabajos();
                break;
            case 'i':
//                mostrarTrabajos(trabajos, TAMTRA);
                break;
            case 'j':
                printf("\nConfirma salida? s/n \n");
                getCharConfirmValidado(&salir);
                break;
        }

    }while(salir == 'n');

    return 0;
}
